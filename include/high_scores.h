#pragma once

#include <string>

struct Player{
	std::string name;
	unsigned int attempts_count = 0;
};

int addScore(Player& player);
int showScore();
void addUser(std::string name, int score);
int showScoreMin();