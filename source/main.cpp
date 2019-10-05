#include <iostream>
#include "Runtime.h"
#include "Data.h"
#include "Frame.h"
#include "MyMemory.h"
#include "Interpreter.h"

int main(int argc, char* argv[]) {

	MyMemory mem;//Program memory
	Runtime rstack;//runtime stack
	Frame fpstack;//stack of frame pointers
	int pc = 0;//program counter
	int sp = -1;//runtime stack pointer
	int fpsp = -1;//frame pointer stack pointer
	int opcode;//instructions to be executed
	short s;
	int i;
	char c;
	float f;

	loadFile(argv[1], &mem);
	while (true){
		opcode = mem.getMemory(pc);
		//pc++;
		switch (opcode) {
			case 132:
				rstack.stack[sp-1] = Data((rstack.stack[sp-1].value == rstack.stack[sp].value), rstack.stack[sp].type);
				sp--;
				break;
			case 136:
				rstack.stack[sp-1].value = Data(rstack.stack[sp].value < rstack.stack[sp-1].value,rstack.stack[sp-1].type)
				sp--;
				break;
			case 140:
				rstack.stack[sp-1].value = Data(rstack.stack[sp].value > rstack.stack[sp-1].value,rstack.stack[sp-1].type)
				sp--;
				break;
			case 36:
				pc = rstack.stack[sp].value;
				sp--;
				break;
			case 40:
				if (rstack.stack[sp-1].value) pc = rstack.stack[sp].value;
				sp = sp - 2;
				break;
			case 44:
				fpstack[++fpsp] = sp - rstack.stack[sp].value;
				sp--;
				pc = rstack.stack[sp--].value;
				break;
			case 48:
				sp = fpstack.stack[fpsp--].value;
				pc = rstack.stack[sp].value;
				break;
			case 68:
				rstack[++sp] = Data(mem.stack[pc+1].value, mem.stack[pc+1].type);
				pc = pc + 2;
				break;
			case 69:
				s = convert2short(mem.stack[pc+1], mem.stack[pc+2]);
				rstack.stack[++sp] = Data(s, "short");
				pc += 3;
				break;
			case 70:
				i = convert2int(mem.stack[pc+1], mem.stack[pc+2], mem.stack[pc+3], mem.stack[pc+4]);
				rstack.stack[++sp] = Data(i, "int");
				pc += 5;
				break;
			case 71:
				break;
			case 72:
				break;
			case 73:
				break;
			case 74:
				break;
			case 75:
				break;
			case 76:
				break;
			case 80:
				break;
			case 77:
				break;
			case 84:
				break;
			case 85:
				break;
			case 86:
				break;
			case 87:
				break;
			case 88:
				break;
			case 89:
				break;
			case 90:
				break;
			case 91:
				break;
			case 94:
				break;
			case 100:
				break;
			case 104:
				break;
			case 108:
				break;
			case 112:
				break;
			case 148:
				break;
			case 149:
				break;
			case 150:
				break;
			case 151:
				break;
			case 0:
				break;
		}
	}

	return 0;
}
