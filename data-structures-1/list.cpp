#include "list.h"
#include <cstdio>

void add_to_list_front(Node * &root, int _value) {
  Node * p = new Node();
  *p = { _value, root };
  root = p; 
 }

void add_to_list_end(Node * &root, int _value) {
  if(!root) {
    root = new Node();
    *root = { _value, 0 };
    return;
  }
  Node *p = root;
  while(p -> next != 0) p = p -> next;
  p -> next = new Node();
  p = p -> next;
  *p = { _value, 0 };
}

const Node * find_element_in_list(const Node * root, int _value) {
  if (!root) return 0;
  const Node * p = root;
  while (p && p -> value != _value) p = p -> next;
  return p;
}
