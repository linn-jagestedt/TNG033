#include "set.hpp"

#include <set>
#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
* std::size_t is an unsigned integer type that can store the maximum size of any possible object
* sizes are non-negative integers -- i.e. unsigned integer type
*/

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{new Node{}}, counter{0} {  // create the dummy node

}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {

    Node* seccondNode = new Node(x, nullptr);
    Node* dummy = new Node(0, seccondNode);
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() 
{
    std::vector<int> temp(elements);
    Set* set = new Set();

    int minVal = INT32_MAX;
    int index = 0;

    head = new Node();
    Node* lastNode = head;

    while (temp.size() > 0) 
    {
        // Find the smallest value in the list
        for (int j = 0; j < temp.size(); j++) 
        {
            // If the current value is less the smallest value, update the value and the index
            if (temp[j] < minVal) 
            {
                minVal = temp[j];
                index = j;
            }
        }

        // Create a new node with the smallest element
        Node* node = new Node[temp[index], 0];
        
        // Create a link between the last node and the current
        lastNode->next = node;
        lastNode = node;

        // Remove the element from the list and reset values
        temp.erase(temp.begin() + index);
        index = 0;
        minVal = INT32_MAX;
    }
}

// copy constructor
Set::Set(const Set& rhs) : Set() {
    // ADD CODE
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) {
    // ADD CODE

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE
}

// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE
    return 0;  // delete, if needed
}

// Test if set is empty
bool Set::empty() const {
    // ADD CODE
    return true;  // delete, if needed

}

// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE
    return false;  // delete, if needed
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const {
    // ADD CODE
    return false;  // delete, if needed
}

// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    // ADD CODE
    return Set{};  // delete, if needed
}

std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/

