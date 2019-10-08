#include "Frame.h"
#include<stdio.h>
#include <string.h>

Frame::Frame() {}
Frame::~Frame() {}
void Frame::print(){
	for (int i=0;i<stack.size;i++){
		std::cout<<stack[i];
	}
}
