#include "Board.h"


Board::Board(Vector2 _size)
{
	size = _size;
	collider = new Collider();
	GenerateCollider();
	position = Vector2::Zero();
	tag = "BOARD";
}

Board::~Board()
{
	delete collider;
}

void Board::GenerateCollider()
{
	std::vector<Vector2> col = std::vector<Vector2>();
	for (int i = 0; i < size.x; i++)
		col.push_back(Vector2(i, 3));
	for (int i = 4; i < size.y - 1; i++)
	{
		col.push_back(Vector2(0, i));
		col.push_back(Vector2(size.x - 1, i));
	}
	for (int i = 0; i < size.x; i++)
		col.push_back(Vector2(i, size.y - 1));
	collider->SetCollider(col);
}

void Board::Update(float dt)
{
	
}

void Board::Draw()
{
	DrawFullLine((char)boardParts::L_UpLeft, (char)boardParts::I_Horizontal, (char)boardParts::L_UpRight, 0);
	DrawFullLine((char)boardParts::I_Vertical, ' ', (char)boardParts::I_Vertical, 1);
	DrawFullLine((char)boardParts::T_Right, (char)boardParts::I_Horizontal, (char)boardParts::T_Left, 2);
	DrawFullLine((char)boardParts::T_Right, (char)boardParts::I_Horizontal, (char)boardParts::T_Left, 3);
	for (int i = 4; i < size.y; i++)
		DrawFullLine((char)boardParts::I_Vertical, ' ', (char)boardParts::I_Vertical, i);
	DrawFullLine((char)boardParts::L_DownLeft, (char)boardParts::I_Horizontal, (char)boardParts::L_DownRight, size.y - 1);
	for (Vector2 col : collider->GetCollider())
		DrawEngine::GetInstance().DrawAtPos(254, position.x + col.x, position.y + col.y, 10);
}

void Board::DrawFullLine(char first, char middle, char last, int line)
{
	DrawEngine::GetInstance().DrawAtPos(first, 0, line);
	DrawMiddleLine(middle, line);
	DrawEngine::GetInstance().DrawAtPos(last, size.x - 1, line);
}

void Board::DrawMiddleLine(char c, int line)
{
	for (int i = 1; i < size.x - 1; i++)
		DrawEngine::GetInstance().DrawAtPos(c, i, line);
}

bool Board::InsideBorders(Vector2 position)
{
	return position.x > 0 && position.x < size.x - 1 && position.y > 3 && position.y < size.y - 1;
}

void Board::OnCollision(HitInfo)
{
}
