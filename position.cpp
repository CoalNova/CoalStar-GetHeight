#include "position.h"

namespace Coal
{
	Position operator+(const Position& position, const Vector3& axial)
	{
		Position pos = {};
		pos.raw.x = position.raw.x + (int)(axial.x * (1 << 14));
		pos.raw.y = position.raw.y + (int)(axial.y * (1 << 14));
		pos.raw.z = position.raw.z + (int)(axial.z * (1 << 14));
		return pos;
	}

	Position operator-(const Position& position, const Vector3& axial)
	{
		Position pos = {};
		pos.raw.x = position.raw.x - (int)(axial.x * (1 << 14));
		pos.raw.y = position.raw.y - (int)(axial.y * (1 << 14));
		pos.raw.z = position.raw.z - (int)(axial.z * (1 << 14));
		return pos;
	}

	float SquareDistance(const Position& posA, const Position& posB)
	{

		Point3 index = posA.index() - posB.index();
		Vector3 axial = posA.axial() - posB.axial();

		axial = axial + Vector3{ index.x * 1024.0f, index.y * 1024.0f, index.z * 1024.0f };

		return axial.x * axial.x + axial.y * axial.y + axial.z * axial.z;
	}

	std::string ToString(const Position& pos)
	{
		return  ToString(pos.index()) + ToString(pos.axial());
	}
	
	Position::Position() : raw() {}
	Position::Position(const Point3& ind, const Vector3& axi) : raw((ind.x << 24) + (int)(axi.x * (1 << 14)), (ind.y << 24) + (int)(axi.y * (1 << 14)), (ind.z << 28) + (int)(axi.z * (1 << 14))) {}
	Position::Position(const Point3& rawInput) : raw(rawInput) {}
	Point3 Position::index() const { return Point3((raw.x >> 24) & 255, (raw.y >> 24) & 255, (raw.y >> 28) & 15); }
	Vector3 Position::axial() const { return Vector3((float)(raw.x & ((1 << 24) - 1)) / (float)(1 << 14), (float)(raw.y & ((1 << 24) - 1)) / (float)(1 << 14), (float)(raw.z & ((1 << 28) - 1)) / (float)(1 << 14)); }
}
