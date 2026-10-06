#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int room_num;
    cin >> room_num;
    vector<int> rooms(room_num);
    int total_cows = 0;
    for (int i = 0; i < room_num; i ++) {
        cin >> rooms[i];
        total_cows += rooms[i];
    }

    int min_dist = 999999999;
    for (int unlock = 0; unlock < room_num; unlock++) {
        int dist = 0;
        int cows_left = total_cows;
        for (int r = 0; r < room_num; r++) {
            cows_left -= rooms[(unlock + r) % room_num];
            dist += cows_left;
        }
        min_dist = min(dist, min_dist);
    }
    cout << min_dist;
    return 0;
}
