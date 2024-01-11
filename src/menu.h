#pragma once
#include "raylib.h"
class Menu{
    public:
    enum GameMode {
        MENU,
        GAMEPLAY
    };
    GameMode currentMode = MENU;
    void DrawMenu();
    int difficulty = 1;
    void UpdateMenu();
};