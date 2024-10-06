#include "include/MyHitbox.hpp"

MyHitbox::MyHitbox(int x, int y, int width, int height)
{
	m_Hitbox.x = x;
	m_Hitbox.y = y;
	m_Hitbox.z = width;
	m_Hitbox.w = height;

	m_StartHitboxTimerMax = 30.f;
	m_StartHitboxTimer = 0.f;

	m_isActive = true;
}

MyHitbox::MyHitbox(Vector4& vect)
{
	m_Hitbox = vect;

	m_StartHitboxTimerMax = 30.f;
	m_StartHitboxTimer = 0.f;

	m_isActive = true;
}

bool MyHitbox::Intersects(Vector4& otherRect)
{
	if(m_Hitbox.x < otherRect.x + otherRect.z &&
		m_Hitbox.x + m_Hitbox.z > otherRect.x &&
		m_Hitbox.y < otherRect.y + otherRect.w &&
		m_Hitbox.y + m_Hitbox.w > otherRect.y && m_isActive)
	{
		m_isActive = false;
		m_StartHitboxTimer = m_StartHitboxTimerMax;
		return true;
	}

	return false;
}

Vector4 MyHitbox::GetHitbox() const
{
	return m_Hitbox;
}

void MyHitbox::UpdateHitbox()
{
	if (m_StartHitboxTimer >= 0)
	{
		m_StartHitboxTimer--;

		if (m_StartHitboxTimer <= 0)
			m_isActive = true;
	}
}
