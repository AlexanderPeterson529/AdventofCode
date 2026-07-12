#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>


using namespace std;
class Ranges{
    private:
        string line;
        // string content;
        string list;
        string startRange;
        string range;
        string endRange;
        string startValue;
        string endValue;
        long long value = 0;
    public:
        void invalidIds(string s, string del = " "){
            int start, end = -1*del.size();
            do{
                start = end + del.size();
                end = s.find(del, start);
                range = s.substr(start,end - start);
                startRange = range.substr(0, range.find('-'));
                endRange = range.substr(range.find('-')+ 1, range.length() - startRange.length());
                for(long long i = stoll(startRange); i <= stoll(endRange); i++){
                    list = to_string(i);
                   if(list[0]== 0){
                        list=list.erase(list[0]);
                   }
                    startValue = list.substr(0,list.length()/2);

                    endValue = list.substr(list.length()/2);
                    //  if(i == 38593859){
                    //     cout<<endValue<<endl;
                    // }
                    if(startValue == endValue){
                        
                        value += i;
                        cout<< value<< endl;
                    }
                }
                
            } while (end != -1);
        }
        void setRange(string filename){ 
            ifstream file;
            file.open(filename);
            while(getline(file,line)) {
               invalidIds(line,",");
            }
        }
        int getRange() const{
            cout<< endl;
            return value;
        }
};

int main() {
    Ranges myRanges;
    myRanges.setRange("serialNumbers.txt");
    //string filename = ;
    //readFile(filename);

    return 0;
}


