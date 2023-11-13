#include "set.hpp"

#include <algorithm>  //std::swap

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    std::cout << "Nodes: "<< Set::Node::count_nodes << "\n";
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{new Node{}}, counter{0} {  // create the dummy node

}

// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {

    Node* seccondNode = new Node(x, nullptr);
    head->next = seccondNode;
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() 
{
    int maxVal = INT32_MIN;

    for (size_t i = 0; i < elements.size(); i++)
    {
        if (elements[i] > maxVal) {
            maxVal = elements[i];
        }
    }

    int lastMinVal = INT32_MIN;

    Node* lastNode = head;

    while (lastMinVal != maxVal)
    {
        int minVal = INT32_MAX;

        for (size_t i = 0; i < elements.size(); i++)
        {
            if (elements[i] > lastMinVal && elements[i] < minVal) {
                minVal = elements[i];
            }
        }

        // Create a new node with the smallest element
        Node* node = new Node(minVal, 0);
            
        // Create a link between the last node and the current
        lastNode->next = node;
        lastNode = node;

        lastMinVal = minVal;
    } 
}

// copy constructor
Set::Set(const Set& other) : Set() 
{
    copy(other);
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set other) {

    copy(other);

    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() 
{
    clear();
    head->~Node();
}

// Return number of elements in the set
std::size_t Set::cardinality() const 
{
    Node* current = head;
    ssize_t count = 0;

    while (current->next != nullptr) {
        current = current->next;
        count++;
    }

    return count; 
}

// Test if set is empty
bool Set::empty() const 
{
    return head->next == nullptr;
}

// Test if x is an element of the set
bool Set::member(int x) const 
{
    Node* current = head;

    while (current != nullptr) 
    {
        if (current->value == x) {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const 
{   
    Node* current = head->next;

    for (int i = 0; i < cardinality(); i++) 
    {
        if (!b.member(current->value)) {
            return false;
        }

        current = current->next;
    }

    return true;
}

// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const 
{
    Set result = Set();

    Node* current_node = result.head;

    Node* a_node = head->next;
    Node* b_node = b.head->next;

    while (a_node != nullptr || b_node != nullptr) 
    {
        int val;

        if (b_node == nullptr) {
            val = a_node->value;
        }
        else if (a_node == nullptr) {
            val = b_node->value;
        } 
        else if (a_node->value < b_node->value) {
            val = a_node->value;
        }
        else {
            val = b_node->value;
        }

        current_node->next = new Node(val);

        while (a_node != nullptr && result.member(a_node->value)) {
            a_node = a_node->next;
        }

        while (b_node != nullptr && result.member(b_node->value)) {
            b_node = b_node->next;
        }

        if (a_node != nullptr || b_node != nullptr) {
            current_node = current_node->next;
        }
    }

    return result;
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const 
{        
    Set result = Set();

    Node* result_current = result.head;
    Node* current = head->next;

    while (current != nullptr) 
    {
        if (b.member(current->value)) {
            result_current->next = new Node(current->value);
            result_current = result_current->next;
        }

        current = current->next;
    }

    return result;
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    Set result = Set();

    Node* result_current = result.head;
    Node* current = head->next;

    while (current != nullptr) 
    {
        if (!b.member(current->value)) {
            result_current->next = new Node(current->value);
            result_current = result_current->next;
        }

        current = current->next;
    }

    return result;
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

void Set::clear() 
{
    Node* current = head->next;
    head->next = nullptr;

    while (current != nullptr) {
        Node* next = current->next;
        current->~Node();
        current = next;
    }
}

void Set::copy(const Set& other) 
{
    clear();

    Node* current = other.head->next;
    Node* lastNode = head;
    
    while (current != nullptr) {
        Node* newNode = new Node(current->value, nullptr);
        lastNode->next = newNode; 
        lastNode = newNode;
        current = current->next;
    }
}