#include <climits>
#include <cstdlib>
#include <sys/stat.h>
#include "queue.h"
#ifndef MYGRAPHTYPE
#define MYGRAPHTYPE

using namespace std;

static const int MAX_VERTICES = 50;
#define infinity 10000;

// Exception class used by GetVertexIndex and DeleteVertex when vertex is not found
class NotFound{
};

// Exception class used by ShortestPath when path is not found
class PathNotFound{
};

// EdgeValueType must be a numeric type
template <class VertexType, class EdgeValueType>
struct EdgeType {
	VertexType fromVertex;
	VertexType toVertex;
	EdgeValueType weight;
};

template <class VertexType, class EdgeValueType>
class GraphType {
public:
	GraphType();
	// Constructor
	// Pre:	 None
	// Post: GraphType is intialized

	~GraphType();
	// Deconstructor
	// Pre:	 GraphType is initialized
	// Post: deletes vertices, edges

	GraphType(const GraphType<VertexType, EdgeValueType>& acopy);
	// Copy constructor
	// Pre:	 GraphType is initialized
	// Post: Graph is initialized with values from acopy

	void MakeEmpty();
	// Function: Initializes the graph to an empty state
	// Pre:		 GraphType is initialized
	// Post:	 marks, vertices, edges are empty, numVertices is zero

	bool IsEmpty();
	// Function: Tests whether the graph is empty
	// Pre:		 GraphType is initialized
	// Post:	 Function value = (graph is empty)

	bool IsFull();
	// Function: Tests whether the graph is full
	// Pre:		 GraphType is initialized
	// Post:	 Function value = (graph is full)

	void AddVertex(VertexType vertex);
	// Function: Adds vertex to the graph
	// Pre:		 GraphType is initialized, Graph is not full
	// Post:	 vertex is in vertices, numVertices is incremented

	void AddEdge(VertexType fromVertex, VertexType toVertex, EdgeValueType weight);
	// Function: Adds an edge with the specified weight from fromVertex to toVertex
	// Pre:		 GraphType is initialized, fromVertex and toVertex are in vertices
	// Post:	 (fromVertex, toVertex) is in edges with the specified weight, throws NotFound exception when fromVertex or toVertex not in vertices

	void UpdateVertex(VertexType vertex);
	// Function: Updates vertex in the graph
	// Pre:      GraphType is initialized
	// Post:     vertex in vertices is replaced with vertex

	EdgeValueType GetWeight(VertexType fromVertex, VertexType toVertex);
	// Function: Returns the weight of the edge from fromVertex to toVertex
	// Pre:		 GraphType is initialized, fromVertex and toVertex are vertices
	// Post:	 Function value = weight of edge from fromVertex to toVertex if edge exists, if edge does not exist function value = special "null-edge" value

	void GetToVertices(VertexType fromVertex, QueueType<VertexType>& vertexQ);
	// Function: Returns a queue of the vertices that are adjacent from fromVertex
	// Pre:		 GraphType is initialized, fromVertex is in vertices
	// Post:	 vertexQ contains the names of all vertices that are adjacent from fromVertex

	bool Search(VertexType& vertex);
	// Function: Searches for a vertex in the graph
	// Pre:		 GraphType is initialized
	// Post:	 Function value = (vertex in vertices), vertex is set to vertex in vertices

	void DeleteVertex(VertexType vertex);
	// Function: Deletes vertex from graph and associated edges
	// Pre:		 GraphType is initialized
	// Post:	 vertices does not contain vertex and numVertices is decremented, NotFound exception thrown if vertex is not in vertices before function call

	void DeleteEdge(VertexType fromVertex, VertexType toVertex);
	// Function: Deletes edge between fromVertex and toVertex
	// Pre:		 GraphType is initialized
	// Post:	 edges does not contain edge, NotFound exception thrown if fromVertex or toVertex is not in vertices

	int GetVerticesCount();
	// Function: Gets the number of vertices in the graph
	// Pre:		 GraphType is initialized
	// Post:	 Function return = (numVertices)

	bool IsConnected();
	// Function: Determines if the graph is connected
	// Pre:		 GraphType is initialized
	// Post:	 Function value = (is graph connected)

	void ShortestPath(VertexType fromVertex, VertexType toVertex, QueueType<VertexType> &pathQ);
	// Function: Finds the shortest path between two vertices
	// Pre:		 GraphType is intialized
	// Post:	 pathQ contains vertices describing the shortest path between fromVertex and toVertex, if no path exists throws PathNotFound exception

	void FindMinimalSpanningTree(VertexType vertex, GraphType<VertexType, EdgeValueType>& subgraph);
	// Function: Finds the subgraph of the graph containing the shortest paths between the vertices starting at vertex
	// Pre:		 GraphType is intialized
	// Post:	 Function value = (graph describing minimal spanning tree)

	void GetAllVertices(QueueType<VertexType>& vertexQ);
	// Function: Returns a queue of all the vertices
	// Pre:		 GraphType is initialized
	// Post:	 vertexQ contains all vertices in graph

	//void GetAllEdges(QueueType<EdgeType>& edgeQ);
	// Function: Returns a queue of all the edges
	// Pre: 	 GraphType is initialized
	// Post:	 edgeQ contains all edges in graph

private:
	int numVertices;
	int numEdges;
	VertexType vertices[MAX_VERTICES];
	EdgeValueType edges[MAX_VERTICES][MAX_VERTICES];
	bool marks[MAX_VERTICES];

	int GetVertexIndex(VertexType vertex);
	// Function: Returns the index for a vertex in the graph
	// Pre:		 GraphType is initialized
	// Post:	 if found Function value = (index of vertex), otherwise throw NotFound exception

	void ReplaceVertex(int fromVertexIndex, int toVertexIndex);
	// Function: Replaces vertex and edges located at toVertexIndex with vertex and edges located at fromVertexIndex
	// Pre:		 GraphType is initialized, fromVertexIndex and toVertexIndex are less than numVertices
	// Post:	 Vertex and edges at toVertexIndex is replaced with values from fromVertexIndex

	void DepthFirstSearch(GraphType<VertexType, EdgeValueType> graph, VertexType fromVertex, VertexType toVertex, QueueType<VertexType> &pathQ);
	// Function: Finds a path by traversing the graph using a LIFO stack to keep track of vertices to explore while marking vertices already visited
	// Pre:		 GraphType is initialized
	// Post:	 pathQ contains vertices describing a path between fromVertex and toVertex, if no path exists throws PathNotFound exception

	void ClearMarks();
	// Function: Sets marks for all vertices to false
	// Pre:		 GraphType is initialized
	// Post:	 All marks have been set to false

	void MarkVertex(VertexType vertex);
	// Function: Sets mark for vertex to true
	// Pre:		 vertex is in vertices
	// Post:	 IsMarked(vertex) is true

	bool IsMarked(VertexType vertex);
	// Function: Determines if vertex has been marked
	// Pre:		 vertex is in vertices
	// Post:	 Function value = (vertex is marked true)
};

#include "graphType.template"
#endif