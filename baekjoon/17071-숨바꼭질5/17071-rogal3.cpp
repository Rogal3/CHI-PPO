#include <cstdio>

const int X_MAX = 500000;

class Queue {
    public:
        Queue() : head(0), tail(0) {con_ = new int[X_MAX * 2 + 1];}
        ~Queue() {if (con_) delete[] con_;}
        int &front() {return con_[head];}
        void push(const int &i) {con_[tail++] = i;}
        void pop() {if (head < tail) ++head;}
        int size() {return tail - head;}
    private:
        int *con_;
        int head;
        int tail;
};

int N, K;
int sister[X_MAX + 1];
int *subin;
int ans = 0x7FFFFFFF;

void sisterMarking(int x) {
    for (int t = 0; x + t <= X_MAX; ++t) {
        x += t;
        sister[x] = t + 1;
    }
}

int subinMove(const int &x, const int &mode) {
    switch (mode) {
        case 0:
            return x - 1;
        case 1:
            if (x < X_MAX) {
                return x + 1;
            } else {
                return -1;
            }
        case 2:
            if (x * 2 <= X_MAX) {
                return x * 2;
            } else {
                return -1;
            }
    }
    return -1;
}

void bfs(const int &x) {
    Queue q;
    subin[x * 2 + 1] = 1;
    q.push(x);
    int t = 1;
    while (q.size()) {
        for (int left_t = q.size(); 0 < left_t; --left_t) {
            int now = q.front();
            if (t <= sister[now]) {
                int term = sister[now] - t;
                if (!(term & 1)) {
                    if (t + term < ans)
                        ans = t + term;
                }
            }
            q.pop();
            int nt = t + 1;
            int odd = nt & 1;
            for (int mode = 0; mode < 3; ++mode) {
                int next = subinMove(now, mode);
                if (next != -1 && !subin[next * 2 + odd]) {
                    subin[next * 2 + odd] = nt;
                    q.push(next);
                }
            }
        }
        ++t;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    subin = new int[(X_MAX * 2 + 1) * 2];
    sisterMarking(K);
    bfs(N);
    printf("%d", ans == 0x7FFFFFFF ? -1 : ans - 1);
    delete[] subin;
    return 0;
}
