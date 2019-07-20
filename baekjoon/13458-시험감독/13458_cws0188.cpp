#include<iostream>
#include<vector>

using namespace std;

int N;
vector<int> vi;
int B, C;
long long ans;

void ReadInput() {
    scanf("%d ", &N);
    char c;
    int sum = 0;
    while ((c = getchar()) != '\n' ) {
        if ('0' <= c && c <= '9') {
            sum = sum * 10 + c - '0';
        } else {
            vi.push_back(sum);
            sum = 0;
        }
    }
    vi.push_back(sum);
    scanf("%d %d", &B, &C);
}

int main() {
    ReadInput();
    int left;
    for (auto i : vi) {
        ++ans;
        left = i - B;
        if (left > 0) {
            ans += left / C;
            if (left % C) {
                ++ans;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
