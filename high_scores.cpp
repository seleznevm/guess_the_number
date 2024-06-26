#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "high_scores.h"

const std::string high_scores_filename = "high_scores.txt";

int addScore(Player& player)
{
	{
		// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		// Append new results to the table:
		out_file << player.name << ' ';
		out_file << player.attempts_count;
		out_file << std::endl;
	} // end of score here just to mark end of the logic block of code

	return 0;
}

int showScore()
	{
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
		return 0;
	}

//add map with users list
std::map<std::string, int> usersList;
void addUser(std::string name, int score)
{
	auto it = usersList.find(name);
	if (it != usersList.end())
	{
		if (it->second > score)
		{
				it->second = score;
		}
	}
	else
	{
		usersList.insert({ name, score });
	}
}

int showScoreMin()
{
	std::ifstream infile{high_scores_filename};
	if(!(infile).is_open())
	{
		std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	std::cout << "High scores table (shown only minimum results)\n";
	std::string username;
	int high_score{0};
	while(true){
		infile >> username;
		infile >> high_score;
		infile.ignore();
			if(infile.fail()) 
			{
				break;
			}
		addUser(username, high_score);
	}
	
	//print minimal scores
	for(auto it = usersList.cbegin(); it != usersList.cend(); it++)
	{
		std::cout << it->first << "\t" << it->second << std::endl;
	}
	return 0;
}