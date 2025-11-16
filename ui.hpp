#pragma once
#include "core.h"

#define CIRCLE_SEGMENTS 10000

// -- Helper functions --

Rect bodyToBorders(Rect body, f32 ofx, f32 ofy)
{
    return {
        body.x - ofx, body.y - ofy,
        body.width  + 2 * ofx,
        body.height + 2 * ofy
    };
}

Rect bodyToBorders(Rect body, f32 offs)
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

// -- Button system --

struct Button
{
    // === Static fields ===
    static inline std::vector<Button*> s_buttons;
    static inline uint s_count = 0;

    // === Instance fields ===
    const uint id;
    Color fgColor = GREEN;
    Color bgColor = WHITE;

    Vec2 pos {0, 0};
    Vec2 size {150, 100};
    Vec2 ofs  {7.5f, 7.5f};

    Rect body {};
    f32 roundness_P = 0.0f;

    bool clicked = false;  // leftPressed & mouseOnButton
    bool hovering = false;  // mouseOnButton

    // === Constructors ===
    Button()
        : id(++s_count)
    {
        s_buttons.push_back(this);
        body = {pos.x, pos.y, size.x, size.y};
    }

    Button(const Vec2 (&xy_wh)[2], const Color (&fg_bg_color)[2],
           f32 roundness_percent = 5.0f, const Vec2& offsets_xy = {7.5f, 7.5f})
        : pos(xy_wh[0]), size(xy_wh[1]),
          fgColor(fg_bg_color[0]), bgColor(fg_bg_color[1]),
          roundness_P(roundness_percent), ofs(offsets_xy),
          id(++s_count)
    {
        s_buttons.push_back(this);
        body = {pos.x, pos.y, size.x, size.y};
    }

    ~Button()
    {
        // safely erase by pointer
        auto it = std::find(s_buttons.begin(), s_buttons.end(), this);
        if (it != s_buttons.end())
            s_buttons.erase(it);
    }

    inline bool isHovering() {
        return
        CheckCollisionPointRec(GetMousePosition(), body);
        &&
    }

    inline bool clicked(const int mouse_btn=MOUSE_BUTTON_LEFT) {
        return
        IsMouseButtonPressed(mouse_btn)
        &&
        CheckCollisionPointRec(GetMousePosition(), this->body);
    }
    inline bool rightClicked() {
        return
        IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)
        &&
        CheckCollisionPointRec(GetMousePosition(), this->body);
    }

    // === Static methods ===
    static void start() {

    }

    static void Loop()
    {
        for (auto* btn : s_buttons)
        {
            btn->body = {btn->pos.x, btn->pos.y, btn->size.x, btn->size.y};
        }
    }

    static void Draw()
    {
        for (auto* btn : s_buttons)
        {
            gfx::rect(bodyToBorders(btn->body, btn->ofs.x, btn->ofs.y), btn->bgColor, btn->roundness_P);
            gfx::rect(btn->body, btn->fgColor, btn->roundness_P);
        }
    }
};

