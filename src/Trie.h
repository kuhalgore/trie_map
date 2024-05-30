#pragma once
#include <array>
#include <memory>

/*!
why 32?
First printable character is 32*/
constexpr  unsigned int C_START_INDEX = 32;

/*!
why 95?
Ascii value range of printable characters is of 95 chars [32,126]
*/
constexpr  unsigned int C_NO_OF_CHILD_NODES = 95;

/*!
    Simple implemntation of a Trie data structure
    We can use,
    - insert() method to add a new entry
    - search() method to find value corresponding the input key

    We can use this Trie wherein keys consists of only digits from [0 to 9] and key length is not too large.
    ( time complexity of insert() and search() is O(n) where n is length of the input key )
    This is ideal for our use case where in we want to find int value corresponding to its string reprenstaion of digits
    for example "00"-> 00, "23"-->23 and "59"-->59, etc.
*/

template <typename ValType, unsigned int NO_OF_CHILD_NODES = C_NO_OF_CHILD_NODES, unsigned int START_INDEX = C_START_INDEX>
class Trie
{
    struct TrieNode
    {
        std::array< std::unique_ptr<TrieNode>, NO_OF_CHILD_NODES> children;
        std::unique_ptr<std::pair <std::string, ValType> > pStoredVal;
    };
    std::unique_ptr<TrieNode> root;
    unsigned int noOfElements;
    
    public:
    /*!
        A simple iterator implementation providing -> and * operator
    */
    struct Iterator
    {
        using pointer = std::pair<std::string, ValType> *;
        using reference = std::pair<std::string, ValType>&;
        
        Iterator(TrieNode* ptr):m_ptr(ptr){}
        pointer operator->() const
        {
            return m_ptr->pStoredVal.get();
        }
        reference operator*() const
        {
            return m_ptr->pStoredVal.get();
        }
        
        private:
        TrieNode* m_ptr;
    };
    
    Trie(): root(std::make_unique<TrieNode>()),noOfElements(0)
    {
        
    }
    
    /*!
        This method inserts a key value pair (word, arg) into the Trie
        - time complexity O(n) where n is length of the input key
    */
    void insert(const std::string & word, ValType&& arg)
    {
        auto len = word.length();
        
        ++noOfElements;
        
        TrieNode* currentNode = root.get();
        
        for(char c: word)
        {
            char indx = c-START_INDEX;
            auto& ptr = currentNode->children[indx];
            if(!ptr) //allocate a new node
            {
                ptr = std::make_unique<TrieNode>();
            }
            currentNode = ptr.get();
        }
        
        //now store the value at this node
        currentNode->pStoredVal = std::make_unique< std::pair <std::string, ValType> >(word, arg);
    }
    
    /*!
        This method retrives the value stored against the passed key as an argument
        - time complexity O(n) where n is length of the input key
    */
    std::pair<bool, Iterator> search(const std::string & word) const
    {
        TrieNode* currentNode = root.get();
        for(char c: word)
        {
            char indx = c-START_INDEX;
            auto& ptr = currentNode->children[indx];
            if(!ptr) //allocate a new node
            {
                return std::make_pair(false, Iterator(nullptr));
            }
            currentNode = ptr.get();
        }
        return std::make_pair(nullptr!=currentNode->pStoredVal, Iterator(currentNode));
    }
    
    size_t size() const
    {
        return noOfElements;
    }
};


