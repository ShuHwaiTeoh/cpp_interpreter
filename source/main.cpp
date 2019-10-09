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
	Data* d;
	int opcode;//instructions to be executed
	short s;
	int i, j, flag = 1;
	float f;

	loadFile(argv[1], mem);
	while (flag){
		*d = mem->getMemory(pc);
		pc++;
		opcode = (d -> charV) - NULL;
		switch (opcode) {
			case 132:
				if (rstack->stack[sp-1].type == 'C'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].charV == rstack->stack[sp].charV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].shortV == rstack->stack[sp].shortV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].intV == rstack->stack[sp].intV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].floatV == rstack->stack[sp].floatV), 'I');
				}
				sp--;
				break;
			case 136:
				if (rstack->stack[sp-1].type == 'C'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].charV < rstack->stack[sp].charV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].shortV < rstack->stack[sp].shortV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].intV < rstack->stack[sp].intV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].floatV < rstack->stack[sp].floatV), 'I');
				}
				sp--;
				break;
			case 140:
				if (rstack->stack[sp-1].type == 'C'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].charV > rstack->stack[sp].charV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].shortV > rstack->stack[sp].shortV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].intV > rstack->stack[sp].intV), 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data((rstack->stack[sp-1].floatV > rstack->stack[sp].floatV), 'I');
				}
				sp--;
				break;
			case 36:
				pc = rstack->stack[sp].intV;
				sp--;
				break;
			case 40:
				if (rstack->stack[sp-1].intV) pc = rstack->stack[sp].intV;
				sp = sp - 2;
				break;
			case 44:
				fpstack->stack.push_back(sp - rstack->stack[sp].intV);
				fpsp++;
				sp--;
				pc = rstack->stack[sp--].intV;
				break;
			case 48:
				sp = fpstack->stack[fpsp--];
				pc = rstack->stack[sp].intV;
				break;
			case 68:
				rstack->stack.push_back(Data(mem->stack[pc+1].charV, 'C'));
				sp++;
				pc = pc + 2;
				break;
			case 69:
				s = convert2short(mem->stack[pc+1], mem->stack[pc+2]);
				rstack->stack.push_back(Data(s, 'S'));
				sp++;
				pc += 3;
				break;
			case 70:
				i = convert2int(mem->stack[pc+1], mem->stack[pc+2], mem->stack[pc+3], mem->stack[pc+4]);
				rstack->stack.push_back(Data(i, 'I'));
				sp++;
				pc += 5;
				break;
			case 71:
				f = convert2float(mem->stack[pc+1], mem->stack[pc+2], mem->stack[pc+3], mem->stack[pc+4]);
				rstack->stack.push_back(Data(f, 'F'));
				sp++;
				pc += 5;
				break;
			case 72:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].intV].charV, 'C'));
				sp++;
				break;
			case 73:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].intV].shortV, 'S'));
				sp++;
				break;
			case 74:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].intV].intV, 'I'));
				sp++;
				break;
			case 75:
				rstack->stack.push_back(Data(rstack->stack[rstack->stack[sp].intV].floatV, 'F'));
				sp++;
				break;
			case 76:
				sp -= rstack->stack[sp].intV;
				break;
			case 80:
				if (rstack->stack[sp-1].type == 'C'){
					rstack->stack[rstack->stack[sp].intV].charV = rstack->stack[sp-1].charV;
				}
				else if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[rstack->stack[sp].intV].shortV = rstack->stack[sp-1].shortV;
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[rstack->stack[sp].intV].intV = rstack->stack[sp-1].intV;
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[rstack->stack[sp].intV].floatV = rstack->stack[sp-1].floatV;
				}
				rstack->stack[rstack->stack[sp].intV].type = rstack->stack[sp-1].type;
				sp -= 2;
				break;
			case 77:
				for(j=0; j < rstack->stack[sp].intV; j++){
					if (rstack->stack[sp-rstack->stack[sp].intV + j].type == 'C'){
						rstack->stack[fpstack->stack[fpsp] + j + 1].charV = rstack->stack[sp-rstack->stack[sp].intV + j].charV;
					}
					else if (rstack->stack[sp-rstack->stack[sp].intV + j].type == 'S'){
						rstack->stack[fpstack->stack[fpsp] + j + 1].shortV = rstack->stack[sp-rstack->stack[sp].intV + j].shortV;

					}
					else if (rstack->stack[sp-rstack->stack[sp].intV + j].type == 'I'){
						rstack->stack[fpstack->stack[fpsp] + j + 1].intV = rstack->stack[sp-rstack->stack[sp].intV + j].intV;

					}
					else if (rstack->stack[sp-rstack->stack[sp].intV + j].type == 'F'){
						rstack->stack[fpstack->stack[fpsp] + j + 1].floatV = rstack->stack[sp-rstack->stack[sp].intV + j].floatV;
					}
					rstack->stack[fpstack->stack[fpsp] + j + 1].type = rstack->stack[sp-rstack->stack[sp].intV + j].type;
				}
				sp = fpstack->stack[fpsp] + rstack->stack[sp].intV;
				break;
			case 84:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].charV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].charV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'C';
				break;
			case 85:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].shortV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].shortV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'S';
				break;
			case 86:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].intV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].intV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'I';
				break;
			case 87:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].floatV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].floatV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'F';
				break;
			case 88:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].charV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].charV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'C';
				break;
			case 89:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].shortV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].shortV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'S';
				break;
			case 90:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].intV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].intV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'I';
				break;
			case 91:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].floatV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].floatV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'F';
				break;
			case 94:
				*temp = rstack->stack[sp-1];
				rstack->stack[sp-1] = rstack->stack[sp];
				rstack->stack[sp] = *temp;
				break;
			case 100:
				if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].shortV + rstack->stack[sp].shortV, 'S');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].intV + rstack->stack[sp].intV, 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].floatV + rstack->stack[sp].floatV, 'F');
				}
				sp--;
				break;
			case 104:
				if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].shortV - rstack->stack[sp].shortV, 'S');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].intV - rstack->stack[sp].intV, 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].floatV - rstack->stack[sp].floatV, 'F');
				}
				sp--;
				break;
			case 108:
				if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].shortV * rstack->stack[sp].shortV, 'S');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].intV * rstack->stack[sp].intV, 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].floatV * rstack->stack[sp].floatV, 'F');
				}
				sp--;
				break;
			case 112:
				if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].shortV / rstack->stack[sp].shortV, 'S');
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].intV / rstack->stack[sp].intV, 'I');
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[sp-1] = Data(rstack->stack[sp-1].floatV / rstack->stack[sp].floatV, 'F');
				}
				sp--;
				break;
			case 144:
				std::cout << rstack->stack[sp--].charV <<std::endl;
				break;
			case 145:
				std::cout << rstack->stack[sp--].shortV <<std::endl;
				break;
			case 146:
				std::cout << rstack->stack[sp--].intV <<std::endl;
				break;
			case 147:
				std::cout << rstack->stack[sp--].floatV <<std::endl;
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
