//
// Created by 123 on 11.11.2023.
//

#include "Figure.h"

Figure::Figure(unsigned short speed, unsigned long time) {
    this->speed = speed;
    nextMoveTime = time + 1000 / speed;
}

void Figure::TryMove() {
    if (nextMoveTime <= clock()){
        Move();
        nextMoveTime += 1000 / speed;
    }
}