#pragma once
#include "../template.hpp"

/*
 * z[i] <- LCP(s[0..], s[i..])
 *
 * Finding z[0..N-1] quickly relies on finding an estimation for z[i] (that is less than the actual value), and
 * increasing it until it reaches the correct value.  This works because z[i] stores the LCP of some strings, so if z[i]
 * is a common prefix, then clearly z[i]-1 is one as well.
 *
 * To do this, we maintain the rightmost interval [l = i, r = i+z[i]-1] and solve for i-s sequentially.  At any point,
 * we have a few cases:
 *
 * (1) i > r : We start our estimate of z[i] as 0, and extend
 * (2) i <= r : Also note that in this case, l<=i<=r as we process i-s in order.  We know that s[l..r] == s[0..r-l] as
 * it is an interval that is defined by [k, k+z[k]-1] (for some k).  Thus, we use one of our previously computed values
 * to initialize z[i].  In this case, we use min(z[i-l], r-i+1), which is when we shift the interval [k, k+z[k]-1] to
 * [0, z[k]-1].
 *
 * Complexity Proof:
 *
 * (1) : We are always extending r and since r<N, we will extend at most N times
 * (2) :
 *   (2a) z[i-l] == r-i+1 : Again, we are extending r so this will happen at most N times (combined with case 1)
 *   (2b) z[i-l] < r-i+1 : We will extend 0 times, as if we could extend z[i], we could also extend z[i-l] as we know
 *        that s[l..r] == s[0..r-l] (and we are still within that range, so the extended character will be the same
 *        at both locations)
 *
 * Note: while z[0] is technically undefined, we'll define it as N for now
 */
template <typename Container> vector<int> z_algorithm(int N, const Container &s) {
    vector<int> z(N); z[0] = N;
    int l = 0, r = -1;
    for (int i = 1; i < N; i++) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i + z[i] < N && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i+z[i]-1 > r) {
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}