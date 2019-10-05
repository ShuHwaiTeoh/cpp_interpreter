#include "Data.h"

Data::Data(int v, std::string t) {
	value = v;
	type = t;
}
Data::Data(short v, std::string t) {
	value = v;
	type = t;
}
Data::Data(char v, std::string t) {
	value = v;
	type = t;
}
Data::Data(float v, std::string t) {
	value = v;
	type = t;
}
Data::~Data() {}
