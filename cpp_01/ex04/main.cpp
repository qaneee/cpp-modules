#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong argument count!" << std::endl;
		return 1;
	}

	std::ifstream inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cerr << "Can't open input file!" << std::endl;
		return 1;
	}

	std::string new_file = std::string(argv[1]) + ".replace";
	std::ofstream outFile(new_file.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Can't open output file!" << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cerr << "s1 cannot be empty!" << std::endl;
		return 1;
	}

	std::string line;
	bool first = true;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;

		if (!first)
			outFile << "\n";
		first = false;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outFile << line;
	}

	inFile.close();
	outFile.close();
	return 0;
}