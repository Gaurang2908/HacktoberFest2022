/*

Implementation of a weighted graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<list>
#include<map>

using namespace std;

template <typename T>
class Graph {
	map<T, list<pair<T, int>>> neighbourMap; 
	bool directed;

public:
	Graph(bool directed=false) {
		this->directed = directed;
	}

	void addEdge(T u, T v, int w) {
		neighbourMap[u].push_back({v, w}); 
		if(!directed) neighbourMap[v].push_back({u, w});
	}

	void print() {
		for(pair<T, list<pair<T, int>>> p : neighbourMap) {
			cout << p.first << " : ";
			for(pair<T, int> neighbour : p.second) {
				cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
			}
			cout << endl;
		}
	}
};


int main() {

	Graph<char> g(true);

	g.addEdge('A', 'B', 2);
	g.addEdge('A', 'C', 1);
	g.addEdge('B', 'C', 4);
	g.addEdge('B', 'D', 5);
	g.addEdge('C', 'D', 3);
	g.addEdge('C', 'E', 0);
	g.addEdge('D', 'E', 2);

	g.print();

	return 0;
}
