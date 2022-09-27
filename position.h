#pragma once
#include "vectors.h"
#include "points.h"

namespace Coal
{

	struct Position
	{
		Position();
		Position(const Point3& ind, const Vector3& axi);
		Position(const Point3& rawInput);
		Point3 index() const;
		Vector3 axial() const;

		//iiii iiii pppp pppp ppdd dddd dddd dddd - x and y
		//iiii pppp pppp pppp ppdd dddd dddd dddd - z
		Point3 raw;
	};

	Position operator+(const Position& position, const Vector3& axial);
	Position operator-(const Position& position, const Vector3& axial);
	float SquareDistance(const Position& posA, const Position& posB);
	std::string ToString(const Position& pos);
}
