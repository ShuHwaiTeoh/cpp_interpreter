#ifndef Data_H
#define Data_H

class Data{
public:
	Data(int, char);
	Data(short, char);
	Data(unsigned char, char);
	Data(float, char);
	virtual ~Data();
	unsigned char charV;
	short shortV;
	static int intV;
	static float floatV;
    char type;//C(Byte), S, I, F
};

#endif /* ALARM_H */
