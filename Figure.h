#ifndef MATRIX_FIGURE_H
#define MATRIX_FIGURE_H

#include <ctime>

class Figure {
private:
    unsigned short speed;
    unsigned long nextMoveTime;
public:
    Figure(unsigned short speed, unsigned long time);
    virtual void Generate() = 0;
    virtual bool NeedToDelete() = 0;
    void TryMove();
private:
    virtual int Move() = 0;
};


#endif //MATRIX_FIGURE_H
