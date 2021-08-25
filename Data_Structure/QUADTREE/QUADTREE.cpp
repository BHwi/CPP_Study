#include<iostream>
#include<string>
using namespace std;

string quard(string::iterator& it) {
	char head = *it;
	++it;
	// 기저사실
	
	if (head == 'b' || head == 'w')
		return string(1, head);
	//x인 경우에는 또다시 4개로 분할이 이루어지기 때문에 재귀로 다시 불러오게 됩니다.
	string one = quard(it);
	string two = quard(it);
	string three = quard(it);
	string four = quard(it);

	//one은 왼쪽 위, two는 오른쪽 위, three는 왼쪽 아래, four는 오른쪽 아래를 나타냅니다.
	//return할때 상하의 위치를 바꿉니다.
	return string("x") + three + four + one + two;
}

int main() {
	int num;
	string str;
	cin >> num;

	while (num--) {
		cin >> str;
		string::iterator iter = str.begin();
		cout << quard(iter) << endl;
	}

	system("read");

	return 0;
}