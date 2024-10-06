#include "include/Playstate.hpp"
#include "include/Command.hpp"

#include <iostream>
#include <cmath>

Playstate Playstate::m_PlayStateScreen;

void Playstate::Init()
{
	m_Players[0] = new Racket(40, 400);
	m_Players[1] = new Racket(700, 40);

	float InitYPos = (GetScreenHeight() / 2) - (m_Players[0]->GetSize().y / 2);

	m_Players[0]->SetPosition(40, InitYPos);
	m_Players[1]->SetPosition(700, InitYPos);

	m_PlayersScore[0] = 0;
	m_PlayersScore[1] = 0;

	m_Ball.RestartBall();
}

void Playstate::Destroy()
{
	delete m_Players[0];
	delete m_Players[1];
}

void Playstate::Pause()
{
}

void Playstate::Resume()
{
}

void Playstate::Update(Game* game)
{
	m_Players[0]->UpdateHitbox();
	m_Players[1]->UpdateHitbox();

	{
		Command* command = input.HandlePlayer1Input();
		if (command != nullptr)
			command->execute(m_Players[0]);
	}

	{
		Command* command = input.HandlePlayer2Input();
		if (command != nullptr)
			command->execute(m_Players[1]);
	}

	m_Ball.Update();

	Vector2 ballPos = m_Ball.GetPosition();
	int screenWidth = GetScreenWidth();
	if (ballPos.x > screenWidth || ballPos.x < 0)
	{
		int playerScore = (ballPos.x > screenWidth) ? 0 : 1;
		m_Players[playerScore]->AddScore();

		m_Ball.RestartBall();
	}

	for (auto& player : m_Players)
	{
		if (m_Ball.Intersects(player->GetHitbox()))
		{
			Vector2 newVel{};
			newVel.x -= m_Ball.GetVelocity().x;
			newVel.y = m_Ball.GetPosition().y - (player->GetPosition().y + (player->GetSize().y / 2));

			float length = std::sqrt((newVel.x * newVel.x) + (newVel.y * newVel.y));

			if (length != 0.f)
			{
				//newVel.x /= length;
				newVel.y /= length;
			}

			m_Ball.SetVelocity(newVel);
		}
	}
}

void Playstate::Render()
{
	DrawText(TextFormat("%i", m_Players[0]->GetScore()), 210, 100, 64, WHITE);
	DrawText(TextFormat("%i", m_Players[1]->GetScore()), 540, 100, 64, WHITE);

	for (auto& player : m_Players)
		player->Draw();

	m_Ball.Draw();
}
