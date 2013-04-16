#include <cstdlib>
#include <sys/stat.h>
#ifndef MYGRAPHTYPE
#define MYGRAPHTYPE

using namespace std;

static const MAX_VERTICES = 50;

// Exception class used by Search and DeleteVertex when vertex is not found
class NotFound{
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

	GraphType(const GraphType<VertexType>& acopy);
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
	// Post:	 (fromVertex, toVertex) is in edges with the specified weight

	EdgeValueType GetWeight(VertexType fromVertex, VertexType toVertex);
	// Function: Returns the weight of the edge from fromVertex to toVertex
	// Pre:		 GraphType is initialized, fromVertex and toVertex are vertices
	// Post:	 Function value = weight of edge from fromVertex to toVertex if edge exists, if edge does not exist function value = special "null-edge" value

	void GetToVertices(VertexType vertex, QueType& vertexQ);
	// Function: Returns a queue of the vertices that are adjacent from vertex
	// Pre:		 GraphType is initialized, vertex is in vertices
	// Post:	 vertexQ contains the names of all vertices that are adjacent from vertex

	int Search(VertexType vertex);
	// Function: Returns the index for a vertex in the graph
	// Pre:		 GraphType is initialized
	// Post:	 if found Function value = (index of vertex), otherwise throw NotFound exception

	void DeleteVertex(VertexType vertex);
	// Function: Deletes vertex from graph and associated edges
	// Pre:		 GraphType is initialized
	// Post:	 vertices does not contain vertex and numVertices is decremented, NotFound exception thrown if vertex is not in vertices before function call

	void DeleteEdge(VertexType fromVertex, VertexType toVertex);
	// Function: Deletes edge between fromVertex and toVertex
	// Pre:		 GraphType is initialized
	// Post:	 edges does not contain edge, NotFound exception thrown if edge is not in edges before function call

	int GetVerticesCount();
	// Function: Gets the number of vertices in the graph
	// Pre:		 GraphType is initialized
	// Post:	 Function return = (numVertices)

	bool IsConnected();
	// Function: Determines if the graph is connected
	// Pre:		 GraphType is initialized
	// Post:	 Function value = (is graph connected)

	QueueType<EdgeType> ShortestPath(VertexType fromVertex, VertexType toVertex);
	// Function: Finds the shortest path between two vertices
	// Pre:		 GraphType is intialized
	// Post:	 Function value = (queue containing edges of shortest path)

	GraphType<VertexType, EdgeValueType> FindMinimalSpanningTree();
	// Function: Finds the subgraph of the graph containing the shortest paths between the vertices
	// Pre:		 GraphType is intialized
	// Post:	 Function value = (graph describing minimal spanning tree)

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

private:
	int numVertices;
	VertexType vertices[MAX_VERTICES];
	EdgeValueType edges[MAX_VERTICES][MAX_VERTICES];
	bool* marks[MAX_VERTICES];
};

#include "graphType.template"
#endif