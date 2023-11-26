//
// Created by 123 on 19.09.2023.
//

#ifndef MATRIX_EXTENSION_H
#define MATRIX_EXTENSION_H


#include "Vector2.h"
#include <string>

class Extension {
public:
    static void GoToXY(int x, int y);
    static void Clear();
    static Vector2 GetConsoleSize();
    static void SetCursorVisibility(bool visibilityFlag);
    static void SetOutputColor(unsigned short color);
    static bool IsNumber(const std::string& s);
    static char GetSymbolFromPosition(short x, short y);
};


#endif //MATRIX_EXTENSION_H
