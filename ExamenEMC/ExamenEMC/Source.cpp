#include <iostream>
#include "../Logging/Logging1.h"
#include <string>
#include <fstream>

int main() {

	std::ofstream of("syslog.log", std::ios::app);
	Logger logger(of);
	logger.log("Started Application...", Logger::Level::Info);

	std::string str1= "jel";
	std::cout << "HEllp" << std::endl;
	std::cout << str1;

	system("pause");

	return 0;
}
