#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<char> cryptos {'2','3','4','5','6','.',',','/','-','1','7','8','9','(',')','=','+','0','?','!',';',':','|','*','>','<','[',']','{','}',};
vector<char> arr {'O','P','E','F','G','H','I','J','K','Q','R','S','T','U','A','B','C','D','L','M','N','V','W','X','Y','Z',' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int findValue(const vector<char>& data, char value) {
    auto result = find(begin(data), end(data), value);
    if (result == end(data))
        return -1;
    return (result - begin(data));
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "No file specified" << endl;
        return 1;
    }

    string fname = argv[1];
    if (fname.substr(fname.find_last_of(".") + 1) != "crp") {
        cerr << "The file is not a .crp file." << endl;
        return 1;
    }

    ifstream inputFile(fname);
    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << fname << endl;
        return 1;
    }

    // Чтение файла построчно и сохранение форматирования
    stringstream buffer;
    string line;
    while (getline(inputFile, line)) {
        buffer << line << '\n'; // Сохраняем строку с символом новой строки
    }
    inputFile.close();

    string words = buffer.str();

    // Преобразуем все символы в верхний регистр

    string cstr;
    for (char &c : words) {
        int position = findValue(arr, c);
        if (position != -1) { // Символ найден в arr
            cstr += (position == 0) ? arr.back() : arr[position - 1];
        } else { // Символ не найден в arr
            position = findValue(cryptos, c);
            if (position != -1) {
                cstr += (position == 0) ? cryptos.back() : cryptos[position - 1];
            } else {
                cstr += c; // Если символ не найден в обоих векторах, оставляем его без изменений
            }
        }
    }

    cout << cstr << endl;

    // Приостановка выполнения для просмотра результата
    system("PAUSE");

    return 0;
}
