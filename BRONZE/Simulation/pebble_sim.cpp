// USACO Bronze Learning
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector> 


using std::vector;

int main() {
    std::freopen("shell.in", "r", stdin);
    std::freopen("shell.out", "w", stdout);
    int n;
    std::cin >> n;
    vector<int> a(n), b(n), g(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i] >> g[i];
    }

    vector<int> scores(3);
    int pebble_pos; //shell position variable
    int score;
    for (int i = 1; i <= 3; i++) {
        pebble_pos = i;
        score = 0;
        
        for (int j = 0; j < n; j++) {
            if (pebble_pos == a[j]) {
                pebble_pos = b[j];
            }
            else if (pebble_pos == b[j]) {
                pebble_pos = a[j];
            }
            if (pebble_pos == g[j]) {
                score++;
            }
        }
        scores[i-1] = score;
    }
    std::cout << std::max({scores[0], scores[1], scores[2]})<< std::endl;
    return 0;
}