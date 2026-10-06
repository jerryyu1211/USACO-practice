#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<int> count_freq(string s) {
    vector<int> freq(26);
    for (char c: s) {
        freq[c - 'a']++;
    }
    return freq;
}

int main() {
    ifstream fin ("blocks.in");
    ofstream fout("blocks.out");
    int N;
    int count[26] = {0};
    string A, B;

    fin >> N;
    
    
    for (int i = 0; i < N; i++) {
        fin >> A >> B;
        vector<int> freq1 = count_freq(A);
        vector<int> freq2 = count_freq(B);

        for (int c = 0; c < 26; c++) {
            count[c] += max(freq1[c], freq2[c]);
        }
    }
    for (int i =0; i < 26; i++) {
        fout << count[i] << endl;
    }
    return 0;

}
