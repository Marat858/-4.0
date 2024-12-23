#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;


void main() {
    setlocale(0, "Rus");
    int choose;
    string s;
    cout << "Если хотите считать строку из файла, введите 1.\nЕсли хотите ввести строку с клавиатуры, введите 0: ";
    cin >> choose;
    if (choose == 1) {
        string path;
        cout << "Введите путь к файлу: ";
        cin >> path;
        ifstream fin;
        fin.open(path);
        getline(fin, s);
        fin.close();
    }
    else if (choose == 0) {
        cin.ignore();
        getline(cin, s);
    }
    else {
        cout << "Выбор неверный. Завершение программы.";
        return;
    }
    int n = s.length();
    char* words = new char[n];
    for (int i = 0; i < n; i++)
        words[i] = s[i];
    // 2.1
    int i_ = 0;
    while (i_ < n) {
        if (words[i_] == ' ' && words[i_ + 1] == ' ') {
            int j_ = i_ + 1;
            while (j_ < n) {
                words[j_] = words[j_ + 1];
                j_++;
            }
            n--;
        }
        else {
            i_++;
        }
    }
    //2.2
    i_ = 0;
    while (i_ < n) {
        if (words[i_] == ',' && (words[i_ + 1] == '.' || words[i_ + 1] == ',')) {
            int j_ = i_ + 1;
            while (j_ < n) {
                words[j_] = words[j_ + 1];
                j_++;
            }
            n--;
        }
        else if (words[i_] == '.') {
            if (words[i_ + 1] == '.' && words[i_ + 2] == '.') {
                i_ += 2;
            }
            else if (words[i_ + 1] == '.' || words[i_ + 1] == ',') {
                int j_ = i_ + 1;
                while (j_ < n) {
                    words[j_] = words[j_ + 1];
                    j_++;
                }
                n--;
            }
            else {
                i_++;
            }
        }
        else {
            i_++;
        }
    }
    // 2.3
    for (int i = 0; i < n; i++) {
        if (i == 0)
            words[i] = toupper(words[i]);
        else if (words[i - 1] == ' ' && isalpha(words[i]))
            words[i] = toupper(words[i]);
        else
            words[i] = tolower(words[i]);
    }
    for (int i = 0; i < n; i++) {
        if (isalpha(words[i]) && (i == 0 || words[i - 1] == ' ')) {
            words[i] = toupper(words[i]);
        }
        else {
            words[i] = tolower(words[i]);
        }
    }
    // 3 задание 3 вариант
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            i++;
            while (words[i] != ' ')
                i++;
            bool is_digit = false;
            for (int j = 0; j < i; j++) {
                if (isdigit(words[j])) {
                    is_digit = true;
                    break;
                }
            }
            if (is_digit == false) {
                for (int j = 0; j < i; j++) {
                    cout << words[j];
                }
                cout << endl;
            }
        }
        if (words[i] == ' ') {
            i_ = i;
            // 18 - 25
            i++;
            while (words[i] != ' ' && i < n - 1)
                i++;
            bool is_digit = false;
            for (int j = i_ + 1; j < i; j++) {
                if (isdigit(words[j])) {
                    is_digit = true;
                    break;
                }
            }
            if (is_digit == false) {
                for (int j = i_ + 1; j < i; j++) {
                    if (words[j] == '.' || words[j] == ',')
                        break;
                    cout << words[j];
                }
                cout << endl;
            }
            i--;
        }
    }
    // 4 задание
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            i++;
            while (words[i] != ' ') {
                i++;
            }
            cout << i << endl;
        }
        if (words[i] == ' ') {
            i_ = i;
            i++;
            while (words[i] != ' ' && i < n) {
                if (words[i] == '.' || words[i] == ',')
                    break;
                i++;
            }
            cout << i - i_ - 1 << endl;
            i--;
        }
    }

    // 5 задание
    int k;
    cout << "Введите длину подстроки: ";
    cin >> k;
    char* substr = new char[k];
    cout << "Введите подстроку: ";
    cin >> substr;
    int begin_index = -1;
    for (int i = 0; i < n - k; i++) {
        bool is_substr = true;
        for (int j = 0; j < k; j++) {
            if (words[i + j] != substr[j]) {
                is_substr = false;
            }
        }
        if (is_substr == true) {
            begin_index = i;
            break;
        }
    }
    if (begin_index == -1) {
        cout << "Подстрока не найдена.";
    }
    else {
        cout << "Подстрока найдена. Она начинается с символа на номере " << begin_index << "\n";
    }
   
}
