#include <iostream>
#include <vector>

#include "Vector.h"
#include "Logger.h"
#include "EncryptedFileManager.h"

int main() {

    Logger::log("Program started.");

    // Array of objects
    std::vector<Vector> vectors;

    vectors.push_back(Vector(2, 4));
    vectors.push_back(Vector(1, 2));
    vectors.push_back(Vector(3, -3));
    vectors.push_back(Vector(5, 0));

    std::cout << "All vectors:\n";

    for (const Vector& vector : vectors) {
        std::cout << vector << std::endl;
    }

    Vector firstVector(2, 4);
    Vector secondVector(1, 2);

    std::cout << "\nVector 1: " << firstVector << std::endl;
    std::cout << "Vector 2: " << secondVector << std::endl;

    std::cout << "\nModulus of vector 1 = "
              << firstVector.calculateModulus()
              << std::endl;

    std::cout << "Dot product = "
              << firstVector.calculateDotProduct(secondVector)
              << std::endl;

    Vector sumVector = firstVector.add(secondVector);

    std::cout << "Addition result = "
              << sumVector
              << std::endl;

    Vector subtractVector = firstVector.subtract(secondVector);

    std::cout << "Subtraction result = "
              << subtractVector
              << std::endl;

    Vector scaledVector = firstVector.multiplyByScalar(3);

    std::cout << "Multiplication by scalar = "
              << scaledVector
              << std::endl;

    if (firstVector.isCollinear(secondVector)) {
        std::cout << "Vectors are collinear." << std::endl;
    }
    else {
        std::cout << "Vectors are NOT collinear." << std::endl;
    }

    if (firstVector.isOrthogonal(secondVector)) {
        std::cout << "Vectors are orthogonal." << std::endl;
    }
    else {
        std::cout << "Vectors are NOT orthogonal." << std::endl;
    }

    EncryptedFileManager::saveVectorsToFile(
        vectors,
        "vectors.txt"
        );

    Logger::log("Program finished.");

    system("pause");

    return 0;
}
