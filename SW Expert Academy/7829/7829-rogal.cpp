#include<stdio.h>
 
int TC;
int P;
int first;
int last;
int ans;
 
int main() {
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        scanf("%d", &P);
        scanf("%d", &first);
        last = first;
        int divisor;
        while (--P) {
            scanf("%d", &divisor);
            first = first > divisor ? divisor : first;
            last = last > divisor ? last : divisor;
        }
        ans = first * last;
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}
