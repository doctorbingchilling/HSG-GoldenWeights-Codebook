#include <bits/stdc++.h>
using namespace std;

const string NAME = "testing";
const int NTEST = 100;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        ofstream inp((NAME + ".inp").c_str());
        inp << Rand(1, 5) << ' ' << Rand(1, 5);
        inp.close();
        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}