#include "factory_npc.h"
#include <iostream>

using namespace lab06;

int main() {
    FactoryNPC f;
    NPC* npc = f.create(BEAR, "bear_name");
    std::cout << npc->name() << std::endl;

    return 0;
}
