#include <iostream>
#include <chrono>
#include "Converter.h"

int main(int argc, char **argv)
{
	std::cout << "Reveares' Waypoint Converter" << std::endl << std::endl;

	if (argc != 3)
	{
		std::cerr << "2 Arguments are needed!" << std::endl << "first: path/to/file.zen" << std::endl << "second: filename.wp" << std::endl;
		return -1;
	}

	auto start = std::chrono::high_resolution_clock::now();

	Converter converter;
	converter.read(argv[1]);
	converter.write(argv[2]);

	auto end = std::chrono::high_resolution_clock::now();
	std::cout << "Which took " << std::chrono::duration<double>(end - start).count() << " seconds." << std::endl;

	return 0;
}
