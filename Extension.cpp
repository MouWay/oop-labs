#include "Extension.h"
#include "Windows.h"

void Extension::GoToXY(int x, int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void Extension::Clear() {
    COORD topLeft = {0,0};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(output, &screen);
    FillConsoleOutputCharacterA(
            output,
            ' ',
            screen.dwSize.X * screen.dwSize.Y,
            topLeft,
            &written);
    FillConsoleOutputAttribute(
            output,
            FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y,
            topLeft,
            &written);
    SetConsoleCursorPosition(output, topLeft);
}

Vector2 Extension::GetConsoleSize() {
    CONSOLE_SCREEN_BUFFER_INFO info;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    columns = info.srWindow.Right - info.srWindow.Left + 1;
    rows = info.srWindow.Bottom - info.srWindow.Top + 1;
    return Vector2(columns, rows);
}

void Extension::SetCursorVisibility(bool visibilityFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = visibilityFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Extension::SetOutputColor(unsigned short color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

bool Extension::IsNumber(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

char Extension::GetSymbolFromPosition(short x, short y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char result;
    COORD coord = {x, y};
    DWORD numRead;
    ReadConsoleOutputCharacter(hConsole, &result, 1, coord, &numRead);
    return result;
}