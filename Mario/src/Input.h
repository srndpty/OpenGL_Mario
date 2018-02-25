// Input.h
// ���͂̐���

#pragma once

#include "Vec2.h"

// �L�[�̏��
struct State
{
	bool pressed;
	bool lastPressed;
};

// ���͐���N���X
class Input
{
public:
	static constexpr int KEY_MAX = 512;
	static constexpr int MOUSE_MAX = 16;

public:
	State mKeyStates[KEY_MAX];
	State mMouseStates[MOUSE_MAX];
	Vec2i mCursorPos;

public:
	// ���͏�Ԃ�1�t���[���i�߂�
	void Update();

	// ���͂̌��ݏ�Ԃ����Z�b�g
	void ResetNow();

	// �w��̃L�[�������ꂽ�u�Ԃ��ǂ������擾
	bool GetButtomDown(int key);
};

extern Input g_input;
