#include <iostream>
#include <string>

#include "high_scores.h"
#include "check_value.h"
#include "random_value.h"
int check_argument(int argc, char** argv);

int max_value = 100;

int main(int argc, char** argv)
{
    check_argument(argc, argv);
    bool not_win = true;
    const int target_value = random_value();

    std::cout << "Welcome to the \"Guess the number\"" << std::endl;
    std::cout << "Enter you name, please:" << " " << std::endl;
    std::string player_name;
    
    //create a Player
    Player player;
    std::cin >> player.name;

    //start check value game
    player.attempts_count = check_value(target_value);
    addScore(player);

}