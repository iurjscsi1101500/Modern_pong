#include "raylib.h"
#include "menu.h"
#include "paddle.h"
#include "ball.h"
#include <iostream>

const int screen_width = 1280;
const int screen_height = 800;
const int fps = 60;
const int win_score = 10;

int playerA_score = 0; //This is B but i set it as A can now i cant change it so it like it 
int playerB_score = 0; //This is A but i set it as B can now i cant change it so it like it 
int scoreDisplayTimer;
Paddle2 playerB;
Ball ball;
Paddle playerA;
Menu menu;
int main() {
    InitWindow(screen_width, screen_height, "Pong");
    InitAudioDevice();
    SetTargetFPS(fps); 
    Sound paddle_hit  = LoadSound("Sounds/paddle_hit.mp3");
    Sound wall_hit = LoadSound("Sounds/wall_hit.mp3");
    Sound score = LoadSound("Sounds/score.mp3");
    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;
    ball.fps = fps;
    ball.scoreDisplayTimer = fps;
    ball.playerA_score = playerA_score;
    ball.playerB_score = playerB_score;
    playerA.width = 25;
    playerA.x = screen_width - playerA.width - 1;
    playerA.y = screen_height / 2 - playerA.height / 2;
    playerA.speed = 7;

    playerB.height = 120/(menu.difficulty/1.5);
    playerB.width = 25;
    playerB.x = 1;
    playerB.speed = 7;
    while (!WindowShouldClose()) {
        switch (menu.currentMode) {
            case menu.GameMode::MENU:
                menu.UpdateMenu();
                BeginDrawing();
                ClearBackground(BLACK);
                menu.DrawMenu();
                EndDrawing();
                break;
            case menu.GameMode::GAMEPLAY:
                playerA.height = 170/menu.difficulty;
                playerB.height = 170/menu.difficulty;
                if (playerB_score >= win_score || playerA_score >= win_score) {
                    ClearBackground(BLACK);
                    if (playerB_score >= win_score) {
                        DrawText("player A WINS", screen_width / 15, screen_height / 2 - 50, 150, GREEN);
                    }
                    if (playerA_score >= win_score) {
                        DrawText("player B WINS", screen_width / 15, screen_height / 2 - 50, 150, RED);
                    }
                    EndDrawing();
                    continue;
                }
                    BeginDrawing();
                    ball.Update(wall_hit,score);
                    playerA_score = ball.playerA_score;
                    playerB_score = ball.playerB_score;
                    playerB.Update1();
                    playerA.Update();

                    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{playerA.x, playerA.y, playerA.width, playerA.height})) {
                        PlaySound(paddle_hit);
                        ball.speed_x *= -1;
                    }

                    if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{playerB.x, playerB.y, playerB.width, playerB.height})) {
                        PlaySound(paddle_hit);
                        ball.speed_x *= -1;
                    }
                    ClearBackground(BLACK);
                    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
                    DrawCircleLines(screen_width / 2, screen_height / 2, 100, WHITE);
                    ball.Draw();
                    playerB.Draw();
                    playerA.Draw();
                    DrawText("player A", screen_width / 8, 150, 80, GREEN);
                    DrawText("player B", 2.45 * screen_width / 4, 150, 80, RED);
                    DrawText(TextFormat("%d", playerB_score), screen_width / 4 - 20, 20, 80, WHITE);
                    DrawText(TextFormat("%d", playerA_score), 3 * screen_width / 4 - 20, 20, 80, WHITE);
                    EndDrawing();
                    break;
        }
    }
    UnloadSound(paddle_hit);
    UnloadSound(wall_hit);
    UnloadSound(score);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
