//
// Created by 123 on 11.11.2023.
//

#include "Explosion.h"
#include "Extension.h"
#include <experimental/random>
#include <iostream>

Explosion::Explosion(unsigned long time, Vector2 p, short maxR)
    : Figure(1, time) {
    pos.X = p.X;
    pos.Y = p.Y;
    maxRadius = maxR;
}

void Explosion::PutPixels(int x, int y, int curX, int curY) {
    int k = 2;
    PutPixel(curX * k + x, curY + y);
    PutPixel(curX * k + x, -curY + y);
    PutPixel(-curX * k + x, -curY + y);
    PutPixel(-curX * k + x, curY + y);
    PutPixel(curY * k + x, curX + y);
    PutPixel(curY * k + x, -curX + y);
    PutPixel(-curY * k + x, -curX + y);
    PutPixel(-curY * k + x, curX + y);
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

bool Explosion::NeedToDelete() {
    return radius >= maxRadius;
}