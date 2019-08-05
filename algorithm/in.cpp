#include <cstdio>

namespace in {
	const int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE + 1];
	char *ite, *end = ite;

	inline char read() {
		if (ite == end) {
			end = buf + fread(buf, 1, BUF_SIZE, stdin);
			*end = 0;
			ite = buf;
		}
		return *ite++;
	}
	inline int readint() {
		unsigned res = 0;
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
	inline int readline(char str[], register int len) {
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
	char *ite = buf;
	const char *END = buf + BUF_SIZE;

	inline void flush() {
		fwrite(buf, 1, ite - buf, stdout);
		ite = buf;
	}
	inline void write(register char c) {
		if (ite == END) {
			flush();
		}
		*ite++ = c;
	}
	inline void writeunsigned(register unsigned u) {
		register char tmp[10], t = 0;
		while (u) {
			tmp[t++] = (u % 10) | 48;
			u /= 10;
		}
		while (t) {
			write(tmp[--t]);
		}
	}
	inline void writeint(const int &i) {
		if (i & 0x80000000) {
			unsigned u = -i;
			write('-');
			writeunsigned(u);
		} else {
			writeunsigned(i);
		}
	}
	inline void writestring(const char str[]) {
		for (int i = 0; str[i] != '\0'; ++i) {
			write(str[i]);
		}
	}
}
