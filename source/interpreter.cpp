#include "interpreter.h"

void loadFile(std::string fileName, MyMemory* mem){
	int begin, end, size, i;
	char byte;
	//std::ifstream file;
	std::ifstream file(fileName, std::ios::binary);

	//if(file.open(fileName, std::ios::binary)){
	//file.open(fileName);
	if(file.is_open()){
	  file.seekg(0, std::ios::end);
	  size = file.tellg();
	  file.seekg(0, std::ios::beg);
//	  begin = file.tellg();
//	  file.seekg (0, std::ios::end);
//	  end = file.tellg();
//	  size = begin - end;
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
//	int reverse[16];
//	int value=0;
//	int left=0;
//	left = int(data2.charV);
//	for (int reverseIdx=0;reverseIdx<8;reverseIdx++){
//		value = left%2;
//		left = left/2;
//		reverse[reverseIdx]=value;
//	}
//	intosh = (0x0(reverse[0])<<16)|
	intosh = (data1.charV <<8) | data2.charV;
	return intosh;
}
int convert2int(Data& data1, Data& data2,Data& data3, Data& data4){
	int packit=0;
//	std::cout<<"data1:"<<data1.charV<<"  data2:"<<data2.charV<<"  data3:"<<data3.charV<<"  data4:"<<data4.charV<<std::endl;
	packit = (data1.charV << 24) | (data2.charV << 16) | (data3.charV << 8) | data4.charV;
	return packit;
//	integer = data1.value*1000 + data2.value*100 + data3.value*10 + data4.
}

float convert2float(Data& data1, Data& data2, Data& data3, Data& data4){
	float inter=0;
	inter = (data1.charV << 24) | (data2.charV << 16) | (data3.charV << 8) | data4.charV;
	return inter;
}



