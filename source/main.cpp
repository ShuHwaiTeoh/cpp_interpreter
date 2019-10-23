#include <iostream>
#include "Runtime.h"
#include "Data.h"
#include "Frame.h"
#include "MyMemory.h"
#include "Interpreter.h"
#include<vector>

//int main(int argc, char* argv[]) {
int main(){

	MyMemory* mem = new MyMemory();//Program memory
	Runtime* rstack = new Runtime();//runtime stack
	Frame* fpstack = new Frame();//stack of frame pointers
	Data *temp = NULL;
	int pc = 0;//program counter
	int sp = -1;//runtime stack pointer
	int fpsp = -1;//frame pointer stack pointer
	int opcode = 0;//instructions to be executed
	short s;
	int i, j, flag = 1;
	float f;
	int valuei = 0;

	//loadFile(argv[1], mem);
	loadFile("D:\\Purdue\\3\\30862\\hw\\interpreter\\src\\100_add_test.smp", mem);
//	loadFile("C:\\Users\\danie\\eclipse-workspace\\sample_test\\src\\interpreter_input.smp", mem);
//	std::cout<<"f:   "<<int('f')<<std::endl;
//	for (int h=0;h<90;h++){
//		temp = mem->getMemory(h);
//		std::cout<<h<<":   "<<int(temp->charV)<<std::endl;
//	}
	while (flag){
//	for(int p=0;p<150;p++){
		temp = mem->getMemory(pc);
		//pc = pc + 1;
		opcode = int(temp->charV);
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
//				rstack->stack.pop_back();
				sp--;
				pc++;
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
//				rstack->stack.pop_back();
				sp--;
				pc++;
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
//				rstack->stack.pop_back();
				sp--;
				pc++;
				break;
			case 36:
				pc = rstack->stack[sp].intV;
				sp--;
				break;
			case 40:
				if (rstack->stack[sp-1].intV) pc = rstack->stack[sp].intV;
				else{
					pc++;
				}
				sp = sp - 2;
				break;
			case 44:
				fpstack->stack.push_back(sp - rstack->stack[sp].intV-1);
				fpsp++;
				sp--;
//				rstack->stack.pop_back();
				pc = rstack->stack[sp--].intV;
//				rstack->stack.pop_back();
				break;
			case 48:
				sp = fpstack->stack[fpsp--];
				pc = rstack->stack[sp].intV;
				break;
			case 68:
//				temp = Data(mem->stack[pc+1].charV, 'C');
				sp++;
				rstack->stack.insert(rstack->stack.begin()+sp,Data(mem->stack[pc+1].charV, 'C'));
				pc = pc + 2;
				break;
			case 69:
				sp++;
				s = convert2short(mem->stack[pc+1], mem->stack[pc+2]);
				rstack->stack.insert(rstack->stack.begin()+sp,Data(s, 'S'));
//				sp++;
				pc += 3;
				break;
			case 70:
				sp++;
				i = convert2int(mem->stack[pc+1], mem->stack[pc+2], mem->stack[pc+3], mem->stack[pc+4]);
				rstack->stack.insert(rstack->stack.begin()+sp,Data(i, 'I'));
//				sp++;
				pc += 5;
				break;
			case 71:
				sp++;
				f = convert2float(mem->stack[pc+1], mem->stack[pc+2], mem->stack[pc+3], mem->stack[pc+4]);
				rstack->stack.insert(rstack->stack.begin()+sp,Data(f, 'F'));
//				sp++;
				pc += 5;
				break;
			case 72:
//				sp++;
//				rstack->stack.insert(rstack->stack.begin()+sp,Data(rstack->stack[rstack->stack[sp].intV].charV, 'C'));
//				sp++;
				if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'C'){
					rstack->stack[sp].charV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].charV;
					rstack->stack[sp].type = 'C';
				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'S'){
					rstack->stack[sp].shortV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].shortV;
					rstack->stack[sp].type = 'S';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'I'){
					rstack->stack[sp].intV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].intV;
					rstack->stack[sp].type = 'I';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'F'){
					rstack->stack[sp].floatV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].floatV;
					rstack->stack[sp].type = 'F';
				}
				pc++;
				break;
			case 73:
//				sp++;
//				rstack->stack.insert(rstack->stack.begin()+sp,Data(rstack->stack[rstack->stack[sp].intV].shortV, 'S'));
//				sp++;
				if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'C'){
					rstack->stack[sp].charV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].charV;
					rstack->stack[sp].type = 'C';
				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'S'){
					rstack->stack[sp].shortV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].shortV;
					rstack->stack[sp].type = 'S';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'I'){
					rstack->stack[sp].intV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].intV;
					rstack->stack[sp].type = 'I';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'F'){
					rstack->stack[sp].floatV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].floatV;
					rstack->stack[sp].type = 'F';
				}
				pc++;
				break;
			case 74:
				if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'C'){
					rstack->stack[sp].charV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].charV;
					rstack->stack[sp].type = 'C';
				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'S'){
					rstack->stack[sp].shortV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].shortV;
					rstack->stack[sp].type = 'S';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'I'){
					rstack->stack[sp].intV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].intV;
					rstack->stack[sp].type = 'I';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'F'){
					rstack->stack[sp].floatV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].floatV;
					rstack->stack[sp].type = 'F';
				}
				pc++;
//				std::cout<<"####################"<<rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].floatV<<std::endl;
				break;
			case 75:
				if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'C'){
					rstack->stack[sp].charV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].charV;
					rstack->stack[sp].type = 'C';
				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'S'){
					rstack->stack[sp].shortV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].shortV;
					rstack->stack[sp].type = 'S';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'I'){
					rstack->stack[sp].intV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].intV;
					rstack->stack[sp].type = 'I';				}
				else if (rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].type == 'F'){
					rstack->stack[sp].floatV = rstack->stack[rstack->stack[sp].intV + fpstack->stack[fpsp] +1].floatV;
					rstack->stack[sp].type = 'F';
				}
				pc++;
				break;
			case 76:
				sp -= rstack->stack[sp].intV;
//				for (int k=0;k<rstack->stack[sp].intV;k++){
//					rstack->stack.pop_back();
//				}
				pc++;//
				break;
			case 80:
				if (rstack->stack[sp-1].type == 'C'){
					rstack->stack[fpstack->stack[fpsp]+rstack->stack[sp].intV+1].charV = rstack->stack[sp-1].charV;
				}
				else if (rstack->stack[sp-1].type == 'S'){
					rstack->stack[fpstack->stack[fpsp]+rstack->stack[sp].intV+1].shortV = rstack->stack[sp-1].shortV;
				}
				else if (rstack->stack[sp-1].type == 'I'){
					rstack->stack[fpstack->stack[fpsp]+rstack->stack[sp].intV+1].intV = rstack->stack[sp-1].intV;
				}
				else if (rstack->stack[sp-1].type == 'F'){
					rstack->stack[fpstack->stack[fpsp]+rstack->stack[sp].intV+1].floatV = rstack->stack[sp-1].floatV;
				}
				rstack->stack[fpstack->stack[fpsp]+rstack->stack[sp].intV+1].type = rstack->stack[sp-1].type;
//****				sp -= 2;
//				rstack->stack.pop_back();
				pc++;
				break;
			case 77:
				valuei=rstack->stack[sp].intV;
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
//				for (int k = 0;k<valuei;k++){
//					rstack->stack.pop_back();
//				}
				sp = fpstack->stack[fpsp] + rstack->stack[sp].intV;
				pc++;
				break;
			case 84:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].charV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].charV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'C';
				pc++;
				break;
			case 85:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].shortV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].shortV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'S';
				pc++;
				break;
			case 86:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].intV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].intV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'I';
				pc++;
				break;
			case 87:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].floatV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].floatV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].type = 'F';
				pc++;
				break;
			case 88:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].charV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].charV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].type = 'C';
				pc++;
				break;
			case 89:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].shortV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].shortV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].type = 'S';
				pc++;
				break;
			case 90:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].intV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].intV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].type = 'I';
				pc++;
				break;
			case 91:
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].floatV =
						rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp-1].intV + 1].floatV;
				rstack->stack[fpstack->stack[fpsp] + rstack->stack[sp].intV + 1].type = 'F';
				pc++;
				break;
			case 94:
				temp = &(rstack->stack[sp-1]);
				rstack->stack[sp-1] = rstack->stack[sp];
				rstack->stack[sp] = *temp;
				pc++;
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
//				rstack->stack.pop_back();
				sp--;
				pc++;
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

//				rstack->stack.pop_back();
				sp--;
				pc++;
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
//				rstack->stack.pop_back();
				sp--;
				pc++;
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
//				rstack->stack.pop_back();
				sp--;
				pc++;
				break;
			case 144:
				std::cout << rstack->stack[sp--].charV <<std::endl;
				pc++;
				break;
			case 145:
				std::cout << rstack->stack[sp--].shortV <<std::endl;
				pc++;
				break;
			case 146:
				std::cout << rstack->stack[sp--].intV <<std::endl;
				pc++;
				break;
			case 147:
				std::cout << rstack->stack[sp--].floatV <<std::endl;
				pc++;
				break;
			case 0:
				sp = -1;
				fpsp = -1;
				rstack->stack.clear();
				fpstack->stack.clear();
//				std::cout << "here" <<std::endl;
				flag = 0;
				std::cout<<std::endl;
				std::cout << "Compile values:" << std::endl;
				std::cout << "pc: " << pc << std::endl;
				std::cout << "sp: " << sp << std::endl;
				std::cout << "rstack: ";
				rstack->print();
				std::cout << "fpsp: " << fpsp << std::endl;
				std::cout << "fpstack: ";
				fpstack->print();

				break;
		}
		std::cout << "Compile values:" << opcode <<std::endl;
		std::cout << "PC: " << pc << std::endl;
		std::cout << "sp: " << sp << std::endl;
		std::cout << "rstack:";
		rstack->print();
		std::cout << "fpsp: " << fpsp << std::endl;
		std::cout << "fpstack:" << std::endl;
		fpstack->print();

	}

	return 0;
}
