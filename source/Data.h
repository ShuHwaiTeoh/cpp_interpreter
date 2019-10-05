#ifndef Data_H
#define Data_H
#include<string>

class Data{
public:
	Data(int, std::string);
	Data(short, std::string);
	Data(char, std::string);
	Data(float, std::string);
	virtual ~Data();
	int value;
	std::string type;//char, short, int, float, byte
};

#endif /* ALARM_H */
