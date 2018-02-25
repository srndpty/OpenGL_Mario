// BmpLoader.h
// BMP画像の読み込みをまとめる

#pragma once

#include "gladfw.h"

// bmp画像の読み込み
// pathは現在のディレクトリからの相対パスでOK
GLuint LoadBmp(const char* filename);