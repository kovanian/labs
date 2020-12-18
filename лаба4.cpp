#include <iostream>
#include <clocale>
#include <cstring>

using namespace std;

class stajer
{
protected:
    string mesto_stajirovki;
    int srok_stajirovki;
    int kolvo_zadaniy;
    string oplata_st;

public:
    stajer() {
        mesto_stajirovki = "EPAM";
        srok_stajirovki = 1;
        kolvo_zadaniy = 1;
        oplata_st = "нет";
    }

    stajer(string _mesto_stajirovki, int _srok_stajirovki, int _kolvo_zadaniy, string _oplata_st) :mesto_stajirovki(_mesto_stajirovki), srok_stajirovki(_srok_stajirovki), kolvo_zadaniy(_kolvo_zadaniy), oplata_st(_oplata_st) {};

    void Show_stajer()
    {
        cout << endl << "--------- Стажировка ---------" << endl;
        cout << "Место стажировки :" << mesto_stajirovki << std::endl;
        cout << "Длительность:" << srok_stajirovki << std::endl;
        cout << "Количество заданий :" << kolvo_zadaniy << std::endl;
        cout << "Зарплата во время стажировки :" << oplata_st << std::endl;
    }

    ~stajer() {};
};

class naviki : virtual public stajer
{
protected:
    string yap;
    string buhgalteria;
    string rabota_s_OS;

public:
    naviki() {

        yap = "да";
        buhgalteria = "нет";
        rabota_s_OS = "нет";
    }

    naviki(string _yap, string _buhgalteria, string rabota_s_OS) :yap(_yap), buhgalteria(_buhgalteria), rabota_s_OS(rabota_s_OS) {};

    void Show_naviki()
    {
        cout << endl << "--------- Требуемые навыки ---------" << endl;
        cout << "Знание ЯП:" << yap << std::endl;
        cout << "Работа в бухгалтерских программах :" << buhgalteria << std::endl;
        cout << "Работа с различными ОС :" << rabota_s_OS << std::endl;
    }

    ~naviki() {};

};

class obiazannosti : virtual public naviki
{
protected:
    string local_network;
    string dop_obiazannosti;
    int tehnika;

public:

    obiazannosti() {
        local_network = "Есть";
        dop_obiazannosti = "Вышивание крестиком";
        tehnika = 15;
    }
    obiazannosti(string _local_network, string _dop_obiazannosti, int _tehnika) :local_network(_local_network), dop_obiazannosti(_dop_obiazannosti), tehnika(_tehnika) {}

    void Show_obiazannosti()
    {
        cout << endl << "--------- Обязанности ---------" << endl;
        cout << "Поддержка локальной сети :" << local_network << std::endl;
        cout << "Дополнительные обязанности :" << dop_obiazannosti << std::endl;
        cout << "Количество обслуживаемой техники :" << tehnika << std::endl;
    }
    ~obiazannosti() {};


};

class obrazovanie : virtual public stajer
{
protected:
    string st_ucherezhdenia;
    string name;
    int kolvo_spets;

public:
    obrazovanie() {
        st_ucherezhdenia = "ВУЗ";
        name = "БГУИР";
        kolvo_spets = 3;
    };

    obrazovanie(string _st_ucherezhdenia, string _name, int _kolvo_spets) :st_ucherezhdenia(_st_ucherezhdenia), name(_name), kolvo_spets(_kolvo_spets) {}

    void Show_obrazovanie()
    {
        cout << endl << "--------- Образование ---------" << endl;
        cout << "Статус учреждения :" << st_ucherezhdenia << std::endl;
        cout << "Название учреждения :" << name << std::endl;
        cout << "Кол-во специальностей :" << kolvo_spets << std::endl;
    }
    ~obrazovanie() {};
};

class spets : virtual public obrazovanie
{
protected:
    int time_obuch;
    string obr2;
    string kval;

public:
    spets() {
        time_obuch = 4;
        obr2 = "ЕСть";
        kval = "Инженер-системотехник";
    }
    spets(int _time_obuch, string _obr2, string _kval) :time_obuch(_time_obuch), obr2(_obr2), kval(_kval) {}

    void Show_spets()
    {
        cout << endl << "--------- Специальность ---------" << endl;
        cout << "Время обучения :" << time_obuch << std::endl;
        cout << "Возможность параллельно получать 2 образование :" << obr2 << std::endl;
        cout << "Квалификация :" << kval << std::endl;
    }

    ~spets() {}

};

class sisadm final : virtual public spets, virtual public obiazannosti
{
protected:
    int zarpl;
    string spetsializa;
    int time_week;

public:


    sisadm() {
        zarpl = 1000;
        spetsializa = "Сетевой администратор";
        time_week = 40;
    }

    sisadm(
        string mesto_stajirovki_,
        int srok_stajirovki_,
        int kolvo_zadaniy_,
        string oplata_st_,
        string yap_,
        string buhgalteria_,
        string rabota_s_OS_,
        string local_network_,
        string dop_obiazannosti_,
        int tehnika_,
        string st_ucherezhdenia_,
        string name_,
        int kolvo_spets_,
        int time_obuch_,
        string obr2,
        string kval_,
        int zarpl_,
        string spetsializa_,
        int time_week_
    )
    {
        mesto_stajirovki = mesto_stajirovki_;
        srok_stajirovki = srok_stajirovki_;
        kolvo_zadaniy = kolvo_zadaniy_;
        oplata_st = oplata_st_;
        yap = yap_;
        buhgalteria = buhgalteria_;
        rabota_s_OS = rabota_s_OS_;
        local_network = local_network_;
        dop_obiazannosti = dop_obiazannosti_;
        tehnika = tehnika_;
        st_ucherezhdenia = st_ucherezhdenia_;
        name = name_;
        kolvo_spets = kolvo_spets_;
        time_obuch = time_obuch_;
        obr2 = kval_;
        kval = kval_;
        zarpl = zarpl_;
        spetsializa = spetsializa_;
        time_week = time_week_;

    };

    void Show_sisadm()
    {
        cout << endl << "--------- Системный администратор ---------" << endl;
        cout << "Место стажировки :" << mesto_stajirovki << std::endl;
        cout << "Длительность :" << srok_stajirovki << std::endl;
        cout << "Количество заданий :" << kolvo_zadaniy << std::endl;
        cout << "Зарплата во время стажировки :" << oplata_st << std::endl;
        cout << "Знание ЯП :" << yap << std::endl;
        cout << "Работа в бухгалтерских программах :" << buhgalteria << std::endl;
        cout << "Работа с различными ОС :" << rabota_s_OS << std::endl;
        cout << "Поддержка локальной сети :" << local_network << std::endl;
        cout << "Дополнительные обязанности :" << dop_obiazannosti << std::endl;
        cout << "Количество обслуживаемой техники :" << tehnika << std::endl;
        cout << "Поддержка локальной сети :" << st_ucherezhdenia << std::endl;
        cout << "Название учреждения :" << name << std::endl;
        cout << "Кол-во специальностей :" << kolvo_spets << std::endl;
        cout << "Время обучения :" << time_obuch << std::endl;
        cout << "Возможность параллельно получать 2 образование :" << obr2 << std::endl;
        cout << "Квалификация :" << kval << std::endl;
        cout << "===========" << std::endl;
        cout << "Зарплата :" << zarpl << std::endl;
        cout << "Специализация :" << spetsializa << std::endl;
        cout << "Количество рабочих часов в неделю :" << time_week << std::endl;
    };

    ~sisadm() {}
};

int getValue_int()
{
    while (true)
    {
        int a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "ERROR! INT!\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return a;
        }
    }
}

string getValue_str()

{
    while (true)
    {
        string a;
        std::cin >> a;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "ERROR! STRING!\n";
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

    setlocale(LC_ALL, "Ru");
    string mesto_stajirovki;
    int srok_stajirovki;
    int kolvo_zadaniy;
    string oplata_st;

    cout << "--------- Стажировка ---------" << endl;
    cout << "Место стажировки :" << endl;
    mesto_stajirovki = getValue_str();
    cout << "Длительность:" << endl;
    srok_stajirovki = getValue_int();
    cout << "Количество заданий :" << endl;
    kolvo_zadaniy = getValue_int();
    cout << "Зарплата во время стажировки :" << endl;
    oplata_st = getValue_str();

    stajer st(mesto_stajirovki, srok_stajirovki, kolvo_zadaniy, oplata_st);

    string yap;
    string buhgalteria;
    string rabota_s_OS;

    cout << endl << "--------- Требуемые навыки ---------" << endl;
    cout << "Знание ЯП:" << endl;
    yap = getValue_str();
    cout << "Работа в бухгалтерских программах :" << endl;
    buhgalteria = getValue_str();
    cout << "Работа с различными ОС :" << endl;
    rabota_s_OS = getValue_str();

    naviki nv(yap, buhgalteria, rabota_s_OS);

    string local_network;
    string dop_obiazannosti;
    int tehnika;

    cout << endl << "--------- Поддержка локальной сети ---------" << endl;
    cout << "Поддержка локальной сети :" << std::endl;
    local_network = getValue_str();
    cout << "Дополнительные обязанности  :" << std::endl;
    dop_obiazannosti = getValue_str();
    cout << "Количество обслуживаемой техники :" << std::endl;
    tehnika = getValue_int();

    obiazannosti obz(local_network, dop_obiazannosti, tehnika);

    string st_ucherezhdenia;
    string name;
    int kolvo_spets;


    cout << endl << "--------- Образование ---------" << endl;
    cout << "Поддержка локальной сети :" << endl;
    st_ucherezhdenia = getValue_str();
    cout << "Название учреждения :" << endl;
    name = getValue_str();
    cout << "Кол-во специальностей :" << endl;
    kolvo_spets = getValue_int();

    obrazovanie obr(st_ucherezhdenia, name, kolvo_spets);

    int time_obuch;
    string obr2;
    string kval;

    cout << endl << "--------- Специальность ---------" << endl;
    cout << "Время обучения:" << endl;
    time_obuch = getValue_int();
    cout << "Возможность параллельно получать 2 образование :" << endl;
    obr2 = getValue_str();
    cout << "Квалификация :" << endl;
    kval = getValue_str();

    spets sp(time_obuch, obr2, kval);

    int zarpl;
    string spetsializa;
    int time_week;

    cout << endl << "--------- Системный администратор ---------" << endl;
    cout << "Зарплата :" << endl;
    zarpl = getValue_int();
    cout << "Специализация :" << endl;
    spetsializa = getValue_str();
    cout << "Количество рабочих часов в неделю :" << endl;
    time_week = getValue_int();

    cout << endl << "--------- ---------" << endl;
    cout << endl << "--------- ---------" << endl;
    cout << endl << "--------- ---------" << endl;


    sisadm SS
    (
        mesto_stajirovki,
        srok_stajirovki,
        kolvo_zadaniy,
        oplata_st,
        yap,
        buhgalteria,
        rabota_s_OS,
        local_network,
        dop_obiazannosti,
        tehnika,
        st_ucherezhdenia,
        name,
        kolvo_spets,
        time_obuch,
        obr2,
        kval,
        zarpl,
        spetsializa,
        time_week
    );

    SS.Show_sisadm();
}