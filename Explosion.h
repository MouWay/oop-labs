#ifndef MATRIX_EXPLOSION_H
#define MATRIX_EXPLOSION_H

#include "Figure.h"
#include "Symbol.h"
#include "Vector2.h"
#include <vector>
#include <memory>

class Explosion : public Figure{
private:
    short radius = 1;
    short maxRadius;
    Vector2 pos{};
    std::vector<std::unique_ptr<Symbol>> symbols;
private:
    void Draw();
    void PutPixel(int x, int y);
    void PutPixels(int x, int y, int curX, int curY);
public:
    Explosion(unsigned long time, Vector2 p, short maxR);
    void Generate() override;
    bool NeedToDelete() override;
    int Move() override;
};


#endif //MATRIX_EXPLOSION_H
