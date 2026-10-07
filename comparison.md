# Comparison

| Criterion | Linear | Quadratic | Double |
|---|---|---|---|
|All 7 inserted|Yes|No (73 fails)|Yes|
|53 probes|5|5|2|
|73 probes|7|10/not found|2|
|83 probes|8|10/not found|6|
|Clustering|High|Reduced|Low for this data|
|Average search|O(1)|O(1)|O(1)|
|Worst search|O(n)|O(n)|O(n)|
|Space|O(m)|O(m)|O(m)|

## Analysis
Linear probing forms a continuous cluster from index 3 to 9. Quadratic probing spreads entries better, but the size-10 table causes its probe sequence to repeat, so 73 cannot be inserted. Double hashing uses key-dependent step sizes and successfully stores all seven IDs with fewer probes for the selected successful searches.

## Most Suitable
Double hashing is the most suitable for this particular input because it successfully inserts all keys, distributes them better, and gives the lowest selected successful-search probe counts. A real system should also use an appropriate table size and resize before the load factor becomes too high.
