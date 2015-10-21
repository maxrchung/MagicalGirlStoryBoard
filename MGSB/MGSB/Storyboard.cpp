#include "Storyboard.hpp"
#include <iostream>
#include <fstream>
#include <stddef.h>

Storyboard* Storyboard::instance = NULL;

Storyboard* Storyboard::Instance() {
	if (!instance) {
		instance = new Storyboard;
	}
	return instance;
}

void Storyboard::Write(std::string destinationPath) {
	std::cout << destinationPath << std::endl;
	std::ofstream outputFile;
	outputFile.open(destinationPath);

	outputFile << "[Events]" << std::endl;
	for (auto sprite : sprites) {
		outputFile << sprite.Write();
	}
	outputFile.close();
}