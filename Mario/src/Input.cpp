#include "Input.h"

Input g_input;

void Input::Update()
{
	// キー
	for (size_t i = 0; i < KEY_MAX; i++)
	{
		mKeyStates[i].lastPressed = mKeyStates[i].pressed;
	}

	// マウス
	for (size_t i = 0; i < MOUSE_MAX; i++)
	{
		mMouseStates[i].lastPressed = mMouseStates[i].pressed;
	}
}

void Input::ResetNow()
{
	// キー
	for (size_t i = 0; i < KEY_MAX; i++)
	{
		mKeyStates[i].pressed = false;
	}

	// マウス
	for (size_t i = 0; i < MOUSE_MAX; i++)
	{
		mMouseStates[i].pressed = false;
	}

}

bool Input::GetButtomDown(int key)
{
	return mKeyStates[key].lastPressed == false && mKeyStates[key].pressed == true;
}
