#ifndef _CSCI441_CANVAS_H_
#define _CSCI441_CANVAS_H_

#include <cmath>
#include <sstream>
#include <regex>

#include <csci441/tuple.h>

class Canvas {
private:
    std::vector< std::vector<Color> > data;

    static const int DEPTH = 255;

    float clamp(float c) const {
        return std::fmax(0, std::fmin(c, 1));
    }

    int to_target(float c) const {
        return std::ceil(DEPTH * clamp(c));
    }

    std::string rtrim(const std::string& s) const {
        return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
    }

    void flush(std::ostringstream& os, std::ostringstream& buffer) const {
        os << rtrim(buffer.str()) << std::endl;
    }

    void write(std::ostringstream& os, std::ostringstream& buffer, float component) const {
        const int LINELEN = 70;
        if (buffer.str().size() > LINELEN-3) {
            flush(os, buffer);

            buffer.str("");
            buffer.clear();
        }
        buffer << to_target(component) << " ";
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
        if (0 <= col && col < width() && 0 <= row && row <= height()) {
            data[row][col] = c;
        }
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
            std::ostringstream buffer;
            for (int col = 0 ; col < width() ; ++col) {
                Color c = at(col, row);
                write(os, buffer, c.r);
                write(os, buffer, c.g);
                write(os, buffer, c.b);
            }
            flush(os, buffer);
        }
        return os.str();
    }
};

#endif
