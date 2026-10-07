# Complexity Analysis

Let n be the number of keys and m the table size.

| Method | Average insertion/search | Worst case | Space |
|---|---|---|---|
|Linear probing|O(1)|O(n)|O(m)|
|Quadratic probing|O(1)|O(n)|O(m)|
|Double hashing|O(1)|O(n)|O(m)|

All three methods use open addressing, so the table requires O(m) space.

At load factor alpha=0.70, collisions are significant. Linear probing suffers from primary clustering. Quadratic probing reduces primary clustering but depends on table size and may cycle through only part of the table. Double hashing usually provides better distribution when the secondary hash is well chosen.
