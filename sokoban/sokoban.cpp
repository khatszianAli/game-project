#include "raylib.h"

#include "globals.h"
#include "move.h"
#include "levels.h"
#include "player.h"
#include "graphics.h"
#include "images.h"
#include "levels_data.h"
#include "sounds.h"

move_player mv;
void update_game() {
    switch (game_state) {
        case MENU_STATE:
            SetExitKey(KEY_ESCAPE);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = GAME_STATE;
            }
            break;
        case GAME_STATE:
            SetExitKey(0);
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                mv.move(0, -1);
                return;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                mv.move(0, 1);
                return;
            } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                mv.move(-1, 0);
                return;
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                mv.move(1, 0);
                return;
            } else if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = RELOAD_REQ_STATE;
            }
            break;
        case RELOAD_REQ_STATE:
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_ENTER)) {
                game_state = GAME_STATE;
            } else if (IsKeyPressed(KEY_R)) {
                lvl.unload_level();
                lvl.get_less_index();
                lvl.load_next_level();
                game_state = GAME_STATE;
            }
            break;
        case VICTORY_STATE:
            SetExitKey(KEY_ESCAPE);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = MENU_STATE;
            }
            break;
    }
}

void draw_game() {
    ++game_frame;

    switch (game_state) {
        case MENU_STATE:
            draw_menu();
            break;
        case GAME_STATE:
            draw_loaded_level();
            draw_player(player);
            draw_player_level();
            break;
        case RELOAD_REQ_STATE:
            draw_reload_req_menu();
            break;
        case VICTORY_STATE:
            draw_victory_menu();
            break;
    }
}

int main() {

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(1024, 480, "Sokoban");
    SetTargetFPS(60);
    HideCursor();

    load_fonts();
    load_images();
    load_sounds();
    lvl.load_next_level();

    while (!WindowShouldClose()) {
        BeginDrawing();

        update_game( );
        draw_game();
        EndDrawing();
    }
    CloseWindow();

   lvl.unload_level();
    unload_sounds();
    unload_images();
    unload_fonts();

    return 0;
}
