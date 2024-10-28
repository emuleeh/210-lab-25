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
float insertVector(vector<string> &v);
float insertList(list<string> &l);
float insertSet(set<string> &s);
float deleteVector(vector<string> &v);
float deleteList(list<string> &l);
float deleteSet(set<string> &s);


int main() {
    vector<string> v;
    list<string> l;
    set<string> s;
    float r_v = readVector(v);
    float r_l = readList(l);
    float r_s = readSet(s);
    float s_v = sortVector(v);
    float s_l = sortList(l);
    float s_s = sortSet(s);
    float i_v = insertVector(v);
    float i_l = insertList(l);
    float i_s = insertSet(s);
    float d_v = deleteVector(v);
    float d_l = deleteList(l);
    float d_s = deleteSet(s);
    

    cout << "Operation" << "\tVector" << "\tList" << "\tSet" << endl;
    cout << "Read" << "\t\t" << r_v << "\t\t" << r_l << "\t\t" << r_s << endl;
    cout << "Sort" << "\t\t" << s_v << "\t\t" << s_l << "\t\t" << s_s << endl;
    cout << "Insert" << "\t\t" << i_v << "\t\t" << i_l << "\t\t" << i_s << endl;
    cout << "Delete" << "\t\t" << d_v << "\t\t" << d_l << "\t\t" << d_s << endl;
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

float sortSet(set<string> &s) {
    return -1;
}

float insertVector(vector<string> &v) {
    auto start = high_resolution_clock::now();
    //insert "TESTCODE" into middle
    v.insert(v.begin() + SZ / 2, "TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float insertList(list<string> &l) {
    auto start = high_resolution_clock::now();
    //insert "TESTCODE" into middle
    auto it = l.begin();
    advance(it, SZ / 2);
    l.insert(it, "TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float insertSet(set<string> &s) {
    auto start = high_resolution_clock::now();
    //insert "TESTCODE" into middle
    auto it = s.begin();
    advance(it, SZ / 2);
    s.insert(it, "TESTCODE");
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float deleteVector(vector<string> &v) {
    auto start = high_resolution_clock::now();
    //delete middlish element
    v.erase(v.begin() + SZ / 2);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float deleteList(list<string> &l) {
    auto start = high_resolution_clock::now();
    //delete middlish element
    auto it = l.begin();
    advance(it, SZ/2);
    l.erase(it);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

float deleteSet(set<string> &s) {
    auto start = high_resolution_clock::now();
    //delete middlish element
    auto it = s.begin();
    advance(it, SZ/2);
    s.erase(it);
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
