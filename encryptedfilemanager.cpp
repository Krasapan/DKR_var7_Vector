#include "EncryptedFileManager.h"
#include "Logger.h"

#include <fstream>

std::string EncryptedFileManager::encrypt(const std::string& text) {
    std::string encryptedText = text;

    for (char& character : encryptedText) {
        character += 3;
    }

    return encryptedText;
}

void EncryptedFileManager::saveVectorsToFile(
    const std::vector<Vector>& vectors,
    const std::string& fileName) {

    std::ofstream outFile(fileName);

    for (const Vector& vector : vectors) {
        std::string data = vector.toString();
        outFile << encrypt(data) << std::endl;
    }

    Logger::log("Vectors were saved to encrypted file.");
}
