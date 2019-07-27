#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;
void find(string,int st, int strSize);
int calcu(int x, char p, int y);

string str;
int strSize = 0;
int maxRes = -2147483647;
int main() {
	int inpSize = 0;
	cin >> inpSize;
	cin.ignore();
	getline(cin, str);

	strSize = str.size();
	find(str.substr(0,2),2,str.size());//첫번째부터 괄호치는 건 노의미
	cout << maxRes << endl;

	getchar();
	getchar();
}
void find(string cop,int st,int copSize) {
	if (st >= strSize) {
		//cout << cop << endl;
		stack<int> temp;
		int res = 0;
		temp.push(atoi(&cop.at(0)));
		for (int i = 1; i < cop.size(); ++i) {
			char ch = cop.at(i);
			if (ch == 42 || ch == 43 || ch == 45 || ch == 47) {//연산자
				int t = temp.top();
				temp.pop();
				int m = 0;
				if (cop.at(i + 1) == '(') {//연산자 다음방이 숫자가 아니라 괄호라면
					m = calcu(atoi(&cop.at(i + 2)), cop.at(i + 3), atoi(&cop.at(i + 4)));
					i += 5;
				}
				else {
					m = atoi(&cop.at(++i));
				}
				temp.push(calcu(t, ch, m));//계산후 스택 삽입
			}
			else {
				temp.push(atoi(&ch));
			}
		}
		if (temp.top() > maxRes)maxRes = temp.top();

		return;
	}
	//cout << cop + str.substr(st, 2) << endl;
	find(cop+str.substr(st,2),st + 2, cop.size()+2);//괄호 안하고 다음 방

	if (st + 3 <= str.size()) {
		string sub = cop + '(' + str.substr(st, 3) + ')';
		if (st + 3 < str.size()) {
			sub.append( str.substr(st+3, 1));
		}
		find(sub,st+4,cop.size()+6);//괄호 하고 다음 방 
	}
}
int calcu(int x, char p, int y) {
	int res = 0;
	switch (p) {
	case '+':
		res = x + y;
		break;
	case '-':
		res = x - y;
		break;
	case '*':
		res = x * y;
		break;
	case '/':
		res = x / y;
		break;
	}
	return res;
}