#include "include/Ball.hpp"

Ball::Ball()
	: MyRectangle(300, 400, 20, 20, WHITE)
{
	m_Velocity.x = -1;
	m_Velocity.y = 0;

	m_Force = 4.f;
	m_InitialDir = -1;
}

void Ball::Update()
{
	UpdateHitbox();
	Move(m_Velocity.x * m_Force, m_Velocity.y * m_Force);

	if (GetPosition().y <= 0 || GetPosition().y >= GetScreenHeight() - GetSize().y)
	{
		Vector2 vel = GetVelocity();
		SetVelocity(vel.x, -vel.y);
	}
}

void Ball::RestartBall()
{
	SetPosition(GetScreenWidth() / 2 - (GetSize().x / 2), (GetScreenHeight() / 2) - (GetSize().y / 2));

	m_InitialDir *= -1;
	SetVelocity(m_InitialDir, 0);
}
