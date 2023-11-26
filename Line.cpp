#include "Line.h"
#include "Extension.h"

Line::Line(unsigned short len, unsigned short x) {
    length = len;
    pos = x;
    for (int i = 0; i < len; ++i) {
        auto s = std::make_unique<Symbol>(Vector2());
        symbols.push_back(std::move(s));
    }
}

void Line::Generate() {
    for (int i = 0; i < symbols.size(); ++i) {
        int offset = length % 2 + i % 2;
        symbols[i]->SetPosition(pos + offset, i - symbols.size());
    }
    lastSymbolIndex = 0;
}

int Line::Move() {
    auto s = symbols[lastSymbolIndex].get();
    short lastY = s->GetPosition().Y;
    int offset = length % 2 + s->GetPosition().X - pos;
    s->SetPosition(pos + offset, lastY + length);
    lastSymbolIndex = ++lastSymbolIndex % length;
    return lastY;
}

Vector2 Line::Explode() {
    int index = lastSymbolIndex == 0 ? length - 1 : lastSymbolIndex - 1;
    Vector2 pos = symbols[index]->GetPosition();
    symbols.erase(symbols.begin() + index);
    length--;
    if (lastSymbolIndex >= length) lastSymbolIndex = length - 1;
    return pos;
}

void Line::SetColor(int color) {
    for (const auto & s : symbols) {
        s->SetColor(color);
    }
}

Vector2 Line::GetLastSymbolPosition() {
    return symbols[lastSymbolIndex]->GetPosition();
}