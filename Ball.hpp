#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"
#include "cmath"

class Ball {
public:
    Ball(Velocity &velocity, Point &center, double radius, const Color &color)
        : _velocity(velocity), _center(center), _radius(radius), _color(color) {
    }

    void setVelocity(const Velocity &velocity);

    Velocity getVelocity() const;

    void draw(Painter &painter) const;

    void setCenter(const Point &center);

    Point getCenter() const;

    double getRadius() const;

    double getMass() const;

private:
    Velocity _velocity;
    Point _center;
    double _radius;
    double _mass = 3.14 * pow(_radius, 3.0) * 4. / 3;
    Color _color;
};
