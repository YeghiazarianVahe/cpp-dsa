# vector

Experiments and implementations around `std::vector` as a data structure.

## Experiment 1 — capacity growth

**Question:** how does `std::vector<int>::capacity()` grow during 1 000 000 `push_back` calls?

**Setup:** `experiments/capacity_growth.cpp`, g++ 15.1, libstdc++, `-std=c++20`.

**Result:**
- capacity changed **21 times**, always **×2** (0→1→2→4→…→1 048 576);
- growth factor is implementation-defined: libstdc++ uses 2, MSVC uses 1.5.

**Why `push_back` is amortized O(1):**
- a reallocation at size `s` copies `s` elements;
- total copies for n pushes: 1 + 2 + 4 + … + n/2 ≈ n (geometric series);
- total work ≈ 2n, so about 2 operations per `push_back` — constant;
- a single `push_back` can still cost O(n) when a reallocation happens.

**Why fixed growth (+10) is bad:**
- reallocations happen n/10 times, total copies ≈ n²/20;
- for n = 10⁶ that is ≈ 5·10¹⁰ copies (~50 000 per element);
- `push_back` becomes O(n) amortized — quadratic overall.

**Growth factor trade-off:** a large factor means few reallocations but a lot of
unused memory; a small factor means less waste but more copying. 1.5 and 2 are the
common compromise.
