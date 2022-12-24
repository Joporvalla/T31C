#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //Ввод и вывод символов.
#include <string>//  Использование строк
#include <fstream>// Работа с файлами
#include <stdio.h>// Операции ввода-вывода
#include <time.h>//  Работа с временем и датой
#include <cstring> //Работа со строками
#include <stdlib.h>//Для работы с памятью, генерации псевдослучайных чисел, целой арифметики, поиска, сортировки и преобразования типов данных.
#include <iomanip>

using namespace std;
int N = 10;

struct Knigpech {
    int nomer;
    string familia;
    string imya;
    string otchestvo;
    string book;
    int price;
    int priceX10;

};
Knigpech* knigpech = new Knigpech[N];
bool isDigital(string bif) { //Проверка на число
    for (int i = 0, n = strlen(bif.c_str()); i < n; i++)
    {
        if (bif[i] < '0' || bif[i] > '9') return false;
    }
    return true;
}

//Функция вызова контекстного меню
void text() {

    cout <<
        "\n             Таблица\n\n"
        "Список книг          -> Нажмите 1\n\n"
        "Сохранение файла     -> Нажмите 2\n\n"
        "Редактирование файла -> Нажмите 3\n\n"
        "Выход из программы   -> Нажмите 4\n\n" << endl;
}
void text_redact() {
    cout <<
        "Если хотите отредактировать стобец номера         -> Нажмите 1\n\n"
        "Если хотите отредактировать стобец фамилии        -> Нажмите 2\n\n"
        "Если хотите отредактировать стобец имени          -> Нажмите 3\n\n"
        "Если хотите отредактировать стобец очества        -> Нажмите 4\n\n"
        "Если хотите отредактировать стобец названия книги -> Нажмите 5\n\n"
        "Если хотите отредактировать стобец цены книги     -> Нажмите 6\n\n"
        "Если хотите выйти из режима редактирования        -> Нажмите 7\n\n";
}


void X10() {
    for (int i = 0; i < N; i++)
    {
        knigpech[i].priceX10 = knigpech[i].price * 10;
    }
}

void output_file() {//Открытие файла
    ifstream F;
    string path = "data.txt";
    F.open(path);
    //Считываем информацию из файла data.txt
    if (!F.is_open())
    {
        cout << "Файл не найден" << endl;
        system("pause");
        return;
    }
    //Запись информации из файла в структуру
    else
        for (int i = 0; i < N; i++)
            F >> knigpech[i].nomer >> knigpech[i].familia >> knigpech[i].imya >> knigpech[i].otchestvo >> knigpech[i].book >> knigpech[i].price;
    F.close();
    return;
}
//Функция сортировки по фамилии и вывода на экран таблицы
void data() {

    cout << setiosflags(ios::left);
    printf("|------------------------------------------------------------------------------------------------------------------|\n");
    printf("|  Номер  |                  ФИО                  |                 Название                  | Цена | Цена десяти |\n");
    printf("|------------------------------------------------------------------------------------------------------------------|\n");
    for (int i = 0; i < N; ++i)
    {
        cout << "    ";
        printf("%2d", knigpech[i].nomer);
        cout << "        ";
        cout << setw(10) << knigpech[i].familia;
        cout << setw(15) << knigpech[i].imya;
        cout << setw(18) << knigpech[i].otchestvo;
        cout << setw(40) << knigpech[i].book;
        cout << setw(10) << knigpech[i].price;
        cout << setw(15) << knigpech[i].priceX10;
        cout << endl;
    }
}
// убрали ретёрн, сменили на войд
void save() {
    string name;
    cout << "Введите название файла c расширением (к примеру .txt)" << endl;
    cin >> name;
    ofstream fout;
    fout.open(name);
    for (int i = 0; i < N; i++)
        fout << knigpech[i].nomer << " " << knigpech[i].familia << " " << knigpech[i].imya << " " << knigpech[i].otchestvo << " " << knigpech[i].book << " " << knigpech[i].price << " " << knigpech[i].priceX10 << "\n";
}
int get_variant(int count) { //Считывание варианта
    string choose;
    cin >> choose;
    while (!isDigital(choose) || atoi(choose.c_str()) < 1 || atoi(choose.c_str()) > count) {//Ошибка
        cout << "Введите число от 1 до 4 в соответствии с указаниями меню!";
        cin >> choose;
    }
    return atoi(choose.c_str());
}

void sred_cena_knigi() {
    int sr_cena = 0;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = sum + knigpech[i].price;
    }
    sr_cena = sum / 10;
    cout << "Средняя цена книги = " << sr_cena << " руб." << endl;
}

void reduct() {
    int i;
    int stolbec;
    string vvodimoestr;
    int vvodimoeint;
    cout << "Введите номер строки которую хотите отредактировать\n\n" << endl;
    cin >> i;
    if (i > 0 && i <= N)
    {
        text_redact();
        cin >> stolbec;
        if (stolbec == 7)
        {
            cout << "Конец редактирования\n\n" << endl;
            return;
        }
        else {
            cout << "Ведите отредактированные данные\n\n" << endl;
            if (stolbec == 1 || stolbec == 6)
                cin >> vvodimoeint;
            else
                cin >> vvodimoestr;
            switch (stolbec) {
            case 1:
                knigpech[i].nomer = vvodimoeint;
                break;
            case 2:
                knigpech[i].familia = vvodimoestr;
                break;
            case 3:
                knigpech[i].imya = vvodimoestr;
                break;
            case 4:
                knigpech[i].otchestvo = vvodimoestr;
                break;
            case 5:
                knigpech[i].book = vvodimoestr;
                break;
            case 6:
                knigpech[i].price = vvodimoeint;
                break;
            }
        }
    }
}




int main() {
    setlocale(LC_ALL, "Russian");
    int choose;
    output_file();
    X10();
    do {
        text();
        choose = get_variant(4); //Обработка пункта в меню
        switch (choose) {
        case 1:
            //Функция проверки правильности ввода


            while (choose != 4)
            {

                //Функция выбора 1 из пунктов меню
                switch (choose) {
                case 1:
                {
                    data();
                    sred_cena_knigi();
                    text(); cin >> choose;
                    break; }
                case 2:
                {save();
                data();
                sred_cena_knigi();
                text(); cin >> choose;
                break; }
                case 3:
                {reduct();
                data();
                sred_cena_knigi();
                text(); cin >> choose;
                break; }
                }
            }

        }if (choose != 4)
            system("pause");
    } while (choose != 4);
    delete[] knigpech;
    return 0;
}

