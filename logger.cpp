#include "Logger.h"
#include <fstream>
#include <ctime>

void Logger::log(const std::string& message) {
    std::ofstream logFile("log.txt", std::ios::app);

    time_t currentTime = time(nullptr);

    logFile << ctime(&currentTime)
            << " -> "
            << message
            << std::endl;
}
