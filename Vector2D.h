#ifndef __Vector2D__
#define __Vector2D__
#include <math.h>

class Vector2D
{
private:
    float x, y;

public:
    // constructor that sets the x and y values based on the given values
    Vector2D(float fx, float fy) : x(fx), y(fy) {}

    // getter functions for x and y values
    float getX() { return x; }
    float getY() { return y; }

    // setter functions for the x and y values
    void setX(float sx) { x = sx; }
    void setY(float sy) { y = sy; }

    // lengthofv(x,y) =  (x^2 + y^2)^(1/2)
    float length() { return sqrt((x * x) + (y * y)); }

    // Addition of a vector
    // v3 = v1 + v2 = (x1,y1) + (x2 + y2) = (x1 + x2, y1 + y2)
    // Addition of two vectors, using operator overloading
    // returns a new vector
    Vector2D operator+(const Vector2D &v2) const
    {
        return Vector2D(x + v2.x, y + v2.y);
    }
    // adds in the first vector
    friend Vector2D &operator+=(Vector2D &v1, const Vector2D &v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }

    // Multiplication of vector by a scalar number
    // v1 * n = (x1 * n, y1 * n)
    // returns a new vector multiplied by the n number
    Vector2D operator*(float scalar)
    {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D &operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // Subtraction of a Vector
    // v3 = v1 - v2, (x1, y1) - (x2, y2) = (x1 - x2, y1 - y2)
    // Subtraction of two vectors, using operator overloading
    // returns a new vector
    Vector2D operator-(const Vector2D &v2) const
    {
        return Vector2D(x - v2.x, y - v2.y);
    }
    // Subtracts and assign to the first vector
    friend Vector2D &operator-=(Vector2D &v1, const Vector2D &v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }

    // Division of a vector
    // v1 / n = (x1 / n, y / n)
    Vector2D operator/(float scalar)
    {
        return Vector2D(x / scalar, y / scalar);
    }
    Vector2D &operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // Normalization of a vector, it means that making the length of the vector equals to 1
    // Unit vectors are helpful to represent the direction
    // To normalize a vector we multiply it by the inverse of its length.
    // L = length, Vnorm = V * (1/L)
    void normalize()
    {
        float l = length();
        if (l > 0) // we never want to attempt to divide by 0
        {
            // both x and y values
            (*this) *= 1 / l;
        }
    }
};

#endif