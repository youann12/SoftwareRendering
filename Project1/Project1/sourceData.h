#ifndef SOURCEDATA_H
#define SOURCEDATA_H


#pragma once
const int CV_EVENT_MOUSEMOVE = 0;
const int Key_R = 114;
const int Key_F = 102;
const int Key_W = 119;
const int Key_A = 97;
const int Key_S = 115;
const int Key_D = 100;

float vertices[] = {
    // 位置              // 颜色
     -0.5f,  -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // 右下
      0.5f,  -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   // 左下
      0.0f,   0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // 顶部
};

int index[] = {
    0, 1, 2
};

float boxs[] = {
    
    -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,     0.0f, 0.0f, // 0
     0.5f, -0.5f, -0.5f,    0.0f, 1.0f, 0.0f,     1.0f, 0.0f, // 1
     0.5f,  0.5f, -0.5f,    1.0f, 1.0f, 0.0f,     1.0f, 1.0f, // 2
    -0.5f,  0.5f, -0.5f,    1.0f, 0.0f, 1.0f,     0.0f, 1.0f, // 3 
    -0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,     0.0f, 0.0f, // 4
     0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 1.0f,     1.0f, 0.0f, // 5
     0.5f,  0.5f,  0.5f,    1.0f, 0.0f, 0.0f,     1.0f, 1.0f, // 6
    -0.5f,  0.5f,  0.5f,    0.0f, 0.0f, 1.0f,     0.0f, 1.0f, // 7

};

//     3 __________ 2    
//      /|        /|
//     /_|_______/ |
//   7 | |      6| |
//     | |_______|_|
//     | / 0     | / 1
//     |/________|/
//     4        5

int indices[] = {
    
    0, 1, 4,
    1, 5, 4,

    6, 2, 1,
    1, 5, 6,

    3, 2, 6,
    6, 7, 3,

    3, 2, 0,
    2, 1, 0,

    3, 7, 0,
    7, 4, 0,

    7, 6, 4,
    6, 5, 4,

};



float lightbox[] = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};


int lightindices[] = {

    0, 1, 2,
    3, 4, 5,

    6, 7, 8,
    9, 10, 11,

    12, 13, 14,
    15, 16, 17,

    18, 20, 19,
    21, 23, 22,

    24, 25, 26,
    27, 28, 29,

    30, 32, 31,
    33, 35, 34,

};

#endif // !SOURCEDATA_H
