#include <catch2/catch.hpp>

#include <csci441/tuple.h>

Point point(float x, float y, float z) {
    return Tuple::make_point(x, y, z);
}

Vector vector(float x, float y, float z) {
    return Tuple::make_vector(x, y, z);
}

SCENARIO("A tuple with w=1.0 is a point", "") {
    GIVEN("a ← tuple(4.3, -4.2, 3.1, 1.0)") {
        Tuple a(4.3, -4.2, 3.1, 1.0);

        THEN("a.x = 4.3") { REQUIRE(a.x == Approx(4.3)); }
        AND_THEN("a.y = -4.2") { REQUIRE(a.y == Approx(-4.2)); }
        AND_THEN("a.z = 3.1") { REQUIRE(a.z == Approx(3.1)); }
        AND_THEN("a.w = 1.0") { REQUIRE(a.w == Approx(1.0)); }
        AND_THEN("a is a point") { REQUIRE(a.is_point()); }
        AND_THEN("a is not a vector") { REQUIRE(!a.is_vector()); }
    }
}


SCENARIO("A tuple with w=0 is a vector", "") {
    GIVEN("a ← tuple(4.3, -4.2, 3.1, 0.0)") {
        Tuple a(4.3, -4.2, 3.1, 0.0);

        THEN("a.x = 4.3") { REQUIRE(a.x == Approx(4.3)); }
        AND_THEN("a.y = -4.2") { REQUIRE(a.y == Approx(-4.2)); }
        AND_THEN("a.z = 3.1") { REQUIRE(a.z == Approx(3.1)); }
        AND_THEN("a.w = 0.0") { REQUIRE(a.w == Approx(0.0)); }
        AND_THEN("a is not a point") { REQUIRE(!a.is_point()); }
        AND_THEN("a is a vector") { REQUIRE(a.is_vector()); }
    }
}


SCENARIO("point() creates tuples with w=1", "") {
    GIVEN("p ← point(4, -4, 3)") {
        Point p = point(4, -4, 3);

        THEN("p = tuple(4, -4, 3, 1)") { REQUIRE(p == Tuple(4, -4, 3, 1)); }
    }
}


SCENARIO("point() creates tuples with w=0", "") {
    GIVEN("v ← vector(4, -4, 3)") {
        Vector v = vector(4, -4, 3);

        THEN("v = tuple(4, -4, 3, 0)") { REQUIRE(v == Tuple(4, -4, 3, 0)); }
    }
}



SCENARIO("Adding two tuples", "") {
    GIVEN("a1 ← tuple(3, -2, 5, 1) & a2 ← tuple(-2, 3, 1, 0)") {
        Tuple a1(3, -2, 5, 1);
        Tuple a2(-2, 3, 1, 0);

        THEN("a1 + a2 = tuple(1, 1, 6, 1)") {
            REQUIRE(a1 + a2 == Tuple(1, 1, 6, 1));
        }
    }
}


SCENARIO("Subtracting two points", "") {
    GIVEN("p1 ← point(3, 2, 1) & p2 ← point(5, 6, 7)") {
        Point p1 = point(3, 2, 1);
        Point p2 = point(5, 6, 7);

        THEN("p1 - p2 = vector(-2, -4, -6)") {
            REQUIRE(p1 - p2 == vector(-2, -4, -6));
        }
    }
}


SCENARIO("Subtracting a vector from a point", "") {
    GIVEN("p ← point(3, 2, 1) & v ← vector(5, 6, 7)") {
        Point p = point(3, 2, 1);
        Vector v = vector(5, 6, 7);

        THEN("p - v = point(-2, -4, -6)") {
            REQUIRE(p - v == point(-2, -4, -6));
        }
    }
}


SCENARIO("Subtracting two vectors", "") {
    GIVEN("v1 ← vector(3, 2, 1) & v2 ← vector(5, 6, 7)") {
        Vector v1 = vector(3, 2, 1);
        Vector v2 = vector(5, 6, 7);

        THEN("v1 - v2 = vector(-2, -4, -6)") {
            REQUIRE(v1 - v2 == vector(-2, -4, -6));
        }
    }
}


SCENARIO("Subtracting a vector from the zero vector") {
    GIVEN("zero ← vector(0, 0, 0) & v ← vector(1, -2, 3)") {
        Vector zero = vector(0, 0, 0);
        Vector v = vector(1, -2, 3);

        THEN("zero - v = vector(-1, 2, -3)") {
            REQUIRE(zero - v == vector(-1, 2, -3));
        }
    }
}


SCENARIO("Negating a tuple", "") {
    GIVEN("a ← tuple(1, -2, 3, -4)") {
        Tuple a(1, -2, 3, -4);

        THEN("-a = tuple(-1, 2, -3, 4)") {
            REQUIRE(-a == Tuple(-1, 2, -3, 4));
        }
    }
}


SCENARIO("Multiplying a tuple by a scalar", "") {
    GIVEN("a ← tuple(1, -2, 3, -4)") {
        Tuple a(1, -2, 3, -4);

        THEN("a * 3.5 = tuple(3.5, -7, 10.5, -14)") {
            REQUIRE(a * 3.5 == Tuple(3.5, -7, 10.5, -14));
        }
    }
}


SCENARIO("Multiplying a tuple by a fraction", "") {
    GIVEN("a ← tuple(1, -2, 3, -4)") {
        Tuple a(1, -2, 3, -4);

        THEN("a * 0.5 = tuple(0.5, -1, 1.5, -2)") {
            REQUIRE(a * 0.5 == Tuple(0.5, -1, 1.5, -2));
        }
    }
}


SCENARIO("Dividing a tuple by a scalar", "") {
    GIVEN("a ← tuple(1, -2, 3, -4)") {
        Tuple a(1, -2, 3, -4);

        THEN("a / 2 = tuple(0.5, -1, 1.5, -2)") {
            REQUIRE(a / 2 == Tuple(0.5, -1, 1.5, -2));
        }
    }
}


SCENARIO("Computing the magnitude of vector(1, 0, 0)", "") {
    GIVEN("v ← vector(1, 0, 0)") {
        Vector v = vector(1, 0, 0);

        THEN("magnitude(v) = 1") {
            REQUIRE(magnitude(v) == 1);
        }
    }
}


SCENARIO("Computing the magnitude of vector(0, 1, 0)", "") {
    GIVEN("v ← vector(0, 1, 0)") {
        Vector v = vector(0, 1, 0);

        THEN("magnitude(v) = 1") {
            REQUIRE(magnitude(v) == 1);
        }
    }
}


SCENARIO("Computing the magnitude of vector(0, 0, 1)", "") {
    GIVEN("v ← vector(0, 0, 1)") {
        Vector v = vector(0, 0, 1);

        THEN("magnitude(v) = 1") {
            REQUIRE(magnitude(v) == 1);
        }
    }
}


SCENARIO("Computing the magnitude of vector(1, 2, 3)", "") {
    GIVEN("v ← vector(1, 2, 3)") {
        Vector v = vector(1, 2, 3);

        THEN("magnitude(v) = √14") {
            REQUIRE(magnitude(v) == Approx(std::sqrt(14)));
        }
    }
}


SCENARIO("Computing the magnitude of vector(-1, -2, -3)", "") {
    GIVEN("v ← vector(-1, -2, -3)") {
        Vector v = vector(-1, -2, -3);

        THEN("magnitude(v) = √14") {
            REQUIRE(magnitude(v) == Approx(std::sqrt(14)));
        }
    }
}

SCENARIO("Normalizing vector(4, 0, 0) gives (1, 0, 0)", "") {
    GIVEN("v ← vector(4, 0, 0)") {
        Vector v = vector(4, 0, 0);

        THEN("normalize(v) = vector(1, 0, 0)") {
            REQUIRE(normalize(v) == vector(1, 0, 0));
        }
    }
}

SCENARIO("Normalizing vector(1, 2, 3)", "") {
    GIVEN("v ← vector(1, 2, 3)") {
        Vector v = vector(1, 2, 3);

        THEN("normalize(v) = approximately vector(0.26726, 0.53452, 0.80178)") {
            REQUIRE(normalize(v) == vector(0.26726, 0.53452, 0.80178));
        }
    }
}


SCENARIO("The magnitude of a normalized vector", "") {
    GIVEN("v ← vector(1, 2, 3)") {
        Vector v = vector(1, 2, 3);

        WHEN("norm ← normalize(v)") {
            Vector norm = normalize(v);

            THEN("magnitude(norm) = 1") {
                REQUIRE(magnitude(norm) == Approx(1));
            }
        }
    }
}


SCENARIO("The dot product of two tuples", "") {
    GIVEN("a ← vector(1, 2, 3) & b ← vector(2, 3, 4)") {
        Vector a = vector(1, 2, 3);
        Vector b = vector(2, 3, 4);

        THEN("dot(a, b) = 20") {
            REQUIRE(dot(a, b) == Approx(20));
        }
    }
}

SCENARIO("The cross product of two vectors", "") {
    GIVEN("a ← vector(1, 2, 3) & b ← vector(2, 3, 4)") {
        Vector a = vector(1, 2, 3);
        Vector b = vector(2, 3, 4);

        THEN("cross(a, b) = vector(-1, 2, -1)") {
            REQUIRE(cross(a, b) == vector(-1, 2, -1));
        }
        AND_THEN("cross(b, a) = vector(1, -2, 1)") {
            REQUIRE(cross(b, a) == vector(1, -2, 1));
        }
    }
}


// Scenario: Colors are (red, green, blue) tuples
//   Given c ← color(-0.5, 0.4, 1.7)
//   Then c.red = -0.5
//     And c.green = 0.4
//     And c.blue = 1.7
//
// Scenario: Adding colors
//   Given c1 ← color(0.9, 0.6, 0.75)
//     And c2 ← color(0.7, 0.1, 0.25)
//    Then c1 + c2 = color(1.6, 0.7, 1.0)
//
// Scenario: Subtracting colors
//   Given c1 ← color(0.9, 0.6, 0.75)
//     And c2 ← color(0.7, 0.1, 0.25)
//    Then c1 - c2 = color(0.2, 0.5, 0.5)
//
// Scenario: Multiplying a color by a scalar
//   Given c ← color(0.2, 0.3, 0.4)
//   Then c * 2 = color(0.4, 0.6, 0.8)
//
// Scenario: Multiplying colors
//   Given c1 ← color(1, 0.2, 0.4)
//     And c2 ← color(0.9, 1, 0.1)
//    Then c1 * c2 = color(0.9, 0.2, 0.04)
//
// Scenario: Reflecting a vector approaching at 45°
//   Given v ← vector(1, -1, 0)
//     And n ← vector(0, 1, 0)
//   When r ← reflect(v, n)
//   Then r = vector(1, 1, 0)
//
// Scenario: Reflecting a vector off a slanted surface
//   Given v ← vector(0, -1, 0)
//     And n ← vector(√2/2, √2/2, 0)
//   When r ← reflect(v, n)
//   Then r = vector(1, 0, 0)
