#include "MyMemory.h"

MyMemory::MyMemory(){}
MyMemory::~MyMemory(){}
Data MyMemory::getMemory(int pc) {
	return stack[pc];
}


