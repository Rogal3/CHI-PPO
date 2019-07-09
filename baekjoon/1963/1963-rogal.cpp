#include<stdio.h>

struct e{
    int p;
    int t;
    e() {}
    e(int _p, int _t) : p(_p), t(_t) {}
};

class queue{
    public:
    queue() { clear(); }
    void push(e _e) {
        q[front++] = _e;
    }
    e pop() { return q[back++]; }
    void clear() { front = 0, back = 0; }
    bool empty() { return front == back; }
    private:
    e q[10000];
    int front;
    int back;
};

int T;
int begin;
int end;
int prime[10000] = {2, 3};
int primeSize = 2;
bool primeIDX[10000];
int ans;
queue q;

void calcPrime() {
    bool flag;
    for (int p = 5; p < 10000; p += 2) {
        flag = false;
        for (int i = 0; i < primeSize; ++i) {
            int curP = prime[i];
            if (p < curP * curP) break;
            if (p % curP == 0) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            prime[primeSize++] = p;
        }
    }
}

void initPrimeIDX() {
    for (int i = 0; i < 10000; ++i) {
        primeIDX[i] = false;
    }
    for (int i = 0; i < primeSize; ++i) {
        primeIDX[prime[i]] = true;
    }
}

int sidePrime(int p, int n, int t) {
    const int exp10[] = {0, 1, 10, 100, 1000};
    int digit = exp10[n];
    return p - (p / digit % 10) * digit + t * digit;
}

void bfs() {
    ans = 0;
    q.clear();
    q.push(e(begin, 0));
    while (!q.empty()) {
        e e0 = q.pop();
        if (e0.p == end) {
            ans = e0.t;
            return;
        }
        for (int n = 1; n <= 3; ++n) {
            for (int t = 0; t <= 9; ++t) {
                int side = sidePrime(e0.p, n, t);
                if (primeIDX[side]) {
                    primeIDX[side] = false;
                    q.push(e(side, e0.t + 1));
                }
            }
        }
        for (int t = 1; t <= 9; ++t) {
            int side = sidePrime(e0.p, 4, t);
            if (primeIDX[side]) {
                primeIDX[side] = false;
                q.push(e(side, e0.t + 1));
            }
        }
    }
    ans = -1;
}

int main() {
    scanf("%d", &T);
    calcPrime();
    while (T--) {
        scanf("%d %d", &begin, &end);
        initPrimeIDX();
        bfs();
        if (ans == -1) {
            puts("Impossible\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
