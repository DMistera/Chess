#include "FieldUtils.h"



FieldUtils::FieldUtils() {
}


FieldUtils::~FieldUtils() {
}

Field FieldUtils::coordToField(Vector2i coords) {
	int x = coords.x / Piece::PIECE_SIZE;
	int y = coords.y / Piece::PIECE_SIZE;
	y = 7 - y;
	return Field(x, y);
}

Vector2f FieldUtils::fieldToCoord(Field field) {
	float x = field.x*Piece::PIECE_SIZE;
	float y = (7 - field.y)*Piece::PIECE_SIZE;
	return Vector2f(x, y);
}