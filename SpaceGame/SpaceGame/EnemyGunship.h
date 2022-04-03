#pragma once
#include "EnemyShip.h"
#include "Bullet.h"

class EnemyGunship : public EnemyShip
{
    /*
    
        -/M\
       C{()|c>
	    -\W/
    
    */

protected:
    const char model[3][6] = {
        {'0', '-', '/', 'M', '\\', '0'},
        {'C', '{', '(', ')', '|', 'c'},
        {'0', '-', '\\', 'W', '/', '0'},
    };
    const Vector2 modelSize = Vector2(6, 3);
    const Vector2 modelOffset = Vector2(3, 1);
    bool reactorOn;
    int lifepoints;
    float shootSpeed;
    float shootTimer;
    bool shootSide;
public:
    EnemyGunship(Vector2 position, float speed, HUD* hud);
    ~EnemyGunship();

    virtual void Start() override;
    std::vector<Vector2> GenerateCollider();
    virtual void Update(float) override;
    void Shoot(float dt);
    void CheckLifePoints();
    void UpdatePosition(float dt);
    virtual void Draw() override;
    virtual void OnCollision(HitInfo) override;
};

