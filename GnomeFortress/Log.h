#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>

class Log {
public:
	static void write(const std::string& str);
	static void init();
private:
	static std::ofstream _log;
};

#endif
