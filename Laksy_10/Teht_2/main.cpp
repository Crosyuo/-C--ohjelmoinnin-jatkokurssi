#include <iostream>

int* varaa_taulukko(int n) {
	int* location = new int[n];
	return location;
}

void lue_arvot(int* t, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Syota kokonaisluku taulukkoon: ";
		std::cin >> t[i];
	}
}

void kaanna(int* t, int n) {
	int temp;

	for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
		temp = t[i];
		t[i] = t[j];
		t[j] = temp;
	}
}

void tulosta_arvot(const int* t, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << t[i] << std::endl;
	}
}

int main() {
	int koko = 5;
	int* taulukko = varaa_taulukko(koko);
	std::cout << taulukko << std::endl;

	lue_arvot(taulukko, koko);

	tulosta_arvot(taulukko, koko);

	kaanna(taulukko, koko);

	std::cout << "\nKaannetty taulukko:\n";
	tulosta_arvot(taulukko, koko);

	delete[] taulukko;
	taulukko = nullptr;

	std::cout << taulukko;

	return 0;
}