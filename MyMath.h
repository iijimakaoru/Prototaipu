#pragma once
#include "Vector2.h"

namespace MyMath
{
	const float PI = 3.14159265f;

	bool Intersection(Vector2 pos1, Vector2 pos2, Vector2 pos3, Vector2 pos4, Vector2& cross);
	bool PointOnLine(Vector2 line1, Vector2 line2, Vector2 pos);
}
