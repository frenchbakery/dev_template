/**
 * @file utils.hpp
 * @author Nilusink
 * @brief A few useful function, mosly for numerical interpolation
 * @version 0.1
 * @date 2023-02-01
 * 
 * @copyright Copyright FrenchBakery (c) 2023
 * 
 */
#include "utils.hpp"


float map(float x, float in_min, float in_max, float out_min, float out_max)
{
    // magic
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


Point_T lerp(float t, Point_T a, Point_T b)
{
    Point_T out;
    out.x = t * (a.x - b.x) + a.x;
    out.y = t * (a.y - b.y) + a.y;

    return out;
}


Point_T bezier(float t, Point_T start, Point_T end, Point_T middle)
{
    // calculate first pair of points
    Point_T sm = lerp(t, start, middle);
    Point_T me = lerp(t, middle, end);
    
    // calculate final point
    return lerp(t, sm, me);
}

Point_T bezier(float t, Point_T start, Point_T end, Point_T a, Point_T b)
{
    // calculate first three points
    Point_T sa = lerp(t, start, a);
    Point_T ab = lerp(t, a, b);
    Point_T be = lerp(t, b, end);

    // calculate second two points
    Point_T sa_ab = lerp(t, sa, ab);
    Point_T ab_be = lerp(t, ab, be);

    // calculate final point
    return lerp(t, sa_ab, ab_be);
}
