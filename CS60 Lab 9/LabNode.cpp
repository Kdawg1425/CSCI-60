#include "LabNode.h"

#include <iostream>

node::node(const value_type & init_data, node * init_link)
{

    _data = init_data;
    _link = init_link;
}

node::value_type node::data() const
{
    return _data;
}

node * node::link() const
{
    return _link;
}

void node::set_data(const value_type & new_data)
{
    _data = new_data;
}

void node::set_link(node * new_link)
{
    _link = new_link;
}

std::size_t list_index(node * head_ptr, int target){
  size_t ans = 0;
  for(node * p = head_ptr; p!=nullptr; p = p->link()){
    if(p->data() == target)
      return ans;
    else
      ans++;
  }
  return -1;
}

node* list_at(node * head_ptr, std::size_t n){
  std::size_t count = 0;
  for(node * p = head_ptr; p!=nullptr; p = p->link()){
    if(count==n)
      return p;
    else
      count++;
  }
  return nullptr;
}

void list_clear(node * & head_ptr, node * & tail_ptr) {
  if(head_ptr == nullptr) {
    return;
  }
  node *next = head_ptr;
  next = next->link();
  for(; next != nullptr; next = next->link()) {
    delete head_ptr;
    head_ptr = next;
  }
  delete head_ptr;
  head_ptr = nullptr;
  tail_ptr = nullptr;
}

void list_reverse(node * & head_ptr, node * & tail_ptr){
  node * current = head_ptr;
  tail_ptr = head_ptr;
  node * prev = nullptr;
  node * next = nullptr;
  while (current != nullptr) {
    next = current->link();
    current->set_link(prev);
    prev = current;
    current = next;
  }
  head_ptr = prev;
}
