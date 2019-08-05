#include <cstdio>

namespace in {
	const int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE + 1];
	int idx, ridx;

	inline char read() {
		if (idx == ridx) {
			ridx = fread(buf, 1, BUF_SIZE, stdin);
			idx = buf[ridx] = 0;
		}
		return buf[idx++];
	}
	inline int readint() {
		int res = 0;
		bool neg = 0;
		register char tmp = read();
		while (tmp < 33) tmp = read();
		if (tmp == '-') neg = 1, tmp = read();
		while (tmp >= 48 && tmp <= 57) {
			res = res * 10 + (tmp & 15);
			tmp = read();
		}
		return neg ? -res : res;
	}
	inline int readLine(char str[], register int len) {
        register char c = read();
        for (int i = 0; i < len; ++i) {
            if (c == '\n') {
                str[i] = '\0';
                return i;
            }
            str[i] = c;
            c = read();
        }
        str[len] = '\0';
        return len;
    }
}

namespace out {
	const int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE];
	int idx;

	inline void flush() {
		fwrite(buf, 1, idx, stdout);
	}
	inline void write(register char c) {
		if (idx == BUF_SIZE) {
			flush();
			idx = 0;
		}
		buf[idx++] = c;
	}
	inline void writeunsigned(unsigned u) {
		register char tmp[10], t = 0;
		while (u) {
			tmp[t++] = (u % 10) | 48;
			u /= 10;
		}
		while (t) {
			write(tmp[--t]);
		}
	}
	inline void writeint(int i) {
		if (i < 0) {
			unsigned u = -i;
			write('-');
			writeunsigned(u);
		} else {
			writeunsigned(i);
		}
	}
	inline void writestring(char str[]) {
		for (int i = 0; str[i] != '\0'; ++i) {
			write(str[i]);
		}
	}
}
