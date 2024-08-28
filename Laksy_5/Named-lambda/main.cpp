#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> hitpoints = { 150, 200, 80, 30, 370 };

    auto take_damage_named_lambda = [](int& hp) {
        if (hp > 100) {
            hp -= 100;
        }
        else {
            hp = 0;
        }
        };

    std::for_each(hitpoints.begin(), hitpoints.end(), take_damage_named_lambda);

    std::sort(hitpoints.begin(), hitpoints.end(), [](int a, int b)
        {
            return a > b;
        });

    for (int hp : hitpoints) {
        std::cout << hp << " ";
    }

    return 0;
}