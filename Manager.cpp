#include "Manager.h"
#include "Extension.h"
#include <iostream>
#include <ctime>
#include <experimental/random>
#include <algorithm>
#include <windows.h>

using namespace std;

Manager::Manager() : consoleSize(Extension::GetConsoleSize()) {
    GetData();
    Initialize();
}

void Manager::GetData() {
    GetFrequency();
    GetVelocity();
    GetLength();
    GetEpilepsyFlag();
    GetExplosionProbability();
    GetMinRadius();
    GetMaxRadius();
}

void Manager::Initialize() {
    curSecond = clock();
    nextMoveTime = curSecond + 1000 / lineVelocity;
    nextExplosionTime = curSecond + 1000;
    Extension::Clear();
    Extension::SetCursorVisibility(false);

    curLine = 0;
    RegenerateDelay();
    nextSpawnTime = delay[curLine] + curSecond;
}

void Manager::Simulate() {
    while (!(GetKeyState(VK_MENU) & 0x8000)){
        int curTime = clock();
        if (curLine >= spawnFrequency && curTime >= curSecond + 1000) {
            curLine = 0;
            curSecond = curTime;
            RegenerateDelay();
            nextSpawnTime = delay[curLine] + curSecond;
        }

        //on console size changed
        auto curConsoleSize = Extension::GetConsoleSize();
        if (consoleSize.X != curConsoleSize.X || consoleSize.Y != curConsoleSize.Y) {
            Extension::Clear();
            Extension::SetCursorVisibility(false);
            consoleSize = curConsoleSize;
        }

        //spawn lines
        if (curTime >= nextSpawnTime && curLine < spawnFrequency) {
            int spawnPoint = std::experimental::randint(0, consoleSize.X);
            auto line = make_shared<Line>(lineVelocity, curTime, lineLength, spawnPoint);
            if (isEpilepsyOn) {
                int color = std::experimental::randint(0, 15);
                line->SetColor(color);
            }
            line->Generate();
            figures.push_back(line);
            lines.push_back(line);
            curLine++;
            nextSpawnTime = curSecond + delay[curLine];
        }

        //explode
        if (curTime >= nextExplosionTime){
            for (int i = 0; i < lines.size(); i++) {
                if (lines[i]->NeedToDelete()) {
                    lines.erase(lines.begin() + i);
                    continue;
                }
                int chance = experimental::randint(1, 1000);
                if (chance <= explosionProbability){
                    Vector2 pos = lines[i]->Explode();
                    auto r = std::experimental::randint(minRadius, maxRadius);
                    auto explosion = make_shared<Explosion>(curTime, pos, r);
                    explosion->Generate();
                    figures.push_back(explosion);
                }
            }
            nextExplosionTime += 1000;
        }

        //move figures
        if (curTime >= nextMoveTime) {
            MoveFigures();
        }
    }
}

void Manager::MoveFigures() {
    for (int i = figures.size() - 1; i >= 0; i--){
        if (figures[i]->NeedToDelete()) figures.erase(figures.begin() + i);
        else figures[i]->TryMove();
    }
    nextMoveTime += 1000 / frameRate;
}

void Manager::GetFrequency() {
    cout << "Input spawn frequency from 1 to 30: ";
    std::string input;
    cin >> input;
    if (!Extension::IsNumber(input)) {
        cout << "Error! Input is not a number!" << std::endl;
        GetFrequency();
        return;
    }
    int curValue = stoi(input);
    if (curValue < 1 || curValue > 30) {
        cout << "Error! Input is not in range!" << std::endl;
        GetFrequency();
        return;
    }
    else spawnFrequency = curValue;
}

void Manager::GetVelocity() {
    cout << "Input line velocity from 1 to 30: ";
    std::string input;
    cin >> input;
    if (!Extension::IsNumber(input)) {
        cout << "Error! Input is not a number!" << std::endl;
        GetVelocity();
        return;
    }
    int curValue = stoi(input);
    if (curValue < 1 || curValue > 30) {
        cout << "Error! Input is not in range!" << std::endl;
        GetVelocity();
        return;
    }
    else lineVelocity = curValue;
}

void Manager::GetLength() {
    cout << "Input line length from 1 to 30: ";
    std::string input;
    cin >> input;
    if (!Extension::IsNumber(input)) {
        cout << "Error! Input is not a number!" << std::endl;
        GetLength();
        return;
    }
    int curValue = stoi(input);
    if (curValue < 1 || curValue > 30) {
        cout << "Error! Input is not in range!" << std::endl;
        GetLength();
        return;
    }
    else lineLength = curValue;
}

void Manager::GetEpilepsyFlag() {
    cout << "Do you want to turn on epilepsy mode? [Y/N]: ";
    char userInput;
    cin >> userInput;
    switch (userInput) {
        case 'Y':
            isEpilepsyOn = true;
            break;
        case 'N':
            isEpilepsyOn = false;
            break;
        default:
            cout << "Invalid input" << endl;
            GetEpilepsyFlag();
            break;
    }
}

void Manager::GetExplosionProbability() {
    cout << "Input explosion probability from 1 to 1000: ";
    std::string input;
    cin >> input;
    if (!Extension::IsNumber(input)) {
        cout << "Error! Input is not a number!" << std::endl;
        GetExplosionProbability();
        return;
    }
    int curValue = stoi(input);
    if (curValue < 1 || curValue > 1000) {
        cout << "Error! Input is not in range!" << std::endl;
        GetExplosionProbability();
        return;
    }
    else explosionProbability = curValue;
}

void Manager::GetMinRadius() {
    cout << "Input min explosion radius from 1 to 10: ";
    std::string input;
    cin >> input;
    if (!Extension::IsNumber(input)) {
        cout << "Error! Input is not a number!" << std::endl;
        GetMinRadius();
        return;
    }
    int curValue = stoi(input);
    if (curValue < 1 || curValue > 10) {
        cout << "Error! Input is not in range!" << std::endl;
        GetMinRadius();
        return;
    }
    else minRadius = curValue;
}

void Manager::GetMaxRadius() {
    cout << "Input max explosion radius from " << minRadius << " to 10: ";
    std::string input;
    cin >> input;
    if (!Extension::IsNumber(input)) {
        cout << "Error! Input is not a number!" << std::endl;
        GetMaxRadius();
        return;
    }
    int curValue = stoi(input);
    if (curValue < minRadius || curValue > 10) {
        cout << "Error! Input is not in range!" << std::endl;
        GetMaxRadius();
        return;
    }
    else maxRadius = curValue;
}

void Manager::RegenerateDelay() {
    delay.clear();
    for (int i = 0; i < spawnFrequency; i++){
        delay.emplace_back(std::experimental::randint(1, 1000));
    }
    std::sort(delay.begin(), delay.end());
}