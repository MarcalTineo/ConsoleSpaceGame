#include "SpaceGame.h"


SpaceGame::SpaceGame()
{
	size = Vector2(120, 35);
	state = State::TITLE_SCREEN;
	scene = new Scene();
	mainMenu = new MainMenu();
	mainMenu->Start();
	gameOverMenu = new GameOverMenu();
	hud = new HUD(size.x);
	hud->Start();
}

SpaceGame::~SpaceGame()
{
	delete scene;
	delete mainMenu;
	delete gameOverMenu;
	delete hud;
}

void SpaceGame::Start()
{
	state = State::PLAY;
	scene->Create(new Board(size));
	player = new PlayerShip(Vector2(20, 20), 10);
	scene->Create(player);
	hud->ResetScore();
	hud->SetPlayer(player);
	scene->Create(new Spawner(waves, playmode, hud));
	endGameTimer = 0;
	repeatGameTimer = 0;

}

void SpaceGame::Update(float dt)
{
	bool spawnerActive;
	switch (state)
	{
	case SpaceGame::TITLE_SCREEN:
		mainMenu->Update(dt);
		if (mainMenu->allDone)
		{
			playmode = mainMenu->GetPlayMode();
			state = State::LOAD_XML;
			mainMenu->SetActive(false);
		}
		break;
	case SpaceGame::LOAD_XML:
		LoadWaves();
		Start();
		break;
	case SpaceGame::PLAY:
		scene->Update();
		this->Game::Update(dt);

		spawnerActive = scene->GetFirst("SPAWNER")->IsActive();
		if (player->GetHealthPoints() <= 0 || (player->GetHealthPoints() > 0 && playmode == MainMenu::PlayMode::ONCE && scene->GetAll("ENEMY_MOTHERSHIP").size() == 0 && !spawnerActive))
			endGameTimer += dt;

		if (player->GetHealthPoints() > 0 && playmode == MainMenu::PlayMode::LOOP && scene->GetAll("ENEMY_MOTHERSHIP").size() == 0 && !spawnerActive)
			repeatGameTimer += dt;

		if (repeatGameTimer > 3)
		{
			scene->GetFirst("SPAWNER")->SetActive(true);
			repeatGameTimer = 0;
		}

		if (endGameTimer > 3)
		{
			int i = 3;
			EndGame();
		}
		
#if _DEBUG
		if (Input::GetInstance().GetKeyDown(VK_F1))
		{
			scene->Create(new EnemyMotherShip(Vector2(100, 20), hud));
		}
#endif
		break;
	case SpaceGame::GAME_OVER:
		gameOverMenu->Update(dt);
		if (gameOverMenu->GetAllDone())
		{
			state = State::TITLE_SCREEN;
			gameOverMenu->SetActive(false);
			mainMenu->SetActive(true);
			mainMenu->Start();
		}
		break;
	default:
		break;
	}	
}

void SpaceGame::EndGame()
{
	state = State::GAME_OVER;

	scene->Clear();
	DrawEngine::GetInstance().Clear();
	
	gameOverMenu->SetActive(true);
	gameOverMenu->Start();
	gameOverMenu->SetScore(hud->GetScore());

	if (hud->GetHighScore() < hud->GetScore())
		hud->SetHighScore();
	hud->ResetScore();
}

void SpaceGame::LoadWaves()
{
	waves = std::vector<Wave>();
	XMLLoader* loader = new XMLLoader();
	loader->LoadFile("waves.xml", waves);
}

void SpaceGame::Draw()
{
	switch (state)
	{
	case SpaceGame::TITLE_SCREEN:
		mainMenu->Draw();
		break;
	case SpaceGame::LOAD_XML:
		break;
	case SpaceGame::PLAY:
		DrawEngine::GetInstance().InitViewport();
		this->Game::Draw();
		hud->Draw();
		DrawEngine::GetInstance().Flush();
		break;
	case SpaceGame::GAME_OVER:
		gameOverMenu->Draw();
		break;
	default:
		break;
	}
}


