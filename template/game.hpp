#pragma once
#include "../lib/core.h"

inline zone SETTINGS
{
    constexpr f32 init_win_w = 1280;
    constexpr f32 init_win_h = 720;

    inline Color bgColor = { 0, 0, 0, 255 };
    inline f32 maxFPS = 120;
    inline bool capFPS = false;
    inline int err_state;

    inline f32 win_w;
    inline f32 win_h;
    inline f32 fps;
    inline f32 dt;
}
