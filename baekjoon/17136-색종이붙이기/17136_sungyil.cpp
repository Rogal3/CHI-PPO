#include <iostream>
using namespace std;
void finds(int bang, int colorSize);

int paper[10][10] = { 0, };
int colorP[5] = { 5,5,5,5,5 };
int leftPaper = 0;
int cnt = 0;
int main() {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; ++j) {
			cin >> paper[i][j];
			if (paper[i][j] == 1)leftPaper++;
		}
	}

	for (int i = 0; i < 5; i++) {
		finds(i, 5 - i);
	}
	if (leftPaper == 0) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
	getchar();
	getchar();
}
void finds(int bang, int colorSize) {//��� ������ ū�ַ� ������. ū�ָ��� ������ ����
	int che = 0;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {

			if (paper[i][j] == 1&&colorP[bang]!=0) {//������� ���̰� ������
				che = 0;
				for (int h = 0; h < colorSize; ++h) {//���� ���� Ž��
					for (int k = 0; k < colorSize; ++k) {
						che += paper[i + h][j + k];
					}
				}
				if (che == colorSize * colorSize) {//�� ������ �ִٸ�
					for (int h = 0; h < colorSize; ++h) {//���� ������.
						for (int k = 0; k < colorSize; ++k) {
							paper[i + h][j + k]=0;
						}
					}
					cnt++;
					colorP[bang]--;
					leftPaper -= colorSize * colorSize;
				}
			}

		}
	}
}