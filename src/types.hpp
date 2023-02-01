/**
 * @file types.hpp
 * @author Nilusink
 * @brief contains a few useful types
 * @version 0.1
 * @date 2023-02-01
 * 
 * @copyright Copyright FrenchBakery (c) 2023
 * 
 */
#include <cmath>


namespace Geometry
{
    /**
     * @brief a simple two dimensional point containing a x and a y value
     * 
     */
    struct Point_T
    {
        float x;
        float y;
    };

    /**
     * @brief simple two dimensional vector class
     */
    class Vec2_T
    {
        private:
            float d;
            float l;
        
            Point_T p;

        void recalculate(int from);

        public:
            Vec2_T(float angle, float length);
            Vec2_T(const Point_T &c);
            Vec2_T();

            // polar stuff
            float length();
            void setLength(float value);

            float angle();
            void setAngle(float value);

            // cartesian stuff
            /**
             * @brief get the cartesian form of the vector (x and y)
             * 
             * @return Point 
             */
            const Point_T &cartesian();

            /**
             * @brief set the cartesian form of the vector (x, y)
             */
            void setCartesian(Point_T value);

            float x();
            void setX(float value);

            float y();
            void setY(float value);
    };
}
