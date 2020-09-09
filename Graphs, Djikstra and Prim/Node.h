template <class Node_entry>
struct Node {
//  data members
   Node_entry entry;
   Node<Node_entry> *next;
   Node_entry parent;
   int shortest_path;
   int degree;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link = NULL);
   Node(int, Node_entry);
};

template <class Node_entry>
Node<Node_entry>::Node()
{
   next = NULL;
   parent = -1;
   shortest_path = 100000;
   degree = 0;
}


template <class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node *add_on)
{
   entry = item;
   next = add_on;
   parent = -1;
   shortest_path = 100000;
}

template <class Node_entry>
Node<Node_entry>::Node(int s, Node_entry p){
	shortest_path = s;
	parent = p;
	next = NULL;
}

