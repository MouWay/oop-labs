#ifndef MATRIX_MANAGER_H
#define MATRIX_MANAGER_H

#include "Line.h"
#include "Explosion.h"

class Manager {
private:
    unsigned short spawnFrequency;
    unsigned short lineVelocity;
    unsigned short lineLength;
    unsigned short explosionProbability;
    unsigned short minRadius;
    unsigned short maxRadius;
    unsigned short curLine = 0;
    unsigned long nextMoveTime;
    unsigned long nextExplosionMoveTime;
    unsigned long nextSpawnTime;
    unsigned long curSecond;
    bool isEpilepsyOn;
    std::vector<Line*> lines;
    std::vector<Explosion*> explosions;
    std::vector<unsigned short> delay;
    Vector2 consoleSize;
public:
    Manager();
    void Simulate();
private:
    void GetData();
    void Initialize();
    void MoveLines();
    void MoveExplosions();
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
