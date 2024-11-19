#ifndef Graph_h
#define Graph_h

#include "Edge.h"
#include <queue>
#include <stack>
#include <climits>


template <class T>
class Graph {
private:
    vector< vector < Edge<T> > > adjList; 
    vector<T> vertices;
    void DFSr(int vertexIndex, vector<bool> &status);
    int minVertexIndex(vector<bool> status, vector<int> cost);
public:
    Graph();
    Graph(vector<T> vertices);
    void addEdge(Edge<T> edge);
    int findVertex(T vertex);
    void BFS(T vertex);
    void DFS(T vertex);
    void Dijkstra(T vertex);
    void print();
    void removeEdge(Edge<T> edge);
    void addVertex(T vertex);
    void removeVertex(T vertex);
    void printMatrix();
};

template <class T>
Graph<T>::Graph() {

}

template <class T>
Graph<T>::Graph(vector<T> vertices) {
    this->vertices = vertices;
    vector< Edge<T> > edges;
    adjList.resize(vertices.size(), edges);
    for (int i=0; i<vertices.size(); i++) {
        adjList[i] = edges;
    }
}

template <class T>
int Graph<T>::findVertex(T vertex) {
    auto it = find(vertices.begin(), vertices.end(), vertex);
    if (it != vertices.end()) {
        return distance(vertices.begin(), it);
    } else {
        return -1;
    }
}

template <class T>
void Graph<T>::addEdge(Edge<T> edge) {
    int sourceIndex = findVertex(edge.source);
    if (sourceIndex == -1) {
        throw invalid_argument("El vértice origen no existe");
    }
    int targetIndex = findVertex(edge.target);
    if (targetIndex == -1) {
        throw invalid_argument("El vértice destino no existe");
    }
    adjList[sourceIndex].push_back(edge);
}

template <class T>
void Graph<T>::BFS(T vertex) {
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        queue<int> bfsQueue;
        vector<bool> status(vertices.size(), false);
        bfsQueue.push(vertexIndex);
        status[vertexIndex] = true;
        while (!bfsQueue.empty()) {
            vertexIndex = bfsQueue.front();
            for (auto edge : adjList[vertexIndex]) {
                int adjIndex = findVertex(edge.target);
                if (!status[adjIndex]) {
                    bfsQueue.push(adjIndex);
                    status[adjIndex] = true;
                }
            }
            cout << vertices[vertexIndex] << " ";
            bfsQueue.pop();
        }
        cout << endl;
    } else { 
        throw invalid_argument("El vertice es inválido");
    }
}

template <class T>
void Graph<T>::DFSr(int vertexIndex, vector<bool> &status) {
    cout << vertices[vertexIndex] << " ";
    status[vertexIndex] = true;
    for (auto edge : adjList[vertexIndex]) {
        int adjIndex = findVertex(edge.target);
        if (!status[adjIndex]) {
            DFSr(adjIndex, status);
        }
    }

}

template <class T>
void Graph<T>::DFS(T vertex) {
    int vertexIndex = findVertex(vertex);
    if (vertexIndex != -1) {
        vector<bool> status(vertices.size(), false);
        DFSr(vertexIndex, status);
        cout << endl;
    } else { 
        throw invalid_argument("El vertice es inválido");
    }
}

template <class T>
int Graph<T>::minVertexIndex(vector<bool> status, vector<int> cost) {
    int minCost = INT_MAX;
    int minIndex = -1;
    for (int i=0; i<vertices.size(); i++) {
        if (!status[i] && cost[i] < minCost) {
            minCost = cost[i];
            minIndex = i;
        }
    }
    return minIndex;


}

template <class T>
void Graph<T>::Dijkstra(T vertex) {
    int vertexIndex = findVertex(vertex);
    if (vertexIndex == -1) {
        throw invalid_argument("El vértice de entrada no existe");
    }
    int size = vertices.size();
    vector<bool> status(size, false);
    vector<int> cost(size, INT_MAX);
    vector<int> path(size, -1);
    cost[vertexIndex] = 0;

    int minIndex = minVertexIndex(status, cost);
    while (minIndex != -1) {
        status[minIndex] = true;
        for (auto& edge : adjList[minIndex]) {
            int adjIndex = findVertex(edge.target);
            if (!status[adjIndex]) {
                if (cost[adjIndex] > cost[minIndex] + edge.weight) {
                    cost[adjIndex] = cost[minIndex] + edge.weight;
                    path[adjIndex] = minIndex;
                }
            }
        }
        minIndex = minVertexIndex(status, cost);
    }

    vector<stack<int>> stackList(size);
    for (int i = 0; i < size; ++i) {
        stackList[i].push(i);
        int auxPath = path[i];
        while (auxPath != -1) {
            stackList[i].push(auxPath);
            auxPath = path[auxPath];
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << "Camino al vértice " << vertices[i] << ": ";
        while (!stackList[i].empty()) {
            cout << vertices[stackList[i].top()] << " ";
            stackList[i].pop();
        }
        cout << "(Costo: " << (cost[i] == INT_MAX ? "INF" : to_string(cost[i])) << ")\n";
    }
}

template <class T>
void Graph<T>::print() {
    for(int i=0; i<adjList.size(); i++) {
        cout << vertices[i] << " -> ";
        for (auto edge : adjList[i]) {
            cout << edge.target << " " << edge.weight << " - ";
        }
        cout << endl;
    }
}

template <class T>
void Graph<T>::removeEdge(Edge<T> edge) {
    int sourceIndex = findVertex(edge.source);
    if (sourceIndex == -1) {
        throw invalid_argument("El vértice origen no existe");
    }
    int targetIndex = findVertex(edge.target);
    if (targetIndex == -1) {
        throw invalid_argument("El vértice destino no existe");
    }
    auto it = find(adjList[sourceIndex].begin(), adjList[sourceIndex].end(), edge);
    if (it != adjList[sourceIndex].end()) {
        adjList[sourceIndex].erase(it);
    } else {
        throw invalid_argument("La arista no existe");
    }
}

template <class T>
void Graph<T>::addVertex(T vertex) {
    if (findVertex(vertex) == -1) {
        vertices.push_back(vertex);
        vector< Edge<T> > edges;
        adjList.push_back(edges);
        for (int i=0; i<adjList.size(); i++) {
            adjList[i].push_back(Edge<T>(vertices[i], vertex, 0));
        }
    } else {
        throw invalid_argument("El vértice ya existe");
    }
}

template <class T>
void Graph<T>::removeVertex(T vertex) {
    int vertexIndex = findVertex(vertex);
    if (vertexIndex == -1) {
        throw invalid_argument("El vértice no existe");
    }
    vertices.erase(vertices.begin() + vertexIndex);
    adjList.erase(adjList.begin() + vertexIndex);
    for (int i=0; i<adjList.size(); i++) {
        auto it = find(adjList[i].begin(), adjList[i].end(), Edge<T>(vertices[i], vertex, 0));
        if (it != adjList[i].end()) {
            adjList[i].erase(it);
        } else {
            throw invalid_argument("La arista no existe");
        }
    }
}

template <class T>
void Graph<T>::printMatrix() {
    cout << "  ";
    for (auto vertex : vertices) {
        cout << vertex << " ";
    }
    cout << endl;
    for (int i=0; i<adjList.size(); i++) {
        cout << vertices[i] << " ";
        cout << "| ";
        for (int j=0; j<adjList.size(); j++) {
            auto it = find(adjList[i].begin(), adjList[i].end(), Edge<T>(vertices[i], vertices[j], 0));
            if (it != adjList[i].end()) {
                cout << it->weight << " ";
            } else {
                cout << "∅ ";
            }
        }
        cout << endl;
    }
}








#endif /* Graph_h */