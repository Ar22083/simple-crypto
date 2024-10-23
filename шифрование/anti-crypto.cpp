#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
vector <char> cryptos {'2','3','4','5','6','.',',','/','-','1','7','8','9','(',')','=','+','0','?','!',';',':','|','*','>','<','[',']','{','}',};
vector<char> arr {'O','P','E','F','G','H','I','J','K','Q','R','S','T','U','A','B','C','D','L','M','N','V','W','X','Y','Z',' ','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int findValue (const vector<char>& data, char value)
{
    auto result{ find(begin(data), end(data), value) };
    if (result == end(data))
        return -1;
    else{
        return (result - begin(data)) ;
    }
}

int main(){
    char answer;
    cout<<"Do you want to decrypt from file?   [y/n]:  ";
    cin>>answer;
    cin.ignore();
    string words ,cstr;
    answer=toupper(answer);
    
    if (answer == 'Y'){
        
    cout<<"Enter a file:";
    string str;
    getline(cin,str);
    str+=".crp";
    ifstream file;
    
    file.open(str);
    if (!file.is_open()){
        cerr<<"Wrong file name"<<endl;
        return 1;
    }
    string line;
    

    while (std::getline(file, line)) { // Читаем файл построчно
        words += line ; // Добавляем каждую строку и символ новой строки
    }
    file.close();
    
    }
    else {
        cout<<"Enter a text: ";
        getline(cin,words);
    }
    
    for(char &c :words){
        int position = findValue(arr,c);
        if (position == -1){
            position=findValue(cryptos,c);
            if (position == 0){
                position=cryptos.size()-1;
                cstr+=cryptos[position];
            }else{
                cstr+=cryptos[position-1];
            }
        }
        else if (position == 0){
            position=arr.size()-1;
            cstr+=arr[position];
        }
        else{
            cstr+=arr[position-1];
        }
    }
    
    cout<<"Name of the file:";
    string name;
    getline(cin,name);
    name+=".txt";

    ofstream outputFile(name);
    if (!outputFile) {
        std::cerr << "File could not be created!" << std::endl;
        return 1;
    }
    outputFile<<cstr;
    outputFile.close();
    system("PAUSE");
    
    return 0;
}