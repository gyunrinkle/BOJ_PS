#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortOrder (string a, string b) {
    if (a.length() == b.length())
        return a < b;

    return a.length() < b.length();
}

int main() {

    int n;
    vector<string> v;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if(find(v.begin(), v.end(), str) == v.end())
            v.push_back(str);
        
    }
    sort(v.begin(), v.end(), sortOrder);

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
    
    return 0;
}