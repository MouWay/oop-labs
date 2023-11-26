#ifndef MATRIX_EXPLOSION_H
#define MATRIX_EXPLOSION_H

#include "Figure.h"
#include "Symbol.h"
#include "Vector2.h"
#include <vector>

class Explosion : Figure{
private:
    short radius = 1;
    short maxRadius;
    Vector2* pos;
    std::vector<Symbol> symbols;
private:
    Explosion(Vector2* p, short r);
    void Draw();
    void PutPixel(int x, int y);
    void PutPixels(int x, int y, int curX, int curY);
public:
    void Generate() override;
    void Move() override;
};


#endif //MATRIX_EXPLOSION_H
