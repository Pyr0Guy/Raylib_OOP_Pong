#pragma once

#include <vector>
#include <raylib.h>

class GameState;

class Game
{
public:
	Game(unsigned int width, unsigned int height, const char* name);
	Game(const Game&) = delete;
	Game& operator =(const Game&) = delete;

	void Update();
	void Render();
	void Destroy();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	bool GameShouldEnd() const;

	Vector2 GetGameSize() const;
private:
	std::vector<GameState*> m_States;

	Vector2 m_Size;
};