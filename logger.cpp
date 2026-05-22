#include "Logger.h"

#include <fstream>
#include <ctime>

using namespace std;

void Logger::log(const string& message) {

    // ios::app означає режим "append"
    // Нові записи додаються в кінець файлу,
    // а не перезаписують його повністю
    ofstream logFile("log.txt", ios::app);

    // Отримання поточного часу системи
    time_t currentTime = time(nullptr);

    // ctime() перетворює час у текстовий формат
    logFile << ctime(&currentTime)
            << " -> "
            << message
            << endl;
}
