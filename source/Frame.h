#ifndef Frame_H
#define Frame_H
#include<vector>
#include "Memory.h"
#include "Data.h"

class Frame{
public:
	Frame();
	virtual ~Frame();
	void print();

	std::vector<int> stack;
};

#endif
