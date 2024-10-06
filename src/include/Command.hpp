#pragma once

#include "MyRectangle.hpp"
#include <raylib.h>

class Command
{
public:
	virtual ~Command() {};
	virtual void execute(MyRectangle* rect) = 0;
};

class UpMove : public Command
{
public:
	void execute(MyRectangle* rect) override
	{
		if(rect->GetPosition().y /* - rect->GetVelocity().y*/ >= 0)
			rect->Move(0, -rect->GetVelocity().y);
	}
};

class DownMove : public Command
{
public:
	void execute(MyRectangle* rect) override
	{
		if((rect->GetPosition().y + rect->GetSize().y)/* + rect->GetVelocity().y*/ <= GetScreenHeight())
			rect->Move(0, rect->GetVelocity().y);
	}
};