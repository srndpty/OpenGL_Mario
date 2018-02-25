// Player.h
// represents player

#pragma once

#include "Vec2.h"
#include "Character.h"
#include "Field.h"

class Player : public Character
{
public:
	static const int ANIM_INTERVAL = 8;

public:
	/// special
	Player() = delete;
	Player(Field& field);
	~Player();

	/// override
	void Tick() override;
	void Initialize();

	/// normal

	/// get set

private:
	void ChangeDirection() override;
	void RefreshUv(const int horizontal, const int vertical) override;

	void GetItem();

};

