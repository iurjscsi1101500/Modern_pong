#pragma once
#include "raylib.h"
class Ball{
    public:
    float x, y;
    int speed_x, speed_y;
    int fps,scoreDisplayTimer,playerB_score,playerA_score;
    int radius;
    void Draw();
    void Update(Sound wall_hit_sound,Sound score);
    void ResetBall();
};