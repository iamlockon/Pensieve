#include<bits/stdc++.h>

using namespace std;

// set output precision
#define setopre(p) cout << fixed << setprecision(p)

// set output width and fill char, only work for single value
#define setowfill(w, f, what) cout << setw(w) << setfill(f) << what << endl

// print vector of T
template<typename T>
ostream& operator<< (std::ostream& out, const vector<T>& v) {
    for (auto &e: v) {
        out << e << ",";
    }
    return out;
}


int main() {
    setowfill(5, ' ', "asfd");
} 