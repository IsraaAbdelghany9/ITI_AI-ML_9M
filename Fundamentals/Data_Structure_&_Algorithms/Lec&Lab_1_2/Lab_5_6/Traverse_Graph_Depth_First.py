# Traverse_Graph_Depth_First

def Traverse_Graph_Depth_First(graph, start, visited=[]):
    
    if start not in graph:
        print(f"Error: {start} is not in the graph")
        return visited
    
    visited.append(start)

    print(start)

    for next in graph[start]:
        if next not in visited:
            Traverse_Graph_Depth_First(graph, next, visited)
            
    return visited


# Graph
graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

print(Traverse_Graph_Depth_First(graph, 'A'))