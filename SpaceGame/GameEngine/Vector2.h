#pragma once

class Vector2
{
public:
	int x;
	int y;

	Vector2() : x(0), y(0) {};
	Vector2(int x, int y) : x(x), y(y) {};
	~Vector2() {};

	Vector2 operator+(const Vector2&) const;
	Vector2 operator-(const Vector2&) const;
	Vector2 operator*(const Vector2&) const;
	Vector2 operator/(const Vector2&) const;

	Vector2& operator+=(const Vector2&);
	Vector2& operator-=(const Vector2&);
	Vector2& operator*=(const Vector2&);
	Vector2& operator/=(const Vector2&);

	bool operator==(const Vector2&);
	bool operator!=(const Vector2&);

	Vector2 operator-() const;

	Vector2 operator*(const int&) const;
	Vector2 operator/(const int&) const;

	static Vector2 Zero();
	static Vector2 One();
	static Vector2 Up();
	static Vector2 Right();
};

