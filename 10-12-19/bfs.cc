// Breath First Search
// Graph traversals
// Graph traversal means visiting every vertex and edge exactly once in a well-defined order. 
// While using certain graph algorithms, you must ensure that each vertex of the graph is visited exactly once. 
// The order in which the vertices are visited are important and may depend upon the algorithm or question that you are solving.
// During a traversal, it is important that you track which vertices have been visited. The most common way of tracking vertices is 
// to mark them.
// https://www.redblobgames.com/pathfinding/a-star/implementation.html
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/


using namespace std;

class SimpleGraph {
  map<char, vector<char>> edges;

public:
  SimpleGraph(map<char, vector<char>> &&m) { edges = m; };
  vector<char> neighbors(char id) { return edges[id]; };
};

// SimpleGraph g{{{'a', {'b'}},
//                {'b', {'a', 'c', 'd'}},
//                {'c', {'a'}},
//                {'d', {'a', 'e'}},
//                {'e', {'b'}}}};

void bfs(SimpleGraph &my_graph, char start) {

  
}
int main() {

  map<char, vector<char>> m;
  vector<char> t{'b'};
  m.insert(pair<char, vector<char>>('a', t));
  // g['a'] = t;
  t = {'a', 'c', 'd'};
  m.insert(pair<char, vector<char>>('b', t));
  // g['b'] = t;
  t = {'a'};
  // g['c'] = t;
  m.insert(pair<char, vector<char>>('c', t));
  t = {'a', 'e'};
  // g['d'] = t;
  m.insert(pair<char, vector<char>>('d', t));
  t = {'b'};
  // g['e'] = t;
  m.insert(pair<char, vector<char>>('e', t));

  bfs(g, 'a');

  bfs(g, 'c');
  return 0;
}






