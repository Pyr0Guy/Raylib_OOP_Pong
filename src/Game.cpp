#include "include/Game.hpp"
#include "include/GameState.hpp"
#include "include/Playstate.hpp"

#include <raylib.h>

Game::Game(unsigned int width, unsigned int height, const char* name)
{
	SetConfigFlags(FLAG_WINDOW_HIGHDPI);
	InitWindow(width, height, name);

	m_Size.x = width;
	m_Size.y = height;

	if (IsWindowReady())
		ChangeState(Playstate::getState());
}

void Game::Update()
{
	m_States.back()->Update(this);
}

void Game::Render()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (auto& state : m_States)
		state->Render();
	
	DrawFPS(0, 0);
	EndDrawing();
}

void Game::Destroy()
{
	CloseWindow();
}

void Game::ChangeState(GameState* state)
{
	while(!m_States.empty())
	{
		m_States.back()->Destroy();
		m_States.pop_back();
	}

	m_States.emplace_back(state);
	m_States.back()->Init();
}

void Game::PushState(GameState* state)
{
	if (!m_States.empty())
		m_States.back()->Pause();

	m_States.emplace_back(state);
	m_States.back()->Init();
}

void Game::PopState()
{
	if (!m_States.empty())
	{
		m_States.back()->Destroy();
		m_States.pop_back();
	}

	if (!m_States.empty())
		m_States.back()->Resume();
}

bool Game::GameShouldEnd() const
{
	return WindowShouldClose();
}

Vector2 Game::GetGameSize() const
{
	return m_Size;
}
