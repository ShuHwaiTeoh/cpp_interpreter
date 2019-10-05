#ifndef RUNTIME_H
#define RUNTIME_H
#include<vector>
#include "Memory.h"
#include "Data.h"

class Runtime{
public:
	Runtime();
	virtual ~Runtime();
	void print();

	std::vector<Data> stack;
};

#endif
