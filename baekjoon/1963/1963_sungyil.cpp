#include <iostream>

using namespace std;
int finds();
void pri();

int t = 0;
int st, ed;
int day = 0;
bool num[10000] = { false, };
int main() {
	
	cin >> t;
	
	pri();

	for (int i = 0; i < t; ++i) {
		cin >> st;
		cin >> ed;

		while (st != ed) {
			if (finds() == -1) {
				day = -1;
				break;
			}
			cout << day << endl;
			getchar();
		}

		if (day != -1) {
			cout << day << endl;
		}
		else {
			cout << "Impossible" << endl;
		}
	}


	getchar();
	getchar();
}
int finds() {
	int che = 0;
	if (st < ed) {
		for (int i = (st/1000)+1; i <= ed/1000; ++i) {
			if (num[st + (i * 1000 - (st / 1000) * 1000)]) {
				st = st + (i * 1000 - (st / 1000) * 1000);
				che = 1;
			}
		}
		cout <<"1천의자리" <<st << endl;
	}
	else {
		for (int i = (st / 1000) -1; i >= ed / 1000; --i) {
			if (num[st + ((st / 1000) * 1000)-i * 1000 ]) {
				st = st + ((st / 1000) * 1000-i * 1000);
				che = 1;
			}
		}
		cout << "2천의자리" << st << endl;
	}

	if (che != 1) {
		int sta = st % 1000 / 100;
		int eda = ed % 1000 / 100;
		if (st / 1000 == ed / 1000) {
			if (sta< eda) {
				for (int i = sta+1; i <= eda; ++i) {
					if (num[st + (sta * 100 - i * 100)]) {
						st = st + (sta * 100 - i * 100);
						che = 2;
					}
				}
			}else {
				for (int i = eda-1; i >= sta; --i) {
					if (num[st + (sta * 100 - i * 100)]) {
						st = st + (sta * 100 - i * 100);
						che = 2;
					}
				}
			}
			cout << "1백의자리 " << st << endl;
		}
		else {
			for (int i = 0; i < 10; ++i) {
				if (num[st + (i * 100-((st % 1000) / 100) *100)]) {
					st = st + (i * 100 - ((st % 1000) / 100) * 100);
					che = 2;
				}
			}
			cout << "2백의자리 " << st << endl;
		}
	}

	if (che != 1 && che != 2) {
		if (st/100==ed/100) {
			int sta = st % 100 / 10;
			int eda = ed % 100 / 10;
			if (sta < eda) {
				for (int i = sta+1; i <= eda; ++i) {
					if (num[st + (sta * 10 - i * 10)]) {
						st = st + (sta * 10 - i * 10);
						che = 3;
					}
				}
			}
			else {
				for (int i = sta-1; i >= eda; --i) {
					if (num[st + (sta * 10 - i * 10)]) {
						st = st + (sta * 10 - i * 10);
						che = 3;
					}
				}
			}
			cout << "1십의자리" << st << endl;
		}
		else {
			for (int i = 0; i < 10; ++i) {
				if (num[st + (st % 100 / 10 * 10 - i * 10)]) {
					st = st + (st % 100 / 10 * 10 - i * 10);
					che = 3;
				}
			}
			cout << "2십의자리" << st << endl;
		}
	}

	if (che != 1 && che != 2&&che!=3) {
		if (st / 10 == ed / 10) {
			
			if (st % 10 < ed % 10) {
				for (int i = st % 10 + 1; i <= ed % 10; ++i) {
					if (num[st + (st % 10 - i)]) {
						st = st + (st % 10 - i);
						che = 4;
					}
				}
			}
			else {
				for (int i = st % 10 - 1; i >= ed % 10; --i) {
					if (num[st + (st % 10 - i)]) {
						st = st + (st % 10 - i);
						che = 4;
					}
				}
			}
			cout << "1일의자리" << st << endl;
		}
		else {
			for (int i =0; i < 10; ++i) {
				if (num[st + (st % 10 - i)]) {
					st = st + (st % 10 - i);
					che = 4;
				}
			}
			cout << "2일의자리" << st << endl;
		}
	}
	
	if (che == 0) {
		return -1;
	}
	return ++day;
}

void pri() {
	for (int i = 2; i < 10000; ++i) {
		if (num[i]==false) {
			for (int j = i * 2; j < 10000; j += i) {
				num[j] = true;
			}
		}
	}
	for (int i = 0; i < 10000; ++i) {
		num[i] = !num[i];
	}
}