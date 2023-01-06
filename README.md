# Templates

[![Actions Status](https://github.com/plasmatic1/templates/workflows/verify/badge.svg)](https://github.com/plasmatic1/templates/actions)
[![Documentation](https://img.shields.io/static/v1?label=&message=GitHub+Pages&color=gray&logo=github)](https://plasmatic1.github.io/templates/)

Restructuring of my Data Structure/Algorithm Templates, rewritten with [verification-helper](https://github.com/online-judge-tools/verification-helper) to test for correctness.

As these templates are being given tests, I will also make improvements as some of them are quite old and have issues.  Documentation for each template is also planned.

Templates under `external/` are not mine and will not include tests.  It is possible in the future that I will be re-implementing those algorithms and thus adding tests to them.

## Some Things to Add

- Math
    - CRT
    - Extended GCD/EEA
    - Matrices
    - Fractions
    - BigInt
    - Linear Diophantine solver?   
    - Tests for
      - Stirling numbers (1st kind)
      - Catalan numbers
      - Chinese Rem. Theorem
    - Stuff that is t o o h a r d
      - Multipoint eval
      - Berlekamp-Massey
      - Everything else in library-checker
- Bounds checking  
- Segtree with permanent flag instead of lazy propagation (a bit faster possibly)
- Iterative segtree
- Floyd Warshall/Bellman Ford? (I don't think these are really necessary since they're super super simple)


- ###### Geometry
    - Point class for now :)
