#ifndef COMPLETE_GRAPH_H
#define COMPLETE_GRAPH_H

#include <lemon/list_graph.h>

namespace lib {

	inline lemon::ListGraph* complete_undirected(int n) {

		static lemon::ListGraph graph_Kn;

		// Add nodes.
		for (int i = 0; i <= n; i++) {
			graph_Kn.addNode();
		}
		
		// Add edges.
		for (int i = 0; i <= n; i++) {
			for (int j = i + 1; j <= 3; j++) {
				graph_Kn.addEdge(graph_Kn.nodeFromId(i), graph_Kn.nodeFromId(j));
			}
		}

		return &graph_Kn; // TODO: Figure out how to return or pass ref.
	}

}
#endif
