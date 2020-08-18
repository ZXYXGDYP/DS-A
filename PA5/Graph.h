#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <fstream>
#include <string>
using namespace std;

template <class T>
class Graph{
private:
	int numOfNodes;
	Node<T>** list;
	Node<T>** primList;
	Node<T>** connections;
	Node<T>** cutTemp;
	string hash;
	int aveDegree = 0;
	ifstream in;
	string input, connectTo, weight;
	void doPrim(int, Node<T>**&);
	void doDjks(int, Node<T>**&);

public:
	Graph();
	~Graph();
	void prim(int);
	void djks(int);
	//void bfs();
	//void dfs();
	void cutLink(int, int, int);
	void read(string s);
	bool falseLeft(bool*&);
	void initializeSource(Node<T>**&, bool*&);
	void relax(Node<T>**&, int, int*&, Node<T>**&);
	int getNext(int, int*&, bool*&, Node<T>**&);
	void getParents(int, int*&, Node<T>**&);
	int nextInPrim(int, int*&, bool*&, Node<T>**&);
	void relaxPrim(Node<T>**&, int, int*&, Node<T>**&);
	void cut(int, int, Node<T>** &);
	void setSource(Node<T>** &);

};

#endif
//a lot of the blue-ed out code is debugging printing functions


template <class T>
Graph<T>::Graph()
{
	numOfNodes = 0;
	list = new Node<T>*[15];
	primList = new Node<T>*[15];
	connections = new Node<T>*[15];
	cutTemp = new Node<T>*[15];
}

template <class T>
Graph<T>::~Graph(){

}

template <class T>
void Graph<T>::prim(int a){
doPrim(a, connections);
}

template <class T>
void Graph<T>::djks(int a){
doDjks(a, connections);
}

template <class T>
void Graph<T>::setSource(Node<T>** &s){
	 for(int i = 0; i < 15; i++){
                if(connections[i] == NULL){
                        s[i] == NULL;
                }
                else{
                        Node<T>* current = connections[i];
                        //cout << connections[i]->shortest_path << " and " << connections[i]->parent << endl;
                        s[i] = new Node<T>(connections[i]->shortest_path, connections[i]->parent);
                        s[i]->degree = connections[i]->degree;
			//cout << cutTemp[i]->shortest_path << " and " << cutTemp[i]->parent << endl;
                        Node<T>* head = cutTemp[i];
                        current = current->next;
                        while(current != NULL){
                        s[i]->next = new Node<T>(current->shortest_path, current->parent);
                        s[i] = s[i]->next;
                        current = current->next;
                        }
                s[i] = head;
                }
        }

}

template <class T>
void Graph<T>::cutLink(int a, int b, int c){
	//copying collisions into new array
	setSource(cutTemp);
	cut(a, b, cutTemp);
	cut(b, a, cutTemp);
	doDjks(c, cutTemp);
	doPrim(c, cutTemp);

	//for debugging, print
	/*for(int i = 0; i < 15; i++){
                if(cutTemp[i] == NULL){
                        cout << "NULL" << endl;
                }
                else{
                        Node<T>* current = cutTemp[i];
                        while(current != NULL){
                        cout << current->parent << " " << current->shortest_path << ", " ;
                        current = current->next;
			}
			cout << "degree is " << cutTemp[i]->degree;
                        cout << endl;
                }
	}*/		
}

template <class T>
void Graph<T>::cut(int a, int b, Node<T>** &t){
 	Node<T>* prev = t[a];
        Node<T>* next = t[a]->next;
        while(next != NULL){
                if(prev->parent == b){
                t[a] = next;
                t[a]->degree = prev->degree - 1;
                delete prev;
                break;
                }
                else if(next->parent == b){
                prev->next = next->next;
                prev->degree -=1;
                delete next;
                break;
                }
                else{
                next = next->next;
                prev = prev->next;
                }
        }
}

template <class T>
void Graph<T>::doPrim(int a, Node<T>** &s){
	bool *B = new bool[15];
	initializeSource(primList, B);
	int nextParent = 0;
	int currentParent = a;
	int *parents = new int[s[a]->degree];
	

	cout << "Minimum spanning tree is " << endl;;
	while(falseLeft(B) == true){
		//cout << currentParent << " to " << endl;;
		getParents(currentParent, parents, s);
		nextParent = nextInPrim(currentParent, parents, B, s);
		B[currentParent] = true;	
		
		relaxPrim(primList, currentParent, parents, s);
		
		cout << currentParent << " to " << primList[currentParent]->parent;
		cout << ", weight is " << primList[currentParent]->shortest_path << endl;
		currentParent = nextParent;
	}
	
}

template <class T>
void Graph<T>::relaxPrim(Node<T>** &pL, int currentP, int* &Par, Node<T>** &s){
	int i = 0;
	Node<T>* current = s[currentP];
	while(current != NULL){
		if(pL[Par[i]]->shortest_path >= current->shortest_path){
		pL[Par[i]]->shortest_path = current->shortest_path;
		pL[Par[i]]->parent = currentP;
		}
		//cout << "parent " << Par[i] << " to " << pL[Par[i]]->parent << endl;
		/*if(pL[currentP]->shortest_path > current->shortest_path){
		pL[currentP]->shortest_path = current->shortest_path;
		}*/
	i++;
	current = current->next;
	}
}

template <class T>
int Graph<T>::nextInPrim(int currentP, int* &Par, bool* &cloud, Node<T>**&s){
	int i = 0;
        Node<T>* current = s[currentP]; //currentP starts at 1 from main
        int* paths = new int[current->degree];
        int sPath = 10000;
	while(current != NULL){
                paths[i] = current->shortest_path;
		//cout << "Paths from " << currentP << " are " << paths[i] << " to " << current->parent << endl;
		i++;
		current = current->next;
        }
	
        int shortestPath = 1000000;
        int next;
	int count = 0;
        for(int j = 0; j < s[currentP]->degree; j++){
		//cout << "in the cloud, " << Par[j] << " is "<< cloud[Par[j]] << endl;
                //cout << "shortest path is " << shortestPath << " >= " << paths[j] << endl;
		if(shortestPath >= paths[j] && cloud[Par[j]] == 0)
                {
                next = Par[j];
		shortestPath = paths[j];
                }
		if(cloud[Par[j]] == 1){
		count++;
		} 
	}
	
	//cout << "count is " << count << endl;
	if(count == s[currentP]->degree){
		for(int i = 0; i < 15; i++){
			//cout << "cloud for " << i << " is " << cloud[i] << endl;
			if(cloud[i] == 0){
			return next = i;	
			}
		}
	}
	 
	return next;
}

template <class T>
void Graph<T>::doDjks(int a, Node<T>**&s){
        //initiallizing set, assuming start is 1 from the lesson
	bool *C = new bool[15];
	initializeSource(list, C);	
	int nextParent = 0;
	int currentParent = a;
	
	//start of shortest path
	int *parents = new int[s[a]->degree];
	while(falseLeft(C) == true){
		//get parents, next parent	
		getParents(currentParent, parents, s);
		nextParent = getNext(currentParent, parents, C, s);
                //cout << "Next Parent is " << nextParent << " Current is " << currentParent << endl;
                C[currentParent] = true;
                
		relax(list, currentParent, parents, s);
		//this reads the function with stepping
		/*for(int i = 0; i < 15; i++){
			cout << "For node " << i << ": ";
			if(list[i] == NULL){
			cout << "NULL" << endl;
			}
			else{
			cout << list[i]->shortest_path << " and " << list[i]->parent << ", ";
			//cout << "In the cloud " << C[i];
			cout << endl;
			}
		}*/
		currentParent = nextParent;
		
	}		
		cout << "Shortest paths to all nodes: " << endl;
		for(int i = 0; i < 15; i++){
 		       cout << "For node " << i << ": ";
                        if(list[i] == NULL){
                        cout << "NULL" << endl;
                        }
                        else{
                        cout << list[i]->shortest_path << " and " << list[i]->parent << ", ";
                        //cout << "In the cloud " << C[i];
                        cout << endl;
                        }
       		}
}

template <class T>
int Graph<T>::getNext(int currentP, int* &Par, bool* &cloud, Node<T>**&s){
	int i = 0;
        Node<T>* current = s[currentP];
	int* paths = new int[current->degree];
	while(current != NULL){
                paths[i] = current->shortest_path;	
                current = current->next;
		i++;
        }
	int shortestPath = 1000000;
	int next; 
	int counter = 0;
	for(int j = 0; j < s[currentP]->degree; j++){
		if(shortestPath >= paths[j] && cloud[Par[j]] == 0)
		{
		next = Par[j];
		shortestPath = paths[j];
		}
		if(cloud[Par[j]] == 1){
		counter++;
		}
	}
	if(counter == s[currentP]->degree){
		for(int i = 0; i < 15; i++){
			if(cloud[i] == 0){
			return next = i; 
			}	
		}
	}
	return next;
}

template <class T>
void Graph<T>::getParents(int currentP, int* &Par, Node<T>**&s){
	int i = 0;
	Node<T>* current = s[currentP];
	while(current != NULL){
	Par[i] = current->parent;
	i++;
	current = current->next;
	}

}

template <class T>
void Graph<T>::relax(Node<T>** &l, int currentP, int* &Par, Node<T>**&s){
	int i = 0;
	Node<T>* current = s[currentP]; //currentP = 1 for first loop
	//cout << "Being called " << endl;   //testing call
	while(current != NULL){
	//cout << "adding " << l[Par[i]]->shortest_path << " > " << l[currentP]->shortest_path;
	//cout << " and " << current->shortest_path << endl;                      //testing whats being added
		if(l[Par[i]]->shortest_path >= l[currentP]->shortest_path + current->shortest_path)
                {                                       //list starts from 0, so to match currentparent take - 1
			//cout << "test " << l[Par[i]]->parent << ", " << l[Par[i]]->shortest_path << endl;
			l[Par[i]]->shortest_path = current->shortest_path + l[currentP]->shortest_path;
                	l[Par[i]]->parent = currentP;
                }
                //cout << "Node " << Par[i] << " " << l[Par[i]]->parent << " " << l[Par[i]]->shortest_path << endl;
                if(l[currentP]->shortest_path > current->shortest_path + l[Par[i]]->shortest_path){
			l[currentP]->shortest_path = current->shortest_path + l[Par[i]]->shortest_path;
			l[currentP]->parent = Par[i];
		}
		//cout << "Node " << Par[i] << " " << l[Par[i]]->parent << " " << l[Par[i]]->shortest_path << endl;
		i++;
                current = current->next;
        }
}


template <class T>
bool Graph<T>::falseLeft(bool* &c){
	int counter = 0;
	for(int i = 0; i < 15; i++){
		if(c[i] == true){
		counter++;
		}
	}
	if(counter  == 15){
	return false;
	}
	else{
	return true;
	}
}

template <class T>
void Graph<T>::initializeSource(Node<T>** &l, bool* &b){
	l[1] = new Node<T>(0, -1);
        b[0] = true;
	b[1] = true;
        for(int i = 2; i < 15; i++){
                l[i] = new Node<T>(100000, -1);
                b[i] = false;
        }
}

template <class T>
void Graph<T>::read(string s){
	
	in.open(s);
	getline(in, hash);
	int h = 19;
	
	while(in >> input >> connectTo >> weight)
	{	
		int index = stoi(input);
		int p = stoi(connectTo);
		int w = stoi(weight);
		int store = index % h;

		if(connections[store] == NULL){
			connections[store] = new Node<T>(w, p);
			connections[store]->degree += 1;
		}
		else{
			Node<T>* temp = connections[store];
			connections[store] = new Node<T>(w, p);
			connections[store]->next = temp;
			connections[store]->degree = temp->degree + 1;
		}
		
		store = p % h;
		if(connections[store] == NULL){
		        connections[store] = new Node<T>(w, index);
			connections[store]->degree += 1;
        	}
        	else{
		        Node<T>* temp = connections[store];
		        connections[store] = new Node<T>(w, index);
		        connections[store]->next = temp;
			connections[store]->degree = temp->degree + 1;
        	}
		//displays the info from the file
		//cout << index << " " << p << " " << w << endl;

	};
	in.close();
	//This loop reads off the adjacency list
	/*for(int i = 0; i < 15; i++){
		if(connections[i] == NULL){
			cout << "NULL" << endl;
		}
		else{
			Node<T>* current = connections[i];
			while(current != NULL){
			cout << current->parent << " " << current->shortest_path << ", " ;
			current = current->next;
			}
			//cout << connections[i]->degree << ",";
			cout << endl;
			aveDegree += connections[i]->degree;
		}
		
	}*/
	//cout << "Average degree is " << aveDegree/14 << endl;
}
