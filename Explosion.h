#ifndef MATRIX_EXPLOSION_H
#define MATRIX_EXPLOSION_H

#include "Figure.h"
#include "Symbol.h"
#include "Vector2.h"
#include <vector>
#include <memory>

class Explosion : Figure{
private:
    short radius = 1;
    Vector2 pos{};
    std::vector<std::unique_ptr<Symbol>> symbols;
private:
    void Draw();
    void PutPixel(int x, int y);
    void PutPixels(int x, int y, int curX, int curY);
public:
    Explosion(Vector2 p);
    void Generate() override;
    int Move() override;
};


#endif //MATRIX_EXPLOSION_H
