#include <iostream>
#include "Manager.h"

int main() {
    auto manager = std::make_unique<Manager>();
    manager.get()->Simulate();

    return 0;
}

