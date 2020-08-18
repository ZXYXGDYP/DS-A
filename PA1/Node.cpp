#include <iostream>
#include "Node.h"


Node::Node()
{
    next = NULL;
}
Node::Node(int x)
{
    entry = x; 
    next = NULL;
}
Node::Node(int x, Node* p)
{
    entry = x;
    next = p;
}
