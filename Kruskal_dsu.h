struct Edge {
  int u, v, w;
  Edge (vector<int> edge) : u(edge[0]), v(edge[1]), w(edge[2]) {};
  bool operator < (Edge const &other) {
    return w < other.w; 
  }
};

class Dsu {
public:
  vector<int> parent, rank;
  int n;
  
  Dsu(int n1) {
    n = n1;
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  };

  int find(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find(parent[v]);
  }

  void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (rank[a] < rank[b]) 
        swap(a, b);
      parent[b] = a;
      if (rank[b] == rank[a]) rank[a]++;
    }
  }
};

class Kruskal {
public:
  vector<Edge> edges, result;
  int cost = 0;
  Dsu *dis;

  Kruskal(int n1, vector<vector<int>> edges1) {
    dis = new Dsu(n1);
    for (auto edge : edges1) edges.emplace_back(edge);
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
      if (dis->find(e.u) != dis->find(e.v)) {
        cost += e.w;
        result.push_back(e);
        dis->join(e.u, e.v);
      }
    }
  }

};
