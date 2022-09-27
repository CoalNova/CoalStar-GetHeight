#include "Points.h"
#include <string>

namespace Coal
{

	Point2::Point2() :x(0), y(0) {}
	Point2::Point2(const int& _x, const int& _y) :x(_x), y(_y) {}
	Point2 operator+(const Point2& lhd, const Point2& rhd) { return Point2(lhd.x + rhd.x, lhd.y + rhd.y); }
	Point2 operator-(const Point2& lhd, const Point2& rhd) { return Point2(lhd.x - rhd.x, lhd.y - rhd.y); }
	bool operator==(const Point2& lhd, const Point2& rhd) { return lhd.x == rhd.x && lhd.y == rhd.y; }
	bool operator!=(const Point2& lhd, const Point2& rhd) { return lhd.x != rhd.x || lhd.y != rhd.y; }
	std::string ToString(const Point2& point) { return '[' + std::to_string(point.x) + ", " + std::to_string(point.y) + ']'; }

	Point3::Point3() : x(0), y(0), z(0) {	}
	Point3::Point3(const int& _x, const int& _y, const int& _z) : x(_x), y(_y), z(_z) {	}
	Point3 operator+(const Point3& lhd, const Point3& rhd) { return Point3(lhd.x + rhd.x, lhd.y + rhd.y, lhd.z + rhd.z); }
	Point3 operator-(const Point3& lhd, const Point3& rhd) { return Point3(lhd.x - rhd.x, lhd.y - rhd.y, lhd.z - rhd.z); }
	bool operator==(const Point3& lhd, const Point3& rhd) { return lhd.x == rhd.x && lhd.y == rhd.y && lhd.z == rhd.z; }
	bool operator!=(const Point3& lhd, const Point3& rhd) { return lhd.x != rhd.x || lhd.y != rhd.y || lhd.z != rhd.z; }
	std::string ToString(const Point3& point) { return '[' + std::to_string(point.x) + ", " + std::to_string(point.y) + ", " + std::to_string(point.z) + ']'; }

	Point4::Point4() :w(0), x(0), y(0), z(0) {}
	Point4::Point4(const int& _w, const int& _x, const int& _y, const int& _z) :w(_w), x(_x), y(_y), z(_z) {}
	Point4 operator+(const Point4& lhd, const Point4& rhd) { return Point4(lhd.w + rhd.w, lhd.x + rhd.x, lhd.y + rhd.y, lhd.z + rhd.z); }
	Point4 operator-(const Point4& lhd, const Point4& rhd) { return Point4(lhd.w - rhd.w, lhd.x - rhd.x, lhd.y - rhd.y, lhd.z - rhd.z); }
	bool operator==(const Point4& lhd, const Point4& rhd) { return lhd.w == rhd.w && lhd.x == rhd.x && lhd.y == rhd.y && lhd.z == rhd.z; }
	bool operator!=(const Point4& lhd, const Point4& rhd) { return lhd.w != rhd.w || lhd.x != rhd.x || lhd.y != rhd.y || lhd.z != rhd.z; }
	std::string ToString(const Point4& lhd)
	{
		return "[" + std::to_string(lhd.w) + ", " + std::to_string(lhd.x) + ", " + std::to_string(lhd.y) + ", " + std::to_string(lhd.z) + "]";
	}
}
