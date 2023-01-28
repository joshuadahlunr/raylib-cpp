#ifndef RAYLIB_CPP_INCLUDE_RADIANS_DEGREES_HPP_
#define RAYLIB_CPP_INCLUDE_RADIANS_DEGREES_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./raymath.hpp"

#ifndef RAYLIB_CPP_NO_MATH
#include <cmath>
#endif

namespace raylib {
    class Degree;

    /**
     * Radian type (allows automatic worry free conversion between radians and degrees)
     */
    class Radian {
        float value;
    public:
        Radian(float radian) : value(radian) {}
        Radian(const Degree d); 

        operator float() const { return value; }
    };

    /**
     * Degree type (allows automatic worry free conversion between radians and degrees)
     */
    class Degree {
        float value;
    public:
        Degree(float degree) : value(degree) {}
        Degree(const Radian r) : Degree(float(r) * RAD2DEG) {}

        operator float() const { return value; }

        float RadianValue() { return Radian(*this); }
    };

    inline Radian::Radian(const Degree d) : Radian(float(d) * DEG2RAD) {}
}

#endif // RAYLIB_CPP_INCLUDE_RADIANS_DEGREES_HPP_