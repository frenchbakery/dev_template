/**
 * @file types.hpp
 * @author Nilusink
 * @version 0.1
 * @date 2023-02-01
 * 
 * @copyright Copyright FrenchBakery (c) 2023
 * 
 */
#include "types.hpp"
using namespace Geometry;


// private
void Vec2_T::recalculate(int from)
{
    switch (from)
    {
        case 0:  // from cartesian
        {
            l = sqrt(pow(p.x, 2) + pow(p.y, 2));
            d = tan(p.y / p.x);
            break;
        }

        case 1:  // from polar
        {
            p.x = l * sin(d);
            p.y = l * cos(d);
            break;
        }
    }
}


// public
Vec2_T::Vec2_T(float angle, float length)
    : d(angle), l(length)
{
    // recalculate x and y values
    recalculate(1);
}

Vec2_T::Vec2_T(const Point_T &c)
    : p(c)
{
    // recalculate length and angle
    recalculate(0);
}

Vec2_T::Vec2_T()
    : d(0), l(0)
{
    Point_T p;
    p.x = 0;
    p.y = 0;
};


// property getters and setters
float Vec2_T::length()
{
    return l;
}

void Vec2_T::setLength(float value)
{
    l = value;
    recalculate(1);
}


float Vec2_T::angle()
{
    return d;
}

void Vec2_T::setAngle(float value)
{
    d = value;
    recalculate(1);
}


const Point_T &Vec2_T::cartesian()
{
    return p;
}

void Vec2_T::setCartesian(Point_T value)
{
    p = value;
    recalculate(0);
}


float Vec2_T::x()
{
    return p.x;
}

void Vec2_T::setX(float value)
{
    p.x = value;
    recalculate(0);
}


float Vec2_T::y()
{
    return p.y;
}

void Vec2_T::setY(float value)
{
    p.y = value;
    recalculate(0);
}
