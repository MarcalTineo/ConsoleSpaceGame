#pragma once
#include "Enemy.h"
#include "Explosion.h"
#include "HUD.h"

class EnemyShip :
    public Enemy
{
protected:
    Vector2 forward;
    float speed;
    float timer;
    int color;
	HUD* hud;
public:
    // Heredado v�a Enemy
    virtual void Start() override;
    virtual void Update(float) override;
    virtual void Draw() override;
    virtual void OnCollision(HitInfo) override;

    int GetColor();
    void SetColor(int color);
};

