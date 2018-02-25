#include <memory>
#include "App.h"

// lib headers
#include "Shader.h"
#include "Vec2.h"
#include "Def.h"
#include "Input.h"
#include "Sprite.h"
#include "BmpLoader.h"
#include "Random.h"
#include "NumDisp.h"
#include "Billboard.h"

// game specific headers
#include "Game.h"

namespace
{
	enum class GameState
	{
		Init,
		Main,
		Gameover,
		GameClear,
	};

	const int STAGE_MAX = 3;

	// main game
	GameState gameState = GameState::Init;
	//std::unique_ptr<Game> game = std::make_unique<Game>();

	auto scoreDispBlack = std::make_unique<NumDisp<2>>(Vec2f{ +0.5f, 0.4f });
	auto scoreDispWhite = std::make_unique<NumDisp<2>>(Vec2f{ +0.5f, 0.2f });
	bool firstGameOver = true;
	int scorePoint = 0;
	int stage = 0;

	// test
	std::unique_ptr<Billboard> test0 = std::make_unique<Billboard>(Vec2f{ 0, -0.3f }, Vec2f{ 0.2f, 0.2f });
	std::unique_ptr<Billboard> test1 = std::make_unique<Billboard>(Vec2f{ 0, +0.3f }, Vec2f{ 0.2f, 0.2f });
}


//----------------------------------------
// 初期化
void Init()
{
	//game->Initialize(stage);
	gameState = GameState::Main;
	std::cout << "Game Start!\n";
}

//----------------------------------------
// メインの処理
void GameMain()
{
	// ゲーム更新
	//if (game->Tick())
	//{
	//	if (game->IsCleared())
	//	{
	//		stage++;
	//		if (stage >= STAGE_MAX)
	//		{
	//			gameState = GameState::GameClear;
	//		}
	//		else
	//		{
	//			gameState = GameState::Init;
	//		}
	//	}
	//	else
	//	{
	//		gameState = GameState::Gameover;
	//	}
	//}

	//// ゲーム中もRで最初から
	//if (g_input.mKeyStates[GLFW_KEY_R].pressed)
	//{
	//	gameState = GameState::Init;
	//}
}

//----------------------------------------
// ゲームオーバー
void GameOver()
{
	if (g_input.mKeyStates[GLFW_KEY_R].pressed)
	{
		stage = 0;
		gameState = GameState::Init;
	}
}

//----------------------------------------
// ゲームクリア
void GameClear()
{
	if (g_input.mKeyStates[GLFW_KEY_R].pressed)
	{
		stage = 0;
		gameState = GameState::Init;
	}
}

//----------------------------------------
// ENTRY POINT
int main()
{
	auto app = std::make_unique<App>();
	app->Run();

	return 0;
}