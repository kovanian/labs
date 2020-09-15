#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void intoASСII(int i) {
	cout << oct << i << endl;
	cout << hex << i << endl;
	return;
}

void intoASСII(char sym) {
	char res = tolower(sym);
	cout << res << endl;
	return;
}

int main()
{
	char buf[255];
	int norm = 0;
	setlocale(LC_ALL, "Russian");
	cout << "Введите символ или число: " << endl;
	cin >> buf;
	for (int i = 0; i < strlen(buf); i++)
	{
		if ((buf[i]) >= '0' && (buf[i]) <= '9')
		{
			continue;
		}
		else
			norm = 1;
	}
	if (norm == 0) {
		int num = atoi(buf);
		intoASСII(num);
	}
	else {
		char sym = buf[0];
		intoASСII(sym);
	}
	system("pause");
	return 0;
}