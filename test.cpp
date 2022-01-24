#define BOOST_TEST_MODULE sub_graph_iso_test

#include <boost/test/included/unit_test.hpp> // Testing

#include <boost/graph/adjacency_list.hpp> // Boost Graph
#include <boost/graph/graphviz.hpp>

#include "sub_graph_iso/sub_graph_iso.hpp" // Modified Boost sub_graph_iso file

#include "lib/complete_graph.hpp" // Helper to create complete graphs.

using namespace boost;

BOOST_AUTO_TEST_SUITE( test_sub_graph_induced )

BOOST_AUTO_TEST_CASE( small_graph_1 )
{

	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	// Build graph
	int num_vertices1 = 8;
	graph_type sub(num_vertices1);
	add_edge(0, 6, sub);
	add_edge(0, 7, sub);
	add_edge(1, 5, sub);
	add_edge(1, 7, sub);
	add_edge(2, 4, sub);
	add_edge(2, 5, sub);
	add_edge(2, 6, sub);
	add_edge(3, 4, sub);

	// Build sub
	int num_vertices2 = 9;
	graph_type graph(num_vertices2);
	add_edge(0, 6, graph);
	add_edge(0, 8, graph);
	add_edge(1, 5, graph);
	add_edge(1, 7, graph);
	add_edge(2, 4, graph);
	add_edge(2, 7, graph);
	add_edge(2, 8, graph);
	add_edge(3, 4, graph);
	add_edge(3, 5, graph);
	add_edge(3, 6, graph);

	// Create callback to print mappings
	vf2_empty_callback < graph_type, graph_type > callback(sub, graph);

	// Print out all subgraph isomorphism mappings between graph and sub.
	// Vertices and edges are assumed to be always equivalent.
	const bool result = vf2_subgraph_mono(sub, graph, callback);

	BOOST_TEST(result);

}

// Test complete graph K4 embedding in K7.
BOOST_AUTO_TEST_CASE( K4_in_K7 )
{

	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	// Build K7
	//graph_type graph_K7(7);
	//for (int i = 0; i <= 6; i++) {
	//	for (int j = i + 1; j <= 6; j++) {
	//		add_edge(i, j, graph_K7);
	//	}
	//}
	graph_type graph_K7 = complete_undirected(7);
	
	// Build K4
	//graph_type graph_K4(4);
	//for (int i = 0; i <= 3; i++) {
	//	for (int j = i + 1; j <= 3; j++) {
	//		add_edge(i, j, graph_K4);
	//	}
	//}
	graph_type graph_K4 = complete_undirected(4);

	// Create callback to print mappings
	vf2_empty_callback < graph_type, graph_type > callback(graph_K4, graph_K7);

	// Print out all subgraph isomorphism mappings between K7 and K4.
	// Vertices and edges are assumed to be always equivalent.
	const bool result = vf2_subgraph_mono(graph_K4, graph_K7, callback);

	BOOST_TEST(result);

}

BOOST_AUTO_TEST_SUITE_END()
