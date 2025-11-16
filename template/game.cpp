#include "game.hpp"

void SETUP()
{

}

void UPDATE()
{
    auto current_key = GetKeyPressed();

    if (current_key) {
        log (char)current_key << " : " << current_key << " pressed!\n";
    }


//* ~ DRAWING ~ *//
    drawer(bgColor);

    DrawCircle(win_w/2, win_h/2, 0.000125*(win_w*win_h), WHITE);

    EndDrawing();
}

void CLEAN()
{

}

