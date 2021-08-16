# DSU

# Overview

DSU (Disjoint set, union-find) can be used when we want to group many elements into one(many) clusters, and check to which cluster any element belongs. Although BFS usually works where DSU works, DSU enables cleaner implementation.

# Summary

Let elements be indexed from 0 to N-1, we use two arrays to store the DSU data structure:

- parents[i]: store the cluster id the ith element belongs to.

- ranks[i]: store the cluster rank for the root of the ith element.

There are two methods supported:

- find: amortized O(1) time complexity, find the root of the element. Note that we will also do path compression in this method.

- merge: O(1) time complexity, group two clusters(elements), and update ranks when appropriate.

# Implementation

## C++
```c++
struct DSU {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    DSU(int n) {
        parents = vector<int>(n);
        ranks = vector<int>(n);
        for (int i = 0; i < n; i++) parents[i] = i;
    }
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return; // important
        if (ranks[ra] > ranks[rb]) parents[ra] = rb;
        else if (ranks[ra] < ranks[rb]) parents[rb] = ra;
        else {
            parents[ra] = rb;
            ranks[rb]++; // only need to update ranks when their ranks are different.
        }
    }
};
```

# Reference

https://www.youtube.com/watch?v=VJnUwsE4fWA