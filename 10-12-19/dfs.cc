// Depth First Search
// Steve: SimpleGraph is cool.

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class SimpleGraph {
  map<char, vector<char>> edges;

public:
  SimpleGraph(map<char, vector<char>> &&m) { edges = m; };
  vector<char> neighbors(char id) { return edges[id]; };
};

void dfs(const SimpleGraph &g, const char start) {

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

  SimpleGraph g(move(m));
  dfs(g, 'a');

  dfs(g, 'c');
  return 0;
}
