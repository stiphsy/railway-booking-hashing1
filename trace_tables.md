# Trace Tables

## Hash Calculation
h(k)=k%10. Every given ID maps to index 3.

| ID | Initial index |
|---:|---:|
|23|3|
|43|3|
|13|3|
|33|3|
|53|3|
|63|3|
|73|3|

## Linear Probing
Formula: (h(k)+i)%10

| ID | Probe sequence | Position |
|---:|---|---:|
|23|3|3|
|43|3,4|4|
|13|3,4,5|5|
|33|3,4,5,6|6|
|53|3,4,5,6,7|7|
|63|3,4,5,6,7,8|8|
|73|3,4,5,6,7,8,9|9|

Final: 3=23, 4=43, 5=13, 6=33, 7=53, 8=63, 9=73.

## Quadratic Probing
Formula: (h(k)+i^2)%10

| ID | Probe sequence | Result |
|---:|---|---|
|23|3|3|
|43|3,4|4|
|13|3,4,7|7|
|33|3,4,7,2|2|
|53|3,4,7,2,9|9|
|63|3,4,7,2,9,8|8|
|73|3,4,7,2,9,8,9,2,7,4|Not inserted|

Final: 2=33, 3=23, 4=43, 7=13, 8=63, 9=53.

## Double Hashing
h1(k)=k%10; h2(k)=7-(k%7).

| ID | h1 | h2 | Probe sequence | Position |
|---:|---:|---:|---|---:|
|23|3|5|3|3|
|43|3|6|3,9|9|
|13|3|1|3,4|4|
|33|3|2|3,5|5|
|53|3|3|3,6|6|
|63|3|7|3,0|0|
|73|3|4|3,7|7|

Final: 0=63, 3=23, 4=13, 5=33, 6=53, 7=73, 9=43.

## Search Trace
Selected keys: existing 53 and 73; non-existing 83.

| Method | Key | Result | Probes |
|---|---:|---|---:|
|Linear|53|Found|5|
|Linear|73|Found|7|
|Linear|83|Not found|8|
|Quadratic|53|Found|5|
|Quadratic|73|Not found|10|
|Quadratic|83|Not found|10|
|Double|53|Found|2|
|Double|73|Found|2|
|Double|83|Not found|6|
