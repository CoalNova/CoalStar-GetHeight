#pragma once
#include <string>

namespace Coal
{

	struct Vector2
	{
		Vector2();
		Vector2(float _x, float _y);
		float x, y;
	};

	Vector2 Normalized(const Vector2& vec);
	Vector2 operator +(const Vector2& lhd, const Vector2& rhd);
	Vector2 operator -(const Vector2& lhd, const Vector2& rhd);
	Vector2 operator *(const Vector2& lhd, const float& rhd);
	Vector2 operator /(const Vector2& lhd, const float& rhd);
	bool operator ==(const Vector2& lhd, const Vector2& rhd);
	bool operator !=(const Vector2& lhd, const Vector2& rhd);
	std::string ToString(const Vector2& vec);

	struct Vector3
	{
		Vector3();
		Vector3(float _x, float _y, float _z);
		float x, y, z;
	};


	Vector3 Normalized(const Vector3& vec);
	Vector3 operator +(const Vector3& lhd, const Vector3& rhd);
	Vector3 operator -(const Vector3& lhd, const Vector3& rhd);
	Vector3 operator *(const Vector3& lhd, const float& rhd);
	Vector3 operator /(const Vector3& lhd, const float& rhd);
	bool operator ==(const   Vector3& lhd, const Vector3& rhd);
	bool operator !=(const   Vector3& lhd, const Vector3& rhd);
	std::string ToString(const Vector3& vec);
	Vector3 BadCross(const Vector3& lhd, const Vector3& rhd);
	Vector3 Cross(const Vector3& lhd, const Vector3& rhd);


	struct Vector4
	{
		Vector4();
		Vector4(float _w, float _x, float _y, float _z);
		float w, x, y, z;
	};


	Vector4 Normalized(const Vector4& vec);
	Vector4 operator +(const Vector4& lhd, const Vector4& rhd);
	Vector4 operator -(const Vector4& lhd, const Vector4& rhd);
	Vector4 operator *(const Vector4& lhd, const float& rhd);
	Vector4 operator /(const Vector4& lhd, const float& rhd);
	bool operator ==(const   Vector4& lhd, const Vector4& rhd);
	bool operator !=(const   Vector4& lhd, const Vector4& rhd);
	std::string ToString(const Vector4& vec);



	Vector3	Normal(Vector3 a, Vector3 b, Vector3 c);
	Vector3 Normal(Vector3 a, Vector3 b, Vector3 c, Vector3 d);
	Vector3 BadNormal(Vector3 a, Vector3 b);

	float VectorDot(const Vector3& a, const Vector3& b);


}