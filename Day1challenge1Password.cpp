#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

int main()
{

    ifstream inputFile("passwords.txt");
    string line;
    int startCode = 50;
    int password = 0;
    int previousCode = 0;
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
        previousCode = startCode;
        startCode += value;    
        cout << "Previous Code: " << previousCode << endl;
        
        //Wrap around logic
        startCode = (startCode % 100);
        
        if(startCode > 99){
            //password += 1;
            if(previousCode + value > 99){
                password += 1*((previousCode + value) / 100);
            }
            else{
                password += 1;
            }
        }
        if(startCode < 0 && previousCode != 0){
           if(previousCode + value < 0){
                password += 1 * (-(previousCode + value) / 100 + 1);
            }
            else{
                password += 1;
            }
        }
        //Check to see if the code is zero
        if(startCode == 0)
        {

            password += 1;

  
        }


        //cout << "Start Code: " << startCode << endl;
        cout << "Passwords Found: " << password << endl;
        
    }
    inputFile.close();

    return 0;
}