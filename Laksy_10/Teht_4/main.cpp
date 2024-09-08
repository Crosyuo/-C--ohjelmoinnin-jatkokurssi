#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

int* varaa_taulukko(int n);
void lue_arvot(int* t, int n);
void lue_arvot_mock(int* t, int n, const int values[]);
void kaanna(int* t, int n);

int* varaa_taulukko(int n) {
    int* location = new int[n];
    return location;
}

void lue_arvot_mock(int* t, int n, const int values[]) {
    for (int i = 0; i < n; i++) {
        t[i] = values[i];
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

TEST_CASE("Test varaa_taulukko with size 5") {
    int koko = 5;
    int* taulukko = varaa_taulukko(koko);

    REQUIRE(taulukko != nullptr);

    delete[] taulukko;
}

TEST_CASE("Test lue_arvot_mock with specific input") {
    int koko = 3;
    int taulukko[3];
    int values[3] = { 10, 20, 30 };

    lue_arvot_mock(taulukko, koko, values);

    CHECK(taulukko[0] == 10);
    CHECK(taulukko[1] == 20);
    CHECK(taulukko[2] == 30);
}

TEST_CASE("Test kaanna with odd number of elements") {
    int koko = 5;
    int taulukko[5] = { 1, 2, 3, 4, 5 };

    kaanna(taulukko, koko);

    CHECK(taulukko[0] == 5);
    CHECK(taulukko[1] == 4);
    CHECK(taulukko[2] == 3);
    CHECK(taulukko[3] == 2);
    CHECK(taulukko[4] == 1);
}

TEST_CASE("Test kaanna with even number of elements") {
    int koko = 4;
    int taulukko[4] = { 10, 20, 30, 40 };

    kaanna(taulukko, koko);

    CHECK(taulukko[0] == 40);
    CHECK(taulukko[1] == 30);
    CHECK(taulukko[2] == 20);
    CHECK(taulukko[3] == 10);
}

TEST_CASE("Test kaanna with single element") {
    int koko = 1;
    int taulukko[1] = { 99 };

    kaanna(taulukko, koko);

    CHECK(taulukko[0] == 99);
}

TEST_CASE("Test kaanna with empty array") {
    int koko = 0;
    int* taulukko = varaa_taulukko(koko);

    kaanna(taulukko, koko);

    CHECK(taulukko != nullptr);

    delete[] taulukko;
}
