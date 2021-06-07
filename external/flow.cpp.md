---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://loj.ac/p/127
    - https://open.kattis.com/problems/maxflow
    - https://open.kattis.com/problems/mincut
    - https://vn.spoj.com/problems/FFLOW/
    - https://www.spoj.com/problems/FASTFLOW/
  bundledCode: "#line 1 \"external/flow.cpp\"\n// A sample edge struct for maximum\
    \ flow\n// Flow of edge can be found with cap - resCap\n// Template Arguments:\n\
    //   _FlowUnit: the type of the flow\n// Constructor Arguments:\n//   to: the\
    \ vertex that this directed edge ends at\n//   rev: the index in the adjacency\
    \ list of vertex to of the reverse edge\n//   cap: the initial capacity of this\
    \ edge\n// Fields:\n//   FlowUnit: the type of the flow\n//   to: the vertex that\
    \ this directed edge ends at\n//   rev: the index in the adjacency list of vertex\
    \ to of the reverse edge\n//   cap: the initial capacity of this edge\n//   resCap:\
    \ the residual capacity of this edge\n// Tested:\n//   https://open.kattis.com/problems/maxflow\n\
    //   https://open.kattis.com/problems/mincut\n//   https://www.spoj.com/problems/FASTFLOW/\n\
    //   https://vn.spoj.com/problems/FFLOW/\n//   https://loj.ac/p/127\ntemplate\
    \ <class _FlowUnit> struct FlowEdge {\n  using FlowUnit = _FlowUnit; int to, rev;\
    \ FlowUnit cap, resCap;\n  FlowEdge(int to, int rev, FlowUnit cap)\n      : to(to),\
    \ rev(rev), cap(cap), resCap(cap) {}\n};\n\n// Computes the maximum flow and minimum\
    \ cut in a flow network using the\n//   Push Relabel algorithm with the highest\
    \ label selection rule and\n//   gap relabelling heuristic\n// Vertices are 0-indexed\n\
    // Template Arguments:\n//   Edge: a generic edge class (such as FlowEdge)\n//\
    \     Required Fields:\n//       FlowUnit: the type of the flow\n//       to:\
    \ the vertex that this directed edge ends at\n//       rev: the index in the adjacency\
    \ list of vertex to of the reverse edge\n//       resCap: the residual capacity\
    \ of this edge\n//     Required Functions:\n//       constructor(to, rev, cap):\
    \ initializes the edge to vertex to with\n//         the reverse index rev and\
    \ capacity cap\n// Constructor Arguments:\n//   V: the number of vertices in the\
    \ flow network\n//   FLOW_EPS: a value for the flow epsilon\n// Fields:\n//  \
    \ V: the number of vertices in the flow network\n//   FLOW_EPS: a value for the\
    \ flow epsilon\n//   G: an adjacency list of all edges and reverse edges in the\
    \ flow network\n//   cut: a vector of booleans indicating which side of a minimum\
    \ s-t cut it\n//     is on\n// Functions:\n//   addEdge(v, w, vwCap, wvCap): adds\
    \ an edge from v to w with capacity\n//     vwCap and a reverse capacity of wvCap\n\
    //   getFlow(s, t): returns the maximum flow from s to t as well as the minimum\n\
    //     s-t cut\n// In practice, has a very small constant\n// Time Complexity:\n\
    //   constructor: O(V)\n//   addEdge: O(1)\n//   getFlow: O(V^2 sqrt E)\n// Memory\
    \ Complexity: O(V + E)\n// Tested:\n//   https://open.kattis.com/problems/maxflow\n\
    //   https://open.kattis.com/problems/mincut\n//   https://www.spoj.com/problems/FASTFLOW/\n\
    //   https://vn.spoj.com/problems/FFLOW/\n//   https://loj.ac/p/127\ntemplate\
    \ <class Edge> struct PushRelabelMaxFlow {\n  using FlowUnit = typename Edge::FlowUnit;\n\
    \  int V; FlowUnit FLOW_EPS; vector<vector<Edge>> G; vector<bool> cut;\n  PushRelabelMaxFlow(int\
    \ V, FlowUnit FLOW_EPS = FlowUnit(1e-9))\n      : V(V), FLOW_EPS(FLOW_EPS), G(V)\
    \ {}\n  void addEdge(int v, int w, FlowUnit vwCap, FlowUnit wvCap = FlowUnit())\
    \ {\n    if (v == w) return;\n    G[v].emplace_back(w, int(G[w].size()), vwCap);\n\
    \    G[w].emplace_back(v, int(G[v].size()) - 1, wvCap);\n  }\n  FlowUnit getFlow(int\
    \ s, int t) {\n    cut.assign(V, false); if (s == t) return FlowUnit();\n    vector<FlowUnit>\
    \ ex(V, FlowUnit()); vector<int> h(V, 0), cnt(V * 2, 0);\n    vector<vector<int>>\
    \ hs(V * 2);\n    vector<typename vector<Edge>::iterator> cur(V);\n    auto push\
    \ = [&] (int v, Edge &e, FlowUnit df) {\n      int w = e.to;\n      if (abs(ex[w])\
    \ <= FLOW_EPS && df > FLOW_EPS) hs[h[w]].push_back(w);\n      e.resCap -= df;\
    \ G[w][e.rev].resCap += df; ex[v] -= df; ex[w] += df;\n    };\n    h[s] = V; ex[t]\
    \ = FlowUnit(1); cnt[0] = V - 1;\n    for (int v = 0; v < V; v++) cur[v] = G[v].begin();\n\
    \    for (auto &&e : G[s]) push(s, e, e.resCap);\n    if (!hs[0].empty()) for\
    \ (int hi = 0; hi >= 0;) {\n      int v = hs[hi].back(); hs[hi].pop_back(); while\
    \ (ex[v] > FLOW_EPS) {\n        if (cur[v] == G[v].end()) {\n          h[v] =\
    \ INT_MAX; for (auto e = G[v].begin(); e != G[v].end(); e++)\n            if (e->resCap\
    \ > FLOW_EPS && h[v] > h[e->to] + 1)\n              h[v] = h[(cur[v] = e)->to]\
    \ + 1;\n          cnt[h[v]]++;\n          if (--cnt[hi] == 0 && hi < V) for (int\
    \ w = 0; w < V; w++)\n            if (hi < h[w] && h[w] < V) { cnt[h[w]]--; h[w]\
    \ = V + 1; }\n          hi = h[v];\n        } else if (cur[v]->resCap > FLOW_EPS\
    \ && h[v] == h[cur[v]->to] + 1) {\n          push(v, *cur[v], min(ex[v], cur[v]->resCap));\n\
    \        } else cur[v]++;\n      }\n      while (hi >= 0 && hs[hi].empty()) hi--;\n\
    \    }\n    for (int v = 0; v < V; v++) cut[v] = h[v] >= V;\n    return -ex[s];\n\
    \  }\n};\n\n\n"
  code: "// A sample edge struct for maximum flow\n// Flow of edge can be found with\
    \ cap - resCap\n// Template Arguments:\n//   _FlowUnit: the type of the flow\n\
    // Constructor Arguments:\n//   to: the vertex that this directed edge ends at\n\
    //   rev: the index in the adjacency list of vertex to of the reverse edge\n//\
    \   cap: the initial capacity of this edge\n// Fields:\n//   FlowUnit: the type\
    \ of the flow\n//   to: the vertex that this directed edge ends at\n//   rev:\
    \ the index in the adjacency list of vertex to of the reverse edge\n//   cap:\
    \ the initial capacity of this edge\n//   resCap: the residual capacity of this\
    \ edge\n// Tested:\n//   https://open.kattis.com/problems/maxflow\n//   https://open.kattis.com/problems/mincut\n\
    //   https://www.spoj.com/problems/FASTFLOW/\n//   https://vn.spoj.com/problems/FFLOW/\n\
    //   https://loj.ac/p/127\ntemplate <class _FlowUnit> struct FlowEdge {\n  using\
    \ FlowUnit = _FlowUnit; int to, rev; FlowUnit cap, resCap;\n  FlowEdge(int to,\
    \ int rev, FlowUnit cap)\n      : to(to), rev(rev), cap(cap), resCap(cap) {}\n\
    };\n\n// Computes the maximum flow and minimum cut in a flow network using the\n\
    //   Push Relabel algorithm with the highest label selection rule and\n//   gap\
    \ relabelling heuristic\n// Vertices are 0-indexed\n// Template Arguments:\n//\
    \   Edge: a generic edge class (such as FlowEdge)\n//     Required Fields:\n//\
    \       FlowUnit: the type of the flow\n//       to: the vertex that this directed\
    \ edge ends at\n//       rev: the index in the adjacency list of vertex to of\
    \ the reverse edge\n//       resCap: the residual capacity of this edge\n//  \
    \   Required Functions:\n//       constructor(to, rev, cap): initializes the edge\
    \ to vertex to with\n//         the reverse index rev and capacity cap\n// Constructor\
    \ Arguments:\n//   V: the number of vertices in the flow network\n//   FLOW_EPS:\
    \ a value for the flow epsilon\n// Fields:\n//   V: the number of vertices in\
    \ the flow network\n//   FLOW_EPS: a value for the flow epsilon\n//   G: an adjacency\
    \ list of all edges and reverse edges in the flow network\n//   cut: a vector\
    \ of booleans indicating which side of a minimum s-t cut it\n//     is on\n//\
    \ Functions:\n//   addEdge(v, w, vwCap, wvCap): adds an edge from v to w with\
    \ capacity\n//     vwCap and a reverse capacity of wvCap\n//   getFlow(s, t):\
    \ returns the maximum flow from s to t as well as the minimum\n//     s-t cut\n\
    // In practice, has a very small constant\n// Time Complexity:\n//   constructor:\
    \ O(V)\n//   addEdge: O(1)\n//   getFlow: O(V^2 sqrt E)\n// Memory Complexity:\
    \ O(V + E)\n// Tested:\n//   https://open.kattis.com/problems/maxflow\n//   https://open.kattis.com/problems/mincut\n\
    //   https://www.spoj.com/problems/FASTFLOW/\n//   https://vn.spoj.com/problems/FFLOW/\n\
    //   https://loj.ac/p/127\ntemplate <class Edge> struct PushRelabelMaxFlow {\n\
    \  using FlowUnit = typename Edge::FlowUnit;\n  int V; FlowUnit FLOW_EPS; vector<vector<Edge>>\
    \ G; vector<bool> cut;\n  PushRelabelMaxFlow(int V, FlowUnit FLOW_EPS = FlowUnit(1e-9))\n\
    \      : V(V), FLOW_EPS(FLOW_EPS), G(V) {}\n  void addEdge(int v, int w, FlowUnit\
    \ vwCap, FlowUnit wvCap = FlowUnit()) {\n    if (v == w) return;\n    G[v].emplace_back(w,\
    \ int(G[w].size()), vwCap);\n    G[w].emplace_back(v, int(G[v].size()) - 1, wvCap);\n\
    \  }\n  FlowUnit getFlow(int s, int t) {\n    cut.assign(V, false); if (s == t)\
    \ return FlowUnit();\n    vector<FlowUnit> ex(V, FlowUnit()); vector<int> h(V,\
    \ 0), cnt(V * 2, 0);\n    vector<vector<int>> hs(V * 2);\n    vector<typename\
    \ vector<Edge>::iterator> cur(V);\n    auto push = [&] (int v, Edge &e, FlowUnit\
    \ df) {\n      int w = e.to;\n      if (abs(ex[w]) <= FLOW_EPS && df > FLOW_EPS)\
    \ hs[h[w]].push_back(w);\n      e.resCap -= df; G[w][e.rev].resCap += df; ex[v]\
    \ -= df; ex[w] += df;\n    };\n    h[s] = V; ex[t] = FlowUnit(1); cnt[0] = V -\
    \ 1;\n    for (int v = 0; v < V; v++) cur[v] = G[v].begin();\n    for (auto &&e\
    \ : G[s]) push(s, e, e.resCap);\n    if (!hs[0].empty()) for (int hi = 0; hi >=\
    \ 0;) {\n      int v = hs[hi].back(); hs[hi].pop_back(); while (ex[v] > FLOW_EPS)\
    \ {\n        if (cur[v] == G[v].end()) {\n          h[v] = INT_MAX; for (auto\
    \ e = G[v].begin(); e != G[v].end(); e++)\n            if (e->resCap > FLOW_EPS\
    \ && h[v] > h[e->to] + 1)\n              h[v] = h[(cur[v] = e)->to] + 1;\n   \
    \       cnt[h[v]]++;\n          if (--cnt[hi] == 0 && hi < V) for (int w = 0;\
    \ w < V; w++)\n            if (hi < h[w] && h[w] < V) { cnt[h[w]]--; h[w] = V\
    \ + 1; }\n          hi = h[v];\n        } else if (cur[v]->resCap > FLOW_EPS &&\
    \ h[v] == h[cur[v]->to] + 1) {\n          push(v, *cur[v], min(ex[v], cur[v]->resCap));\n\
    \        } else cur[v]++;\n      }\n      while (hi >= 0 && hs[hi].empty()) hi--;\n\
    \    }\n    for (int v = 0; v < V; v++) cut[v] = h[v] >= V;\n    return -ex[s];\n\
    \  }\n};\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: external/flow.cpp
  requiredBy: []
  timestamp: '2021-06-06 19:00:04-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: external/flow.cpp
layout: document
redirect_from:
- /library/external/flow.cpp
- /library/external/flow.cpp.html
title: external/flow.cpp
---
