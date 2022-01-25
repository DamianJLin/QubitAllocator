#ifndef VF2_HPP
#define VF2_HPP

#include <lemon/core.h>
#include <lemon/smart_graph.h>
#include <lemon/list_graph.h>

// Subgraph Isomorphism Search using VF2-based rules.
	
using namespace lemon;

// graph = *import graph from wherever. For now:
int subgraph_isom_finder() {

	// For now...
	ListGraph g; //    1           4
	g.addNode(); //   / \         /
	g.addNode(); //  /   \       /
	g.addNode(); // 0 --- 2 --- 3
	g.addNode(); // 
	g.addNode(); // 
	g.addEdge(g.nodeFromId(0), g.nodeFromId(1));
	g.addEdge(g.nodeFromId(1), g.nodeFromId(2));
	g.addEdge(g.nodeFromId(2), g.nodeFromId(0));
	g.addEdge(g.nodeFromId(2), g.nodeFromId(3));
	g.addEdge(g.nodeFromId(3), g.nodeFromId(4));

	ListGraph s; // 1' --- 2' --- 3' --- 4'
	s.addNode();
	s.addNode();
	s.addNode();
	s.addNode();
	s.addEdge(g.nodeFromId(0), g.nodeFromId(1));
	s.addEdge(g.nodeFromId(1), g.nodeFromId(2));
	s.addEdge(g.nodeFromId(2), g.nodeFromId(3));
	s.addEdge(g.nodeFromId(3), g.nodeFromId(0));

	ListGraph::NodeMap<int> map(s); // Map from s to (index of) g. Beware the asymmetry:
									// map[ . ]: {slet of Nodes} --> {set of ints}
	// Set map to -1 initially.
	for (ListGraph::NodeIt n(g); n != INVALID; ++n) { 
		map[n] = -1;
	}
	std::cout << map[g.nodeFromId(0)] << std::endl;



	return 0;
}

#endif
