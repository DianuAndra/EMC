#include "Logging1.h"

const char* LogLevelToString(Logger::Level level)
{
	switch (level)
	{
	case Logger::Level::Info:
		return "Info";
	case Logger::Level::Warning:
		return "Warning";
	case Logger::Level::Error:
		return "Error";
	default:
		return "";
	}
}

Logger::Logger(std::ostream & os, Logger::Level minimumLevel) :
	os{ os },
	minimumLevel{ minimumLevel }
{
	// Empty
}

void Logger::log(const char * message, Level level)
{
	if (static_cast<int>(level) < static_cast<int>(minimumLevel))
		return;

	os << "[" << LogLevelToString(level) << "] " << message << std::endl;
}

void Logger::log(const std::string & message, Level level)
{
	this->log(message.c_str(), level);
}

void Logger::setMinimumLogLevel(Level level)
{
	this->minimumLevel = level;
}


