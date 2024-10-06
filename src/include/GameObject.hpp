#pragma once

class GameObject
{
public:
	virtual	~GameObject() = default;
	virtual void Draw() = 0;
};