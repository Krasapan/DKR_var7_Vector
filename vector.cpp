#include "Vector.h"

#include <cmath>
#include <sstream>

using namespace std;

// Конструктор за замовчуванням
Vector::Vector() : m_x(0), m_y(0) {}

// Конструктор з параметрами
Vector::Vector(double x, double y) : m_x(x), m_y(y) {}

// Конструктор копіювання
Vector::Vector(const Vector& other) {
    m_x = other.m_x;
    m_y = other.m_y;
}

// Setter для X
void Vector::setX(double x) {
    m_x = x;
}

// Setter для Y
void Vector::setY(double y) {
    m_y = y;
}

// Getter для X
double Vector::getX() const {
    return m_x;
}

// Getter для Y
double Vector::getY() const {
    return m_y;
}

// Обчислення модуля вектора
double Vector::calculateModulus() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

// Обчислення скалярного добутку
double Vector::calculateDotProduct(const Vector& other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

// Додавання двох векторів
Vector Vector::add(const Vector& other) const {
    return Vector(m_x + other.m_x, m_y + other.m_y);
}

// Віднімання двох векторів
Vector Vector::subtract(const Vector& other) const {
    return Vector(m_x - other.m_x, m_y - other.m_y);
}

// Множення вектора на число
Vector Vector::multiplyByScalar(double scalar) const {
    return Vector(m_x * scalar, m_y * scalar);
}

// Перевірка на колінеарність
// Якщо визначник дорівнює 0 — вектори колінеарні
bool Vector::isCollinear(const Vector& other) const {
    return (m_x * other.m_y - m_y * other.m_x) == 0;
}

// Перевірка на ортогональність
// Якщо скалярний добуток дорівнює 0 — вектори ортогональні
bool Vector::isOrthogonal(const Vector& other) const {
    return calculateDotProduct(other) == 0;
}

// Перетворення об'єкта Vector у рядок
string Vector::toString() const {

    // stringstream дозволяє формувати рядок як потік
    stringstream ss;

    ss << "(" << m_x << ", " << m_y << ")";

    return ss.str();
}

// Перевантаження оператора <<
// Дає можливість виводити об'єкт через cout
ostream& operator<<(ostream& out, const Vector& vector) {

    out << vector.toString();

    return out;
}
