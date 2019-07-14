#include<cstdio>

char buf[1<<18];
int idx, nidx;

char read()
{
	if (idx == nidx) {
		nidx = fread(buf, 1, 1 << 18, stdin);
		idx = 0;
	}
	return buf[idx++];
}

inline int readInt()
{
	int sum = 0;
	int flg = 0;
	char now = read();

	while (now == ' ' || now == '\n') now = read();
	if (now == '-') flg = 1, now = read();
	while (now >= '0' && now <= '9') {
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? -sum : sum;
}
