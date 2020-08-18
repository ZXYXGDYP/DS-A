template <class Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node<Node_entry> *next;
	int chainSize;
	bool deleted;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link = NULL);
};

template <class Node_entry>
Node<Node_entry>::Node()
{
   next = NULL;
	chainSize = 0;
}


template <class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node *add_on)
{
   entry = item;
   next = add_on;
}

