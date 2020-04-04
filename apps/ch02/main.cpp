#include <iostream>

#include <csci441/tuple.h>
#include <csci441/canvas.h>


struct Projectile {
    Point position;
    Vector velocity;

    Projectile(const Point& p, const Vector& v) : position(p), velocity(v) {}
};

struct Environment {
    Vector gravity;
    Vector wind;

    Environment(const Vector& g, const Vector& w) : gravity(g), wind(w) {}
};


Projectile tick(const Environment& env, const Projectile& proj) {
    Vector position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;
    return Projectile(position, velocity);
}

void draw_position(Canvas& canvas, const Projectile& p) {
    Color color = Tuple::make_color(1.0, 0, 0);
    canvas.set(p.position.x, canvas.height()-p.position.y, color);
}


int main() {
    Projectile p(
        Tuple::make_point(0, 1, 0),
        Tuple::make_vector(1, 1, 0).normalize() * 11.25
    );

    Environment e(
        Tuple::make_vector(0, -0.1, 0),
        Tuple::make_vector(-0.01, 0, 0)
    );

    Canvas c(1280, 768);

    int t = 0;
    draw_position(c, p);

    do {
        t++;
        p = tick(e, p);
        draw_position(c, p);
    } while (p.position.y > 0);

    std::cout << c.to_ppm();
}
