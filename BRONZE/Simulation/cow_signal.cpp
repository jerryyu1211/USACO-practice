#include <algorithm> 
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main () {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int N;
    int M;
    int K;

    scanf("%d %d %d", &N, &M , &K);

    string original;
    string line;
    for (int i = 0; i < N; i++) {
        std::cin >> original;

        string line = "";

        for (int j = 0; j < M; j++) {
            for (int r = 0; r < K; r++) {
                line += original[j];
            }
        }

        for (int p = 0; p < K; p++) {
            std::cout << line << endl;
        }
    }
    return 0;
}
