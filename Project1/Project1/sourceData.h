#pragma once

#define MY_PI 3.1415926

float vertices[] = {
    // 位置              // 颜色
     -0.5f,  -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // 右下
      0.5f,  -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   // 左下
      0.0f,   0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // 顶部
};

int index[] = {
    0, 1, 2
};