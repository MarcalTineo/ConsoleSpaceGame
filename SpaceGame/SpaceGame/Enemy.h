#pragma once
#include <Actor.h>
using namespace ConsoleEngine;

class Enemy : public Actor
{
public:
	Enemy() {};
	~Enemy() {};

	// Heredado vía Actor
	virtual void OnCollision(HitInfo) override {};
	virtual void Start() = 0;
	virtual void Update(float) = 0;
	virtual void Draw() = 0;
/*
	

	GUNSHIP

	-/M\
   C{()|c>
	-\W/
-------------------
	SMALLS
 
	{Þ

	{Ð

	<Þ
	
	[[

------------------
	MOTHERSHIP

                 <=====]
           _____    )  ]
      _.--´   \\'-,/__/ 
 ___//_@/.-----.||~\_]  
<|||]~   ()()()||| (_]  
   `\\   '-----´||_/_]  
   -)=='--.___//.-´\  \ 
                    )  ]
                 <=====]

--------------------------
LASERS

  ^  
 /|\ 
/_·_\

							  
-------------·-----------------\\\
/\///\\\///\\\/\///\\\///\\\/\/<«<
----------------------·--------///






*/
};

