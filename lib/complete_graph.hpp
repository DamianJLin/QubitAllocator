#include <boost/graph/adjacency_list.hpp>

using namespace boost;

typedef adjacency_list< setS, vecS, undirectedS > graph_type;

inline graph_type complete_undirected(int n) {

	graph_type graph_Kn(n);
	
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= 3; j++) {
			add_edge(i, j, graph_Kn);
		}
	}

	return graph_Kn;
}
