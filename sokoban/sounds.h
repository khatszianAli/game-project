#ifndef SOUNDS_H
#define SOUNDS_H

#include "raylib.h"
#include "globals.h"

void load_sounds();
void unload_sounds();
void play_sound(const Sound& sound);

#endif // SOUNDS_H