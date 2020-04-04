#include "helpers.h"

Point point(float x, float y, float z) {
    return Tuple::make_point(x, y, z);
}

Vector vector(float x, float y, float z) {
    return Tuple::make_vector(x, y, z);
}

Color color(float r, float g, float b) {
    return Tuple::make_color(r, g, b);
}

