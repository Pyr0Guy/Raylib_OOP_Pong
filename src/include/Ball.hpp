#pragma once

#include "GameObject.hpp"
#include "MyRectangle.hpp"

#include <raylib.h>

class Ball
	: public MyRectangle
{
public:
	Ball();

	void Update();

	void RestartBall();

	inline void SetVelocity(Vector2& newVel) { m_Velocity = newVel; };
	inline void SetVelocity(float x, float y) { m_Velocity.x = x; m_Velocity.y = y; };

	inline Vector2 GetVelocity() const { return m_Velocity; }
private:
	float m_Force;
	int m_InitialDir;
};