#include <iostream>

#include <csci441/tuple.h>


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

void output_position(int t, const Projectile& p) {
    std::cout << t << ": " << p.position << std::endl;
}


int main() {
    Projectile p(
        Tuple::make_point(0, 1, 0),
        normalize(Tuple::make_vector(1, 1, 0))
    );

    Environment e(
        Tuple::make_vector(0, -0.1, 0),
        Tuple::make_vector(-0.01, 0, 0)
    );

    int t = 0;
    output_position(t, p);

    do {
        t++;
        p = tick(e, p);
        output_position(t, p);
    } while (p.position.y > 0);
}
