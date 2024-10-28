#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;
using namespace std:: chrono;

const int SZ = 20000;

float readVector(vector<string> &v);
float readList(list<string> &l);
float readSet(set<string> &s);
float sortVector(vector<string> &v);
float sortList(list<string> &l);
float sortSet(set<string> &s);



int main() {
    vector<string> v;
    list<string> l;
    set<string> s;
    
    
    
    
    cout << "Operation" << "\tVector" << "\tList" << "\tSet" << endl;
    cout << "Read" << "\t" <<
    
    
    return 0;
}

float readVector(vector<string> &v) {
    //read into vector
    auto start = high_resolution_clock::now();
    
    ifstream fin;
    fin.open("codes.txt");
    if (fin.is_open())
    {
        string line;
        while (fin >> line)
        {
            v.push_back(line);
        }
        fin.close();
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float readList(list<string> &l) {
    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");
    string codes[SZ];
    int i = 0;
    while (fin >> codes[i++]);
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float readSet(set<string> &s) {
    auto start = high_resolution_clock::now();
    ifstream fin("codes.txt");
    string nm;
    while (getline(fin, nm)) {
        s.insert(nm);
    }
    fin.close();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float sortVector(vector<string> &v) {
    auto start = high_resolution_clock::now();
    sort(v.begin(), v.end());
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float sortList(list<string> &l) {
    auto start = high_resolution_clock::now();
    l.sort();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}
/* syntax examples:
 auto start = high_resolution_clock::now()
 auto end = high_resolution_clock::now()
 auto duration = duration_cast<milliseconds>(end - start)
 duration.count() references elapsed milliseconds
 */
