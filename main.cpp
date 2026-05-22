#include <iostream>
#include <vector>

// Підключення власних класів
#include "Vector.h"
#include "Logger.h"
#include "EncryptedFileManager.h"

// Дозволяє не писати std:: перед cout, vector тощо
using namespace std;

int main() {

    // Логування запуску програми
    Logger::log("Program started.");

    // STL-контейнер для збереження масиву об'єктів Vector
    vector<Vector> vectors;

    // Додавання елементів у контейнер
    vectors.push_back(Vector(2, 4));
    vectors.push_back(Vector(1, 2));
    vectors.push_back(Vector(3, -3));
    vectors.push_back(Vector(5, 0));

    cout << "All vectors:\n";

    // Вивід усіх векторів
    for (const Vector& vector : vectors) {
        cout << vector << endl;
    }

    // Створення двох окремих векторів
    Vector firstVector(2, 4);
    Vector secondVector(1, 2);

    cout << "\nVector 1: " << firstVector << endl;
    cout << "Vector 2: " << secondVector << endl;

    // Обчислення модуля вектора
    cout << "\nModulus of vector 1 = "
         << firstVector.calculateModulus()
         << endl;

    // Обчислення скалярного добутку
    cout << "Dot product = "
         << firstVector.calculateDotProduct(secondVector)
         << endl;

    // Додавання векторів
    Vector sumVector = firstVector.add(secondVector);

    cout << "Addition result = "
         << sumVector
         << endl;

    // Віднімання векторів
    Vector subtractVector = firstVector.subtract(secondVector);

    cout << "Subtraction result = "
         << subtractVector
         << endl;

    // Множення вектора на число
    Vector scaledVector = firstVector.multiplyByScalar(3);

    cout << "Multiplication by scalar = "
         << scaledVector
         << endl;

    // Перевірка на колінеарність
    if (firstVector.isCollinear(secondVector)) {
        cout << "Vectors are collinear." << endl;
    }
    else {
        cout << "Vectors are NOT collinear." << endl;
    }

    // Перевірка на ортогональність
    if (firstVector.isOrthogonal(secondVector)) {
        cout << "Vectors are orthogonal." << endl;
    }
    else {
        cout << "Vectors are NOT orthogonal." << endl;
    }

    // Запис усіх векторів у зашифрований файл
    EncryptedFileManager::saveVectorsToFile(
        vectors,
        "vectors.txt"
        );

    // Логування завершення програми
    Logger::log("Program finished.");

    cout<<endl;
    system("pause");

    return 0;
}
