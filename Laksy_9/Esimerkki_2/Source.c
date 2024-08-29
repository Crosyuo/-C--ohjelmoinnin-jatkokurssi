#include <stdio.h>
#include <time.h>

#define ITERATIONS 10000000
#define ROWS 25
#define COLS 40
char screen_mem[ROWS][COLS];

inline void scroll_up();

int main()
{
    clock_t t1, t2;
    int i;

    t1 = clock();
    for (i = 0; i < ITERATIONS; ++i)
    {
        scroll_up();
    }
    t2 = clock();
    printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
    printf("Kuinka paljon enemmän muistia optimoitu versio kuluttaa: molemmat versiot kuluttavat saman määrän muistia\n");
    printf("Kuinka paljon nopeammin optimoitu versio toimii: (original: 19.4 sec / optimized: 11.8 sec)\n");

    return 0;
}

inline void scroll_up()
{
    int r, c;
    for (r = 1; r < ROWS; r += 5)
    {
        for (c = 0; c < COLS; ++c)
        {
            screen_mem[r - 1][c] = screen_mem[r][c];
            screen_mem[r - 0][c] = screen_mem[r + 1][c];
            screen_mem[r + 1][c] = screen_mem[r + 2][c];
            screen_mem[r + 2][c] = screen_mem[r + 3][c];
            screen_mem[r + 3][c] = screen_mem[r + 4][c];
        }
    }
}
