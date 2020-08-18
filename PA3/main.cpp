#include "utility.h"
#include "Binary_node.h"
#include "Binary_tree.h"
#include "Search_tree.h"
#include "AVL_node.h"
#include "AVL_tree.h"


int main(){
   string input = "";
   bool exit_now = false;
   AVL_tree<int> atree;
   while(!exit_now){
      cout << endl;
      cout << "***********************" << endl;
      cout << "Menu:" << endl;
      cout << "1. Incremental Insert" << endl;
      cout << "2. Insert from File" << endl;
      cout << "3. Incremental Delete" << endl;
      cout << "4. Delete from File" << endl;
      cout << "p. Print tree" << endl;
      cout << "x. Exit" << endl;
      cout << "***********************" << endl;

      getline(cin, input);

      if(input == "1"){
         cout << endl;
         cout << "Enter new integer keys to insert.  Enter \"q<Enter>\" to quit." << endl;
         cout << endl;
         getline(cin, input);
         while(input != "q"){
            atree.insert(string_to_int(input));
            atree.print();            
            getline(cin, input);
         }
      } 
      else if(input == "2"){
         cout << endl << "Enter Insertion File Name:" << endl;
         getline(cin, input);
         ifstream insertion_file;
         insertion_file.open(input.c_str());
         if(!insertion_file.fail()){
            while(!insertion_file.fail() && !insertion_file.eof()){
               getline(insertion_file, input);
               atree.insert(string_to_int(input));
            }
            atree.print();
         } else
            cout << "Invalid file name." << endl;
      }
      else if(input == "3"){
         cout << endl;
         cout << "Enter integer keys to delete.  Enter \"q<Enter>\" to quit." << endl;
         cout << endl;
         getline(cin, input);
         while(input != "q"){
            atree.remove(string_to_int(input));
            atree.print();            
            getline(cin, input);
         }
      } 
      else if(input == "4"){
         cout << endl << "Enter Deletion File Name:" << endl;
         getline(cin, input);
         ifstream deletion_file;
         deletion_file.open(input.c_str());
         if(!deletion_file.fail()){
            while(!deletion_file.fail() && !deletion_file.eof()){
               getline(deletion_file, input);
               atree.remove(string_to_int(input));
            }
            atree.print();
         } else
            cout << "Invalid file name." << endl;
      }
      else if (input == "p")
         atree.print();
      else if(input == "x")
         exit_now = true;
   }
   
}
