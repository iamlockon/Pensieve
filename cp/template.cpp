#include<bits/stdc++.h>

using namespace std;

// set output precision
#define setopre(p) cout << fixed << setprecision(p)

// set output width and fill char, only work for single value
#define setowfill(w, f, what) cout << setw(w) << setfill(f) << what << endl

// logging (variadic)
#define log(...) [](const auto&...x){ char c='='; cout<<#__VA_ARGS__<<" "; ((cout<<exchange(c,',')<<" "<<x),...); cout<<endl; }(__VA_ARGS__);
// logging (iterable object)
#define logv(v) [](const auto& v){ cout<<#v<<" = ";for(const auto&i : v) cout<<i<<" "; cout<<endl; }(v);


int main() {
    setowfill(5, ' ', "asfd");
} 