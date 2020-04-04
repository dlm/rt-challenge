#include <catch2/catch.hpp>

#include <csci441/canvas.h>

#include "helpers.h"


SCENARIO("Creating a canvas", "") {
    GIVEN("c ← canvas(10, 20)") {
        Canvas c = Canvas(10, 20);

        THEN("c.width = 10") { REQUIRE(c.width() == 10); }
        AND_THEN("c.height = 20") { REQUIRE(c.height() == 20); }
        AND_THEN("every pixel of c is color(0, 0, 0)") {
            for (int row = 0 ; row < c.height() ; ++row) {
                for (int col = 0 ; col < c.width() ; ++col) {
                    REQUIRE(c(col, row) == color(0, 0, 0));
                }
            }
        }
    }
}


SCENARIO("Writing pixels to a canvas") {
    GIVEN("c ← canvas(10, 20) & red ← color(1, 0, 0)") {
        Canvas c(10, 20);
        Color red = color(1, 0, 0);

        WHEN("write_pixel(c, 2, 3, red)") {
            c.set(2, 3, red);

            THEN("pixel_at(c, 2, 3) = red") {
                REQUIRE(c.at(2, 3) == red);
            }
        }
    }
}



SCENARIO("Constructing the PPM pixel data", "") {
    GIVEN("c ← canvas(5, 3) & c1 ← color(1.5, 0, 0) & c2 ← color(0, 0.5, 0) & c3 ← color(-0.5, 0, 1)") {
        Canvas c(5, 3);
        Color c1 = color(1.5, 0, 0);
        Color c2 = color(0, 0.5, 0);
        Color c3 = color(-0.5, 0, 1);

        WHEN("write pixels") {
            c.set(0, 0, c1);
            c.set(2, 1, c2);
            c.set(4, 2, c3);

            THEN("lines ppm are as expected") {
                std::string ppm = c.to_ppm();
                std::string expected = "P3\n5 3\n255\n255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
                REQUIRE(ppm == expected);
            }
        }
    }
}


SCENARIO("Splitting long lines in PPM files", "") {
    GIVEN("c ← canvas(10, 2)") {
        Canvas c(10, 2);
        WHEN("every pixel of c is set to color(1, 0.8, 0.6) & ppm ← canvas_to_ppm(c)") {
            for (int row = 0 ; row < c.height() ; ++row) {
                for (int col = 0 ; col < c.width() ; ++col) {
                    c.set(col, row, color(1, 0.8, 0.6));
                }
            }

            THEN("lines ppm are as expected") {
                std::string expected = "P3\n10 2\n255\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n";
                std::string ppm = c.to_ppm();
                REQUIRE(ppm == expected);
            }
        }
    }
}


SCENARIO("PPM files are terminated by a newline character", "") {
    GIVEN("c ← canvas(5, 3)") {
        Canvas c(5, 3);

        WHEN("ppm ← canvas_to_ppm(c)") {
            std::string ppm = c.to_ppm();

            THEN("Then ppm ends with a newline character") {
                char last = ppm.back();
                REQUIRE(last == '\n');
            }
        }
    }
}
