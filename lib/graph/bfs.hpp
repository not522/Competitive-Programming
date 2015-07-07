#pragma once
#include "graph/search.hpp"

namespace bfs {
  template<typename Edge> struct BFSState {
    int pos, prev;

    BFSState(int pos, int prev = -1) : pos(pos), prev(prev) {}
  
    BFSState next(const Edge& edge) const {
      return BFSState(edge.to, pos);
    }
  };
}

template<typename Graph> class BFS : public Search<Graph, bfs::BFSState<typename Graph::EdgeType>> {
protected:
  typedef typename Graph::EdgeType Edge;
  typedef bfs::BFSState<Edge> State;

private:
  queue<State> que;
  
  void push(const State& state) {
    que.push(state);
  }
  
  State next() {
    State now = que.front();
    que.pop();
    return now;
  }
  
  bool isRunning() {
    return !que.empty();
  }

public:
  BFS(const Graph& graph) : Search<Graph, State>(graph) {}
};

namespace bfs_distance {
  template<typename Graph> class BFSDistance : public BFS<Graph> {
  private:
    typedef typename BFS<Graph>::State State;
    void visit(const State& state) {
      if (state.prev != -1) dis[state.pos] = dis[state.prev] + 1;
    }
  public:
    BFSDistance(const Graph& graph) : BFS<Graph>(graph), dis(graph.size(), 0) {}
    vector<int> dis;
  };
}

template<typename Graph> inline bfs_distance::BFSDistance<Graph> bfsDistance(const Graph& graph, int from) {
  bfs_distance::BFSDistance<Graph> bfs(graph);
  bfs.solve(from);
  return bfs;
}
