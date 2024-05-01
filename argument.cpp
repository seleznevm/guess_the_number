#include <iostream>
#include <string>
#include <high_scores.h>

extern int max_value;

int check_argument(const int argc, const char** argv) {

	// argc - it is a count of arguments
	// But there is some detail - OS always pass one system argument - the name of the executable
	// So, is the application was executed without arguments at all, argc will be still == 1

	// To check - does use print some other argument we should check if the argc >= 2
	if (argc >= 2) {
		std::string arg1_value{ argv[1] };

		// add -max atribute input
		if (arg1_value == "-max") {
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			int parameter_value = 0;
			if (argc < 3) {
				std::cout << "The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			parameter_value = std::stoi(argv[2]);
			max_value = parameter_value;
		}

		// add -table atribute
		if(arg1_value == "-table")
		{
			showScore();
			return 1;
		}
	}

	return 0;

}