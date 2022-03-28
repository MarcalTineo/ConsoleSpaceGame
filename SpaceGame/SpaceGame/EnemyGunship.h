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
    char model[6][3] = {};
public:
    EnemyGunship(Vector2 position, float speed);
    ~EnemyGunship();
    virtual void Start() override;
    virtual void Update(float) override;
    virtual void Draw() override;
    virtual void OnCollision(HitInfo) override;
};

