#include "paddle.h"
void Paddle::Draw(){
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
}
void Paddle::Update(){
    if (IsKeyDown(KEY_UP)) {
            y = y - speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y = y + speed;
        }
        LimitMovement();
}
void Paddle::LimitMovement() {
        if (y <= 0) {
            y = 0;
        }
        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height;
        }
    }
void Paddle2::Update1(){
        if (IsKeyDown(KEY_W)) {
            y = y - speed;
        }
        if (IsKeyDown(KEY_S)) {
            y = y + speed;
        }
        LimitMovement();
}