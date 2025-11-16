#pragma once
#include <raylib.h>
#include <iostream>
#include <cmath>
#include <vector>
//#include <array>
#include <random>
#include <stdint.h>
#include <chrono>
#include <charconv>
//#include <map>



namespace z {};
void SETUP();
void UPDATE();
void CLEAN();

#define drawer(bgColor)  do { \
    BeginDrawing(); \
    ClearBackground(bgColor); \
} while(0);

#define log std::cerr<<
#define zone namespace
#define foreach for
#define let decltype(auto)
#define Color3(r,g,b) Color(r,g,b,255)

#define try_static_assert(cond, msg)  \
    if (std::is_constant_evaluated()) \
    static_assert(cond, msg)

#define Do_Once(_stmt, _captures)  static auto block = []{ \
    _stmt;\
}();


// C/C++ types
using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;
using int128 = __int128;
//
using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;
using uint128 = unsigned __int128;
//
using f16 = _Float16;
using f32 = float;
using f64 = double;
using f80 = long double;
using f128 = __float128;
//
using uchar = unsigned char;
using byte = uint8;
using ternary = enum {no, yes=!no, neutral=!no&&!yes};
//
using std::string;
using Clock = std::chrono::high_resolution_clock;
template<class T> using Initlist = std::initializer_list<T>;


// Raylib types
using Vec2 = Vector2;
using Rect = Rectangle;
using Circle = struct{f32 x, y, r;};


// Custom structs
struct Uvec2 {
    uint i;
    uint j;

    Vec2 toVec2() {
        return {f32(i),f32(j)};
    }
};


// convert two <Vec2> to single <Rect> relevantly
inline Rect operator<=> (Vec2 pos, Vec2 size)
{
    return {pos.x, pos.y, size.x, size.y};
}

inline bool operator== (Vec2 first, Vec2 second)
{
    return (
        first.x==second.x && first.y==second.y
    );
}


