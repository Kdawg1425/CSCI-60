#ifndef LABNODE_H
#define LABNODE_H
#include <iostream>

class node {
public:

    typedef int value_type;

    // pre: none
    // post: creates a new node with given data and link values
    //       defaults: 0 and nullptr
    node(const value_type & = value_type(),//value_type() requires C++11
         node * = nullptr);

    // pre: none
    // post: returns data value stored in this node
    value_type data() const;

    // pre: none
    // post: returns link value stored in this node
    node* link() const;

    // pre: none
    // post: sets the data field to given value
    void set_data(const value_type &);

    // pre: none
    // post: sets the link field to given value
    void set_link(node *);


private:
    value_type _data;
    node *   _link;
    // invariants:
    //  _data holds the data value stored in this node
    //  _link holds the address of the next node
};

std::size_t list_index(node * head_ptr, int target);

node* list_at(node * head_ptr, std::size_t n);

//Pre: none
//Post: Clears the linked list
void list_clear(node * & head_ptr, node * & tail_ptr);

//Pre: none
//Post: Reverses the linked list
void list_reverse(node * & head_ptr, node * & tail_ptr);


#endif // NODE_H
