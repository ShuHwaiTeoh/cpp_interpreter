#ifndef MyMemory_H
#define MyMemory_H
#include<vector>
#include<Data.h>

class MyMemory {
public:
	MyMemory();
	virtual ~MyMemory();
	Data getMemory(int);

	std::vector<Data> stack;
};
