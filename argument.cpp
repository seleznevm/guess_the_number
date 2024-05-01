#include <iostream>
#include <string>
#include <high_scores.h>
#include <program_options.hpp>

extern int max_value;

namespace po = boost::program_options;

void check_argument(int argc, char** argv) {
	po::options_description desc("Allowed options");
	desc.add_options()
		("table", "Print the table")
		("max", po::value<int>(), "Set the maximum value")
		("level", po::value<int>(), "Set the level");
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);

	if(vm.count("max") && vm.count("level")){
		std::cerr << "Can't have max and level arguments at one time" << std::endl;
		exit(1);
	}

	if(vm.count("max")) {
		std::cout << "Maximum value set to: " << vm["max"].as<int>() << std::endl;
		max_value = vm["max"].as<int>();
	}

	if(vm.count("table")){
		showScoreMin();
		exit(0);
	}
	}