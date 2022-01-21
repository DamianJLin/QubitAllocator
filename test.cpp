#define BOOST_TEST_MODULE sub_graph_iso_test

#include <boost/test/included/unit_test.hpp>

#include <boost/graph/adjacency_list.hpp>
#include "sub_graph_iso/sub_graph_iso.hpp"

using namespace boost;

BOOST_AUTO_TEST_SUITE( test_sub_graph_induced )

BOOST_AUTO_TEST_CASE( small_graph_1 )
{

	typedef adjacency_list< setS, vecS, bidirectionalS > graph_type;

	// Build graph
	int num_vertices1 = 8;
	graph_type graph(num_vertices1);
	add_edge(0, 6, graph);
	add_edge(0, 7, graph);
	add_edge(1, 5, graph);
	add_edge(1, 7, graph);
	add_edge(2, 4, graph);
	add_edge(2, 5, graph);
	add_edge(2, 6, graph);
	add_edge(3, 4, graph);

	// Build sub
	int num_vertices2 = 9;
	graph_type sub(num_vertices2);
	add_edge(0, 6, sub);
	add_edge(0, 8, sub);
	add_edge(1, 5, sub);
	add_edge(1, 7, sub);
	add_edge(2, 4, sub);
	add_edge(2, 7, sub);
	add_edge(2, 8, sub);
	add_edge(3, 4, sub);
	add_edge(3, 5, sub);
	add_edge(3, 6, sub);

	// Create callback to print mappings
	vf2_empty_callback< graph_type, graph_type > callback(graph, sub);

	// Print out all subgraph isomorphism mappings between graph and sub.
	// Vertices and edges are assumed to be always equivalent.
	const bool result = vf2_subgraph_iso(graph, sub, callback);

	BOOST_TEST(result);

}

// Test complete graph K4 embedding in K7. Test currently not working (TODO).
BOOST_AUTO_TEST_CASE( K4_in_K7 )
{

	typedef adjacency_list< setS, vecS, bidirectionalS > graph_type;

	// Build K7
	graph_type graph_K7(7);
	for (int i = 0; i <= 6; i++) {
		for (int j = i; j <= 6; j++) {
			add_edge(i, j, graph_K7);
		}
	}
	
	// Build K4
	graph_type graph_K4(2);
	for (int i = 0; i <= 3; i++) {
		for (int j = i; j <= 4; j++) {
			add_edge(i, j, graph_K4);
		}
	}
	
	// Create callback to print mappings
	vf2_empty_callback< graph_type, graph_type > callback(graph_K7, graph_K4);

	// Print out all subgraph isomorphism mappings between K7 and K4.
	// Vertices and edges are assumed to be always equivalent.
	const bool result = vf2_subgraph_iso(graph_K7, graph_K4, callback);

	BOOST_TEST(result);

}

BOOST_AUTO_TEST_SUITE_END()
