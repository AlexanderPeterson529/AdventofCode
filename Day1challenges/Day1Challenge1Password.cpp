#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream inputFile("passwords.txt");
    inputFile.open("passwords.txt");
    string line;
    int startCode = 50;
    int finalCode = 0;
    int password = 0;
    bool isLeft = false;
    while(getline(inputFile, line)){
    if(line[0] == 'L'){
        isLeft = true;
    }
    int value = stoi(line.substr(1, line.length() - 1)) % 99;
    if(isLeft){
        value = -value;
    }
    startCode += value;
    finalCode = startCode;
    if(finalCode == 0){
        password += 1;
    }
    if(finalCode < 0){
        finalCode = 99 + finalCode;
    }
    cout << "Current Code: " << finalCode << endl;
    cout << "Passwords Found: " << password << endl;
    isLeft = false;
    }
    return 0;

}