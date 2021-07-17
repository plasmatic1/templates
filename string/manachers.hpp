#pragma once
#include "../template.hpp"

/*
 * d[i] = Longest odd-length palindrome centered at i.  Formally, largest value d[i] s.t. s[i-k] == s[i+k] for all
 * 0<=k<d[i].
 *
 * This algorithm works almost identically to z-algorithm.  For more information and explanation, see
 * string/z_algorithm.hpp
 *
 * The key differences between the algorithms are: instead of 'shifting' from i -> i-l when using precomputed values,
 * we instead flip across the midpoint of rightmost palindrome substring we found to find our precomputed value.
 * Additionally, we extend out in both directions instead of only forwards as we are looking for palindromes.
 *
 * To find the longest palindromes for even locations, add placeholders between each character.
 */
template <typename Container> vector<int> manachers(int N, const Container &s) {
    vector<int> d(N);
    int l = 0, r = -1;
    for (int i = 0; i < N; i++) {
        if (i <= r) d[i] = min(r-i+1, d[l + r - i]); // flip across (l+r)/2
        while (0 <= i-d[i] && i+d[i] < N && s[i-d[i]] == s[i+d[i]]) d[i]++;
        if (i+d[i]-1 > r) {
            l = i-d[i]+1;
            r = i+d[i]-1;
        }
    }
    return d;
}