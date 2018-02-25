// App.h
// アプリケーション全体のメイン処理

#pragma once

struct GLFWwindow;

class App
{
private:
	GLFWwindow* pWindow = nullptr;


public:
	App();
	~App();

	void Run();

private:
	bool LibInit();
	void Draw();
};

