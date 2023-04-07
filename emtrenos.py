#exercicio Em Trenos
#Cristian Cesar Martins 799714
#Vitor Gabriel Orsin 801575
#-------------------------------------------------------------------------------------#
#libs
from heapq import heappop, heappush #usando heap para otimizar o djikstra
import igraph as ig
#input
# m = num salas
# e = ligacoes entre salas
# n = ligacoes por tubo
# c = consultas
m, e, n, c = map(int,input().split())
#lendo caminhos 
#u = sala inicial
#v = sala final
#d = peso da arest
#-------------------------------------------------------------------------------------#
#grafo
G = ig.Graph(directed=False)
Gimpostor = ig.Graph(directed=False)

#caminhos
ipt = list(map(float,input().split()))
#print(ipt)
for i in range(0,(len(ipt)),3):
        u = ipt[i]
        v = ipt[i+1]
        d = ipt[i+2]
        if u not in G.vs:
            G.add_vertex(u)
        if v not in G.vs:
            G.add_vertex(v)
        if u not in Gimpostor.vs:
            Gimpostor.add_vertex(u)
        if v not in Gimpostor.vs:
            Gimpostor.add_vertex(v)
        
        G.add_edge(int(u),int(v),weight=d)
        Gimpostor.add_edge(int(u),int(v),weight=d)

#le as vent
ipt = list(map(float,input().split()))
for i in range(0,len(ipt),2):
    u = ipt[i]
    v = ipt[i+1]
    if u not in Gimpostor.vs:
        Gimpostor.add_vertex(u)
    if v not in Gimpostor.vs:
        Gimpostor.add_vertex(v)
    Gimpostor.add_edge(int(u),int(v),weight=1.0)

#le asconsultas
consultas = []
for i in range(c):
    sala = int(input())
    consultas.append(sala)
#-------------------------------------------------------------------------------------#
def dijkstra(graph, start, end):
    # inicializa as distâncias para todos os vértices como infinito
    distances = [float('inf')] * graph.vcount()
    # o vértice inicial tem distância 0
    distances[start] = 0
    
    # lista de vértices visitados
    visited = []
    # lista de vértices não visitados
    unvisited = list(range(graph.vcount()))
    
    while unvisited:
        # seleciona o vértice não visitado com menor distância atual
        current = min(unvisited, key=lambda v: distances[v])
        # remove o vértice da lista de não visitados e adiciona na lista de visitados
        unvisited.remove(current)
        visited.append(current)
        
        # para cada vizinho do vértice atual
        for neighbor in graph.neighbors(current):
            # calcula a nova distância a partir do vértice atual
            new_distance = distances[current] + graph.es[graph.get_eid(current, neighbor)]['weight']
            # se a nova distância for menor do que a distância atual do vizinho
            if new_distance < distances[neighbor]:
                # atualiza a distância do vizinho
                distances[neighbor] = new_distance
    
    # retorna a distância do vértice inicial ao vértice final
    return distances[end]
#-------------------------------------------------------------------------------------#
for sala in consultas:
    
    distancia_impostor = dijkstra(Gimpostor,sala,0)
    print(distancia_impostor)
    distancia_player = dijkstra(G,sala,0)
    print(distancia_player)

    if(distancia_player) == float('inf'):
        print('defeat')

    if distancia_impostor >= distancia_player:
        print('victory')
    else:
        print('defeat')

#0 1 1.3 0 5 1.5 0 4 3.2 1 2 0.7 1 3 0.3 2 3 2.3 4 9 0.2 5 6 1.7 5 7 3.0 6 7 0.9 6 8 2.1 7 8 1.1