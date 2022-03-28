#pragma once
#include "EnemyShip.h"
using namespace ConsoleEngine;

class SmallShip : public EnemyShip
{
protected:
    const char model[4][2] = {
        {'{', (char)232},
        {'{', (char)209},
        {'<', (char)232},
        {'[', '['},
    };
    int type; //el tipus es nomes visual
    int color;
    
public:
    SmallShip(Vector2 position, float speed, int type);
    ~SmallShip();
    virtual void Start() override;
    virtual void Update(float) override;
    virtual void Draw() override;
    virtual void OnCollision(HitInfo) override;
};

