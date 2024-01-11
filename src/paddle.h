#pragma once
#include "raylib.h"
class Paddle{
    protected:
    void LimitMovement();
    public:
    float x, y, width, height;
    int speed;
    void Draw();
    void Update();
};
class Paddle2 : public Paddle{
    public:
        void Update1();
};