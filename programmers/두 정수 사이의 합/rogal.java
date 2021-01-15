class Solution {
    public long solution(int a, int b) {
        return (long)(a + b) * ((a < b ? (b - a) : (a - b)) + 1) / 2;
    }
}
