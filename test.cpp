#define BOOST_TEST_MODULE sub_graph_iso_test

#include <boost/test/included/unit_test.hpp> // Testing

#include <boost/graph/adjacency_list.hpp> // Boost Graph
#include <boost/graph/graphviz.hpp>

#include "sub_graph_iso/sub_graph_iso.hpp" // Modified Boost sub_graph_iso file

#include "lib/complete_graph.hpp" // Helper to create complete graphs.

using namespace boost;

BOOST_AUTO_TEST_SUITE( test_sub_graph_induced )

BOOST_AUTO_TEST_CASE( small_sub_graph_finds_iso )
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
BOOST_AUTO_TEST_CASE( K4_K7_finds_iso )
{

	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	graph_type graph_K7 = complete_undirected(7);
	
	graph_type graph_K4 = complete_undirected(4);

	// Create callback to print mappings
	vf2_empty_callback < graph_type, graph_type > callback(graph_K4, graph_K7);

	// Find subgraph isomorphism mappings between K7 and K4.
	// Vertices and edges are assumed to be always equivalent.
	const bool result = vf2_subgraph_mono(graph_K4, graph_K7, callback);

	BOOST_TEST(result);

}

// Test medium-sized embedding of K6 into K9.
BOOST_AUTO_TEST_CASE ( K6_K9_finds_iso ) 
{

	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	graph_type graph_K9 = complete_undirected(9);
	graph_type graph_K6 = complete_undirected(6);

	vf2_empty_callback < graph_type, graph_type > callback(graph_K6, graph_K9);

	const bool result = vf2_subgraph_mono(graph_K6, graph_K9, callback);

	BOOST_TEST(result);
}

// Test no embedding of K4 into complete bipartite graph KB3,4.
BOOST_AUTO_TEST_CASE ( K4_bipartite_no_iso )
{

	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	graph_type graph_KB3c4(7);
	for (int i = 0; i <= 3; i++) {
		for (int j = 4; j <= 7; j++) {
			add_edge(i, j, graph_KB3c4);
		}
	}
	
	graph_type graph_K4 = complete_undirected(4);

	vf2_empty_callback < graph_type, graph_type > callback(graph_K4, graph_KB3c4);

	const bool result = vf2_subgraph_mono(graph_K4, graph_KB3c4, callback);

	BOOST_TEST(result == false);

}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( test_sub_graph_non_induced )

// Test sqaure embeds in K4.
BOOST_AUTO_TEST_CASE( square_K4_finds_iso )
{
	
	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	graph_type graph_square(4);
	add_edge(0, 1, graph_square);
	add_edge(1, 2, graph_square);
	add_edge(2, 3, graph_square);
	add_edge(3, 0, graph_square);

	graph_type graph_K4 = complete_undirected(4);

	vf2_empty_callback < graph_type, graph_type > callback(graph_square, graph_K4);

	const bool result = vf2_subgraph_mono(graph_square, graph_K4, callback);

	BOOST_TEST(result);

}


// Test almost complete graph K4 embedding in K7.
BOOST_AUTO_TEST_CASE( almost_K4_K7_finds_iso )
{

	typedef adjacency_list< setS, vecS, undirectedS > graph_type;

	graph_type graph_K7 = complete_undirected(7);
	
	graph_type graph_almost_K4 = complete_undirected(4);
	remove_edge(0, 1, graph_almost_K4);

	// Create callback to print mappings
	vf2_empty_callback < graph_type, graph_type > callback(graph_almost_K4, graph_K7);

	// Find subgraph isomorphism mappings between K7 and K4.
	// Vertices and edges are assumed to be always equivalent.
	const bool result = vf2_subgraph_mono(graph_almost_K4, graph_K7, callback);

	BOOST_TEST(result);

}


BOOST_AUTO_TEST_SUITE_END()
