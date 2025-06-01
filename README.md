# Flam-Android-Assignment-1

Q1: LRU Cache
For this problem, I constructed an LRU (Least Recently Used) Cache that returns and updates quickly. To ensure that all operations execute in constant time (O(1)), I utilized two data structures in conjunction:
-> A doubly linked list to track the usage order of keys.
-> A hash map to access immediately any key's position in the list.
When we acquire a key, it gets relocated to the front (most recently used). When we add a new key and the cache is complete, the least recently used key (at the back) gets deleted to create space.
Achieved O(1) time complexity for both get() and put().


Q2: Custom MyHashMap
Here, I created my own version of a HashMap — without using any built-in hash table like unordered_map. Since the key range is known (up to 1 million), I used a simple trick: a big array where each index directly represents a key.
Adding, updating, or removing a key is just a matter of setting values in the array.
If a key isn’t present, it returns -1 by default.
Everything runs in constant time (O(1)).
