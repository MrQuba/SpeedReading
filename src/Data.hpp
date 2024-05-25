#include <iostream>
#pragma once

namespace string {
	typedef std::vector<std::string> vector;
}
namespace open {
	typedef std::ios_base::openmode mode;
	typedef std::ios_base type;
}
class Path {
public:
	Path(std::string path) : path(path){}
	std::string get() const { return this->path; }
private:
	std::string path;
};
template<typename T>
class Speed {
public:
	Speed(T speed) : speed(speed) {}
private:
	T speed;
};
namespace sfml {
	typedef sf::Uint32 Style;
	class VideoMode : sf::VideoMode {
	public:
		VideoMode(sf::Vector2i size) : mode(sf::VideoMode(size.x, size.y)) {}
		sf::VideoMode get() const { return this->mode; }
	private:
		sf::VideoMode mode;
	};
}