#include "Line.h"
#include "Extension.h"

Line::Line(unsigned short len, unsigned short x) {
    length = len;
    pos = x;
    for (int i = 0; i < len; ++i) {
        symbols.push_back(new Symbol(new Vector2(0, 0)));
    }
}

void Line::Generate() {
    for (int i = 0; i < symbols.size(); ++i) {
        int offset = length % 2 + i % 2;
        symbols[i]->SetPosition(pos + offset, i - symbols.size());
    }
    lastSymbolIndex = 0;
}

void Line::Move() {
    Symbol* s = symbols[lastSymbolIndex];
    short lastY = s->GetPosition().Y;
    int offset = length % 2 + s->GetPosition().X - pos;
    s->SetPosition(pos + offset, lastY + length);
    lastSymbolIndex = ++lastSymbolIndex % length;
}

void Line::Explode() {
    int index = lastSymbolIndex == 0 ? length - 1 : lastSymbolIndex - 1;
    Vector2 pos = symbols[index]->GetPosition();
    delete symbols[index];
    symbols.erase(symbols.begin() + index);
}

void Line::SetColor(int color) {
    for (auto s : symbols) {
        s->SetColor(color);
    }
}

Vector2 Line::GetLastSymbolPosition() {
    return symbols[lastSymbolIndex]->GetPosition();
}