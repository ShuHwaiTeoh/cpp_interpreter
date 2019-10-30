#include "Data.h"

Data::Data(int v, char t) {
	intV = v;
	type = t;
}
Data::Data(short v, char t) {
	shortV = v;
	type = t;
}
Data::Data(unsigned char v, char t) {
	charV = v;
	type = t;
}
Data::Data(float v, char t) {
	floatV = v;
	type = t;
}
Data::~Data() {}
