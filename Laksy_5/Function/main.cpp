#include <iostream>
#include <algorithm>
#include <vector>

void take_damage_function(int& hp) {
    if (hp > 100) {
        hp -= 100;
    }
    else {
        hp = 0;
    }
}

int main() {
    std::vector<int> hitpoints = { 150, 200, 80, 30, 370 };

    std::for_each(hitpoints.begin(), hitpoints.end(), take_damage_function);

    std::sort(hitpoints.begin(), hitpoints.end(), [](int a, int b)
        {
            return a > b;
        });

    for (int hp : hitpoints) {
        std::cout << hp << " ";
    }

    return 0;
}