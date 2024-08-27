#include <iostream>
#include <mutex>
#include <future>

int pankkitili = 0;
std::mutex pankkitili_mutex;

void talleta(int maara, int loop) {
    for (int i = 0; i < loop; ++i) {
        std::lock_guard<std::mutex> lock(pankkitili_mutex);
        pankkitili += maara;
    }
}

void nosta(int maara, int loop) {
    for (int i = 0; i < loop; ++i) {
        std::lock_guard<std::mutex> lock(pankkitili_mutex);
        pankkitili -= maara;
    }
}

int main() {
    int maara = 2;
    int loop = 1000000;

    std::future<void> talletus = std::async(std::launch::async, talleta, maara, loop);
    std::future<void> nosto = std::async(std::launch::async, nosta, maara, loop);

    talletus.get();
    nosto.get();

    std::cout << "Tilin saldo: " << pankkitili << std::endl;

    return 0;
}
