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
        graph/scc.cpp
        judge/fhc.cpp
        judge/google.cpp
        judge/topcoder.cpp
        judge/usaco.cpp
        math/choose.cpp
        math/choose_old.cpp
        math/fast_modinv.cpp
        math/fastmod.cpp
        math/matrix.cpp
        math/mod.cpp
        math/mod_old.cpp
        math/stirling.cpp
        old/template_additons.cpp
        old/templateredux.cpp
        old/test.cpp
        string/hash.cpp
        string/hash_utils.cpp
        string/suffix_array.cpp
        string/suffix_automaton.cpp
        tree/hld.cpp
        tree/lca.cpp
        tree/lct.cpp
        fraction.cpp
        point.cpp
        multiple_cases.cpp
        random.cpp
        rank_compression.cpp
        template.cpp

        tests/ds/bit.test.cpp
        tests/ds/dsu.test.cpp
        tests/ds/li_chao_tree.test.cpp
        tests/ds/segment_tree.test.cpp
        tests/ds/segment_tree_lazy.test.cpp
        tests/ds/sparse_table.test.cpp

        tests/graph/2sat.test.cpp
        tests/graph/articulation_points.test.cpp
        tests/graph/bcc.test.cpp
        tests/graph/bridges.test.cpp)