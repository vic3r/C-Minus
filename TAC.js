createRegex: () => {
	let Rx = {};
	Rx['int'] = "[0-9]+";
	Rx['float'] = "[0-9]+.[0-9]+";
	Rx['string'] = "[a-zA-Z0-9]*";
	Rx['char'] = "[a-zA-Z0-9]{0,1}";
	Rx['var'] = "[a-zA-Z][a-zA-Z0-9]*(\\[([0-9]+|[a-zA-Z][a-zA-Z0-9]*)\\])?";
	Rx['constant'] = "[0-9]+";
	Rx['op'] = "[\\*\\-\\+\\/\\&\\=\\<\\!\\>\\%]+";
	Rx['goto'] = "(\\s+)?goto(\\s+)(" + Rx.var + ")(\\s+)?";
	Rx['exp'] = "(\\s+)?((((" + Rx.var + ")|(" + Rx.constant + "))?(\\s+)?(" + Rx.op + ")(\\s+)?((" + Rx.var + ")|(" + Rx.constant + ")))|(" + Rx.var + ")|(" + Rx.constant + "))";
	Rx['exp_int'] = "(\\s+)?((((" + Rx.int + ")|(" + Rx.constant + "))?(\\s+)?(" + Rx.op + ")(\\s+)?((" + Rx.int + ")|(" + Rx.constant + ")))|(" + Rx.int + ")|(" + Rx.constant + "))";
	Rx['exp_float'] = "(\\s+)?((((" + Rx.float + ")|(" + Rx.constant + "))?(\\s+)?(" + Rx.op + ")(\\s+)?((" + Rx.float + ")|(" + Rx.constant + ")))|(" + Rx.float + ")|(" + Rx.constant + "))";
	Rx['exp_string'] = "(\\s+)?((((" + Rx.string + ")|(" + Rx.constant + "))?(\\s+)?(" + Rx.op + ")(\\s+)?((" + Rx.string + ")|(" + Rx.constant + ")))|(" + Rx.string + ")|(" + Rx.constant + "))";
	Rx['exp_char'] = "(\\s+)?((((" + Rx.char + ")|(" + Rx.constant + "))?(\\s+)?(" + Rx.op + ")(\\s+)?((" + Rx.char + ")|(" + Rx.constant + ")))|(" + Rx.char + ")|(" + Rx.constant + "))";
	Rx['method'] = '(\\s+)?call\\s+(' + Rx.var + ')(\\s+)?,(\\s+)?(' + Rx.exp + ')(\\s+)?';
	Rx['method_int'] = '(\\s+)?call\\s+(' + Rx.int + ')(\\s+)?,(\\s+)?(' + Rx.exp_int + ')(\\s+)?';
	Rx['method_float'] = '(\\s+)?call\\s+(' + Rx.float + ')(\\s+)?,(\\s+)?(' + Rx.exp_float + ')(\\s+)?';
	Rx['method_string'] = '(\\s+)?call\\s+(' + Rx.string + ')(\\s+)?,(\\s+)?(' + Rx.exp_string + ')(\\s+)?';
	Rx['method_char'] = '(\\s+)?call\\s+(' + Rx.char + ')(\\s+)?,(\\s+)?(' + Rx.exp_char + ')(\\s+)?';
	Rx['return'] = "(\\s+)?return(\\s+(" + Rx.exp + "))?(\\s+)?";
	Rx['print'] = "(\\s+)?print\\s+(" + Rx.exp + ")(\\s+)?";
	Rx['if'] = "(\\s+)?if\\s+(" + Rx.exp + ")\\s+((" + Rx.exp + ")|(" + Rx.goto + ")|(" + Rx.return + ")|(" + Rx.print + "))(\\s+)?";
	Rx['param'] = "(\\s+)?param\\s+(" + Rx.exp + ")(\\s+)?";
	Rx['def_method'] = '(\\s+)?Entry: \\s+(' + Rx.var + ')(\\s+)?,(\\s+)?(' + Rx.constant + ')(\\s+)?';
	Rx['end_method'] = "(\\s+)?End: (\\s+)?";
	return Rx
}

let TAC = (Config) => {
	let Lines = [];
	let Heap = {};
	// Heapify the variables
	let Operations = {};
	let Indexes = {};
	let Parameters = [];

	let Outputs = [];
	let StdOut;
	let StdErr;

	//Regex definition
	let Rx = createRegex()
	let isMethodDef = false;
	let methodName = "root";

	let stack = [];

	let debug = false;
	let stopOnError = false;
	let separater = '\n';

	if (typeof Config == "object") {
		if(typeof Config['debug'] != "undefined")
			debug = Config['debug'];
		
		if(typeof Config['stopOnError'] != "undefined")
			stopOnError = Config['stopOnError'];

		if(typeof Config['separater'] != "undefined")
			separater = Config['separater'];
	}

	this.run = (code, stdin, callback, error) => {

		Heap = {};

		if(typeof callback == "function")
			StdOut = callback;

		if(typeof error == "function")
			StdErr = error;

		if (typeof code == "string" && code.length > 0) {
			code = code.split(separater);
			Lines = code;
		}

		if(typeof stdin == "object" && stdin.length > 0) {
			for (key in stdin) {
				Heap['p' + key] = stdin[key];
			}
		}

		if(Lines.length > 0) {
			return build();
		}

		return false;
	}

	this.run_line = (code, stdin, callback, error, clearHeap) => {
		if(clearHeap) 
			Heap = {};

		if(typeof callback == "function")
			StdOut = callback;

		if(typeof error == "function")
			StdErr = error;

		if (typeof code == "string" && code.length > 0) {
			Lines = [];
			Lines.push(code);
		}

		if(typeof stdin == "object" && stdin.length > 0) {
			for (key in stdin) {
				Heap['p' + key] = stdin[key];
			}
		}

		if(Lines.length > 0) {
			return build();
		}

		return false;
	}

	this.add = (line) => {
		Lines.push(line);
	}

	this.get = (v) => {
		return evaluate(v);

		throw {'message': "Undefined variable '"+v + "'", 'code': 100};
	}

	this.output = () => {
		return Outputs
	}

	this.debug = () => {
		if(!debug) return false;

		console.log(Rx, Heap, Lines, Indexes, Parameters, Operations);
		return Heap;
	}

	isNumber: (n) => {
		return !isNaN(parseFloat(n)) && isFinite(n);
	}

	isVar: (n) => {
		return (typeof Heap[n] != "undefined");
	}

	isMethod: (n) => {
		return (typeof Operations[n] == "object");
	}

	isIndexedVar: (n) => {
		if(n.match(/\[.*\]/)) {
			return (typeof Heap[n.substr(0, n.indexOf('['))] == "object");
		}
		
		return false;
	}

	isPointer: (n, level) => {
		if(typeof level == "undefined" || level == 1) {
			if (isVar(n) && isVar(getVar(n))) return true;
		} else {
			return isVar(n) && isPointer(getVar(n), level-1);
		}
		return false;
	}

	let getVar = (id) => {
		id = id.replace(/\s+/, "");

		if (id.length == 0) 
			throw {'message': "Missing Operand", 'code': 101};

		if(isNumber(id)) 
			return parseFloat(id);

		if(isVar(id)) 
			return Heap[id];

		if(isIndexedVar(id)) {
			let Indexes = evaluate(id.substr(id.indexOf('[')+1, id.indexOf(']')- 1 - id.indexOf('[')));
			let obj = Heap[id.substr(0, id.indexOf('['))];

			if (typeof obj[parseFloat(Indexes)] != "undefined")
				return obj[parseFloat(Indexes)];

			throw {'message':  "Array Indexes out of bound '" + id + "'", code: 108};
		}


		else throw {'message': "Unknown variable '"+ id + "'", 'code': 100};
	}

	let evaluate = (exp) => {
		exp = exp.replace(/\s+/g, "");

		if(exp.match(Rx.op)) {
			let op = exp.match(Rx.op)[0];
			let vars = exp.split(op);

			if(vars[0].replace(/\s+/, "").length == 0 && vars[1].replace(/\s+/, "").length > 0) {
				switch(op) {
					case "-": 	return -getVar(vars[1]);
					case "*": 	if(isPointer(vars[1], 1)) return getVar(getVar(vars[1]));
								break;
					case "&": 	if(isVar(vars[1])) return vars[1];
								break; 
					case "**": 	if(isPointer(vars[1], 2)) return getVar(getVar(getVar(vars[1])));
								break;
				}

				throw {'message': "Unknown operator '"+ op + "'", 'code': 102};
			}

			try {
				switch(op) {
					case "+": 	return getVar(vars[0]) + getVar(vars[1]);
					case "-": 	return getVar(vars[0]) - getVar(vars[1]);
					case "*": 	return getVar(vars[0]) * getVar(vars[1]);
					case "/": 	return getVar(vars[0]) / getVar(vars[1]);
					case "%": 	return getVar(vars[0]) % getVar(vars[1]);
					case "==": 	return getVar(vars[0]) == getVar(vars[1]);
					case "<": 	return getVar(vars[0]) < getVar(vars[1]);
					case ">": 	return getVar(vars[0]) > getVar(vars[1]);
					case "!=": 	return getVar(vars[0]) != getVar(vars[1]);
					case "<=": 	return getVar(vars[0]) <= getVar(vars[1]);
					case ">=": 	return getVar(vars[0]) >= getVar(vars[1]);
				}

				throw {'message': "Unknown operator '"+ op + "'", 'code': 102};
			} catch (e) {
				throw e;
			}

		} else {
			return getVar(exp);
		}
	}

	let evalVar = (v, res) => {
		if (v.indexOf("*") == 0) {
			let pointerLevel = (v.match(/\*/g) || []).length;

			if (pointerLevel <= 2 && isPointer(v.substr(pointerLevel), pointerLevel)) {
				v = v.substr(pointerLevel);
				if(pointerLevel == 1)
					Heap[Heap[v]] = res;
				else
					Heap[Heap[Heap[v]]] = res;
			}
			else
				throw {'message': "Invalid Pointer Reference '"+ v + "'", 'code': 104};
		} else if (v.match(/\[.*\]/)) {
			if(isIndexedVar(v)) {
				Heap[v.substr(0, v.indexOf("["))][v.substr(v.indexOf("[")+1, v.indexOf("]")-1-v.indexOf("["))] = res;
			} else {
				if(isVar(v.substr(0, v.indexOf("["))))
					throw {'message': "Invalid Type Conversion - cannot convert integer '"+ v + "' to array", 'code': 105};
				Heap[v.substr(0, v.indexOf("["))] = {};
				Heap[v.substr(0, v.indexOf("["))][v.substr(v.indexOf("[")+1, v.indexOf("]")-1-v.indexOf("["))] = res;
			}
		} else {
			Heap[v] = res;
		}
	}

	let handleSpecialExp = (exp, line) => {
		if(isMethodDef) {
			if (exp.match(Rx.end_method)) {
				isMethodDef = false;
				methodName = '';

			} else {
				Operations[methodName].compiler.add(exp);
			}
			return false;
		} 
	
		if(exp.indexOf(":") != -1) {
			if(exp.length <= exp.indexOf(":")+1) return false;

			exp = exp.substr(exp.indexOf(":")+1);
		}

		if(exp.replace(/\s+/g, "").length == 0) return false;

		if (exp.match(Rx.if)) {
			let cond = exp.match(Rx.if)[2];
			let cond_res = evaluate(cond);

			if(cond_res) {
				let task = exp.substr(exp.indexOf(cond) + cond.length);
				handleSpecialExp(task, line);
			}

		} else if(exp.match(Rx.print)) {
			let cond = exp.match(Rx.print)[2];
			let cond_res = evaluate(cond);

			throw {"print": cond_res};

		} else if(exp.match(Rx.return)) {
			let cond = exp.match(Rx.return)[2];

			if(typeof cond != "undefined") {
				let cond_res = evaluate(cond);
				throw {"return": cond_res};
			}

			throw {"return": ""};

		}  else if (exp.match(Rx.goto)) {
			let label = exp.match(Rx.goto)[3];

			if(typeof Indexes[label] != "undefined") {
				throw {"label": Indexes[label]};
			} else {
				throw {'message': "Undefined Label '"+ label + "'", 'code': 106};
			}

		} else if (exp.match(Rx.method)) {
			let list = exp.match(Rx.method);

			let method = list[2];
			let paramlength = list[7];

			if(isMethod(method) && Parameters.length >= paramlength) {

				attribs = Parameters.slice(0, paramlength);
				Parameters = Parameters.slice(paramlength);

				let ret = Operations[method].compiler.run("", attribs, StdOut);

				if (typeof ret != "undefined")
					Heap['out'] = ret;

			} else {
				throw {'message': "Invalid Method call '"+ method + "' with " + paramlength + " Parameters", 'code': 107};
			}
		
		}	
			else if (exp.match(Rx.method_int)) {
				let list = exp.match(Rx.method_int);
	
				let method_int = list[2];
				let paramlength = list[7];
	
				if(isMethod(method_int) && Parameters.length >= paramlength) {
	
					attribs = Parameters.slice(0, paramlength);
					Parameters = Parameters.slice(paramlength);
	
					let ret = Operations[method_int].compiler.run("", attribs, StdOut);
	
					if (typeof ret != "undefined")
						Heap['out'] = ret;
	
				} else {
					throw {'message': "Invalid Method call '"+ method_int + "' with " + paramlength + " Parameters", 'code': 107};
				}
			}
			else if (exp.match(Rx.method_float)) {
				let list = exp.match(Rx.method_float);

				let method_float = list[2];
				let paramlength = list[7];

				if(isMethod(method_float) && Parameters.length >= paramlength) {

					attribs = Parameters.slice(0, paramlength);
					Parameters = Parameters.slice(paramlength);

					let ret = Operations[method_float].compiler.run("", attribs, StdOut);

					if (typeof ret != "undefined")
						Heap['out'] = ret;

				} else {
					throw {'message': "Invalid Method call '"+ method_float+ "' with " + paramlength + " Parameters", 'code': 107};
				}
			}
			else if (exp.match(Rx.method_string)) {
				let list = exp.match(Rx.method_string);
	
				let method_string = list[2];
				let paramlength = list[7];
	
				if(isMethod(method_string) && Parameters.length >= paramlength) {
	
					attribs = Parameters.slice(0, paramlength);
					Parameters = Parameters.slice(paramlength);
	
					let ret = Operations[method_string].compiler.run("", attribs, StdOut);
	
					if (typeof ret != "undefined")
						Heap['out'] = ret;
	
				}
				else {
					throw {'message': "Invalid Method call '"+ method_string + "' with " + paramlength + " Parameters", 'code': 107};
				}
			}
			else if (exp.match(Rx.method_char)) {
				let list = exp.match(Rx.method_char);
	
				let method_char = list[2];
				let paramlength = list[7];
	
				if(isMethod(method_char) && Parameters.length >= paramlength) {
	
					attribs = Parameters.slice(0, paramlength);
					Parameters = Parameters.slice(paramlength);
	
					let ret = Operations[method_char].compiler.run("", attribs, StdOut);
	
					if (typeof ret != "undefined")
						Heap['out'] = ret;
	
				}
				else {
					throw {'message': "Invalid Method call '"+ method_char + "' with " + paramlength + " Parameters", 'code': 107};
				}
			}
		
			else if (exp.match(Rx.param)) {

			let cond = exp.match(Rx.param)[2];
			Parameters.push(evaluate(cond));

		} else if(exp.match(Rx.def_method)) {

			let list = exp.match(Rx.def_method);
			let method = list[2];
			let paramlength = list[5];

			Operations[method] = {};
			Operations[method]['compiler'] = new TAC;
			Operations[method]['paramlength'] = paramlength;
			Operations[method]['Parameters'] = [];

			isMethodDef = true;
			methodName = method;

		} else if (exp.match(Rx.exp)) {
			exp = exp.replace(/\s+/g, "");
			vars = exp.split('=');

			if(vars.length > 1)
				evalVar(vars[0], evaluate(vars[1]));
			else {

				let cond_res = evaluate(exp);
				throw {"print": cond_res};
			}
		}

		return true;
	}

	let build = () => {
		for(let position in Lines) {
			let line = Lines[position];

			if(line.indexOf(":") != -1) {
				Indexes[line.substr(0, line.indexOf(":")).replace(/\s+/, "")] = parseInt(position);
			}
		}

		let position = 0;
		while(position < Lines.length) {
			let line = Lines[position];

			try {
				handleSpecialExp(line, position);
			} catch(err) {
				if(typeof err == "object" && typeof err['label'] != "undefined") {
					position = err['label']-1;
				} else if(typeof err == "object" && typeof err['return'] != "undefined") { 
					return err['return'];
				} else if(typeof err == "object" && typeof err['print'] != "undefined") { 
					Outputs.push({val:err['print'], line: position+1});
					if (typeof StdOut == "function")
						StdOut({val:err['print'], line: position+1});
				} else {
					if(typeof err == "object") {
						err['message'] += " in line " + (position+1);
						err['line'] = position+1;
					} else {
						err = {'message': err, 'line': position+1, 'code': 120};
					}

					if(typeof StdErr == "function")
						StdErr(err);

					if(debug) console.error(err);
					if(stopOnError) return;
				}
			}

			position++;
		}

		return true;
	}
};
