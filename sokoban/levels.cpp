#include "levels.h"
#include "player.h"
#include "globals.h"

using std::vector;
using std::pair;
extern std::string levelDataAddress;
extern levels LEVELS[];
extern const size_t LEVEL_COUNT;
extern void create_victory_menu_background();
extern void derive_graphics_metrics_from_loaded_level();

void levels::load_levels(){
    std::fstream file(levelDataAddress);
    std::string curr_line;
    int whichLevel = 0;
    while (std::getline(file, curr_line)){
        if (curr_line[0]==';') continue;
        pair<pair<int,int>, vector<char>> levelData = parse(curr_line);
        LEVELS[whichLevel].rows = levelData.first.first;
        LEVELS[whichLevel].columns = levelData.first.second;
        LEVELS[whichLevel].data = new char[levelData.second.size()];
        std::copy(levelData.second.begin(), levelData.second.end(), LEVELS[whichLevel].data);
        whichLevel++;
    }
    file.close();
}

void levels::load_next_level() {
    unload_level();
    lvl.get_more_index();
    if (lvl.get_index() >= LEVEL_COUNT) {
        lvl.set_index(0);
        game_state = VICTORY_STATE;
        create_victory_menu_background();
    }

    load_levels();

    lvl.set_rows(LEVELS[lvl.get_index()].rows);
    lvl.set_columns(LEVELS[lvl.get_index()].columns);

    char* new_data = new char[lvl.get_rows() * lvl.get_columns()];
    lvl.set_data(new_data);

    for (size_t row = 0; row < lvl.get_rows(); ++row) {
        for (size_t column = 0; column < lvl.get_columns(); ++column) {
            char cell = LEVELS[lvl.get_index()].data[row * lvl.get_columns() + column];
            if (cell == PLAYER) {
                lvl.set_level_cell(row, column, FLOOR);
                player.spawn(row, column);
            } else if (cell == PLAYER_ON_GOAL) {
                lvl.set_level_cell(row, column, GOAL);
                player.spawn(row, column);
            } else {
                lvl.set_level_cell(row, column, cell);
            }
        }
    }

    derive_graphics_metrics_from_loaded_level();
}



void levels::unload_level() {
    rows = 0;
    columns = 0;
    if(data!= nullptr) {
        delete[] data;
        data = nullptr;
    }
}

[[nodiscard]] bool levels::is_cell_inside_level(int row, int column) const {
    return row < rows && column < columns;
}

char & levels::get_level_cell(size_t row, size_t column) {
    return data[row * columns + column];
}

void levels::set_level_cell(size_t row, size_t column, char cell) {
    data[row * columns + column] = cell;
}

[[nodiscard]] size_t levels::get_index() const{
    return level_index;
}
size_t levels:: get_more_index() {
    return level_index++;
}
size_t levels:: get_less_index() {
    return --level_index;
}
void levels::set_index(size_t new_index) {
    level_index = new_index;
}
void levels::set_rows(size_t new_rows) {
    rows = new_rows;
}
void levels::set_columns(size_t new_columns) {
    columns = new_columns;
}
void levels::set_data(char *new_data) {
    data = new_data;
}
[[nodiscard]] size_t levels::get_rows() const{
    return rows;
}
[[nodiscard]] size_t levels::get_columns() const{
    return columns;
}


