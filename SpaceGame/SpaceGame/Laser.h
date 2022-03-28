#pragma once
#include "Enemy.h"
class Laser :
    public Enemy
{
    /*
    
  ^  
 /|\ 
/_·_\
					  
-------------·-----------------\
/\///\\\///\\\/\///\\\///\\\/\//>-)
----------------------·--------/
    
    
    */
public:
    enum State
    {
        WARNING, FIRE, OFF
    };
protected:
    char edgeCharacters[2] = { '.', (char)250 };
    char centerCharacters[2] = { '/', '\\' };
    float animationSpeed;
    float timer;
    int laserColor;


    State state;
    float warningCycles;
    float warningCycleTime;
    bool drawWarning;
    int warningCyclesDone;
    int warningColor;

    std::vector<char> upperEdge;
    std::vector<char> center;
    std::vector<char> lowerEdge;
public:
    Laser(Vector2 position);
    // Heredado vía Enemy
    virtual void OnCollision(HitInfo hit);
    virtual void Start() override;
    std::vector<char> GenerateEdge();
    std::vector<char> GenerateCenter();
    virtual void Update(float dt) override;
    void MoveOneCenter();
    void MoveOneEdge(std::vector<char>& edge);
    virtual void Draw() override;
    void Fire();
    void TurnOff();
};

