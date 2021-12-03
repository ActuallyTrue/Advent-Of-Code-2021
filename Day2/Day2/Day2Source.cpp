#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
	/////////////////Part 1//////////////////////////////////
	/*std::ifstream input ("input.txt");
	std::string line;
	int horizontal = 0;
	int depth = 0;

	if (input.is_open())
	{
		std::string direction;
		int decide;
		while (std::getline(input, line))
		{
			std::stringstream value(line);
			value >> direction;
			if (direction.compare("forward") == 0) {
				decide = 0;
			}

			if (direction.compare("down") == 0) {
				decide = 1;
			}

			if (direction.compare("up") == 0) {
				decide = 2;
			}
			int num;
			value >> num;
			
			switch (decide)
			{
			case 0:
				horizontal += num;
				break;
			case 1:
				depth += num;
				break;
			case 2:
				depth -= num;
				break;
			}
		}

		input.close();
		std::cout << horizontal * depth << "\n";
		std::cin.get();
	}
	else {
		std::cout << "Unable to open file...." << "\n";
	}*/

	/////////////////Part 2//////////////////////////////////
	std::ifstream input("input.txt");
	std::string line;
	int horizontal = 0;
	int depth = 0;
	int aim = 0;

	if (input.is_open())
	{
		std::string direction;
		int decide;
		while (std::getline(input, line))
		{
			std::stringstream value(line);
			value >> direction;
			if (direction.compare("forward") == 0) {
				decide = 0;
			}

			if (direction.compare("down") == 0) {
				decide = 1;
			}

			if (direction.compare("up") == 0) {
				decide = 2;
			}
			int num;
			value >> num;

			switch (decide)
			{
			case 0:
				horizontal += num;
				depth += num * aim;
				break;
			case 1:
				aim += num;
				break;
			case 2:
				aim -= num;
				break;
			}
		}

		input.close();
		std::cout << horizontal * depth << "\n";
		std::cin.get();
	}
	else {
		std::cout << "Unable to open file...." << "\n";
	}
	return 0;
}