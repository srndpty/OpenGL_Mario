// App.h
// �A�v���P�[�V�����S�̂̃��C������

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

