//
// Created by 123 on 11.11.2023.
//

#include "Explosion.h"
#include "Extension.h"
#include <experimental/random>
#include <iostream>

Explosion::Explosion(Vector2 p) {
    pos.X = p.X;
    pos.Y = p.Y;
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
        PutPixels(pos.X, pos.Y, curX, curY);
        if (d <= 0) {
            d = d + 4 * curX + 6;
        } else {
            d = d + 4 * (pos.X - pos.Y) + 10;
            curY--;
        }
        curX++;
    }
}

void Explosion::PutPixel(int x, int y){
    auto s = std::make_unique<Symbol>(Vector2(0, 0));
    int color = std::experimental::randint(0, 15);
    s.get()->SetColor(color);
    s.get()->SetPosition(x, y);
    symbols.push_back(std::move(s));
}

void Explosion::Generate() {
    Draw();
}

int Explosion::Move() {
    radius++;
    for (int i = symbols.size() - 1; i >= 0; i--) {
        symbols.erase(symbols.begin() + i);
    }
    Draw();
    return radius;
}