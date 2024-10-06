#include "include/MyRectangle.hpp"

#include <iostream>

MyRectangle::MyRectangle(float x, float y, int width, int height, Color color)
	: m_Color(color), MyHitbox(x, y, x + width, y + height)
{
	m_Pos = { x, y };
	m_Size.x = width;
	m_Size.y = height;

	//m_Hitbox = { x, y, width, height };
	m_Hitbox.x = m_Pos.x;
	m_Hitbox.y = m_Pos.y;
	m_Hitbox.z = m_Size.x;
	m_Hitbox.w = m_Size.y;

 	m_Velocity = { 0, 0 };
}

void MyRectangle::Draw()
{
	DrawRectangle(m_Pos.x, m_Pos.y, m_Size.x, m_Size.y, m_Color);
}

void MyRectangle::SetPosition(int x, int y)
{
	m_Pos.x = x;
	m_Pos.y = y;

	UpdateRectangleBox();
}

void MyRectangle::SetSize(int width, int height)
{
	m_Size.x = width;
	m_Size.y = height;

	UpdateRectangleBox();
}

void MyRectangle::SetColor(Color color)
{
	m_Color = color;
}

void MyRectangle::Move(int x, int y)
{
	m_Pos.x += x;
	m_Pos.y += y;

	UpdateRectangleBox();
}

void MyRectangle::UpdateRectangleBox()
{
	m_Hitbox.x = m_Pos.x;
	m_Hitbox.y = m_Pos.y;
	m_Hitbox.z = m_Size.x;
	m_Hitbox.w = m_Size.y;
}
