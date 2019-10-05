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
		  mem->stack.push_back(Data(byte, "byte"));
	  }
	}
	else std::cout << "cannot open file" <<std::endl;
	file.close();
}
