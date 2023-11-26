#ifndef MATRIX_SYMBOL_H
#define MATRIX_SYMBOL_H

#include "vector2.h"
#include <memory>

class Symbol {
private:
    char symbol = 'a';
    unsigned short color = 2;
    Vector2 pos{};
public:
    explicit Symbol(Vector2 pos);
    ~Symbol();
    void SetColor(int c);
    void SetSymbol(char s);
    void SetRandomSymbol();
    void SetPosition(short x, short y);
    int GetColor() const;
    char GetSymbol() const;
    [[nodiscard]] Vector2 GetPosition() const;
private:
    [[nodiscard]] bool IsInRange(Vector2 p) const;
};


#endif //MATRIX_SYMBOL_H
