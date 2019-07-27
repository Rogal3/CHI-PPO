#include <cstdio>
namespace in {
    const int BUF_SIZE = 1 << 18;  // = 262,144
    char inbuf[BUF_SIZE];
    char* buf_end = inbuf + BUF_SIZE;
    char* buf_idx = buf_end;
    inline char get_c() {
        if (buf_idx == buf_end) {
            int size = fread(inbuf, 1, BUF_SIZE, stdin);
            buf_idx = inbuf;
            buf_end = inbuf + size;
        }
        return *buf_idx++;
    }
    inline int readInt() {
        bool neg = false;
        int sum = 0;
        char c = get_c();
        if (c == '-') {
            neg = true;
            c = get_c();
        }
        while ('0' <= c && c <= '9') {
            sum = sum * 10 + (c & 0xF);
            c = get_c();
        }
        return neg ? -sum : sum;
    }
    inline int readLine(char str[], int len) {
        char c = get_c();
        for (int i = 0; i < len; ++i) {
            if (c == '\n') {
                str[i] = '\0';
                return i;
            }
            str[i] = c;
            c = get_c();
        }
        str[len] = '\0';
        return len;
    }
}
