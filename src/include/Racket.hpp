#pragma once

#include <raylib.h>

#include "GameObject.hpp"
#include "MyRectangle.hpp"

class Racket
	: public MyRectangle
{
public:
	Racket(int x, int y);

	void MoveUp();
	void MoveDown();

	inline void AddScore() { m_Score++; };
	inline unsigned int GetScore() const { return m_Score; }
private:
	unsigned int m_Score;
};