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
#include "types.hpp"
using namespace Geometry;


/**
 * @brief maps a value from range in_start...in_end to a corresponding value in the range of out_start..out_end
 * 
 * @param value current value
 * @param in_start input range minimum
 * @param in_end input range maximum
 * @param out_start output range minimum
 * @param out_end output range minimum
 * @return float 
 */
float map(float value, float in_start, float in_end, float out_start, float out_end);


/**
 * @brief basic linear interpolation
 * 
 * @param t between 0 and 1
 * @param a first point
 * @param b second point
 * @return Point 
 */
Point_T lerp(float t, Point_T a, Point_T b);


/**
 * @brief bezier interpolation
 * 
 * @param t between 0 and 1
 * @param start first point
 * @param end last point
 * @param middle center point
 * @return current point at time t
 */
Point_T bezier(float t, Point_T start, Point_T end, Point_T middle);

/**
 * @brief bezier interpolation
 * 
 * @param t between 0 and 1
 * @param start first point
 * @param end last point
 * @param a first point
 * @param b second point
 * @return current point at time t
 */
Point_T bezier(float t, Point_T start, Point_T end, Point_T a, Point_T b);
