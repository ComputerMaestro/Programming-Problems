import random

data = open("karger_input.txt").read()
graph = [list(map(int, edges.split())) for edges in data.split('\n')[:-1]]
#graph = [[2,3,4], [1,3,4], [1,2,4], [1,2,3]]
tot_vertices = 200
curr_edges = sum([len(edges) for edges in graph])

contract_check = [0]*tot_vertices

while tot_vertices > 2:
    print(tot_vertices, curr_edges)
    
    # selecting random edge
    selected_edge = random.randint(1,curr_edges)
    #print(selected_edge)

    #extract actual selected edge
    for (idx, edges) in enumerate(graph):
        if edges is not None:
            selected_edge -= len(edges)
        if selected_edge <= 0: break
    #print(idx, selected_edge)
    contracting_vertex_idx = graph[idx].pop(selected_edge - 1)-1

    # idx and contracting_vertex_idx represent indices of
    # vertices to be contracted
    if contract_check[contracting_vertex_idx]:
        temp = contract_check[contracting_vertex_idx]
        contract_check[contracting_vertex_idx] = idx
        contracting_vertex_idx = temp
    contract_check[contracting_vertex_idx] = idx
    print(idx, contracting_vertex_idx)
    # concat both the vertices, delete duplicate edges and
    # remove self-loops
    graph[idx] = graph[idx] + graph[contracting_vertex_idx]
    parallel_edges = len(graph[idx])
    graph[idx] = list(set(graph[idx]))
    parallel_edges -= len(graph[idx])
    curr_edges -=(parallel_edges+2)

    graph[idx].remove(idx+1)
    
    graph[contracting_vertex_idx] = None

    tot_vertices -= 1
#print(graph, curr_edges)
crossing_edges = len(graph[contract_check[0]])

