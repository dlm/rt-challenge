#ifndef _CSCI441_TUPLE_H_
#define _CSCI441_TUPLE_H_

#include <sstream>
#include <cmath>


class Tuple {
private:
    bool fp_eq(float a, float b, float eps=0.00001) const {
        return std::abs(a-b) < eps;
    }

public:
    union { float x; float r; };
    union { float y; float g; };
    union { float z; float b; };
    float w;

    Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

    static Tuple make_point(float x, float y, float z) {
        return Tuple(x, y, z, 1.0);
    }

    static Tuple make_vector(float x, float y, float z) {
        return Tuple(x, y, z, 0.0);
    }

    static Tuple make_color(float r, float g, float b) {
        return Tuple(r, g, b, 0.0);
    }

    bool is_point() const { return w == 1; }
    bool is_vector() const { return w == 0; }

    float dot(const Tuple& b) const {
        return x*b.x + y*b.y + z*b.z + w*b.w;
    }

    float magnitude() const {
        return std::sqrt(this->dot(*this));
    }

    Tuple normalize() const {
        return *this / magnitude();
    }

    Tuple cross(const Tuple& b) const {
        return Tuple::make_vector(
                y * b.z - z * b.y,
                z * b.x - x * b.z,
                x * b.y - y * b.x
        );
    }

    Tuple operator+(const Tuple& other) const {
        return Tuple(x+other.x, y+other.y, z+other.z, w+other.w);
    }

    Tuple operator-(const Tuple& other) const {
        return Tuple(x-other.x, y-other.y, z-other.z, w-other.w);
    }

    Tuple operator-() const {
        return Tuple(0,0,0,0) - *this;
    }

    Tuple operator*(float s) const {
        return Tuple(s*x,s*y,s*z,s*w);
    }

    Tuple operator*(const Tuple other) const {
        return make_color(r*other.r, g*other.g, b*other.b);
    }

    Tuple operator/(float s) const {
        return (*this) * (1/s);
    }

    bool operator==(const Tuple& other) const {
        return fp_eq(x, other.x)
            && fp_eq(y, other.y)
            && fp_eq(z, other.z)
            && fp_eq(w, other.w);
    }

    std::string to_string() const {
        std::ostringstream os;
        os << "(" << x << ", " << y << ", " << z << ", " << w << ")";
        return os.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const Tuple& t) {
        os << t.to_string();
        return os;
    }
};

typedef Tuple Point;
typedef Tuple Vector;
typedef Tuple Color;

#endif
