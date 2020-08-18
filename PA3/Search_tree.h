template <class Record>
class Search_tree: public Binary_tree<Record> {
public:
   Error_code insert(const Record &new_data);
   Error_code remove(const Record &old_data);
   Error_code tree_search(Record &target) const;
protected:
   // Auxiliary functions
   Error_code search_and_insert(Binary_node<Record>* &sub_root, const Record &new_data);
   Error_code search_and_delete(Binary_node<Record>* &sub_root, const Record &target);
   Binary_node<Record>* search_for_node(Binary_node<Record>* sub_root, const Record &target) const;
};


template <class Record>
Error_code Search_tree<Record>::insert(const Record &new_data)
{
   return search_and_insert(this->root, new_data);
}


template <class Record>
Error_code Search_tree<Record>::search_and_insert(
           Binary_node<Record> *&sub_root, const Record &new_data)
{
   if (sub_root == NULL) {
      sub_root = new Binary_node<Record>(new_data);
      return success;
   }
   else if (new_data < sub_root->data)
      return search_and_insert(sub_root->left, new_data);
   else if (new_data > sub_root->data)
      return search_and_insert(sub_root->right, new_data);
   else return duplicate_error;
}


template <class Record>
Error_code Search_tree<Record>::remove(const Record &target)
/*
Post: If a Record with a key matching that of target belongs to the
      Search_tree, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function search_and_destroy
*/
{
   return search_and_delete(this->root, target);
}


template <class Record>
Error_code Search_tree<Record>::search_and_delete(
           Binary_node<Record>* &sub_root, const Record &target)
/*
Pre:  sub_root is either NULL or points to a subtree of the Search_tree.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions search_and_delete recursively
*/
{
   Error_code result = success;
   if (sub_root == NULL) 
      result = not_present;   
   else if (sub_root->data == target) {
      Binary_node<Record>* to_delete; // used to remember the node to delete
      result = success;
      if(sub_root->left == NULL){ // no left child
         to_delete = sub_root;
         sub_root = sub_root->right;
         delete to_delete;
      }
      else if(sub_root->right == NULL){ // no right child
         to_delete = sub_root;
         sub_root = sub_root->left;
         delete to_delete;
      }
      else{ // has both children
         to_delete = sub_root->left;
         while (to_delete->right != NULL) //  find the immediate predecessor.
            to_delete = to_delete->right;
         sub_root->data = to_delete->data;  //  Move the immediate predecessor from to_delete to current node

         search_and_delete(sub_root->left, sub_root->data); // NOTE that we start to delete the immediate predecessor here 
      }
   }
   else if (target < sub_root->data) { // Delete in left subtree.
      result = search_and_delete(sub_root->left, target);
   }
   else { //  Delete in right subtree.
      result = search_and_delete(sub_root->right, target);
   }
   return result;
}



template <class Record>
Error_code Search_tree<Record>::tree_search(Record &target) const
/*
Post: If there is an entry in the tree whose key matches that in target,
      the parameter target is replaced by the corresponding record from
      the tree and a code of success is returned.  Otherwise
      a code of not_present is returned.
Uses: function search_for_node
*/
{
   Error_code result = success;
   Binary_node<Record> *found = search_for_node(this->root, target);
   if (found == NULL)
      result = not_present;
   else
      target = found->data;
   return result;
}


template <class Record>
Binary_node<Record> *Search_tree<Record>::search_for_node(
            Binary_node<Record>* sub_root, const Record &target) const
{
   if (sub_root == NULL || sub_root->data == target) return sub_root;
   else if (sub_root->data < target)
      return search_for_node(sub_root->right, target);
   else return search_for_node(sub_root->left, target);
}

