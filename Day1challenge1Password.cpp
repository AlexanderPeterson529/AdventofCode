#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

int main()
{

    ifstream inputFile("exampleTest.txt");
    string line;
    int password = 0;
    int previousCode = 50;
    int result = 0;
    while(getline(inputFile, line))
    {
        string num = line.substr(1, line.size() - 1);
        int value = stoi(num);
        if((isalpha(line[0])) && (line[0] == 'L') )
        {
            value = -value;
        }
       
        //cout << "Previous Code: " << previousCode << endl;
         
        //cout << "Start Code: " << startCode << endl;
        cout << "Value: " << value << endl;
        result = previousCode + value;    
        cout << "Previous Code: " << previousCode << endl;
        
        //Wrap around logic
        // startCode = (startCode % 100);
        if((result == 0) || (result == 100))
        {
            password += 1;
        }
        else if(result > 99){
            password += 1 * result/100;
            result %= 100;
        }
        if (result < 0){
            
            if (previousCode > 0)
            {
                password += 1 * abs(result)/100;
            }
            result = 100 + result;
        }
        cout << "result:" << result << endl;
        if((previousCode < 0 && result > 0 )){
           password += 1;
        }
        //Check to see if the code is zero
 
        //cout << "Start Code: " << startCode << endl;
        cout << "Passwords Found: " << password << endl;
        previousCode = result;
    }
    inputFile.close();

    return 0;
}