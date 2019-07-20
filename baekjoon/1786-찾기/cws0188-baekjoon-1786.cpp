#include<iostream>
#include<vector>

using namespace std;

const int STR_MAX = 1000000;
char str[STR_MAX + 1];
char pattern[STR_MAX + 1];
int pi[STR_MAX + 1];
int patternSize;
vector<int> ans;

void preprocess() {
    char c;
    int j = 0;
    for (patternSize = 1; (c = pattern[patternSize]) != '\0'; ++patternSize) {
        while (j > 0 && c != pattern[j]) {
            j = pi[j];
        }
        if (c == pattern[j]) {
            pi[patternSize + 1] = ++j;
        }
    }
}

void kmp() {
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        while (j > 0 && str[i] != pattern[j]) {
            j = pi[j];
        }
        if (str[i] == pattern[j]) {
            if (patternSize <= ++j) {
                ans.push_back(i - j + 2);
                j = pi[j];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin.getline(str, STR_MAX + 1);
    cin.getline(pattern, STR_MAX + 1);
    preprocess();
    kmp();
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d\n", i);
    }
    return 0;
}
