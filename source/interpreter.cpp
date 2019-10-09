#include "interpreter.h"

void loadFile(char* fileName, MyMemory* mem){
	int begin, end, size, i;
	char byte;
	std::ifstream file(fileName, std::ios::binary);

	if(file.is_open()){
	  begin = file.tellg();
	  file.seekg (0, std::ios::end);
	  end = file.tellg();
	  size = begin - end;
	  for(i=0; i < size; i++){
		  file.read(&byte,1);
		  mem->stack.push_back(Data(byte, 'C'));
	  }
	}
	else std::cout << "cannot open file" <<std::endl;
	file.close();
}

short convert2short(Data& data1, Data& data2){
	short intosh;
	intosh = (data1.charV <<8) | data2.charV;
	return intosh;
}
int convert2int(Data& data1, Data& data2,Data& data3, Data& data4){
	int packit=0;
	packit = (data1.charV << 12) | (data2.charV << 8) | (data3.charV << 4) | data4.charV;
	return packit;
//	integer = data1.value*1000 + data2.value*100 + data3.value*10 + data4.
}

float convert2float(Data& data1, Data& data2, Data& data3, Data& data4){
	float inter=0;
	inter = (data1.charV << 12) | (data2.charV << 8) | (data3.charV << 4) | data4.charV;
	return inter;
}


