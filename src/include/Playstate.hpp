#pragma once

#include "GameState.hpp"

#include "include/Racket.hpp"
#include "include/Ball.hpp"

#include <array>
#include "HandleInput.hpp"

class Playstate
	: public GameState
{
public:
	void Init();
	void Destroy();

	void Pause();
	void Resume();

	void Update(Game* game);
	void Render();

	static Playstate* getState()
	{
		return &m_PlayStateScreen;
	}

protected:
	Playstate() {}
private:
	static Playstate m_PlayStateScreen;

	std::array<Racket*, 2> m_Players;
	std::array<unsigned int, 2> m_PlayersScore;

	Ball m_Ball;
	HandleInput input;
};