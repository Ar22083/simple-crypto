#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string name;
    cout<<"Files name:";
    getline(cin,name);
    cout<<"Text :";
    string text;
    getline(cin,text);
    name+=".crp";
    ofstream file(name);
    if (!file) {
        cerr << "File could not be created!" << std::endl;
        return 1;
    }
    file<<text;
    file.close();

    return 0;

}