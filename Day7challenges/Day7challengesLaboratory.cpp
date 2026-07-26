#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main() {
    string filename = "teleporter.txt";
    ifstream file(filename);
    vector<string> grid;
    string line;
    while(getline(file, line)){
        grid.push_back(line);
    }

    int rows = (int)grid.size();
    int cols = (int)grid[0].length();

    
    vector<bool> beams(cols, false);
    for(int c = 0; c < cols; ++c){
        if(grid[0][c] == 'S'){
            beams[c] = true;
        }
    }

    int splitEvents = 0; 
    
    for(int r = 0; r < rows; ++r){
        vector<bool> nextBeams(cols, false);
        for(int c = 0; c < cols; ++c){
            if(!beams[c]) continue;
            char cell = grid[r][c];
            if(cell == '^'){
                
                ++splitEvents;
                if(r + 1 < rows){
                    if(c - 1 >= 0) nextBeams[c - 1] = true;
                    if(c + 1 < cols) nextBeams[c + 1] = true;
                }
            } else if(cell == '.' || cell == '|' || cell == 'S'){
                
                if(r + 1 < rows) nextBeams[c] = true;
            }
        }
        beams.swap(nextBeams);
    }

    cout << "Beam split events: " << splitEvents << endl;
    return 0;
}