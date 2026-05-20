#ifndef ENCRYPTED_FILE_MANAGER_H
#define ENCRYPTED_FILE_MANAGER_H

#include <string>
#include <vector>
#include "Vector.h"

class EncryptedFileManager {
private:
    static std::string encrypt(const std::string& text);

public:
    static void saveVectorsToFile(const std::vector<Vector>& vectors,
                                  const std::string& fileName);
};

#endif
