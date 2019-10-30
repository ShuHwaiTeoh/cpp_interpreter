#ifndef RUNTIME_H
#define RUNTIME_H
#include<vector>
#include "MyMemory.h"
#include "Data.h"
#include<iostream>

class Runtime{
public:
	Runtime();
	virtual ~Runtime();
	void print();

	std::vector<Data> stack;
};

#endif
