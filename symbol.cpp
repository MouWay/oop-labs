#include "symbol.h"
#include "Extension.h"
#include <iostream>
#include <experimental/random>
#include <memory>

Symbol::Symbol(Vector2 p){
    pos.X = p.X;
    pos.Y = p.Y;
}

Symbol::~Symbol(){
    if ((IsInRange(pos) && Extension::GetSymbolFromPosition(pos.X, pos.Y) == symbol)){
        Extension::GoToXY(pos.X, pos.Y);
        std::cout << ' ';
    }
}

void Symbol::SetColor(int c) {
    color = c;
}

void Symbol::SetPosition(short x, short y) {
    char lastSymbol = symbol;
    SetRandomSymbol();
    if (IsInRange(pos) && Extension::GetSymbolFromPosition(pos.X, pos.Y) == lastSymbol){
        Extension::GoToXY(pos.X, pos.Y);
        std::cout << ' ';
    }
    pos.X = x;
    pos.Y = y;
    if (IsInRange(pos)){
        Extension::GoToXY(pos.X, pos.Y);
        Extension::SetOutputColor(color);
        std::cout << symbol;
    }
}

void Symbol::SetSymbol(char s) {
    symbol = s;
}

int Symbol::GetColor() const {
    return color;
}

Vector2 Symbol::GetPosition() const {
    return pos;
}

char Symbol::GetSymbol() const {
    return symbol;
}

bool Symbol::IsInRange(Vector2 p) const {
    Vector2 consoleSize = Extension::GetConsoleSize();
    return p.X >= 0 && p.X < consoleSize.X - 1 && p.Y >= 0 && p.Y < consoleSize.Y;
}

void Symbol::SetRandomSymbol() {
    SetSymbol(std::experimental::randint(33, 126));
}