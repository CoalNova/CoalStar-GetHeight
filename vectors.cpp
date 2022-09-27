#include "Vectors.h"

namespace Coal
{
	Vector2::Vector2() : x(0), y(0) {		}
	Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {		}

	Vector3::Vector3() : x(0), y(0), z(0) {		}
	Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {		}

	Vector4::Vector4() :w(0), x(0), y(0), z(0) {		}
	Vector4::Vector4(float _w, float _x, float _y, float _z) : w(_w), x(_x), y(_y), z(_z) {		}


	Vector3 Cross(const Vector3& lhd, const Vector3& rhd)
	{
		return {
			lhd.y * rhd.z - lhd.z * rhd.y,
			lhd.z * rhd.x - lhd.x * rhd.z,
			lhd.x * rhd.y - lhd.y * rhd.x
		};
	}

	Vector3 BadCross(const Vector3& lhd, const Vector3& rhd)
	{
		return Vector3{
			lhd.y * rhd.z - lhd.z * rhd.y,
			lhd.z * rhd.x - lhd.x * rhd.z,
			lhd.y * rhd.x - lhd.x * rhd.y
		}; //I have learned not to question why this works
	}

	Vector3 Normal(Vector3 a, Vector3 b, Vector3 c) { return Normalized(Cross(b - a, c - a)); }
	Vector3 Normal(Vector3 a, Vector3 b, Vector3 c, Vector3 d) { return Normalized(Cross(a, b) + Cross(c, d)); }
	Vector3 BadNormal(Vector3 a, Vector3 b) { return Normalized(BadCross(a, b)); }

	float VectorDot(const Vector3& a, const Vector3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	Vector2 Normalized(const Vector2& vec)
	{
		float magnitude = sqrt(vec.x * vec.x + vec.y * vec.y);
		return { vec.x / magnitude, vec.y / magnitude };
	}
	Vector2 operator+(const Vector2& lhd, const Vector2& rhd) { return Vector2(lhd.x + rhd.x, lhd.y + rhd.y); }
	Vector2 operator-(const Vector2& lhd, const Vector2& rhd) { return Vector2(lhd.x - rhd.x, lhd.y - rhd.y); }
	Vector2 operator*(const Vector2& lhd, const float& rhd) { return Vector2(lhd.x * rhd, lhd.y * rhd); }
	Vector2 operator/(const Vector2& lhd, const float& rhd) { return Vector2(lhd.x / rhd, lhd.y / rhd); }
	bool operator==(const Vector2& lhd, const Vector2& rhd) { return lhd.x == rhd.x && lhd.y == rhd.y; }
	bool operator!=(const Vector2& lhd, const Vector2& rhd) { return lhd.x != rhd.x || lhd.y != rhd.y; }
	std::string ToString(const Vector2& vec) { return "(" + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ")"; }

	Vector3 Normalized(const Vector3& vec)
	{
		float magnitude = sqrt(vec.z * vec.z + vec.x * vec.x + vec.y * vec.y);
		return { vec.x / magnitude, vec.y / magnitude,vec.z / magnitude };
	}
	Vector3 operator+(const Vector3& lhd, const Vector3& rhd) { return Vector3(lhd.x + rhd.x, lhd.y + rhd.y, lhd.z + rhd.z); }
	Vector3 operator-(const Vector3& lhd, const Vector3& rhd) { return Vector3(lhd.x - rhd.x, lhd.y - rhd.y, lhd.z - rhd.z); }
	Vector3 operator*(const Vector3& lhd, const float& rhd) { return Vector3(lhd.x * rhd, lhd.y * rhd, lhd.z * rhd); }
	Vector3 operator/(const Vector3& lhd, const float& rhd) { return Vector3(lhd.x / rhd, lhd.y / rhd, lhd.z / rhd); }
	bool operator==(const Vector3& lhd, const Vector3& rhd) { return lhd.x == rhd.x && lhd.y == rhd.y && lhd.z == rhd.z; }
	bool operator!=(const Vector3& lhd, const Vector3& rhd) { return lhd.x != rhd.x || lhd.y != rhd.y || lhd.z != rhd.z; }
	std::string ToString(const Vector3& vec) { return "(" + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ", " + std::to_string(vec.z) + ")"; }

	Vector4 Normalized(const Vector4& vec)
	{
		float magnitude = sqrt(vec.w * vec.w + vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		return { vec.w / magnitude, vec.x / magnitude, vec.y / magnitude,vec.z / magnitude };
	}
	Vector4 operator+(const Vector4& lhd, const Vector4& rhd) { return Vector4(lhd.w + rhd.w, lhd.x + rhd.x, lhd.y + rhd.y, lhd.z + rhd.z); }
	Vector4 operator-(const Vector4& lhd, const Vector4& rhd) { return Vector4(lhd.w - rhd.w, lhd.x - rhd.x, lhd.y - rhd.y, lhd.z - rhd.z); }
	Vector4 operator*(const Vector4& lhd, const float& rhd) { return Vector4(lhd.w * rhd, lhd.x * rhd, lhd.y * rhd, lhd.z * rhd); }
	Vector4 operator/(const Vector4& lhd, const float& rhd) { return Vector4(lhd.w / rhd, lhd.x / rhd, lhd.y / rhd, lhd.z / rhd); }
	bool operator==(const Vector4& lhd, const Vector4& rhd) { return lhd.w == rhd.w && lhd.x == rhd.x && lhd.y == rhd.y && lhd.z == rhd.z; }
	bool operator!=(const Vector4& lhd, const Vector4& rhd) { return lhd.w != rhd.w || lhd.x != rhd.x || lhd.y != rhd.y || lhd.z != rhd.z; }
	std::string ToString(const Vector4& vec) { return "(" + std::to_string(vec.w) + ", " + std::to_string(vec.x) + ", " + std::to_string(vec.y) + ", " + std::to_string(vec.z) + ")"; }

}