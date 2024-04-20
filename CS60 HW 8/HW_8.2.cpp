#include <iostream>
#include "LabNode.h"

using namespace std;

int main() {
  node * head_ptr;
  node * tail_ptr;
  head_ptr = tail_ptr = new node(1, nullptr);
  for(int i = 2; i < 5; i++) {
    tail_ptr->set_link(new node(i,nullptr));
    tail_ptr = tail_ptr->link();
  }
  node * p = head_ptr;
  for(; p != nullptr; p = p->link()) {
    cout << p->data() << " ";
  }
  cout << endl;

  list_clear(head_ptr,tail_ptr);

  for(; p != nullptr; p = p->link()) {
    cout << p->data() << " ";
  }
  cout << endl;
  cout << (head_ptr == nullptr) << endl;
}
