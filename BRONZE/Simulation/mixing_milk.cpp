#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int N = 3;
const int TURN_NUM = 100;

int main() {
    freopen("mixmilk.in", "r", stdin);

    vector<int> capacity(N);

    vector<int> milk(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &capacity[i], &milk[i]);
    }

    for (int i = 0; i < TURN_NUM; i++) {
        int bucket1 = i % N;
        int bucket2 = (i + 1) % N;

        int amt = std::min(milk[bucket1], capacity[bucket2] - milk[bucket2]);
        milk[bucket1] -= amt;
        milk[bucket2] += amt;
    }

    freopen("mixmilk.out", "w", stdout);
    std::cout << milk[0] << std::endl;
    std::cout << milk[1] << std::endl;
    std::cout << milk[2] << std::endl;
}