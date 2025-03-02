# Breadth First conserned by
# 1- visit all the neighbors of a node before visiting the neighbors of its neighbors
# 2- Explore the neighbor nodes before moving to the next level of neighbors

# The order is not important of the neighbors 


def Traverse_Graph_Breadth_First(graph, start):

    visited = []
    queue = [start]  

    while queue:
        new_queue = []  

        for node in queue:

            if node not in visited:
                visited.append(node)
                print(node)  
                
                for neighbor in graph[node]:
                    new_queue.append(neighbor)  # Add to the new queue

        queue = new_queue  # Move to the next level

    return visited



# graph = 
# {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F', 'G'],
#     'D': [],
#     'E': ['H', 'I'],
#     'F': [],
#     'G': [],
#     'H': [],
#     'I': []
# }

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}


print(Traverse_Graph_Breadth_First(graph, 'A'))
