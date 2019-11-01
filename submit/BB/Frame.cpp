#include "Frame.h"
#include<stdio.h>
#include <string.h>

Frame::Frame() {}
Frame::~Frame() {}
void Frame::print(){
	if (stack.size()==0){
		std::cout<<"empty"<<std::endl;
	}
	else{
		for (unsigned int i=0; i< stack.size(); i++){
			std::cout<<stack[i];
		}
		std::cout<<std::endl;
	}
}
