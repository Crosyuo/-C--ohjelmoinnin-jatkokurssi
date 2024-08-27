#include <iostream>
#include <vector>
#include <numeric>
#include <future>


std::vector<int> taulukko(1000000, 1);

int laske_summa(int alku, int loppu) {
    return std::accumulate(taulukko.begin() + alku, taulukko.begin() + loppu, 0);
}

int main() {
    std::future<int> summa1 = std::async(std::launch::async, laske_summa, 0, 500000);
    std::future<int> summa2 = std::async(std::launch::async, laske_summa, 500000, 1000000);

    int vastaus = summa1.get() + summa2.get();

    std::cout << "Lopputulos: " << vastaus << std::endl;

    return 0;
}