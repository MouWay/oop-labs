#ifndef MATRIX_MANAGER_H
#define MATRIX_MANAGER_H

#include "Line.h"
#include "Explosion.h"
#include "ArrayList.h"

class Manager {
private:
    unsigned short spawnFrequency;
    unsigned short lineVelocity;
    unsigned short lineLength;
    unsigned short explosionProbability;
    unsigned short minRadius;
    unsigned short maxRadius;
    unsigned short curLine = 0;
    unsigned short frameRate = 30;
    unsigned long nextMoveTime;
    unsigned long nextSpawnTime;
    unsigned long nextExplosionTime;
    unsigned long curSecond;
    bool isEpilepsyOn;
    ArrayList<std::shared_ptr<Figure>> figures;
    ArrayList<std::shared_ptr<Line>> lines;
    std::vector<unsigned short> delay;
    Vector2 consoleSize;
public:
    Manager();
    void Simulate();
private:
    void GetData();
    void Initialize();
    void MoveFigures();
    void GetFrequency();
    void GetVelocity();
    void GetLength();
    void GetEpilepsyFlag();
    void GetExplosionProbability();
    void GetMinRadius();
    void GetMaxRadius();
    void RegenerateDelay();
};


#endif //MATRIX_MANAGER_H
