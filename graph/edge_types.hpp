#pragma once
#include "../template.hpp"

struct Edge {
    using EdgeType = int;
    int v(EdgeType e) { return e; }
    int w(EdgeType e) { return 1; }
    int i(EdgeType e) { throw domain_error("no information on edge indices"); }
    EdgeType swapNode(EdgeType e, int v) { return v; }
};
template <typename T> struct WeightedEdge {
    using EdgeType = pair<int, T>;
    int v(EdgeType e) { return e.first; }
    T w(EdgeType e) { return e.second; }
    int i(EdgeType e) { throw domain_error("no information on edge indices"); }
    EdgeType swapNode(EdgeType e, int v) { return {v, w(e)}; }
};
struct IndexedEdge {
    using EdgeType = pair<int, int>;
    int v(EdgeType e) { return e.first; }
    int w(EdgeType e) { return 1; }
    int i(EdgeType e) { return e.second; }
    EdgeType swapNode(EdgeType e, int v) { return {v, i(e)}; }
};
template <typename T> struct WeightedIndexedEdge {
    using EdgeType = tuple<int, T, int>;
    int v(EdgeType e) { return get<0>(e); }
    T w(EdgeType e) { return get<1>(e); }
    int i(EdgeType e) { return get<2>(e); }
    EdgeType swapNode(EdgeType e, int v) { return {v, w(e), i(e)}; }
};
