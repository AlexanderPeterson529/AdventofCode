#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
ifstream file("forkLiftRolls.txt");
string line;
vector<string> grid;

int main(){
    int totalNumberOfRolls = 0;
    int incorrectRolls = 0;
    while(getline(file, line)){
        
    grid.push_back(line);
}
    size_t pos = 0;
    int rowCount = (int)grid.size();
    int colCount = (int)grid[0].length();
    for(int r = 0; r < rowCount; ++r){
        for(int c = 0; c < colCount; ++c){
            char cell = grid[r][c];
            char oneLeft = (c > 0) ? grid[r][c-1] : ' ';
            char oneRight = (c < colCount - 1) ? grid[r][c+1] : ' ';
            char oneUp = (r > 0) ? grid[r-1][c] : ' ';
            char oneDown = (r < rowCount - 1) ? grid[r+1][c] : ' ';
            char diagUpLeft = (r > 0 && c > 0) ? grid[r-1][c-1] : ' ';
            char diagUpRight = (r > 0 && c < colCount - 1) ? grid[r-1][c+1] : ' ';
            char diagDownLeft = (r < rowCount - 1 && c > 0) ? grid[r+1][c-1] : ' ';
            char diagDownRight = (r < rowCount - 1 && c < colCount  - 1) ? grid[r+1][c+1] : ' ';
            bool foundUp = false;
            bool foundDown = false;
            bool foundLeft = false;
            bool foundRight = false;
            bool foundUpLeft = false;
            bool foundUpRight = false;
            bool foundDownLeft = false;
            bool foundDownRight = false;
            incorrectRolls = 0;
            //pos++;
            if(cell == '@') {
                

            if(c == 0){
                if(oneUp == '@'){incorrectRolls++; foundUp = true;};
                if(oneDown == '@'){incorrectRolls++; foundDown = true;};
                if(oneRight == '@'){ incorrectRolls++; foundRight = true;};
                if(diagUpRight == '@'){ incorrectRolls++; foundUp = true;};
                if(diagDownRight == '@'){ incorrectRolls++; foundDown = true;};
            }
            if(c == colCount - 1){
                if(oneUp == '@' && foundUp != true) {incorrectRolls++; foundUp = true;};
                if(oneDown == '@' && foundDown != true) {incorrectRolls++; foundDown = true;};
                if(oneLeft == '@' && foundLeft != true) {incorrectRolls++; foundLeft = true;};
                if(diagUpLeft == '@' && foundUpLeft != true) {incorrectRolls++; foundUpLeft = true;};
                if(diagDownLeft == '@' && foundDownLeft != true) {incorrectRolls++; foundDownLeft = true;};
            }
            if(r == 0){
                if(oneLeft == '@' && foundLeft != true) {incorrectRolls++; foundLeft = true;};
                if(oneRight == '@' && foundRight != true) {incorrectRolls++; foundRight = true;};
                if(oneDown == '@' && foundDown != true) {incorrectRolls++; foundDown = true;};
                if(diagDownLeft == '@' && foundDownLeft != true){ incorrectRolls++; foundDownLeft = true;};
                if(diagDownRight == '@' && foundDownRight != true) {incorrectRolls++; foundDownRight = true;};
            }
            if(r == rowCount - 1){
                if(oneLeft == '@' && foundLeft != true) {incorrectRolls++; foundLeft = true;};
                if(oneRight == '@' && foundRight != true) {incorrectRolls++; foundRight = true;};
                if(oneUp == '@' && foundUp != true) {incorrectRolls++; foundUp = true;};
                if(diagUpLeft == '@' && foundUpLeft != true) {incorrectRolls++; foundUpLeft = true;};
                if(diagUpRight == '@' && foundUpRight != true) {incorrectRolls++; foundUpRight = true;};
                if(oneRight == '@' && foundRight != true) {incorrectRolls++; foundRight = true;};
                if(oneUp == '@' && foundUp != true) {incorrectRolls++; foundUp = true;};
                if(diagUpLeft == '@' && foundUpLeft != true) {incorrectRolls++; foundUpLeft = true;};
                if(diagUpRight == '@' && foundUpRight != true) {incorrectRolls++; foundUpRight = true;};
            }

            if(c == colCount - 1 && r == 0){
                if(oneLeft == '@' && foundLeft != true) {incorrectRolls++; foundLeft = true;};
                if(oneDown == '@' && foundDown != true) {incorrectRolls++; foundDown = true;};
                if(diagDownLeft == '@' && foundDownLeft != true) {incorrectRolls++; foundDownLeft = true;};
            }
            if(c != colCount - 1 && r != rowCount - 1 && c != 0 && r != 0){
                if(oneLeft == '@' && foundLeft != true) {incorrectRolls++; foundLeft = true;};
                if(oneRight == '@' && foundRight != true) {incorrectRolls++; foundRight = true;};
                if(oneUp == '@' && foundUp != true) {incorrectRolls++; foundUp = true;};
                if(oneDown == '@' && foundDown != true) {incorrectRolls++; foundDown = true;};
                if(diagUpLeft == '@' && foundUpLeft != true) {incorrectRolls++; foundUpLeft = true;};
                if(diagUpRight == '@' && foundUpRight != true) {incorrectRolls++; foundUpRight = true;};
                if(diagDownLeft == '@' && foundDownLeft != true) {incorrectRolls++; foundDownLeft = true;};
                if(diagDownRight == '@' && foundDownRight != true) {incorrectRolls++; foundDownRight = true;};
            }
            
            if(incorrectRolls < 4){
                cell = 'X';
                totalNumberOfRolls++;
            }
            }
            
            cout << cell;
             //grid[r][c] = cell;
            
        }
        cout << endl;
    }
    cout << "Total number of correct rolls: " << totalNumberOfRolls << endl;



    file.close();
    return 0;
}