#include <iostream>
#include "Runtime.h"
#include "Data.h"
#include "Frame.h"
#include "MyMemory.h"
#include "Interpreter.h"
#include<vector>

int main(int argc, char* argv[]) {

	MyMemory* mem = new MyMemory();//Program memory
	Runtime* rstack = new Runtime();//runtime stack
	Frame* fpstack = new Frame();//stack of frame pointers
	Data* temp;
	int pc = 0;//program counter
	int sp = -1;//runtime stack pointer
	int fpsp = -1;//frame pointer stack pointer
	int opcode;//instructions to be executed
	short s;
	int i, j, flag = 1;
	char c;
	float f;

	loadFile(argv[1], mem);
	while (flag){
		opcode = mem->getMemory(pc);
		//pc++;
		switch (opcode) {
			case 132:
				rstack->stack[sp-1] = Data((rstack->stack[sp-1].value == rstack->stack[sp].value), rstack->stack[sp].type);
				sp--;
				break;
			case 136:
				rstack->stack[sp-1].value = Data(rstack->stack[sp].value < rstack->stack[sp-1].value,rstack->stack[sp-1].type);
				sp--;
				break;
			case 140:
				rstack->stack[sp-1].value = Data(rstack->stack[sp].value > rstack->stack[sp-1].value,rstack->stack[sp-1].type);
				sp--;
				break;
			case 36:
				pc = rstack->stack[sp].value;
				sp--;
				break;
			case 40:
				if (rstack->stack[sp-1].value) pc = rstack->stack[sp].value;
				sp = sp - 2;
				break;
			case 44:
				fpstack->stack.push_back(sp - rstack->stack[sp].value);
				fpsp++;
				sp--;
				pc = rstack->stack[sp--].value;
				break;
			case 48:
				sp = fpstack->stack[fpsp--];
				pc = rstack->stack[sp].value;
				break;
			case 68:
				rstack->stack.push_back(Data(mem->stack[pc+1].value, mem->stack[pc+1].type));
				sp++;
				pc = pc + 2;
				break;
			case 69:
				s = convert2short(mem->stack[pc+1], mem->stack[pc+2]);
				rstack->stack.push_back(Data(s, "short"));
				sp++;
				pc += 3;
				break;
			case 70:
				i = convert2int(mem->stack[pc+1], mem->stack[pc+2], mem->stack[pc+3], mem->stack[pc+4]);
				rstack->stack.push_back(Data(i, "int"));
				sp++;
				pc += 5;
				break;
			case 71:
				f = convert2float(mem->stack[pc+1], mem->stack[pc+2], mem->stack[pc+3], mem->stack[pc+4]);
				rstack->stack.push_back(Data(f, "float"));
				sp++;
				pc += 5;
				break;
			case 72:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].value].value, "char"));
				sp++;
				break;
			case 73:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].value].value, "short"));
				sp++;
				break;
			case 74:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].value].value, "int"));
				sp++;
				break;
			case 75:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].value].value, "float"));
				sp++;
				break;
			case 76:
				sp -= rstack->stack[sp].value;
				break;
			case 80:
				rstack->stack[rstack->stack[sp].value].value = rstack->stack[sp-1].value;
				rstack->stack[rstack->stack[sp].value].type = rstack->stack[sp-1].type;
				sp -= 2;
				break;
			case 77:
				for(j=0; j < rstack->stack[sp].value; j++){
					rstack->stack[fpstack->stack[fpsp] + j + 1].value = rstack->stack[sp-rstack->stack[sp] + j].value;
					rstack->stack[fpstack->stack[fpsp] + j + 1].type = rstack->stack[sp-rstack->stack[sp] + j].type;
				}
				sp = fpstack->stack[fpsp] + rstack->stack[sp].value;
				break;
			case 84:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 85:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 86:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 87:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 88:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 89:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 90:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 91:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].value =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].value;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].value + 1].type =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].value + 1].type;
				break;
			case 94:
				temp = rstack->stack[sp-1];
				rstack->stack[sp-1] = rstack->stack[sp];
				rstack->stack[sp] = temp;
				break;
			case 100:
				rstack->stack[sp-1] = Data(rstack->stack[sp-1].value + rstack->stack[sp].value, rstack->stack[sp].type);
				sp--;
				break;
			case 104:
				rstack->stack[sp-1] = Data(rstack->stack[sp-1].value - rstack->stack[sp].value, rstack->stack[sp].type);
				sp--;
				break;
			case 108:
				rstack->stack[sp-1] = Data(rstack->stack[sp-1].value * rstack->stack[sp].value, rstack->stack[sp].type);
				sp--;
				break;
			case 112:
				rstack->stack[sp-1] = Data(rstack->stack[sp-1].value / rstack->stack[sp].value, rstack->stack[sp].type);
				sp--;
				break;
			case 148:
				std::cout << rstack->stack[sp--].value <<std::endl;
				break;
			case 149:
				std::cout << rstack->stack[sp--].value <<std::endl;
				break;
			case 150:
				std::cout << rstack->stack[sp--].value <<std::endl;
				break;
			case 151:
				std::cout << rstack->stack[sp--].value <<std::endl;
				break;
			case 0:
				flag = 0;
				std::cout << "pc: " << pc << std::endl;
				std::cout << "pc: " << sp << std::endl;
				rstack->print();
				std::cout << "fpsp: " << fpsp << std::endl;
				fpstack->print();
				break;
		}
	}

	return 0;
}
