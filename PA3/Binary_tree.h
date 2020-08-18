template <class Entry>
class Binary_tree {
public:
   Binary_tree();
   bool empty() const;
   void preorder(void (*visit)(Entry &));
   void inorder(void (*visit)(Entry &));
   void postorder(void (*visit)(Entry &));

   int size() const;
   void clear();
   int height() const;
   void insert(const Entry &);

   void print() const; // New method to print out the tree using preorder

   /*
   Binary_tree (const Binary_tree<Entry> &original);
   Binary_tree & operator =(const Binary_tree<Entry> &original);
   ~Binary_tree();
*/
protected:
   // Auxiliary functions
   void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
   void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
   void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

   void recursive_preorder_print_node(Binary_node<Entry> *sub_root) const;

   // Data member
   Binary_node<Entry>* root;
};

template <class Entry>
Binary_tree<Entry>::Binary_tree()
/*
Post: An empty binary tree has been created.
*/
{
   root = NULL;
}

template <class Entry>
bool Binary_tree<Entry>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
   return root == NULL;
}

template <class Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Entry &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Entry &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_inorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Entry &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   recursive_postorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::print() const{
/* 
Post: The tree has been traversed in preorder.  Each node and its two children is printed 
Uses: The function recursive_preorder_print_node
*/
   cout << endl;
   cout << "++++++++++++++++++++++" << endl;
   if(root == NULL)
      cout << "EMPTY TREE" << endl;
   else{
      if(root->left == NULL && root->right == NULL)
         cout << root->data << ":  -  -" << endl;

      recursive_preorder_print_node(root);
   }
   cout << "++++++++++++++++++++++" << endl;
   cout << endl;
}

// Functions

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root,
                                            void (*visit)(Entry &))
/*
Pre:  sub_root is either NULL or points to a subtree of the Binary_tree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder recursively
*/
{
   if (sub_root != NULL) {
      (*visit)(sub_root->data);
      recursive_preorder(sub_root->left, visit);
      recursive_preorder(sub_root->right, visit);
   }
}

template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root,
                                           void (*visit)(Entry &))
/*
Pre:  sub_root is either NULL or points to a subtree of the Binary_tree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{
   if (sub_root != NULL) {
      recursive_inorder(sub_root->left, visit);
      (*visit)(sub_root->data);
      recursive_inorder(sub_root->right, visit);
   }
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root,
                                             void (*visit)(Entry &))
/*
Pre:  sub_root is either NULL or points to a subtree of the Binary_tree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{
   if (sub_root != NULL) {
      recursive_postorder(sub_root->left, visit);
      recursive_postorder(sub_root->right, visit);
      (*visit)(sub_root->data);
   }
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder_print_node(Binary_node<Entry> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the Binary_tree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if (sub_root != NULL) {
      if(sub_root->left != NULL || sub_root->right != NULL){
         cout << sub_root->data << ":  ";
         if(sub_root->left != NULL)
            cout << sub_root->left->data << "  ";
         else
            cout << "-  "; // "-" represents no child
         if(sub_root->right != NULL)
            cout << sub_root->right->data << " ";
         else
            cout << "-  "; // "-" represents no child
         //cout << "; ";
         cout << endl;
      }
      recursive_preorder_print_node(sub_root->left);
      recursive_preorder_print_node(sub_root->right);
   }
}

