#include <fstream>
#include <vector>
#include "Data.hpp"
#pragma once
class File {
public:
	File(Path path,  open::mode m) {
		file.open(path.get(), m);
		initVector();
		iterator = words.begin();
	}
	string::vector::iterator advanceIterator() { iterator++; return iterator; }
	std::string getWord() { return *iterator; }
	string::vector getWords() { return words; }
	bool hasVectorEnded() { return iterator == words.end(); }
	void displayVector() {
		std::cout << "Vector elements: ";
		for (const auto& element : words) {
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}
	~File() { file.close(); }
private:
	std::fstream file;
	string::vector words;
	string::vector::iterator iterator;
	void initVector() {
		std::string line;
		while (std::getline(file, line)) {
			std::string word = "";
			for (char c : line) {
				if (c == ' ' || c == '\n' || c == '\r') {
					words.push_back(word);
					word = "";
				} else
				word += c;
			}
		}
	}
};
