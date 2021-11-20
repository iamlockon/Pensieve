# Patience Sort

# Overview

Patience Sort is useful in finding LIS (Longest Increasing Subsequence). It has two rules:

・Can't place a higher-valued card onto a lowered-valued card.
・Can form a new pile and put a card onto it

And the goal is to form as few piles as possible.

There are following properties for Patience Sort:

1. At any stage during greedy algorithm, top cards of piles increase from left to right.
2. Cards within a pile form a decreasing subsequence.
3. (Important) [Hammersley 1972]  Min number of piles = length of LIS.
4. Each card maintains a pointer to top card in previous pile.

[1]

# Summary

We use a vector `tops` to store the index of top of piles. And `prev` map to trace the top index of last pile.

Space: O(nlogn)
Time: O(n)

# Implementation

## C++
```c++
int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    vector<int> tops{0}; // record indices of pile top
    unordered_map<int,int> prev;
    for (int i = 0 ; i < N; i++) {
        if (nums[i] <= nums[tops[0]]) { // when i less than/ equal to first pile top
            tops[0] = i;
        } else if (nums[i] > nums[tops.back()]) { // when i bigger than last pile top
            prev[i] = tops.back();
            tops.push_back(i);
        } else { // when i is in between, binary search
            auto it = lower_bound(begin(tops), end(tops), nums[i], [&](int idx, int val) { // since tops stores idx, we need to write our own comp.
                return nums[idx] < val;    
            });
            int idx = it - begin(tops);
            tops[idx] = i;
            prev[i] = tops[idx-1];
        }
    }

    // If you want to reconstruct the LIS
    // vector<int> res;
    // for (int idx = tops.back(); idx != 0; idx = prev[idx]) res.push_back(nums[idx]);
    // reverse(begin(res), end(res));
    // for (auto &i : res) cout << i << " ";
    // cout << endl;
    return tops.size();
}

```

# Resource

[1] https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf