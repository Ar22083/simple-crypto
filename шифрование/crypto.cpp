#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

vector<char> arr {'O','P','E','F','G','H','I','J','K','Q','R','S','T','U','A','B','C','D','L','M','N','V','W','X','Y','Z',' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
vector<char> crypto {'2','3','4','5','6','.',',','/','-','1','7','8','9','(',')','=','+','0','?','!',';',':','|','*','>','<','[',']','{','}',};

int findValue(const std::vector<char>& data, char value) {
    auto result = find(begin(data), end(data), value);
    if (result == end(data)) {
        return -1;
    }
    return (result - begin(data));
}

int main() {
    char answer;
    cout << "Do you want to crypt from file? [y/n]: ";
    cin >> answer;
    cin.ignore();  // Очищаем буфер ввода

    string words, cstr;
    answer = toupper(answer);

    if (answer == 'Y') {
        cout << "Enter a file: ";
        string filename;
        getline(cin, filename);
        filename += ".txt";

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Wrong file name" << endl;
            return 1;
        }

        string line;
        while (getline(file, line)) { // Читаем файл построчно
            words += line + "\n"; // Добавляем каждую строку и символ новой строки
        }
        file.close();
    } else {
        cout << "Enter a text: ";
        getline(cin, words);
    }

    int cou = 0;
    for (char &c : words) {
        cou++;
    }
    cout << cou << " Symbols" << endl;

    for (char &c : words) {
        int position = findValue(arr, c);
        if (position == -1) {
            position = findValue(crypto, c);
            if (position == -1) {
                cstr += c; // Если символ не найден в таблицах, оставляем его как есть
            } else {
                if (position == crypto.size() - 1) {
                    cstr += crypto[0];
                } else {
                    cstr += crypto[position + 1];
                }
            }
        } else {
            if (position == arr.size() - 1) {
                cstr += arr[0];
            } else {
                cstr += arr[position + 1];
            }
        }
    }

    cout << "Name of the file: ";
    string name;
    getline(cin, name);
    name += ".crp";

    ofstream outputFile(name);
    if (!outputFile) {
        cerr << "File could not be created!" << endl;
        return 1;
    }
    outputFile << cstr;
    outputFile.close();

    system("PAUSE");
    return 0;
}
