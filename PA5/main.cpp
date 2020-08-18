#include <iostream>
#include "Graph.h"


using namespace std;

int main(int argc, char* argv[]){

	if(argc < 2){
	cout << "Usage: $PA5 graph (insert filename nsf.txt)" << endl;
	exit(1);
	}
string file = string(argv[1]); 

cout << "___________Create class G from Graph___________ " << endl;
Graph<int> g;
cout << "1: Read file nsf.txt into the program" << endl;
g.read(file);


int k = 1;
cout << "2: Run Dijkstra's algorithm on the array" << endl;
g.djks(k);
cout << endl;
cout << "3: Run Prim's algorigtm on the array" << endl;
g.prim(k);
cout << endl;
cout << "4: Remove link from 2 and 4 and run both algorithms again" << endl;
g.cutLink(2, 4, k);

Graph<int> h;
}
