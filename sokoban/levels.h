#ifndef LEVELS_H
#define LEVELS_H

#include <cstddef>
#include <fstream>
#include <vector>
#include "levels_data.h"

const char WALL           = '#';
const char FLOOR          = '-';
const char BOX            = '$';
const char BOX_ON_GOAL    = '*';
const char GOAL           = '.';
const char PLAYER         = '@';
const char PLAYER_ON_GOAL = '+';

class levels {
public:
    levels(): rows(0), columns(0), data(nullptr), level_index(-1){};
    void load_next_level();
    void unload_level();
    bool is_cell_inside_level(int row, int column) const;
    char & get_level_cell(size_t row, size_t column);
    void set_level_cell(size_t row, size_t column, char cell);
    size_t get_index() const;
    size_t get_more_index();
    size_t get_less_index();
    void set_index(size_t new_index);
    void set_rows(size_t new_rows);
    void set_columns(size_t new_columns);
    void set_data(char* new_data);
    size_t get_rows() const;
    size_t get_columns() const;
    void load_levels();

private:
    size_t level_index = 1;
    size_t rows = 0, columns = 0;
    char *data = nullptr;
    std::vector<char> lv_data;
};

extern levels lvl;  // Declaration only

#endif // LEVELS_H