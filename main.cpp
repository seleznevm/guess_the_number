#include <iostream>
#include <string>
#include <map>

#include "high_scores.h"
#include "check_value.h"
#include "random_value.h"
void check_argument(int argc, char** argv);

int max_value = 100;

int main(int argc, char** argv)
{
    check_argument(argc, argv);
    const int target_value = random_value();

    std::cout << "Welcome to the \"Guess the number\"" << std::endl;
    std::cout << "Enter you name, please:" << " " << std::endl;
    std::string player_name;
    
    //create a Player
    Player player;
    try
    {
        std::cin >> player.name;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
 
    //start check value game
    player.attempts_count = check_value(target_value);
    std::map<std::string, int> usersList;
    addScore(player);
    showScoreMin();
    return 0;
}