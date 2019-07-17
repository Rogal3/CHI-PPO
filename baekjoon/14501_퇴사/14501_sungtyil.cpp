#include <iostream>
#include <queue>
using namespace std;
void finds( int ,int);

int check[16] = { 0 };
pair<int, int> day[16];//���Ⱓ, ���º��
int money = 0;

int n;
int main() {
	cin >> n;
	int d, m;
	for (int i = 1; i <= n; ++i) {
		cin >> d >> m;
		day[i].first = d;
		day[i].second = m;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (check[i] != 1) {//ù°�� üŷ�ȵ������� üŷ�ϸ鼭 ����
			check[i] = 1;
			finds(day[i].second,i);
		}
		else {
			break;
		}
	}
	cout << money << endl;

	getchar();
	getchar();
}
void finds(int empMoney,int start) {
	int next = day[start].first + start;
	if (next > n) {//next�� �������� ���� ũ�ٸ� ����� ����
		if (next > n + 1) {
			empMoney -= day[start].second;
		}
		if (empMoney > money) {
			money = empMoney;
		}
		return;
	}
	check[start] = 1;
	for (int i = next; i <= n; ++i) {//�������� �� ���̵� ���ȣ��
		finds(empMoney + day[i].second, i);
	}

	return;
}