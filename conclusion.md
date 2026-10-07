# Final Conclusion

The railway booking system was implemented using linear probing, quadratic probing and double hashing. A table size of 10 was selected and h(k)=k%10 was used, making all seven given booking IDs collide at index 3.

Linear probing stored all seven keys but produced a long cluster. Quadratic probing reduced clustering but could not insert 73 because the probe sequence repeated with this table size. Double hashing successfully stored all seven keys and produced the best selected search performance.

The requested load factor was 7/10 = 0.70 (70%). For quadratic probing, only six of the seven requested IDs were actually inserted, so its final occupancy is 6/10 = 0.60 (60%). As load factor increases, collisions and probe counts generally increase.

Therefore, for this experiment, double hashing is the most suitable of the three methods. The experiment also demonstrates that hash-function and table-size selection are as important as the collision-resolution method itself.
