//
// Created by new owner on 22/5/24.
//

#ifndef SOKOBAN_MOVE_H
#define SOKOBAN_MOVE_H

#include "levels.h"
#include "player.h"
#include "sounds.h"
class move_player{
public:
    move_player(){};
    void move(int dx, int dy) {

        int next_row = static_cast<int>(player.get_row()) + dy;
        int next_column = static_cast<int>(player.get_column()) + dx;
        if (!lvl.is_cell_inside_level(next_row, next_column)) {
            return;
        }

        char &cell = lvl.get_level_cell(static_cast<size_t>(next_row), static_cast<size_t>(next_column));
        if (cell == FLOOR || cell == GOAL) {
            player.set_row(static_cast<size_t>(next_row));
            player.set_column(static_cast<size_t>(next_column));
        } else if (cell == BOX || cell == BOX_ON_GOAL) {
            int target_row = next_row + dy;
            int target_column = next_column + dx;
            if (!lvl.is_cell_inside_level(target_row, target_column)) {
                return;
            }
            char &target_cell = lvl.get_level_cell(static_cast<size_t>(target_row), static_cast<size_t>(target_column));
            if (target_cell == FLOOR || target_cell == GOAL) {
                cell = cell == BOX ? FLOOR : GOAL;
                if (target_cell == FLOOR) {
                    target_cell = BOX;
                } else {
                    target_cell = BOX_ON_GOAL;
                    if(goal_sound.frameCount > 0) play_sound(goal_sound);
                }

                player.set_row(static_cast<size_t>(next_row));
                player.set_column(static_cast<size_t>(next_column));

                bool level_solved = true;
                for (size_t row = 0; level_solved && row < lvl.get_rows(); ++row) {
                    for (size_t column = 0; level_solved && column < lvl.get_columns(); ++column) {
                        char cell_to_test = lvl.get_level_cell(row, column);
                        if (cell_to_test == GOAL) {
                            level_solved = false;
                        }
                    }
                }

                if (level_solved) {
                    lvl.unload_level();
                    lvl.load_next_level();
                    if(goal_sound.frameCount > 0)play_sound(exit_sound);
                }
            }
        }
    }
};
#endif //SOKOBAN_MOVE_H
