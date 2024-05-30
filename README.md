# trie_map
C++ implementation of Trie data structure  - to have very fast retrieval of values based on string keys.

***Note*** - 
This data structure can be used to store {key, value} pairs where key is of type std::string.
Time complexity for search is O(n) where n is length of the key,

consequently this would give drastic performance gain when the length of the key is shorter.
The performance can be even improved if we know the span of characters that our keys can have.
In that case we specify number of distinct characters the keys can have and the ascii value of the starting char.

for eg - if we want to store mapping between string representation of digits against their actual values,
we can specify no of different chars as 10 [ 0 to 9] and starting char as 48 (ascci value of char '0' )


** Specifications **

The template class Trie can be initialized with 3 template parameters( 1 mandatory, 2 optional)
By default key can be of string type with chars range from 32 to 126 (95 printable chars)

For Example,
Trie<int> - mapping between key->int (where key can have chars between 32 to 196)
Trie<double, 10, 48> - mapping between key ->double (where key can have chars between 48 to 57 - ie only digits)
Trie<string, 26, 65> - mapping between key ->string (where key can have chars between 65 to 92 - ie only lower case charaters)

public methods
void insert(const std::string & key) method to add a new entry
std::pair<bool, Iterator>  search(const std::string & key) method to find value corresponding the input key



## Unit testing
We have used Catch2 - a header only unit testing framework to write the test cases.  
The header file catch.hpp is included in the src directory solely to be able to write some unit test cases using the Catch2 framework.  
The code contains main() function which calls these unit test cases, 
when the main program is executed without any arguments it will run all the unit test cases  and provide the output on std::out console.  
All unit tests are written in UnitTests.cpp file.


## How to use?
All source code is written in a single header file Trie.h
We can #include Trie.h in our code and directly utilize its functionality

Get set go !!