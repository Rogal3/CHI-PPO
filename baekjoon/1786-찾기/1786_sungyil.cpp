#include <iostream>
#include <string>
using namespace std;

string t;
string p;

int counter = 0;
int findS[1000000];
int main() {
	
	getline(cin, t);
	cin.clear();
	getline(cin, p);
	int i = 0;//t�� 
	int j = 0;//p��
	int che = 0;//t�� p�� ������ ������ ����� ��Ÿ�� -1�̸� �Ȱ���

	//cout << t.size() << " " << p.size() << endl << endl;
	while (i != t.size()) {
		
		for (; j < p.size(); ++j) {
			if (p.at(che) == t.at(j+i)) {
				che++;
			}
			else {
				che = 0;
				if (p.at(che) == t.at(j + i)) {
					che++;
				}
			}
		}

		i++;//������ �Ѿ
		//cout << "che= " << che << " i= " << i << endl;
		if (che == p.size()) {
			findS[counter] = i;
			counter++;
			che = 0;
			j = 0;
		}
		else {
			j = che;
		}
		if (i + p.size() > t.size())break;

	}

	cout << counter << endl;
	for (int i = 0; i < counter; ++i) {
		cout << findS[i] << endl;
	}

	getchar();
	getchar();
}