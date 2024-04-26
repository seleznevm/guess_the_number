#include <iostream>
#include "random_value.h"
#include "high_scores.h"
#include "check_value.h"

int check_value(const int target_value) 
{
	int attemps_count{0};
	do {
		std::cout << "Enter your guess:" << std::endl;
		int current_value = 0;
		std::cin >> current_value;
		if (current_value < target_value)
			{ 
			std::cout << "less than " << current_value << std::endl;
			attemps_count++;
			}
		else if (current_value > target_value) 
			{
			std::cout << "greater than " << current_value << std::endl;
			attemps_count++;
			}
		else {
			std::cout << "you win!" << std::endl;
			return attemps_count;
			}
		}
	while (true);
		
}