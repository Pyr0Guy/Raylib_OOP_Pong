#pragma once

#include <raylib.h>

class MyHitbox
{
public:
	MyHitbox(int x, int y, int width, int height);
	MyHitbox(Vector4& vect);

	void UpdateHitbox();

	bool Intersects(Vector4& otherRect);
	Vector4 GetHitbox() const;
protected:
	Vector4 m_Hitbox;

private:
	bool m_isActive;
	float m_StartHitboxTimer;
	float m_StartHitboxTimerMax;
};