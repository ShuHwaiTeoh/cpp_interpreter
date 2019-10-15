#include "Runtime.h"
#include<stdio.h>
#include <string.h>


Runtime::Runtime() {}
Runtime::~Runtime() {}
void Runtime::print(){
	if (stack.size()==0){
		std::cout<<"empty"<<std::endl;
	}
	else{
		for (unsigned int i=0;i< stack.size();i++){
			if (stack[i].type == 'C') std::cout<<stack[i].charV<<",";
			else if (stack[i].type == 'S') std::cout<<stack[i].shortV<<",";
			else if (stack[i].type == 'I') std::cout<<stack[i].intV<<",";
			else if (stack[i].type == 'F') std::cout<<stack[i].floatV<<",";
		}
		std::cout<<std::endl;
	}
}

