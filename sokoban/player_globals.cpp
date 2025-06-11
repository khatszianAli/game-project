#include "player.h"

void players::spawn(size_t row, size_t column) {
    player_row = row;
    player_column = column;
}

[[nodiscard]] size_t players::get_row() const{
    return player_row;
}
[[nodiscard]] size_t players::get_column() const{
    return player_column;
}
void players::set_row(size_t new_row){
    this-> player_row = new_row;
}
void players::set_column(size_t new_column){
    this-> player_column = new_column;
}
players player;  // Definition of global instance