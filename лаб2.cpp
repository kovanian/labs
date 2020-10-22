#include <iostream>
#include <string>
#include <iomanip>
#include <locale.h>

using namespace std;

class Student {

private:
	int id;
	string name;
	int rate;
public:
	friend class Decan;

	Student() {   //ум
		id = 0;
		name = "";
		rate = 0;
	}

	//инит
	Student(int def_id, string def_name, int def_rate) :id(def_id), name(def_name), rate(def_rate) {};

	Student(const Student& S) :  //коп
		id(S.id),
		name(S.name),
		rate(S.rate) {};

	~Student() {};

	friend void Ratett(Student& student);
};


class Decan {

public:
	Decan() {};
	~Decan() {};

	void S_Rate(Student& student) {
		std::cout << "Рейтинг:\n ";
		std::cin >> student.rate;
	}
};

void Ratett(Student& student)
{
	cout << "Id:" << student.id << endl;
	cout << "ФИО:" << student.name << endl;
	cout << "Рейтинг:" << student.rate << endl;
}

int getValue()
{
	while (true)
	{
		int a;
		std::cin >> a;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Ошибка!\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return a;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Student stud_ms[5];
	Decan rate_z;
	Ratett(stud_ms[0]);
	cout << "================" << endl;

	Student def(16, "Контанистов Иван Александрович", 6);
	Ratett(def);

	cout << "================" << endl;
	int ids, r, i, n, sw = 1;
	string name;
	for (i = 1; i < 5; i++)
	{

		cout << "id студента №" << i << endl;
		ids = getValue();
		cout << "ФИО студента №" << i << endl;
		cin >> name;
		cout << "Рейтинг №" << i << endl;
		r = getValue();
		stud_ms[i] = { ids,name, r };
		cout << endl;
	}
	cout << "================" << endl;
	for (i = 1; i < 5; i++) {
		Ratett(stud_ms[i]);
	}
	cout << "================" << endl;
	for (i = 1; i < 5; i++) {
		cout << "Рейтинг №" << i << endl;
		rate_z.S_Rate(stud_ms[i]);
	}
	system("CLS");
	cout << "Рейтинг:" << endl;

	for (i = 1; i < 5; i++)
	{
		cout << "Студент №" << i << endl;
		Ratett(stud_ms[i]);
	}

	system("pause");
}