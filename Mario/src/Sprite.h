// Sprite.h
// 画像1枚分を管理する

#pragma once

#include <iostream>

#include "gladfw.h"
#include "Vec2.h"
#include "Vec4.h"
#include "linmath.h"
#include "Def.h"
#include "Shader.h"

//extern Shader shader;

namespace 
{
	const int VertsCount = 4;
}

// base class for sprite object
class Sprite
{
public:
	/// special
	// default ctor
	Sprite()
	{
		//std::cout << "default constructor of Sprite called. this shouldn't be happened!\n";
		//SHOULD_NOT_REACH_HERE();
	}

	Sprite(const Vec2f& aPos, const Vec2f& aSize)
		: pos(aPos)
		, size(aSize)
	{
		InitSpriteInfo(aPos, aSize);
	}

	// ctor init color
	Sprite(const vec4& v)
	{
		SetColor({v[0],v[1],v[2],v[3]});
	}

	// dtor
	virtual ~Sprite() = default;

	/// normal
	void InitSpriteInfo(const Vec2f& aPos, const Vec2f& aSize)
	{
		pos = aPos;
		size = aSize;

		// left bottom origined - counter clockwise
		vertex[0] = geom[0] = { -size.x, +size.y };
		vertex[1] = geom[1] = { +size.x, +size.y };
		vertex[2] = geom[2] = { +size.x, -size.y };
		vertex[3] = geom[3] = { -size.x, -size.y };

		SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}

	// 描画
	// NOTE: linmath.h がnon-constなvec4[]などを要求するので、この関数自体をconstにできない
	void Draw(int texId)
	{
		// 反映
		for (size_t i = 0; i < VertsCount; i++)
		{
			geom[i] = pos + vertex[i];
		}


		mat4x4_identity(m);
		mat4x4_ortho(p, -ASPECT_RATIO, ASPECT_RATIO, -1.0f, 1.0f, 1.0f, -1.0f);
		mat4x4_translate_in_place(m, pos.x, pos.y, 0);
		mat4x4_mul(mvp, p, m);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glUniformMatrix4fv(Shader::Instance().mMvpLocation, 1, false, (const GLfloat*)mvp);
		// attribute属性を登録
		glVertexAttribPointer(Shader::Instance().mPositionLocation, 2, GL_FLOAT, false, 0, geom);
		glVertexAttribPointer(Shader::Instance().mUvLocation, 2, GL_FLOAT, false, 0, uv);
		glVertexAttribPointer(Shader::Instance().mColorLocation, 4, GL_FLOAT, false, 0, (const float*)&color);

		// モデルの描画
		glBindTexture(GL_TEXTURE_2D, texId);
		glDrawArrays(GL_TRIANGLE_FAN, 0, VertsCount);
	}

	void SetColor(Vec4f col)
	{
		for (size_t i = 0; i < VertsCount; i++)
		{
			color[i] = col;
		}
	}

	// UVを全体にする
	void ResetUv()
	{
		uv[0] = { 0, 0 };
		uv[1] = { 0, 1 };
		uv[2] = { 1, 1 };
		uv[3] = { 1, 0 };
	}

public:
	Vec2f size{}; // サイズ
	Vec2f pos{}; // オブジェクトの中心座標
	Vec2f vertex[VertsCount]{}; // 中心座標からのoffset（固定）
	Vec2f geom[VertsCount]{}; // 実際のワールド座標
	Vec2f uv[VertsCount]{}; // uv
	Vec4f color[VertsCount]{}; // tint color

private:
	mat4x4 m, p, mvp; // 計算用変数
};

