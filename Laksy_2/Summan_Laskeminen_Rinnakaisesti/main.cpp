#include <iostream>
#include <thread>
#include <vector>
#include <numeric>


std::vector<int> taulukko(1000000, 1);

void laske_summa(int alku, int loppu, int& tulos) {
    tulos = std::accumulate(taulukko.begin() + alku, taulukko.begin() + loppu, 0);
}

int main() {
    int summa1 = 0;
    int summa2 = 0;

    std::thread th1(laske_summa, 0, 500000, std::ref(summa1));
    std::thread th2(laske_summa, 500000, 1000000, std::ref(summa2));

    th1.join();
    th2.join();

    int vastaus = summa1 + summa2;

    std::cout << "Lopputulos: " << vastaus << std::endl;

    return 0;
}