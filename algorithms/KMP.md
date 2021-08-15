## KMP

# Overview

KMP is useful in string matching, it uses a hash table(next table, or some calls it fail table) to store the partially matched substring information (usually the next index of the pattern string that you should try to match) of a pattern string.

# Summary

Let pattern string length `m`, text length `n`:

Space: O(m), A hash table `next` to build for matching.
Time: O(n+m), build `next` with O(m) and match with O(n).

# Implementation

```c++

// KMP matches s with p, returns the match indices
vector<int> KMP(const string& s, const string& p) {
    vector<int> res;
    auto nxt = build(p); // build next table
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = nxt[j]; // 
        if (s[i] == p[j]) j++; // check if the last (i, j) is a match
        if (j == p.size()) { // got a match
            res.push_back(i-p.size()+1);
            j = nxt[j]; // reset j
        }
    }
    return res;
}

```

# The build function

The build function is used to generate the `next` table, it is very similar with the matching part of KMP, since it basically matches itself. Note that the first 2 elements of `next` are always `0`, so we can iterate from `i = 1`.

```python

def build(pat: str) nxt: List[int]:
    nxt = [0, 0]
    j = 0
    for i in range(1, len(pat)):
        while j > 0 and pat[i] != pat[j]:
            j = nxt[j]
        if pat[i] == pat[j]:
            j += 1
        nxt.append(j)
    return nxt

```

```c++

vector<int> build(const string& pat) {
    vector<int> nxt(2);
    for (int i = 1, j = 0; i < pat.size(); i++) {
        while (j > 0 && pat[i] != pat[j]) j = nxt[j];
        if (pat[i] == pat[j]) j++;
        nxt.push_back(j);
    }
    return nxt;
}

```

# Resource

https://www.youtube.com/watch?v=uKr9qIZMtzw