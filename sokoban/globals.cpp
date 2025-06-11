#include "globals.h"

std::string levelDataAddress = "data/levels.sl";

levels LEVEL_1;
levels LEVEL_2;
levels LEVEL_3;
const size_t LEVEL_COUNT = 3;
levels LEVELS[LEVEL_COUNT] = { LEVEL_1, LEVEL_2, LEVEL_3 };

size_t game_frame = 0;

enum game_state game_state = MENU_STATE;

victory_ball victory_balls[VICTORY_BALL_COUNT];
 const float GAME_LEVEL_FONT_SIZE = 70.0f;
 const float GAME_LEVEL_Y_SHIFT   = 30.0f;
 const Color GAME_LEVEL_COLOR1    = GRAY;
 const Color GAME_LEVEL_COLOR2    = WHITE;