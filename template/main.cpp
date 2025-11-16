#include <charconv>
#include "game.hpp"

int main(int argc, char *argv[])
{
    log "\033[1;36mmain function started!\n\n";
    InitWindow(init_win_w, init_win_h, "~ STARTED! ~");
    log "\nWindow initialized!\n\n";
    if (capFPS) {
        SetTargetFPS(maxFPS);
    }

    int err_state = 0;
    SETUP();
    log "Setup done\n\n";


    win_w = init_win_w;
    win_h = init_win_h;

    log "\033[1;35mGame loop started!\n\n\n";
    while (!WindowShouldClose())
    {
        fps = GetFPS();
        dt = GetFrameTime();
        win_w = GetScreenWidth();
        win_h = GetScreenHeight();

        UPDATE();

        char buf[20];
        auto result = std::to_chars(buf, buf + sizeof(buf), fps);
        *result.ptr = '\0';
        SetWindowTitle(buf);

        EndDrawing();
    }
    log "\n\nGame loop ended\n\033[1;32m&\n";

    log "\033[1;34mClean-up started\n\n";
    CLEAN();

    CloseWindow();
    return (
        log "Window Closed, main function ended! (" << err_state << ")\n",
        err_state
    );
}

