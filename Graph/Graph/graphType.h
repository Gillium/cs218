template <class ItemType>
class GraphType
{
public:
	GraphType();
	// Constructor
	// Pre:	 None
	// Post: GraphType is intialized

	~GraphType();
	// Deconstructor
	// Pre:	 GraphType is initialized
	// Post: 

	GraphType();
	// Copy constructor
	// Pre:	 GraphType is initialized
	// Post:

	void MakeEmpty();
	// Function: Initializes the graph to an empty state
	// Pre:		 GraphType is initialized
	// Post:	 Graph is empty

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
	// Pre:		 Graph is not full
	// Post:	 vertex is in V(graph)

	void AddEdge(VertexType fromVertex, VertexType toVertex);
	// Function: Adds an edge with the specified weight from fromVertex to toVertex
	// Pre:		 fromVertex and toVertex are in V(graph)
	// Post:	 (fromVertex, toVertex) is in E(graph) with the specified weight

	EdgeValueType GetWeight(VertexType fromVertex, VertexType toVertex);
	// Function: Determines the weight of the edge from fromVertex to toVertex
	// Pre:		 fromVertex to toVertex
	// Post:	 Function value = weight of edge from fromVertex to toVertex if edge exists, if edge does not exist function value = special "null-edge" value

	void GetToVertices(VertexType vertex, QueType& vertexQ);
	// Function: Returns a queue of the vertices that are adjacent from vertex
	// Pre:		 vertex is in V(graph)
	// Post:	 vertexQ contains the names of all vertices that are adjacent from vertex

	int Search(VertexType vertex);
	// Function: Returns the index for a vertex in the graph
	// Pre:		 GraphType is initialized
	// Post:	 

	DeleteVertex();
	// Function:
	// Pre:
	// Post:

	DeleteEdge();
	// Function:
	// Pre:
	// Post:

	GetVerticesCount();
	// Function:
	// Pre:
	// Post:

	Display();
	// Function:
	// Pre:
	// Post:

	IsConnected();
	// Function:
	// Pre:
	// Post:

	FindShortestPath();
	// Function:
	// Pre:
	// Post:

	FindMinimalSpanningTree();
	// Function:
	// Pre:
	// Post:

	void ClearMarks();
	// Function: Sets marks for all vertices to false
	// Pre:
	// Post:	 All marks have been set to false

	void MarkVertex(VertexType vertex);
	// Function: Sets mark for vertex to true
	// Pre:		 vertex is in V(graph)
	// Post:	 IsMarked(vertex) is true

	bool IsMarked(VertexType vertex);
	// Function: Determines if vertex has been marked
	// Pre:		 vertex is in V(graph)
	// Post:	 Function value = (vertex is marked true)

private:
};