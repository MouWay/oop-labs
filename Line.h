#ifndef MATRIX_LINE_H
#define MATRIX_LINE_H

#include "Symbol.h"
#include "Figure.h"
#include <vector>

class Line : Figure {
private:
    unsigned short length;
    unsigned short pos = 0;
    unsigned short lastSymbolIndex = 0;
    std::vector<std::unique_ptr<Symbol>> symbols;
public:
    Line(unsigned short length, unsigned short x);
    void Generate() override;
    int Move() override;
    Vector2 Explode();
    Vector2 GetLastSymbolPosition();
    void SetColor(int color);
};


#endif //MATRIX_LINE_H