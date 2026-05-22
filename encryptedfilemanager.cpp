#include "EncryptedFileManager.h"
#include "Logger.h"

#include <fstream>

using namespace std;

// Метод шифрування рядка
string EncryptedFileManager::encrypt(const string& text) {

    // Копія вхідного рядка
    string encryptedText = text;

    // Просте Caesar-like шифрування
    // Кожен символ зміщується на +3 в ASCII
    for (char& character : encryptedText) {
        character += 3;
    }

    return encryptedText;
}

void EncryptedFileManager::saveVectorsToFile(
    const vector<Vector>& vectors,
    const string& fileName) {

    // Відкриття файлу для запису
    ofstream outFile(fileName);

    // Перебір усіх векторів у контейнері
    for (const Vector& vector : vectors) {

        // Перетворення об'єкта у рядок
        string data = vector.toString();

        // Запис зашифрованого рядка у файл
        outFile << encrypt(data) << endl;
    }

    // Логування завершення запису
    Logger::log("Vectors were saved to encrypted file.");
}
