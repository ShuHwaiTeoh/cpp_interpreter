#ifndef Frame_H
#define Frame_H
#include<vector>
#include "MyMemory.h"
#include "Data.h"
#include<iostream>

class Frame{
public:
	Frame();
	virtual ~Frame();
	void print();
	std::vector<int> stack;
};

#endif
