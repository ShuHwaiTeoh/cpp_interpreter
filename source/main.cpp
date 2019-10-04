#include <iostream>
#include "Runtime.h"
#include "Data.h"
#include "Frame.h"

int main(int argc, char* argv[]) {
<<<<<<< HEAD
//	myMemory mem;//Program memory
=======
	//myMemory mem;//Program memory
>>>>>>> b78719728d2cedd98ee8cfddf42d18cd130c25e6
	Runtime rstack;//runtime stack
	Frame fpstack;//stack of frame pointers
	int pc = 0;//program counter
	int sp = -1;//runtime stack pointer
	int fpsp = -1;//frame pointer stack pointer
	int opcode;//instructions to be executed

	//loadFile(argv[0], mem);
	while (true){
		//opcode = mem.getMemory(pc);
		//pc++;
		switch (opcode) {
			case 132:
				break;
			case 136:
				break;
			case 140:
				break;
			case 36:
				break;
			case 40:
				break;
			case 44:
				break;
			case 48:
				break;
			case 68:
				break;
			case 69:
				break;
			case 70:
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
