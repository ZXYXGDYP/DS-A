enum Balance_factor { left_higher, equal_height, right_higher };

template <class Entry>
struct Binary_node{
//    data members:
   Entry data;
   Binary_node<Entry> *left;
   Binary_node<Entry> *right;
//    constructors:
   Binary_node();
   Binary_node(const Entry &x);

   // virtual methods:
   virtual void set_balance(Balance_factor b);
   virtual Balance_factor get_balance() const;
};

template <class Entry>
Binary_node<Entry>::Binary_node(){
   left = NULL;
   right = NULL;
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x){
   data = x;
   left = NULL;
   right = NULL;
}

// Dummy functions
template <class Entry>
void Binary_node<Entry>::set_balance(Balance_factor b){
}

template <class Entry>
Balance_factor Binary_node<Entry>::get_balance() const {
	return equal_height;
}
