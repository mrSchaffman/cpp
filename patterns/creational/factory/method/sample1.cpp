/*
    this is only for demostration purpose
*/
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

namespace entity
{
    namespace graphic
    {

        enum class PointType
        {
            cartesian,
            polar
        };

        class Point
        {
            /*Point(float a, float b, PointType type = PointType::cartesian)
            {
            if (type == PointType::cartesian)
            {
            x = a; b = y;
            }
            else
            {
            x = a*cos(b);
            y = a*sin(b);
            }
            }*/

            Point(const float x, const float y)
                : x{x},
                  y{y}
            {
            }

        public:
            float x, y;

            friend std::ostream &operator<<(std::ostream &os, const Point &obj)
            {
                return os
                       << "x: " << obj.x
                       << " y: " << obj.y;
            }

            static Point NewCartesian(float x, float y)
            {
                return {x, y};
            }
            static Point NewPolar(float r, float theta)
            {
                return {r * cos(theta), r * sin(theta)};
            }
        };

    } // namespace 2d

} // namespace entity

int main()
{
    auto p = entity::graphic::Point::NewPolar(5, M_PI_4);
    std::cout << p << std::endl;

    return 0;
}