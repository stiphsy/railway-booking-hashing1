# Railway Booking System - Hashing Collision Resolution

## Problem
Booking IDs: 23, 43, 13, 33, 53, 63, 73.

This project implements Linear Probing, Quadratic Probing and Double Hashing in C.

## Hash Table
- Table size: 10
- Primary hash: h(k) = k % 10
- All seven IDs initially hash to index 3, creating a collision-heavy test case.

Double hashing:
- h1(k) = k % 10
- h2(k) = 7 - (k % 7)
- index = (h1(k) + i*h2(k)) % 10

## Load Factor
For the requested 7 booking IDs: alpha = 7/10 = 0.70 (70%).

## Main Result
Linear probing inserts all seven keys but forms a large cluster.
Quadratic probing reduces clustering, but with table size 10 its probe sequence repeats, so 73 cannot be inserted.
Double hashing inserts all seven keys and gives the best selected search performance.

## Files
- linear_probing.c
- quadratic_probing.c
- double_hashing.c
- input.txt
- output.txt
- trace_tables.md
- complexity.md
- comparison.md
- conclusion.md

## Compile
gcc linear_probing.c -o linear
gcc quadratic_probing.c -o quadratic
gcc double_hashing.c -o double

On Windows, run linear.exe, quadratic.exe and double.exe.

## Conclusion
For this particular collision-heavy input, double hashing is the most suitable of the three methods. In a real system, table size and load factor should be chosen carefully; prime-sized tables are commonly preferred for open addressing.
