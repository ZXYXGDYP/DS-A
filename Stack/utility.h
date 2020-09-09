#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
using namespace std;

//Enumeration type
//Error_code: data type name
//defines a set of integer constants represented by identifiers
//The values of the enumeration constants start at 0 unless specified

enum Error_code { success, range_err, underflow, overflow, fail, not_present, duplicate_error, entry_inserted, entry_found, internal_error };
#endif
