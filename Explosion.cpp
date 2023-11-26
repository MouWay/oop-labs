//
// Created by 123 on 11.11.2023.
//

#include "Explosion.h"
#include "Extension.h"
#include <iostream>

Explosion::Explosion(Vector2* p, short r) {
    pos = p;
    maxRadius = r;
}

void Explosion::PutPixels(int x, int y, int curX, int curY) {
    PutPixel(curX + x, curY + y);
    PutPixel(curX + x, -curY + y);
    PutPixel(-curX + x, -curY + y);
    PutPixel(-curX + x, curY + y);
    PutPixel(curY + x, curX + y);
    PutPixel(curY + x, -curX + y);
    PutPixel(-curY + x, -curX + y);
    PutPixel(-curY + x, curX + y);
}

void Explosion::Draw() {
    int curX, curY, d;
    d = 3 - 2 * radius;
    curX = 0;
    curY = radius;
    while (curX <= curY){
        PutPixels(pos->X, pos->Y, curX, curY);
        if (d <= 0) {
            d = d + 4 * curX + 6;
        } else {
            d = d + 4 * (pos->X - pos->Y) + 10;
            curY--;
        }
        curX++;
    }
}

void Explosion::PutPixel(int x, int y){
    Symbol s = *new Symbol(new Vector2(0, 0));
    s.SetPosition(x, y);
    symbols.push_back(s);
}

void Explosion::Generate() {
    Draw();
}

void Explosion::Move() {
    radius++;
    for (int i = symbols.size() - 1; i >= 0; i--) {
        delete &symbols[i];
        symbols.erase(symbols.begin() + i);
    }
    if (radius == maxRadius) delete this;
    Draw();
}