// COMSC-210-5293 | Lab 25 | Yuyi Chen

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono;

const int SIZE = 20000;

int main() {
    vector<string> vec;
    list<string> lst;
    set<string> st;

    ifstream fin("codes.txt");

    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string word;

    // Start timing vector reading
    auto start = high_resolution_clock::now();

    while (fin >> word) {
        vec.push_back(word);
    }

    // End timing vector reading
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(end - start);

    cout << "Vector reading time: " << duration.count()
         << " nanoseconds" << endl;

    fin.close();

    //-----------------------------------------------------
    // Open the file again for list reading
    fin.open("codes.txt");

    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Start timing list reading
    start = high_resolution_clock::now();

    while (fin >> word) {
        lst.push_back(word);
    }

    // End timing list reading
    end = high_resolution_clock::now();

    duration = duration_cast<nanoseconds>(end - start);

    cout << "List reading time: " << duration.count()
         << " nanoseconds" << endl;

    fin.close();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/