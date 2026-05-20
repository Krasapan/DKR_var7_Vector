#include "Vector.h"
#include <cmath>
#include <sstream>

Vector::Vector() : m_x(0), m_y(0) {}

Vector::Vector(double x, double y) : m_x(x), m_y(y) {}

Vector::Vector(const Vector& other) {
    m_x = other.m_x;
    m_y = other.m_y;
}

void Vector::setX(double x) {
    m_x = x;
}

void Vector::setY(double y) {
    m_y = y;
}

double Vector::getX() const {
    return m_x;
}

double Vector::getY() const {
    return m_y;
}

double Vector::calculateModulus() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

double Vector::calculateDotProduct(const Vector& other) const {
    return m_x * other.m_x + m_y * other.m_y;
}

Vector Vector::add(const Vector& other) const {
    return Vector(m_x + other.m_x, m_y + other.m_y);
}

Vector Vector::subtract(const Vector& other) const {
    return Vector(m_x - other.m_x, m_y - other.m_y);
}

Vector Vector::multiplyByScalar(double scalar) const {
    return Vector(m_x * scalar, m_y * scalar);
}

bool Vector::isCollinear(const Vector& other) const {
    return (m_x * other.m_y - m_y * other.m_x) == 0;
}

bool Vector::isOrthogonal(const Vector& other) const {
    return calculateDotProduct(other) == 0;
}

std::string Vector::toString() const {
    std::stringstream ss;
    ss << "(" << m_x << ", " << m_y << ")";
    return ss.str();
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    out << vector.toString();
    return out;
}
