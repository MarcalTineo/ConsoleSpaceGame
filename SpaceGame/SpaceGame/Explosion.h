#pragma once
#include <Actor.h>

using namespace ConsoleEngine;
/*
EXPLIOSIONS

         \|/ 	` ' ´
  o  	 -o- 	·   ·
         /|\ 	, . ,

*/
class Explosion :
    public Actor
{
protected:
    float timer;
    int frame;
    float animationFrameRate;
    const char model[3][3][5] = 
    { 
        {
            {'0', '0', '0', '0', '0'},
            {'0', '0', 'o', '0', '0'},
            {'0', '0', '0', '0', '0'},
        },
        {
            {'0', '\\', '|', '/', '0'},
            {'0', '-', 'o', '-', '0'},
            {'0', '/', '|', '\\', '0'},
        },
        {
            {'`', '0', '\'', '0', (char)239},
            {'-', '0', '0', '0', '-'},
            {',', '0', '.', '0', ','},
        } 
    };
    const Vector2 modelSize = Vector2(5, 3);
    const Vector2 modelOffset = Vector2(2, 1);
public:
    Explosion(Vector2 position);
    ~Explosion();
    // Heredado vía Actor
    virtual void OnCollision(HitInfo) override;
    virtual void Start() override;
    virtual void Update(float) override;
    virtual void Draw() override;
};

