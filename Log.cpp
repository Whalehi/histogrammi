#include "Log.h"

Logger::Logger(){};

void Logger::log(const std::string &message)
{
    std::cout << message << std::endl;
}