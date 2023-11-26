#ifndef MATRIX_SYMBOL_H
#define MATRIX_SYMBOL_H

#include "vector2.h"

class Symbol {
private:
    char symbol = 'a';
    unsigned short color = 2;
    Vector2* pos;
public:
    Symbol(Vector2* pos);
    Symbol();
    ~Symbol();
    void SetColor(int c);
    void SetSymbol(char s);
    void SetRandomSymbol();
    void SetPosition(short x, short y);
    int GetColor() const;
    char GetSymbol() const;
    Vector2 GetPosition() const;
    void Redraw();
private:
    bool IsInRange(Vector2 p) const;
};


#endif //MATRIX_SYMBOL_H
