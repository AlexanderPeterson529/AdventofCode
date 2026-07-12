#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;


int main() {
    ifstream file("mathHomework.txt");
    string line;
    vector<vector<string>> rows;
    long long totalVal = 0;
    // read every line as a vector of tokens
    while (getline(file, line)) {
        istringstream ss(line);
        string token;
        vector<string> tokens;
        while (ss >> token) tokens.push_back(token);
        if (!tokens.empty()) rows.push_back(move(tokens));
    }

    if (rows.empty()) return 0;

    
    vector<string> opRow = rows.back();
    rows.pop_back();

    
    size_t cols = 0;
    for (auto &r : rows) cols = max(cols, r.size());
    vector<vector<string>> columns(cols);
    for (auto &r : rows) {
        for (size_t j = 0; j < r.size(); ++j) columns[j].push_back(r[j]);
    }


    for (size_t j = 0; j < cols; ++j) {
        string op;
        if (opRow.size() > j) op = opRow[j];
        else if (opRow.size() == 1) op = opRow[0];
        else op = "+";

        long long sum = 0;
        long long prod = 1;
        for (auto &cell : columns[j]) {
            if (cell.empty()) continue;
            // skip non-numeric tokens
            size_t start = (cell[0] == '+' || cell[0] == '-') ? 1 : 0;
            if (start >= cell.size()) continue;
            if (!all_of(cell.begin() + start, cell.end(), ::isdigit)) continue;
            long long v = stoll(cell);
            sum += v;
            prod *= v;
        }
        
        cout << "Column " << j << ": ";
        if (op == "*") {
            cout << "Product = " << prod;
            totalVal += prod;
        }
        else {
            cout << "Sum = " << sum;
            totalVal += sum;
        }
        
        
        
        cout << '\n';
    }
    cout<< totalVal << endl;
    file.close();
}