#include "ball.h"
void Ball::Draw(){
    DrawCircle(x, y, radius, WHITE);
}
void Ball::Update(Sound wall_hit_sound,Sound score){   
    x += speed_x;
    y += speed_y;
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        PlaySound(wall_hit_sound);
        speed_y *= -1;
    }
    if (scoreDisplayTimer > 0) {
        scoreDisplayTimer--;
        if (x + radius >= GetScreenWidth()) {
            DrawText("PLAYER A SCORES!!", GetScreenWidth() / 7.65, GetScreenHeight() / 3, 100, GREEN);
            PlaySound(score);
            if (scoreDisplayTimer == 0) {
                playerB_score++;
                ResetBall();
            }
        }
        if (x - radius <= 0) {
            DrawText("PLAYER B SCORES!!", GetScreenWidth() / 7.65, GetScreenHeight() / 3, 100, RED);
            PlaySound(score);
            if (scoreDisplayTimer == 0) {
                playerA_score++;
                ResetBall();
            }
        }
    } else {
        if (x + radius >= GetScreenWidth() || x - radius <= 0) {
            scoreDisplayTimer = fps;
        }
    }
}
void Ball::ResetBall(){
    x = GetScreenWidth() / 2;
     y = GetScreenHeight() / 2;
    int speed_choices[2] = {-1, 1};
    speed_x = 7 * speed_choices[GetRandomValue(0, 1)];
    speed_y = 5 * speed_choices[GetRandomValue(0, 1)];
}