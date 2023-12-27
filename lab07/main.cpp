#include "battlefield.h"
#include <iostream>

using namespace lab07;

int main() {
    std::shared_ptr<Battlefield> btf = std::make_shared<Battlefield>();
    btf->fill_randomly(time(NULL), 20,20,20);
    std::shared_ptr<OutputObserverBattlefield> obsO = std::make_shared<OutputObserverBattlefield>();
    btf->attach_obs(obsO);
    btf->battle();
    btf->remove_deadmen();
    std::cout << *btf;

    return 0;
}
