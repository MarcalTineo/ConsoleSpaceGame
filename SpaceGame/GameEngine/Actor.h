#pragma once
#include "Object.h"
#include <vector>
#include <string>
class Actor : public Object
{
protected:
	std::vector<Vector2> collider;
	std::string tag;
public:
	Actor();
	~Actor();

	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;

	virtual void OnCollision(Actor* other) {};

	std::vector<Vector2> GetCollider();

	void SetTag(std::string tag);
	std::string GetTag();
	bool CompareTag(std::string tag);
};

