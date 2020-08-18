#ifndef NODE_H
#define NODE_H
struct Node {
    int entry;
    Node* next;
    
    Node();
    Node(int);
    Node(int, Node*);

};

#endif
