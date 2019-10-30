#ifndef INTERPRETER_H
#define INTERPRETER_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"MyMemory.h"
#include"Data.h"
#include <math.h>

void loadFile(std::string, MyMemory*);
short convert2short(Data&, Data&);
int convert2int(Data&, Data&, Data&, Data&);
float convert2float(Data&, Data&, Data&, Data&);

#endif
