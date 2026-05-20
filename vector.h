#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

class Vector {
private:
    double m_x;
    double m_y;

public:
    Vector();
    Vector(double x, double y);
    Vector(const Vector& other);

    void setX(double x);
    void setY(double y);

    double getX() const;
    double getY() const;

    double calculateModulus() const;
    double calculateDotProduct(const Vector& other) const;

    Vector add(const Vector& other) const;
    Vector subtract(const Vector& other) const;
    Vector multiplyByScalar(double scalar) const;

    bool isCollinear(const Vector& other) const;
    bool isOrthogonal(const Vector& other) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
};

#endif
