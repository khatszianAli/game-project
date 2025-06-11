#include "sounds.h"

 Sound goal_sound;
 Sound exit_sound;

void load_sounds() {
    InitAudioDevice();
    goal_sound = LoadSound("data/sounds/goal.wav");
    exit_sound = LoadSound("data/sounds/exit.wav");
}

void unload_sounds() {
    UnloadSound(goal_sound);
    UnloadSound(exit_sound);
    CloseAudioDevice();
}

void play_sound(const Sound& sound) {
    PlaySound(sound);
}