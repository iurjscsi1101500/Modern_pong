#include "menu.h"
void Menu::DrawMenu() {
    DrawText("Intrusions", 10, 10, 20, RED);
    DrawText("W AND S FOR PLAYER A",10, 30, 20, YELLOW);
    DrawText("UP AND DOWN FOR PLAYER B",10, 60, 20, GREEN);
    DrawText("ESC TO EXIT",10, 90, 20, PURPLE);
    DrawText("Credits", GetScreenWidth() - MeasureText("Credits", 20) - 10, 10, 20, BLUE);
    DrawText("Iurjsci1101(Creator)", GetScreenWidth() - MeasureText("Credits", 20) -120, 40, 20, ORANGE);
    DrawText("PONG", GetScreenWidth() / 2 - MeasureText("PONG", 40) / 2, GetScreenHeight() / 4, 40, WHITE);
    DrawText("Press ENTER to start", GetScreenWidth() / 2 - MeasureText("Press ENTER to start", 20) / 2, GetScreenHeight() / 2, 20, WHITE);
    DrawText("Press 1 For Easy, 2 For Hard, or 3 For SUPER Hard to set difficulty", GetScreenWidth() / 2 - MeasureText("Press 1 For Easy, 2 For Hard, or 3 For SUPER Hard to set difficulty", 20) / 2, GetScreenHeight() / 2 + 40, 20, WHITE);
}
void Menu::UpdateMenu() {
    if (IsKeyPressed(KEY_ENTER)) {
        currentMode = GAMEPLAY;
    }
    if (IsKeyDown(KEY_ONE)) {
        difficulty = 1;
    } else if (IsKeyDown(KEY_TWO)) {
        difficulty = 2;
    } else if (IsKeyDown(KEY_THREE)) {
        difficulty = 3;
    }
}