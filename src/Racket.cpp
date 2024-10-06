#include "include/Racket.hpp"

Racket::Racket(int x, int y)
	: MyRectangle(x, y, 30, 70, WHITE)
{
	m_Velocity.x = 0.f;
	m_Velocity.y = 7.f;

	m_Score = 0;
}

void Racket::MoveUp()
{
	Move(0, -m_Velocity.y);
}

void Racket::MoveDown()
{
	Move(0, m_Velocity.y);
}

