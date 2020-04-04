#ifndef _CSCI441_CANVAS_H_
#define _CSCI441_CANVAS_H_

#include <cmath>
#include <sstream>
#include <csci441/tuple.h>

class Canvas {
private:
    std::vector< std::vector<Color> > data;

    static const int DEPTH = 255;

    float clamp(float c) const {
        return std::fmax(0, std::fmin(c, 1));
    }

    int to_color(float c) const {
        return std::ceil(DEPTH * clamp(c));
    }

public:
    Canvas(int width, int height) : data(height) {
        for (auto it = data.begin() ; it != data.end() ; ++it) {
            it->resize(width, Tuple::make_color(0,0,0));
        }
    }

    Color operator()(int col, int row) {
        return data[row][col];
    }

    int width() const {
        return data.front().size();
    }

    int height() const {
        return data.size();

    }

    void set(int col, int row, const Color& c) {
        data[row][col] = c;
    }

    Color at(int col, int row) const {
        return data[row][col];
    }

    std::string to_ppm() const {
        std::ostringstream os;
        os << "P3" << std::endl;
        os << width() << " " << height() << std::endl;
        os << DEPTH << std::endl;

        for (int row = 0 ; row < height() ; ++row) {
            for (int col = 0 ; col < width() ; ++col) {
                Color c = at(col, row);
                os << to_color(c.r) << " ";
                os << to_color(c.g) << " ";
                os << to_color(c.b) << ((col < width()-1) ? " " : "");
            }
            os << std::endl;
        }
        return os.str();
    }
};

#endif
