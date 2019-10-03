#ifndef Data_H
#define Data_H
#include<string>

class Data{
public:
	Data(int, std::string);
	virtual ~Data();
	int value;
	std::string type;//char, short, int, float
};

#endif /* ALARM_H */
