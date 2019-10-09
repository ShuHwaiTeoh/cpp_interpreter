#ifndef INTERPRETER_H
#define INTERPRETER_H
#include<iostream>
#include<fstream>
#include<vector>
#include"myMemory.h"
#include"Data.h"

void loadFile(char*, MyMemory*);
short convert2short(Data&, Data&);
int convert2int(Data&, Data&, Data&, Data&);
float convert2float(Data&, Data&, Data&, Data&);

#endif
