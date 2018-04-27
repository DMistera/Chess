#pragma once

#include "Field.h"
#include "Piece.h"

class FieldUtils {
public:
	FieldUtils();
	~FieldUtils();
	static Field coordToField(Vector2i coords);
	static Vector2f fieldToCoord(Field field);
};

