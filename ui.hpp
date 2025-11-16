#pragma once
#include "core.h"

#define CIRCLE_SEGMENTS 10000

// -- Helper functions --

inline Rect bodyToBorders(Rect body, f32 ofx, f32 ofy)
{
    return {
        body.x - ofx, body.y - ofy,
        body.width  + 2 * ofx,
        body.height + 2 * ofy
    };
}

inline Rect bodyToBorders(Rect body, f32 offs)
{
    return {
        body.x - offs, body.y - offs,
        body.width  + 2 * offs,
        body.height + 2 * offs
    };
}

// -- gfx zone (assuming macro expands to namespace gfx) --

zone gfx
{
    inline void rect(Vec2 pos, Vec2 size, Color color = WHITE, f32 roundness_percent = 0.f)
    {
        DrawRectangleRounded({pos.x, pos.y, size.x, size.y}, roundness_percent / 100.0f, CIRCLE_SEGMENTS, color);
    }

    inline void rect(Rect rec, Color color = WHITE, f32 roundness_percent = 0.f)
    {
        DrawRectangleRounded(rec, roundness_percent / 100.0f, CIRCLE_SEGMENTS, color);
    }
}


