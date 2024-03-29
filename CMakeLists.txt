cmake_minimum_required(VERSION 3.19)
project(templates)

set(CMAKE_CXX_STANDARD 17)

add_executable(templates
        ds/bit.hpp
        ds/dsu.hpp
        ds/segment_tree_lazy.hpp
        ds/li_chao_tree.hpp
        ds/segment_tree.hpp
        ds/sparse_table.hpp
        ds/treap.cpp
        external/E_fft.cpp
        external/E_reverse_it.cpp
        external/E_suffix_automaton.cpp
        external/extgcd.cpp
        external/fft.cpp
        external/flow.cpp
        external/mint.cpp
        external/UNFINISHED_ntt_big_mod.cpp
        graph/edge_types.hpp
        graph/2sat.hpp
        graph/tarjan_undirected.hpp
        graph/scc.hpp
        graph/bfs.hpp
        graph/bfs_0_1.hpp
        graph/dijkstra.hpp
        graph/spfa.hpp
        judge/fhc.cpp
        judge/google.cpp
        judge/topcoder.cpp
        judge/usaco.cpp
        math/choose.hpp
        math/_old_choose.cpp
        math/fast_modinv.hpp
        external/fastmod.cpp
        math/matrix.hpp
        math/mod.hpp
        math/_old_mod.cpp
        math/stirling1.hpp
        old/template_additons.cpp
        old/templateredux.cpp
        old/test.cpp
        string/_old_hash.cpp
        string/hash_utils.hpp
        string/suffix_array.hpp
        string/suffix_automaton.hpp
        tree/hld.hpp
        tree/lca_binary_lift.hpp
        tree/lca_jump.hpp
        tree/lca_sparse_table.hpp
        tree/lct.cpp
        fraction.cpp
        point.cpp
        timing.hpp
        multiple_cases.cpp
        random.hpp
        rank_compression.hpp
        template.cpp

        tests/ds/bit.test.cpp
        tests/ds/dsu.test.cpp
        tests/ds/li_chao_tree.test.cpp
        tests/ds/segment_tree.test.cpp
        tests/ds/segment_tree_lazy.test.cpp
        tests/ds/sparse_table.test.cpp

        tests/graph/2sat.test.cpp
        tests/graph/articulation_points.test.cpp
        tests/graph/biconnected_components.test.cpp
        tests/graph/bridges.test.cpp
        tests/graph/bfs.test.cpp
        tests/graph/dijkstra.test.cpp
        tests/graph/spfa.test.cpp

        tests/math/modint.test.cpp
        tests/math/choose.test.cpp
        tests/math/stirling2.test.cpp
        tests/math/prime_factor1.test.cpp
        tests/math/prime_factor2.test.cpp
        tests/math/totient.test.cpp
        tests/math/eea.test.cpp

        tests/tree/lca_binary_lift.test.cpp
        tests/tree/lca_sparse_table.test.cpp)
