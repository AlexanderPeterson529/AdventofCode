#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("joltage.txt");

    string line;
    string newLine;
    string joltage;
    //int maxNum;
    long long joltageSum = 0;
    while(getline(file, line)) {
        auto maxNum = max_element(line.begin(), line.end());
        //cout<< *maxNum <<endl;
        char maxChar = *maxNum;
        string rest;
        size_t pos = distance(line.begin(), maxNum);
        if(pos != line.size() -1){
            rest = line.substr(pos + 1);
            joltage.push_back(maxChar);
            auto secondMax = max_element(rest.begin(), rest.end());
            char secondChar = *secondMax;
            joltage.push_back(secondChar);
        }
        if(pos == line.size() - 1){
            rest = line.substr(0, line.size() -1);
            auto secondMax = max_element(rest.begin(), rest.end());
            char secondChar = *secondMax;
            //cout << secondChar << endl;
            joltage.push_back(secondChar);
            joltage.push_back(maxChar);
        }
        
        
        //joltage.clear();

        


        //cout << joltage << endl;
        if(joltage.size() == 2){
            cout << joltage << endl;
            joltageSum += stoll(joltage);
        }
        joltage.clear();
    }
    
    cout << "Final Joltage Sum: " << joltageSum << endl;
    file.close();
    return 0;
}