#ifndef _CSCI441_TUPLE_H_
#define _CSCI441_TUPLE_H_

#include <sstream>

class Tuple {
public:
    float x, y, z, w;

    Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

    static Tuple make_point(float x, float y, float z) {
        return Tuple(x, y, z, 1.0);
    }

    static Tuple make_vector(float x, float y, float z) {
        return Tuple(x, y, z, 0.0);
    }

    bool is_point() const { return !is_vector(); }
    bool is_vector() const { return w == 0; }

    bool operator==(const Tuple& other) const {
        return x == other.x
            && y == other.y
            && z == other.z
            && w == other.w;
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


template <typename Stringable>
std::ostream& operator<<(std::ostream& os, const Stringable& s) {
    os << s.to_string();
    return os;
}

#endif
