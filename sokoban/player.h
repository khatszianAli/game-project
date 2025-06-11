#ifndef PLAYER_H
#define PLAYER_H

#include <cstddef>

class players {
public:
    players() = default;
    void spawn(size_t row, size_t column);
    size_t get_row() const;
    size_t get_column() const;
    void set_row(size_t new_row);
    void set_column(size_t new_column);

private:
    size_t player_row{};
    size_t player_column{};
};

extern players player;  // Declaration only

#endif // PLAYER_H