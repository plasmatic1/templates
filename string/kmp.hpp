#pragma once
#include "../template.hpp"

/*
 * Assume `s` is a string that is 0-indexed
 * Let pi[i] -> longest proper prefix `k` of s[0..i] s.t. s[0..k-1] == s[i-k+1..i].  This is known as prefix property
 *
 * 1: pi[i-1] -> pi[i] can increase by at most 1.  If this was not the case, then we can delete the last character of
 * pi[i] and obtain a better result for pi[i-1]
 *
 * 2: To calculate pi[i] we enumerate all values `j` s.t. the prefix property holds for s[0..i-1], and pick the longest one
 * s.t. s[j] == s[i].  This follows from (1)
 *
 * 2a: We can do this by repeatedly picking the largest value of `j` we have not tried yet
 * 2b: To do this we can begin with pi[i-1] (which is by definition the largest `j`) and move iteratively from there
 * 2c: pi[i-1] allows us to map s[i-pi[i-1]+1..i] to s[0..pi[i-1]-1], which means that the next largest `j` will be at
 * pi[pi[i-1]-1] (which is the first pi[i-1] chars of s and is guaranteed to be less than pi[i-1].  We then repeat
 * iteratively until we find a value.
 */
template <typename Container> vector<int> kmp(int N, const Container &s) {
    vector<int> pi(N);
    for (int i = 1; i < N; i++) {
        int cur = pi[i-1];
        while (cur && s[i] != s[cur]) cur = pi[cur-1];
        if (s[i] == s[cur]) cur++;
        pi[i] = cur;
    }
    return pi;
}