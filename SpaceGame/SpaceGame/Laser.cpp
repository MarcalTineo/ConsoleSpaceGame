#include "Laser.h"
#include "DrawEngine.h"


Laser::Laser(Vector2 _position)
{
	position = _position;
	upperEdge = std::vector<char>();
	center = std::vector<char>();
	lowerEdge = std::vector<char>();
	collider = new Collider(id,std::vector<Vector2>());
}

Laser::~Laser()
{
	delete collider;
}

void Laser::OnCollision(HitInfo hit)
{
}

void Laser::Start()
{
	tag = "LASER";
	animationSpeed = 30;
	timer = 0;
	upperEdge = GenerateEdge();
	lowerEdge = GenerateEdge();
	center = GenerateCenter();
	laserColor = 12;
	state = State::OFF;
	warningCyclesDone = 0;
	warningCycles = 10;
	warningCycleTime = 0.3f;
	warningColor = 6;
	collider->enabled = false;

}

std::vector<Vector2> Laser::GenerateCollider()
{
	std::vector<Vector2> col = std::vector<Vector2>();
	col.push_back(Vector2::Zero());
	for (int i = position.x - 1; i > 0; i--)
	{
		for (int j = -1; j < 2; j++)
		{
			col.push_back(Vector2(-i, j));
		}
	}
	return col;
}

std::vector<char> Laser::GenerateEdge()
{
	std::vector<char> edge;
	for (int i = position.x - 2; i > 0; i--)
	{
		int rnd = Helpers::GetRandomNumber(0, 100);
		if (rnd > 10)
			edge.push_back(edgeCharacters[0]);
		else
			edge.push_back(edgeCharacters[1]);
	}
	return edge;
}

std::vector<char> Laser::GenerateCenter()
{
	std::vector<char> center;
	for (int i = position.x - 1; i > 0; i--)
	{
		int rnd = Helpers::GetRandomNumber(0, 100);
		if (rnd > 50)
			center.push_back(centerCharacters[0]);
		else
			center.push_back(centerCharacters[1]);
	}
	return center;
}

void Laser::Update(float dt)
{
	timer += dt;
	switch (state)
	{
	case Laser::WARNING:
		if (timer > warningCycleTime)
		{
			std::cout << warningCyclesDone;
			timer -= warningCycleTime;
			drawWarning = !drawWarning;
			warningCyclesDone++;
			if (warningCyclesDone >= warningCycles)
			{
				state = State::FIRE;
				drawWarning = false;
				collider->enabled = true;
			}
		}
		break;
	case Laser::FIRE:
		if (timer >= 1 / animationSpeed)
		{
			timer -= 1 / animationSpeed;
			MoveOneCenter();
			MoveOneEdge(lowerEdge);
			MoveOneEdge(upperEdge);
		}
		break;
	default:
		break;
	}
}

void Laser::MoveOneCenter()
{
	int rnd = Helpers::GetRandomNumber(0, 100);
	center.erase(center.end()-1);
	center.insert(center.begin(), centerCharacters[rnd > 50 ? 0 : 1]);
}

void Laser::MoveOneEdge(std::vector<char>& edge)
{
	int rnd = Helpers::GetRandomNumber(0, 100);
	edge.erase(edge.end()-1);
	edge.insert(edge.begin(), edgeCharacters[rnd > 50 ? 0 : 1]);
}


void Laser::Draw()
{
	switch (state)
	{
	case Laser::WARNING:
		if (drawWarning)
		{
			DrawEngine::GetInstance().DrawAtPos('^', position.x - 3, position.y - 1, warningColor);
			DrawEngine::GetInstance().DrawAtPos('\\', position.x - 2, position.y, warningColor);
			DrawEngine::GetInstance().DrawAtPos('|', position.x - 3, position.y, warningColor);
			DrawEngine::GetInstance().DrawAtPos('/', position.x - 4, position.y, warningColor);
			DrawEngine::GetInstance().DrawAtPos('\\', position.x - 1, position.y + 1, warningColor);
			DrawEngine::GetInstance().DrawAtPos('_', position.x - 2, position.y + 1, warningColor);
			DrawEngine::GetInstance().DrawAtPos(250, position.x - 3, position.y + 1, warningColor);
			DrawEngine::GetInstance().DrawAtPos('_', position.x - 4, position.y + 1, warningColor);
			DrawEngine::GetInstance().DrawAtPos('/', position.x - 5, position.y + 1, warningColor);
		}
		break;
	case Laser::FIRE:
		DrawEngine::GetInstance().DrawAtPos('>', position.x, position.y, laserColor);
		DrawEngine::GetInstance().DrawAtPos('/', position.x - 1, position.y + 1, laserColor);
		DrawEngine::GetInstance().DrawAtPos('\\', position.x - 1, position.y - 1, laserColor);
		DrawEngine::GetInstance().DrawAtPos(center[0], position.x - 1, position.y, laserColor);
		for (int i = 0; i < lowerEdge.size(); i++)
		{
			DrawEngine::GetInstance().DrawAtPos(center[i + 1], position.x - 2 - i, position.y, laserColor);
			DrawEngine::GetInstance().DrawAtPos(lowerEdge[i], position.x - 2 - i, position.y + 1, laserColor);
			DrawEngine::GetInstance().DrawAtPos(upperEdge[i], position.x - 2 - i, position.y - 1, laserColor);
		}
		/*for (Vector2 col : collider->GetCollider())
			DrawEngine::GetInstance().DrawAtPos(254, col.x + position.x, col.y + position.y, 10);*/
		break;
	default:
		break;
	}
	
}

void Laser::Fire()
{
	warningCyclesDone = 0;
	timer = 0;
	state = State::WARNING;

}

void Laser::TurnOff()
{
	collider->enabled = false;
	state = State::OFF;
}
