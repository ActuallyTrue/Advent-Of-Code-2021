#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
	/*/////////////////Part 1//////////////////////////////////
	std::ifstream input ("input.txt");
	std::string line;
	int count = 0;

	if (input.is_open())
	{
		std::getline(input, line);

		std::stringstream value(line);

		int previous = 0;
		value >> previous;
		int current;
		
		while (std::getline(input, line))
		{
			std::stringstream currentValue(line);
			currentValue >> current;
			//std::cout << current << "\n";
			if (current > previous) {
				count++;
			}
			previous = current;
		}

		input.close();
		std::cout << count << "\n";
		std::cin.get();
	}
	else {
		std::cout << "Unable to open file...." << "\n";
	}*/

	//////////////////////Part 2///////////////////////////////
	std::ifstream input("input.txt");
	std::string line;
	int count = 0;

	if (input.is_open())
	{
		int lastThree[3];

		std::getline(input, line);

		std::stringstream value(line);
		int holder;
		value >> holder;
		lastThree[0] = holder;

		std::getline(input, line);
		value.clear();
		value.str(line);

		value >> holder;
		lastThree[1] = holder;

		std::getline(input, line);
		value.clear();
		value.str(line);

		value >> holder;
		lastThree[2] = holder;

		while (std::getline(input, line))
		{
			int sum1 = 0;
			for (int i = 0; i < 3; i++) {
				sum1 += lastThree[i];
			}
			int sum2 = sum1 - lastThree[0];

			value.str(line);
			value >> holder;
			/*std::cout << holder << "\n";*/
			sum2 += holder;
			
			if (sum2 > sum1) {
				count++;
			}
			lastThree[0] = lastThree[1];
			lastThree[1] = lastThree[2];
			lastThree[2] = holder;
			value.clear();
		}

		input.close();
		std::cout << count << "\n";
		std::cin.get();
	}
	else {
		std::cout << "Unable to open file...." << "\n";
	}

	return 0;
}