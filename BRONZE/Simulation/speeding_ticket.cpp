#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>


int main() {
    const int tracklength = 100;
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N;
    int M;

    scanf("%d %d", &N, &M);
    std::vector<int> length(N), speed(N);
    std::vector<int> cowlength(M), cowspeed(M);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &length[i], &speed[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d", &cowlength[i], &cowspeed[i]);
    }
    
    
    std::vector<int> limit(100);
    std::vector<int> bessie(100);

    int start = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < length[i]; j++) {
            limit[j + start] = speed[i];
        }
        start += length[i];
    }

    start = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < cowlength[i]; j++) {
            bessie[j + start] = cowspeed[i];
        }
        start += cowlength[i];
    }

    int worst = 0;
    for (int i = 0; i < 100; i++) {
        worst = std::max(worst, bessie[i] - limit[i]);
    }
    std::cout << worst << std::endl;
    return 0;
}
