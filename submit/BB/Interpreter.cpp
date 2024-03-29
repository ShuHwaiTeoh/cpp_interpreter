#include "interpreter.h"
#include <string.h>


void loadFile(std::string fileName, MyMemory* mem){
	int size, i;
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
//		  std::cout<<"byte:"<<byte<<std::endl;
		  mem->stack.push_back(Data(static_cast<unsigned char>(byte), 'C'));
	  }
//	  std::cout<<"size:"<<size<<std::endl;

	}
	else std::cout << "cannot open file" <<std::endl;
	file.close();
}

short convert2short(Data& data1, Data& data2){
	short result;
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
//	intosh = (data1.charV <<8) | data2.charV;
	result = short(double(data1.charV) * std::pow(2,0) + double(data2.charV) * std::pow(2,8));
	return result;
}
int convert2int(Data& data1, Data& data2,Data& data3, Data& data4){
	int result;
//	std::cout<<"data1:"<<data1.charV<<"  data2:"<<data2.charV<<"  data3:"<<data3.charV<<"  data4:"<<data4.charV<<std::endl;
//	packit = (data1.charV << 24) | (data2.charV << 16) | (data3.charV << 8) | data4.charV;
	result = int(double(data1.charV) * std::pow(2,0) + double(data2.charV) * std::pow(2,8) +
			double(data3.charV) * std::pow(2,16) + double(data4.charV) * std::pow(2,24));
	return result;
//	integer = data1.value*1000 + data2.value*100 + data3.value*10 + data4.
}

float convert2float(Data& data1, Data& data2, Data& data3, Data& data4){
	float result = 0.0;
	unsigned char arr[4] = {data1.charV, data2.charV, data3.charV, data4.charV};
	memcpy(&result, &arr, sizeof(result));
//	const float result = static_cast<float>(arr[0] | arr[1] | arr[2] | arr[3]);
	//	float f=(float)(arr);
//	float d1, d2, d3, d4;
//	float result;
//	d4 = data1.charV << 24;
//	d3 = (data2.charV << 24) >> 8;
//	d2 = (data3.charV << 24) >> 16;
//	d1 = (data4.charV << 24) >> 24;
//	result = d4 + d3 + d2 + d1;
//	result =(data4.charV << 24) | (data3.charV << 16) | (data2.charV << 8) | data1.charV);
//	result = double(data1.charV) * std::pow(2,0.5) + double(data2.charV) * std::pow(2,0) +
//			double(data3.charV) * std::pow(2,0) + double(data4.charV) * std::pow(2,0);

	return result;
}



