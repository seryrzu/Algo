#ifndef LIST_H
#define LIST_H

struct Node {
  int value;
  Node * next;
};


void add_to_list_front(Node * &root, int _value);

void add_to_list_end(Node * &root, int _value);

const Node * find_element_in_list(const Node * root, int _value);

#endif // LIST_H
