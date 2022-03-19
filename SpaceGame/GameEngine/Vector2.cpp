#include "Vector2.h"

namespace ConsoleEngine
{
	Vector2 Vector2::operator+(const Vector2& v) const
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 Vector2::operator-(const Vector2& v) const
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 Vector2::operator*(const Vector2& v) const
	{
		return Vector2(x * v.x, y * v.y);
	}

	Vector2 Vector2::operator/(const Vector2& v) const
	{
		return Vector2(x / v.x, y / v.y);
	}

	Vector2& Vector2::operator+=(const Vector2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2& v)
	{
		x *= v.x;
		y *= v.y;
		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2& v)
	{
		x /= v.x;
		y /= v.y;
		return *this;
	}

	bool Vector2::operator==(const Vector2& v)
	{
		return x == v.x && y == v.y;
	}

	bool Vector2::operator!=(const Vector2& v)
	{
		return x != v.x || y != v.y;
	}

	Vector2 Vector2::operator-() const
	{
		return Vector2(-x, -y);
	}

	Vector2 Vector2::operator*(const int& s) const
	{
		return Vector2(x * s, y * s);
	}

	Vector2 Vector2::operator/(const int& s) const
	{
		return Vector2(x / s, y / s);
	}

	Vector2 Vector2::Zero()
	{
		return Vector2(0, 0);
	}

	Vector2 Vector2::One()
	{
		return Vector2(1, 1);
	}

	Vector2 Vector2::Up()
	{
		return Vector2(0, 1);
	}

	Vector2 Vector2::Right()
	{
		return Vector2(1, 0);
	}
}