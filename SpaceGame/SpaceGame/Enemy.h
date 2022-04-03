#pragma once
#include <Actor.h>
using namespace ConsoleEngine;

class Enemy : public Actor
{
public:
	enum Type
	{
		MOTHERSHIP = 0,
		SMALL1, 
		SMALL2, 
		SMALL3, 
		SMALL4, 
		GUNSHIP, 
		LASER
	};


	Enemy() {};
	~Enemy() {};

	// Heredado v�a Actor
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
 
	{�

	{�

	<�
	
	[[

------------------
	MOTHERSHIP

                 <=====]
           _____    )  ]
      _.--�   \\'-,/__/ 
 ___//_@/.-----.||~\_]  
<|||]~   ()()()||| (_]  
   `\\   '-----�||_/_]  
   -)=='--.___//.-�\  \ 
                    )  ]
                 <=====]

--------------------------
LASERS

  ^  
 /|\ 
/_�_\

							  
-------------�-----------------\\\
/\///\\\///\\\/\///\\\///\\\/\/<�<
----------------------�--------///






*/
};

