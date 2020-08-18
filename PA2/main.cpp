#include "utility.h"
#include "Node.h"
#include "List.h"
#include "SortedList_LL.h"
#include "SortedList_Arr.h"

template <class List_entry>
void increaseByOne(List_entry&);

int main() {

cout << "=============================================================="<< endl;
cout << "Start of program, testing SortedList_LL and SortedList_Arr. " << endl;
cout << "Starting with SortedList_LL. " << endl << endl;
cout << "Creating list b of type double: ";
ListLL<double> b;

cout << endl << "Filling LL b with items. (#s 1-20) " << endl;
for(int i = 1; i < 20; i++){
b.insertLL(i);
}
cout << endl << "Finding the position of the number 9, should expect at position 8" << endl;
b.searchLL(9);

cout << endl << "Deleting the first number out of the linked list, should be number 1" << endl;
double a;
b.removeLL(a);
cout << "The number is " << a << endl;

cout << endl << "inserting random numbers into the LL, should create a sorted list. (2, 4 and 6) " << endl;
b.insertLL(4);
b.insertLL(6);
b.insertLL(2);

cout << endl << "Deleting firt 5 numbers to see arrangment. " << endl;
double c, d, e, f, g, h, i, j;
b.removeLL(c); b.removeLL(d); b.removeLL(e); b.removeLL(f); b.removeLL(g);
cout << c << "," << d << ", " << e << ", " << f << ", " << g << endl;

cout << endl << "Running the list through the function IncreaseByOne. " << endl;
b.visitLL(increaseByOne);

cout << endl << "Deleting the next 3 numbers (5, 6, 6) to see an increase " << endl;;
b.removeLL(h); b.removeLL(i); b.removeLL(j);
cout << h << "," << i << ", " << j << endl;

cout << endl << "Finally, using the copy constructor to set up another LL. " << endl;
ListLL<double> b2(b);

cout << "Outputing the first numbers of b2." << endl;
b2.removeLL(c); b2.removeLL(d); b2.removeLL(e);
cout << c << ", " << d << ", " << e << endl;


cout << "=============================================================="<< endl;
cout << "Start of 2nd part, testing SortedList_Arr. " << endl;
cout << "Creating list list of type ints: ";
ListArr<int> list;

cout << endl << "Filling ARR list with items. (#s 1-20) " << endl;
for(int i = 1; i < 20; i++){
list.insertAr(i);
}
cout << endl << "Finding the position of the number 12, should expect at position 11" << endl;
int num = 12;
list.searchAr(num);

cout << endl << "Deleting the number 10 out of ehe array" << endl;
int z = 10;
list.removeAr(z);

cout << endl << "inserting random numbers into the Arr, should create a sorted list. (3, 5 and 7) " << endl;
list.insertAr(3);
list.insertAr(5);
list.insertAr(7);

/*
cout << endl << "Deleting firt 5 numbers to see arrangment. " << endl;
int m, n, o, p, q, r, s, t;
list.removeAr(m); list.removeAr(n); list.removeAr(o); list.removeAr(p); list.removeAr(q);
cout << m << "," << n << ", " << o << ", " << p << ", " << q << endl;

cout << endl << "Running the list through the function IncreaseByOne. " << endl;
list.visitAr(increaseByOne);

cout << endl << "Deleting the next 3 numbers (5, 6, 7) to see an increase " << endl;;
list.removeAr(r); list.removeAr(s); list.removeAr(t);
cout << r << "," << s << ", " << t << endl;

cout << endl << "Finally, using the copy constructor to set up another LL. " << endl;
ListArr<int> list2(list);

cout << "Outputing the first numbers of list2." << endl;
list2.removeAr(m); list2.removeAr(n); list2.removeAr(o);
cout << m << ", " << n << ", " << o << endl;
*/


}

template <class List_entry>
void increaseByOne(List_entry& x){
	x++;
}
