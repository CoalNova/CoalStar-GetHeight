#pragma once
#include <string>

namespace Coal
{
	struct Point2
	{
		Point2();
		Point2(const int& _x, const int& _y);
		int x, y;
	};

	Point2 operator+(const Point2& lhd, const Point2& rhd);
	Point2 operator-(const Point2& lhd, const Point2& rhd);
	bool operator==(const Point2& lhd, const Point2& rhd);
	bool operator!=(const Point2& lhd, const Point2& rhd);
	std::string ToString(const Point2& lhd);

	struct Point3
	{
		Point3();
		Point3(const int& _x, const int& _y, const int& _z);
		int x, y, z;
	};

	Point3 operator+(const Point3& lhd, const Point3& rhd);
	Point3 operator-(const Point3& lhd, const Point3& rhd);
	bool  operator==(const Point3& lhd, const Point3& rhd);
	bool  operator!=(const Point3& lhd, const Point3& rhd);
	std::string ToString(const Point3& lhd);

	struct Point4
	{
		Point4();
		Point4(const int& _w, const int& _x, const int& _y, const int& _z);
		int w, x, y, z;
	};

	Point4 operator+(const Point4& lhd, const Point4& rhd);
	Point4 operator-(const Point4& lhd, const Point4& rhd);
	bool  operator==(const Point4& lhd, const Point4& rhd);
	bool  operator!=(const Point4& lhd, const Point4& rhd);
	std::string ToString(const Point4& lhd);

}
