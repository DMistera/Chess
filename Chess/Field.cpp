#include "Field.h"



Field::Field(int x, int y) {
	this->x = x;
	this->y = y;
}

Field::Field() {
}


Field::~Field() {
}

void Field::reverse()
{
	y = 7 - y;
}
