#include "Log.h"

std::ofstream Log::_log("log.txt", std::ios::out | std::ios::app);

void Log::write(const std::string& str) {
	_log << "[LOG] " << str << "\n";
}

void Log::init() {
	const std::string path = "log.txt";
	std::ifstream f(path);
	if (f.good())
		std::remove(path.c_str());

	std::ofstream log(path);
	log.close();
}
