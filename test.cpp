#define BOOST_TEST_MODULE sub_graph_iso_test

#include <boost/test/included/unit_test.hpp> // Testing
#include <lemon/list_graph.h> // LEMON Graph

#include "lib/complete_graph.hpp" // Helper to create complete graphs.

using namespace lemon;

BOOST_AUTO_TEST_SUITE( test_sub_graph_induced )

BOOST_AUTO_TEST_CASE( small_sub_graph_finds_iso )
{

	// Build graph
	ListGraph g;
	for (int i = 0; i <= 4; i++) {
		g.addNode();
	}
	
	g.addEdge(g.nodeFromId(0), g.nodeFromId(1));
	g.addEdge(g.nodeFromId(1), g.nodeFromId(2));
	g.addEdge(g.nodeFromId(2), g.nodeFromId(0));
	g.addEdge(g.nodeFromId(2), g.nodeFromId(3));
	g.addEdge(g.nodeFromId(3), g.nodeFromId(4));
	
	ListGraph s;
	for (int i = 0; i<= 3; i++) {
		s.addNode();
	}
	
	s.addEdge(s.nodeFromId(0), s.nodeFromId(1));
	s.addEdge(s.nodeFromId(1), s.nodeFromId(2));
	s.addEdge(s.nodeFromId(2), s.nodeFromId(3));

	// TODO: Call algorithm
	BOOST_TEST(false);

}

// Test complete graph K4 embedding in K7.
BOOST_AUTO_TEST_CASE( K4_K7_finds_iso )
{

	ListGraph graph_K7 = *lib::complete_undirected(7);
	ListGraph graph_K4 = *lib::complete_undirected(4);

	// TODO: Call algorithm
	BOOST_TEST(false);
}

// Test medium-sized embedding of K6 into K9.
BOOST_AUTO_TEST_CASE ( K6_K9_finds_iso ) 
{

	ListGraph graph_K9 = *lib::complete_undirected(9);
	ListGraph graph_K6 = *lib::complete_undirected(6);

	// TODO: Call algorithm
	BOOST_TEST(false);
}

// Test no embedding of K4 into complete bipartite graph KB3,4.
BOOST_AUTO_TEST_CASE ( K4_bipartite_no_iso )
{

	ListGraph graph_KB3c4;
	
	for (int i = 0; i <= 6; i++) {
		graph_KB3c4.addNode();
	}

	for (int i = 0; i <= 3; i++) {
		for (int j = 4; j <= 7; j++) {
			graph_KB3c4.addEdge(graph_KB3c4.nodeFromId(i), graph_KB3c4.nodeFromId(j));
		}
	}
	
	ListGraph graph_K4 = *lib::complete_undirected(4);

	// TODO: Call algorithm
	BOOST_TEST(false); // Should not find embedding.

}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( test_sub_graph_non_induced )

// Test sqaure embeds in K4.
BOOST_AUTO_TEST_CASE( square_K4_finds_iso )
{
	
	ListGraph graph_square;
	graph_square.addEdge(graph_square.nodeFromId(0), graph_square.nodeFromId(1));
	graph_square.addEdge(graph_square.nodeFromId(1), graph_square.nodeFromId(2));
	graph_square.addEdge(graph_square.nodeFromId(2), graph_square.nodeFromId(3));
	graph_square.addEdge(graph_square.nodeFromId(3), graph_square.nodeFromId(0));

	ListGraph graph_K4 = *lib::complete_undirected(4);

	// TODO: Call algorithm
	BOOST_TEST(false);

}


// Test almost complete graph K4 embedding in K7.
BOOST_AUTO_TEST_CASE( almost_K4_K7_finds_iso )
{

	ListGraph graph_K7 = *lib::complete_undirected(7);
	
	ListGraph graph_almost_K4 = *lib::complete_undirected(4);
	graph_almost_K4.erase(graph_almost_K4.edgeFromId(0));

	// TODO: Call algorithm
	BOOST_TEST(false);

}


BOOST_AUTO_TEST_SUITE_END()
