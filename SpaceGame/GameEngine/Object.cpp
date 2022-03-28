#include "Object.h"


namespace ConsoleEngine
{
	Object::Object()
	{
		position = Vector2::Zero();
		isActive = true;
	}

	Object::~Object()
	{
	}

	bool Object::IsActive()
	{
		return isActive;
	}

	void Object::SetActive(bool active)
	{
		isActive = active;
	}

	int Object::GetId()
	{
		return id;
	}
	void Object::SetId(int _id)
	{
		id = _id;
	}
}