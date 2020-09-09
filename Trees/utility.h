#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

enum Error_code { duplicate_error, not_present, success };


int string_to_int(string s){
   istringstream instr(s);
   int n;
   instr >> n;
   return n;
}