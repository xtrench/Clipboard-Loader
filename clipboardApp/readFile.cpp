#include "readFile.h"


std::vector<std::string> GetDataFromFile(std::string fileName)
{
	std::vector<std::string> data;

	std::ifstream input(fileName);
	std::string line;
	if (input.is_open())
	{
		while (std::getline(input, line)) {
			data.push_back(line);
		}
		input.close();
	}
	else 
		std::cout << "Unable to open file \"data.txt\"";
	

	return data;
}