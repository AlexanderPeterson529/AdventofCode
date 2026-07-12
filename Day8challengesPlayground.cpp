#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <filesystem>

using namespace std;

struct Point { double x, y, z; };

int main() {
    cout << "cwd: " << std::filesystem::current_path() << '\n'; // help verify file location
    long long numberofCircuits = 0;
    ifstream file("exampleTestDay8.txt");
    if (!file.is_open()) {
        cerr << "Could not open exampleTestDay8.txt\n";
        return 1;
    }

    string line;
    vector<Point> points;
    vector<Point> circuits;
    while (getline(file, line)) {
        Point p;
        p.x = stod(line.substr(0, line.find(',')));
        p.y = stod(line.substr(line.find(',') + 1, line.find(',', line.find(',') + 1) - line.find(',') - 1));
        p.z = stod(line.substr(line.find_last_of(',') + 1));
        //cout << "Read coordinates: " << p.x << ", " << p.y << ", " << p.z << endl;
        points.push_back(p);
    }

    // compute distances and keep the associated point pairs
    vector<double> distances;
    vector<pair<Point, Point>> pairs;
    for (size_t i = 0; i + 1 < points.size(); ++i) { // example: consecutive pairs
        const Point &a = points[i];
        const Point &b = points[i+1];
        double dx = b.x - a.x;
        double dy = b.y - a.y;
        double dz = b.z - a.z;
        double dist = sqrt(dx*dx + dy*dy + dz*dz);
        distances.push_back(dist);
        pairs.emplace_back(a, b);
    }
    while(!distances.empty() && distances.size() > 1) {
        auto min_it = min_element(distances.begin(), distances.end());
        size_t idx = distance(distances.begin(), min_it);
        cout << "Shortest distance: " << *min_it << endl;
        auto &best = pairs[idx];
        cout << "Between points: (" << best.first.x << ", " << best.first.y << ", " << best.first.z
             << ") and (" << best.second.x << ", " << best.second.y << ", " << best.second.z << ")\n";
        circuits.push_back(best.first);
        circuits.push_back(best.second);
        numberofCircuits++;
        distances.erase(distances.begin() + idx);
        // if(pairs[idx].first == best.first && pairs[idx].second != best.second) {
        //     pairs.erase(pairs.begin() + idx);
        
    }

    
    file.close();
    return 0;
}