#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {

  public:
    Ball(Velocity& velocity, Point& center, double radius, const Color& color)
        : velocity(velocity), center(center), radius(radius), color(color) {}

  private:
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;

    Velocity& velocity;
    Point& center;
    double radius;
    double mass = 3.14 * std::pow(radius,3) * 4. /3;
    Color color;
};
