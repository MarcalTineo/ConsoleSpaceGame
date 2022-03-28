#pragma once
#include "EnemyShip.h"
class EnemyGunship : public EnemyShip
{
    /*
    
    
    	-/M\
       C{()|c>
	    -\W/
    
    
    
    
    */



protected:
    const char model[6][3] = {};
    const Vector2 modelSize = Vector2(6, 3);
    const Vector2 modelOffset = Vector2(3, 1);
public:
    EnemyGunship(Vector2 position, float speed);
    ~EnemyGunship();
    virtual void Start() override;
    virtual void Update(float) override;
    virtual void Draw() override;
    virtual void OnCollision(HitInfo) override;
};

