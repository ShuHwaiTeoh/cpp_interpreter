#include "Runtime.h"
#include<stdio.h>
#include <string.h>

Runtime::Runtime() {}
Data::~Data() {}
void Runtime::print(){
	for (int i=0;i<stack.size;i++){
		std::cout<<stack[i];
	}
}

