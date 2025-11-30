#pragma once
#include "core.h"

#define CIRCLE_SEGMENTS 10000

//*  Helper functions  *//

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


zone gfx
{
    inline Font gfx_DEF_FONT = GetFontDefault();
    constexpr const f32 gfx_DEF_FONT_SIZE = 32.f;

    inline void rect(Vec2 pos, Vec2 size, Color color = WHITE, f32 roundness_percent = 0.f)
    {
        DrawRectangleRounded({pos.x, pos.y, size.x, size.y}, roundness_percent / 100.0f, CIRCLE_SEGMENTS, color);
    }
    inline void rect(Rect rec, Color color = WHITE, f32 roundness_percent = 0.f)
    {
        DrawRectangleRounded(rec, roundness_percent / 100.0f, CIRCLE_SEGMENTS, color);
    }

    inline void text(const char *txt, Vec2 position, f32 font_size = gfx_DEF_FONT_SIZE,
        Color font_color = Color3(240, 240, 240), Font _font = gfx_DEF_FONT, f32 spacing = 0.1
    ) {
        DrawTextEx(_font, txt, position, font_size, spacing, font_color);
    }
}


