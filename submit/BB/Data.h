#ifndef Data_H
#define Data_H

class Data{
public:
	Data(int, char);
	Data(short, char);
	Data(unsigned char, char);
	Data(float, char);
	virtual ~Data();
	unsigned char charV = '\0';
	short shortV = 0;
	int intV = 0;
	float floatV = 0.0;
    char type;//C(Byte), S, I, F
};

#endif /* ALARM_H */
