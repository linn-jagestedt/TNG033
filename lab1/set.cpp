#include "set.hpp"

#include <algorithm>  //std::swap

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

   insert(x);
}

// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() 
{
    for (int e : elements) {
       insert(e); 
    }
}

// copy constructor
Set::Set(const Set& other) : Set() 
{
    clear();

    Node* current = other.head->next;
    
    while (current != nullptr) {
        insert(current->value);
        current = current->next;
    }
}

// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set other) {

    std::swap(head, other.head);
    counter = other.counter;
    return *this;
}

// Destructor: deallocate all nodes
Set::~Set() 
{
    clear();
    delete head;
}

// Return number of elements in the set
std::size_t Set::cardinality() const 
{
    return counter; 
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

    for (size_t i = 0; i < cardinality(); i++) 
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
Set Set::set_union(const Set& other) const 
{
    Set result = Set();

    Node* this_ptr = head->next;
    Node* other_ptr = other.head->next;

    while (this_ptr != nullptr && other_ptr != nullptr) {
        if (this_ptr->value < other_ptr->value) {
            result.insert(this_ptr->value);
            this_ptr = this_ptr->next;
        } else if (other_ptr->value < this_ptr->value) {
            result.insert(other_ptr->value);
            other_ptr = other_ptr->next;
        } else {
            result.insert(this_ptr->value);
            this_ptr = this_ptr->next;
            other_ptr = other_ptr->next;
        }
    }

    while (this_ptr != nullptr) {
        result.insert(this_ptr->value);
        this_ptr = this_ptr->next;
    }

    while (other_ptr != nullptr) {
        result.insert(other_ptr->value);
        other_ptr = other_ptr->next;
    }

    return result;
}

// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const 
{        
    Set result = Set();

    Node* current = head->next;

    while (current != nullptr) 
    {
        if (b.member(current->value)) {
            result.insert(current->value);
        }

        current = current->next;
    }

    return result;
}

// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const 
{
    Set result = Set();

    Node* current = head->next;

    while (current != nullptr) 
    {
        if (!b.member(current->value)) {
            result.insert(current->value);
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

void Set::insert(int value) 
{
    if (member(value)) {
        return;
    }

    Node* current_node = head;

    while (current_node->next != nullptr && current_node->next->value < value) {
        current_node = current_node->next;
    }

    Node* new_node = new Node(value, current_node->next);
    current_node->next = new_node;

    counter++;
}

void Set::clear() 
{
    Node* current = head->next;
    head->next = nullptr;

    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    counter = 0;
}