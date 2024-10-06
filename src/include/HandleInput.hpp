#pragma once

#include "Command.hpp"

#include <raylib.h>

#include <unordered_map>
#include <iostream>

class HandleInput
{
public:
	HandleInput()
	{
		m_player1Input[KEY_W] = &up;
		m_player1Input[KEY_S] = &down;

		m_player2Input[KEY_UP] = &up;
		m_player2Input[KEY_DOWN] = &down;
	}

	Command* HandlePlayer1Input()
	{
		for (const auto& comand : m_player1Input)
		{
			if (IsKeyDown(comand.first))
			{
				return comand.second;
			}
		}

		return nullptr;
	}

	Command* HandlePlayer2Input()
	{
		for (const auto& input : m_player2Input)
		{
			if (IsKeyDown(input.first))
			{
				return input.second;
			}
		}

		return nullptr;
	}

private:
	UpMove up;
	DownMove down;

	std::unordered_map<int, Command*> m_player1Input;
	std::unordered_map<int, Command*> m_player2Input;
};