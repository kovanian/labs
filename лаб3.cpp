#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>


class String {
    char* str;
    int len;
public:
    String();  
    String(const char* string);
    String(const String&); 
    ~String();
    char getChar(const int pos) const;
    bool setChar(const char c, const int pos);
    void showStr() const;
    void bubbleSort();
    int getLen() const;
    int operator-(const String& string) const;
    void operator()(const char* string);
    friend String& operator--(String& string);
};

String::String() : str(0), len(0) { }   

String::String(const char* string)
{
    len = strlen(string);
    str = new char[getLen() + 1];
    strcpy(str, string);
}

String::String(const String& string)
{
    len = string.getLen();
    str = new char[getLen() + 1];
    strcpy(str, string.str);
}

String::~String()
{
    delete[] str;
}
int String::getLen() const { return len; }

char String::getChar(const int pos) const
{
    if (pos < getLen())
        return str[pos];
    return 0;
}

bool String::setChar(const char c, const int pos)
{
    if (pos < getLen()) {
        str[pos] = c;
        return true;
    }
    return false;
}

void String::showStr() const
{
    std::cout << str << '\n';
}

void String::bubbleSort()
{
    for (int i = 0; i < getLen(); ++i) {
        for (int j = 0; j < getLen() - i - 1; ++j) {
            if (str[j] < str[j + 1]) {
                char tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
}

int String::operator-(const String& string) const
{
    return getLen() - string.getLen();
}

void String::operator()(const char* string)
{
    delete[] str;
    len = strlen(string);
    str = new char[getLen() + 1];
    strcpy(str, string);
}

String& operator--(String& string) {
    char* new_str = new char[string.getLen()];
    string.setChar(0, string.getLen() - 1);
    strcpy(new_str, string.str);
    delete[] string.str;
    string.str = new_str;
    --string.len;
    return string;
}

int main() {
    srand(time(NULL));
    char* str = new char[257];
    std::cin.clear();
    std::cin.getline(str, 256);

    String string1(str);
    String string2 = string1;

    string1.showStr();
    string2.showStr();
    std::cout << '\n';

    int pos;
    char c;
    std::cin >> c >> pos;
    string1.setChar(c, pos);
    string1.showStr();

    --string1;
    string1.showStr();

    string1.bubbleSort();
    string1.showStr();
    std::cout << '\n';

    string1.showStr();
    if (string1 - string2 > 0)
        std::cout << "bigger than ";
    else if (string1 - string2 < 0)
        std::cout << "less than ";
    else
        std::cout << "equal ";
    string2.showStr();
    if (string1 - string2 != 0)
        std::cout << "on " << std::fabs(string1 - string2) << '\n';

    string1.showStr();
    string2.showStr();

    int n;
    std::cin >> n;
    String* arr = new String[n];
    for (int i = 0; i < n; ++i) {
        std::cin.get();
        std::cin.getline(str, 256);
        arr[i](str);
    }
    std::cout << '\n';
    for (int i = 0; i < n; ++i) {
        arr[i].showStr();
    }
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i].getChar(rand() % arr[i].getLen()) << '\n';
    }
    delete[] arr;
    delete[] str;
    return 0;
}
