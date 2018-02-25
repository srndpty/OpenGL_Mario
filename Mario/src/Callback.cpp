#include "Callback.h"

#include "gladfw.h"
#include <iostream>
#include "Input.h"

//----------------------------------------
// �G���[�R�[���o�b�N
void ErrorCallback(int error, const char* description)
{
	std::cerr << "Error Occured code: " << error << " desc: " << description << "\n";
}

//----------------------------------------
// ���̓R�[���o�b�N
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		g_input.mKeyStates[key].pressed = true;
	}
	else if (action == GLFW_RELEASE)
	{
		g_input.mKeyStates[key].pressed = false;
	}

	// ESC�ŏI��
	if (g_input.mKeyStates[GLFW_KEY_ESCAPE].pressed)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

//----------------------------------------
// �J�[�\���ړ��R�[���o�b�N
void CursorPosCallBack(GLFWwindow* window, double xpos, double ypos)
{
	static double pastx = 0, pasty = 0;
	if (pastx == xpos && pasty == ypos)
	{
		return;
	}

	// �J�[�\���ʒu�X�V
	g_input.mCursorPos = { static_cast<int>(xpos), static_cast<int>(ypos) };
	//std::cout << "cursor pos x: " << xpos << " y: " << ypos << "\n";
}

//----------------------------------------
// �}�E�X�N���b�N�R�[���o�b�N
void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		g_input.mMouseStates[button].pressed = true;
		//std::cout << "mouse " << button << " pressed!\n";
	}

	//if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	//{

	//}
}
