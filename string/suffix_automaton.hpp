#pragma once
#include "../template.hpp"

template <int MN> struct SAM {
    struct state {
        int len, link;
        map<char, int> to;
    };
    state st[MN*2];
    int last, sz = 0;
    void init() {
        for (auto i = 0; i < MN*2; i++) st[i] = {0, 0, map<char, int>()};
        st[0] = {0, -1, map<char, int>()};
        sz = 1; last = 0;
    }
    void extend(char c) {
        int cur = sz++, p = last;
        st[cur].len = st[last].len + 1;
        for (; p != -1 && !st[p].to.count(c); p = st[p].link)
            st[p].to[c] = cur;
        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].to[c];
            if (st[p].len + 1 == st[q].len) st[cur].link = q; // transition is continuous, we can link directly to Q as the parent in the prefix trie
            else { // transition is discontinuous, we must split node q into p+1, 
                int clone = sz++; 
                st[clone] = st[q]; st[clone].len = st[p].len + 1;
                for (; p != -1 && st[p].to[c] == q; p = st[p].link)
                    st[p].to[c] = clone;
                st[cur].link = st[q].link = clone;
            }
        }

        last = cur;
    }
};

