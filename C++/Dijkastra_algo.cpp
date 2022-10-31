/*

Computing SSSP using the Dijkstra's algorithm in a weighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<list>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<climits>

using namespace std;

template <typename T>
class Graph {
	unordered_map<T, list<pair<T, int>>> neighbourMap; 
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

	void dijkstra(T s, T d) {
		map<T, int> distanceMap;
		for(pair<T, list<pair<T, int>>>vertex : neighbourMap) {
			T vertexName = vertex.first;
			distanceMap[vertexName] = INT_MAX;
		}

		// the length of the shortest path from s to s is zero
		distanceMap[s] = 0;

		// to keep track explored vertices
		unordered_set<T> explored; 

		// to keep track of unexplored vertices
		set<pair<int, T>> minHeap;

		for(pair<T, int> vertex : distanceMap) {
			T vertexName = vertex.first;
			int vertexDist = vertex.second;
			minHeap.insert({vertexDist, vertexName});
		}

		unordered_map<T, T> parentMap;
		parentMap[s] = s;

		while(!minHeap.empty()) {
			pair<int, T> minVertex = *(minHeap.begin()); 
			minHeap.erase(minHeap.begin());

			int minVertexDist = minVertex.first;
			T minVertexName = minVertex.second;

			for(pair<T, int> neighbour : neighbourMap[minVertexName]) {
				T neighbourName = neighbour.first;
				int edgeWgt = neighbour.second;
				if(explored.find(neighbourName) == explored.end() &&
				   distanceMap[neighbourName] > minVertexDist + edgeWgt) {
				   	// neighbour is unexplored i.e. present inside the minHeap
					// and the edge between minVertex & neighbour is tensed so relax
					
					// relaxation

					// update the distance of the neighbour inside the minHeap
					auto it = minHeap.find({distanceMap[neighbourName], neighbourName});
					if(it != minHeap.end()) minHeap.erase(it);
					minHeap.insert({minVertexDist + edgeWgt, neighbourName});

					// update the distance of the neighbour inside the distanceMap
					distanceMap[neighbourName] = minVertexDist + edgeWgt;

					// update the parent
					parentMap[neighbourName] = minVertexName;
				}
			}

			explored.insert(minVertexName);
		}

		cout << endl;

		for(pair<T, int> vertex : distanceMap) {
			T vertexName = vertex.first;
			int vertexDist = vertex.second;
			cout << "(" << vertexName << ", " << vertexDist << ")" << endl;
		}

		cout << endl;

		cout << "The length of the shortest path between " << s << " & " << d << " = " << distanceMap[d] << endl;
		cout << "The shortest path between " << s << " & " << d << " is ";

		T temp = d;
		while(parentMap[temp] != temp) {
			cout << temp << "<-";
			temp = parentMap[temp];
		}
		cout << temp << endl << endl;
	} 
};


int main() {

	Graph<char> g;

	g.addEdge('A', 'B', 10);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'C', 3);
	g.addEdge('B', 'D', 1);
	g.addEdge('C', 'D', 9);
	g.addEdge('C', 'E', 2);
	g.addEdge('D', 'E', 8);

	g.print();

	g.dijkstra('A', 'D');

	return 0;
}
