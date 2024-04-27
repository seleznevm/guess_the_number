#pragma once

#include <string>

struct Player{
	std::string name;
	unsigned int attempts_count;
};

int addScore(Player& player);
int showScore();