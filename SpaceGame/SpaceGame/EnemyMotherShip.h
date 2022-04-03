#pragma once
#include "EnemyShip.h"
#include "Bullet.h"
#include "HealthBar.h"
#include "Laser.h"

class EnemyMotherShip :
    public EnemyShip
{
/*
    
                 <=====]
           _____    )  ]
      _.--´   \\'-,/__/ 
 ___//_@/.-----.||~\_]  
<|||]~   ()()()||| (_]  
   `\\   '-----´||_/_]  
   -)=='--.___//.-´\  \ 
                    )  ]
                 <=====]


                 */
protected:
    const char model[9][24] = {
        {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','<','=','=','=','=','=',']',},
        {'0','0','0','0','0','0','0','0','0','0','0','_','_','_','_','_','0','0','0','0',')',' ',' ',']',},
        {'0','0','0','0','0','0','_','.','-','-',(char)239,' ',' ',' ','\\','\\','\'','-',',','/','_','_','/','0',},
        {'0','_','_','_','/','/','_','@','/','.','-','-','-','-','-','.','|','|','~','\\','_',']','0','0',},
        {'<','|','|','|',']','~',' ',' ',' ','(',')','(',')','(',')','|','|','|',' ','(','_',']','0','0',},
        {'0','0','0','`','\\','\\',' ',' ',' ','\'','-','-','-','-','-',(char)239,'|','|','_','/','_',']','0','0',},
        {'0','0','0','-',')','=','=','\'','-','-','.','_','_','_','/','/','.','-',(char)239,'\\',' ',' ','\\','0'},
        {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',')',' ',' ',']',},
        {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','<','=','=','=','=','=',']',}
    };
    const Vector2 modelSize = Vector2(24, 9);
    const Vector2 modelOffset = Vector2(10, 4);
    int lifepoints;
    float shootSpeed;
    float shootTimer;
    bool shootSide;
    int initialYPosition;
    float sinAmplitude;
    float sinVelocity;
    HealthBar* healthBar;

    float laserTimer;
    float laserTimeBetweenShots;
    float laserDuration;
    Vector2 laserOffset;
    Laser* laser;



public:
    EnemyMotherShip(Vector2 position, HUD* hud);
    ~EnemyMotherShip();

    virtual void Start() override;
    std::vector<Vector2> GenerateCollider();
    virtual void Update(float) override;
    void ShootUpdate(float dt);
    void ShootTurretUpdate(float dt);
    void ShootLaserUpdate(float dt);
    void CheckLifePoints();
    void UpdatePosition(float dt);
    virtual void Draw() override;
    virtual void OnCollision(HitInfo) override;
};

