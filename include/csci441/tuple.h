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
    float x, y, z, w;

    Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

    static Tuple make_point(float x, float y, float z) {
        return Tuple(x, y, z, 1.0);
    }

    static Tuple make_vector(float x, float y, float z) {
        return Tuple(x, y, z, 0.0);
    }

    bool is_point() const { return w == 1; }
    bool is_vector() const { return w == 0; }

    Tuple operator+(const Tuple& other) const {
        return Tuple(x+other.x, y+other.y, z+other.z, w+other.w);
    }

    Tuple operator-(const Tuple& other) const {
        return Tuple(x-other.x, y-other.y, z-other.z, w-other.w);
    }

    Tuple operator-() const {
        return Tuple(0,0,0,0) - *this;
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


#endif
