#include <cstdio>
const int BUF_SIZE = 1 << 20;
namespace in {
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
}

namespace out {
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
	inline void writeint(int i) {
		register char tmp[8], t = 0;
		while (i) {
			tmp[t++] = (i % 10) | 48;
			i /= 10;
		}
		while (t) {
			write(tmp[--t]);
		}
	}
}
