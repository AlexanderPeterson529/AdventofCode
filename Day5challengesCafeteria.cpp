#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ifstream file("freshIngredients.txt");
    ifstream ingredientFile("freshIngredientList.txt");



    string line;
    long long startRange, endRange;
    vector<pair<long long,long long>> Ingredients;
    //set<long long> IngredientsChecked;
    long long goodIngredients = 0;
    

    while(getline(file, line)) {
        size_t dash = line.find('-');
        if(dash == string::npos) continue;

        startRange = stoll(line.substr(0, dash));
        endRange = stoll(line.substr(dash + 1));
        Ingredients.push_back({startRange, endRange});
    }
    while(getline(ingredientFile, line)){
        if(line.empty())
            continue;
        long long val = stoll(line);
        // auto it = find(Ingredients.begin(),Ingredients.end(),val);
        for(auto &i : Ingredients)
            if(val >= i.first&& val <= i.second){
                cout<< val<< endl;
                goodIngredients++;
                break;
            }
        }

    cout << "Total Fresh Ingredients: " << goodIngredients << endl;
    file.close();
    ingredientFile.close();
    
    return 0;
}