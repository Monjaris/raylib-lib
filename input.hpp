#pragma once
#include "core.h"

inline bool hasKeyPressed(int key)
{
    return (
        IsKeyPressed(key) || IsKeyPressedRepeat(key)
    );
}

inline bool onClickedCircleReleased(Vec2 pos, Vec2 center, f32 rad)
{
    static bool pressed_circle = false;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&CheckCollisionPointCircle(pos, center, rad))
    {
        pressed_circle = true;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && pressed_circle)
    {
        pressed_circle = false;
        return true;
    }

    return false;
}
