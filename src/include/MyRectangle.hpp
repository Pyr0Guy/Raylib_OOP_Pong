#pragma once

#include <raylib.h>

#include "MyHitbox.hpp"

class MyRectangle
	: public MyHitbox
{
public:
	MyRectangle(float x, float y, int width, int height, Color color);
	virtual ~MyRectangle() = default;
	
	virtual void Draw();

	void SetPosition(int x, int y);
	void SetSize(int width, int height);
	void SetColor(Color color);

	void Move(int x, int y);

	inline Vector2	GetPosition()	const	{ return m_Pos;				}
	inline Vector2	GetSize()		const	{ return m_Size;			}
	inline Color	GetColor()		const	{ return m_Color;			}
	inline Vector2	GetVelocity()	const	{ return m_Velocity;		}
protected:
	Vector2 m_Pos;
	Vector2 m_Size;
	Color	m_Color;
	Vector2 m_Velocity;

private:
	void UpdateRectangleBox();
};