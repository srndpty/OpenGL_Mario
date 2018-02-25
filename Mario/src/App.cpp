// App.h
// �A�v���P�[�V�����S�̂̃��C������

#include "App.h"

#include "gladfw.h"
#include <iostream>
#include "Def.h"
#include "Util.h"
#include "Callback.h"
#include "Shader.h"
#include "Input.h"

// tmp
#include "BmpLoader.h"
#include "Player.h"
#include "Field.h"

namespace 
{
	const char* GAME_TITLE = "Mario";
}

App::App()
{
}


App::~App()
{
}

// ret: false if fail, true if succeeded
bool App::LibInit()
{
	std::cout << "current directory is " << GetCurrentWorkingDir().c_str() << "\n";

	if (!glfwInit())
	{
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	pWindow = glfwCreateWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, GAME_TITLE, NULL, NULL);
	if (!pWindow)
	{
		glfwTerminate();
		return false;
	}

	glfwSetErrorCallback(ErrorCallback);
	glfwSetKeyCallback(pWindow, KeyCallback);
	glfwSetCursorPosCallback(pWindow, CursorPosCallBack);
	glfwSetMouseButtonCallback(pWindow, MouseButtonCallback);

	// ���j�^�Ƃ̓���
	glfwMakeContextCurrent(pWindow);
	auto addr = (GLADloadproc)glfwGetProcAddress;
	gladLoadGLLoader(addr);
	glfwSwapInterval(1);

	return true;
}

void App::Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0);

	//game->Draw();
}

void App::Run()
{
	if (!LibInit())
	{
		return;
	}

	Shader::Instance().SetUp();

	// load images
	Field f;
	auto p = new Player(f);
	p->Initialize();
	p->InitSpriteInfo(Vec2f(0, 0), Vec2f(0.2f, 0.2f));

	int test = LoadBmp("images/chara.bmp");
	
	// ���C�����[�v
	while (!glfwWindowShouldClose(pWindow))
	{
		//// -- �v�Z --
		//switch (gameState)
		//{
		//case GameState::Init:
		//	Init();
		//	break;
		//case GameState::Main:
		//	GameMain();
		//	break;
		//case GameState::Gameover:
		//	GameOver();
		//	break;
		//case GameState::GameClear:
		//	GameClear();
		//	break;
		//default:
		//	std::cout << "unknown state\n";
		//	break;
		//}

		g_input.Update();
		g_input.ResetNow();


		// -- �`�� -- 
		Draw();
		p->Draw(test);

		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}
	
	
	glfwTerminate();
}

