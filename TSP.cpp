/*-------------------------------------------------------------------------
FILE NAME:         TSP.cpp
DESCRIPTION:	   Traveling sales person w/ boost library
USAGE:
COMPILER: 	   GNU g++ on Linux
NOTES:		   final project for cs302 using slide from
		   Kostas Alexis Website to guide
MODIFICATION HISTORY:
Author               Date             Version
----------------     -------------    ------------------------
Annette McDonough    2020-04-30	      1.0 original version
Holden Bowman        2020-04-30
--------------------------------------------------------------------------*/
# include <iostream>
# include <utility>
# include <algorithm>
# include <boost/graph/graph_traits.hpp>
# include <boost/graph/adjacency_list.hpp>
# include <boost/graph/dijkstra_shortest_paths.hpp>

const char PROGRAMMER_NAME [] = "Holden Bowman and Annette McDonough";


using namespace std;
using namespace boost;

int main()
{
	// create a typedef for the graph type
	typedef adjacency_list<vecS, vecS, bidirectionalS> Graph;

	// Convienent vertice labels
	enum {Reno, SF ,SLC, Seattle, Vegas};
	const int num_vertices = 5;
	
	// writing out the edges in the graph
	typedef std::pair<int, int> Edge;
        Edge edge_array[] = {Edge(Reno, SF), Edge(Reno, Seattle),
                             Edge(SLC, Reno), Edge(Seattle,SLC),
                             Edge(SLC, Vegas), Edge(SF, Seattle),
                             Edge(Seattle, Vegas)};

	const int num_edges = sizeof(edge_array)/sizeof(edge_array[0]);

	// declare a graph object
        Graph g(num_vertices);

        // add the edges to the graph object
        for(int i = 0; i < num_edges; i++)
		add_edge(edge_array[i].first, edge_array[i].second, g);
		
	

	// get the property map for vertex indices
	typedef property_map<Graph, vertex_index_t>::type IndexMap;
	IndexMap index = get(vertex_index, g);
                    
	
	cout << "vertices(g) = ";
        typedef graph_traits<Graph>::vertex_iterator vertex_iter;
	pair<vertex_iter, vertex_iter> vp;
     
        for(vp = vertices(g); vp.first != vp.second; vp.first++)
		cout << index[*vp.first] << " \n";

	cout << "edges(g) = ";
        graph_traits<Graph>::edge_iterator ei, ei_end; 
   	for(tie(ei, ei_end) = edges(g); ei != ei_end; ei++)
	{		
		cout << "(" << index[source(*ei, g)]
		     << ", " << index[target(*ei, g)] << ")\n";
	}
	
	cout << endl << endl << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- "
	     << __DATE__ << " " <<__TIME__ << endl << endl;

	return 0;

}
