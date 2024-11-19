#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Graph.h"

int main() {

    vector<string> vertices = {"0","1","2","3","4","5","6","7"};
    Graph<string> graph(vertices);
    try {
        graph.addEdge(Edge<string>("0","2",1)); 
        graph.addEdge(Edge<string>("1","0",4));
        graph.addEdge(Edge<string>("1","5",2));
        graph.addEdge(Edge<string>("2","1",6));  
        graph.addEdge(Edge<string>("2","4",4));
        graph.addEdge(Edge<string>("2","6",9));
        graph.addEdge(Edge<string>("3","1",6));
        graph.addEdge(Edge<string>("3","7",7));
        graph.addEdge(Edge<string>("5","7",1));
        graph.addEdge(Edge<string>("6","4",1));
        graph.addEdge(Edge<string>("6","5",9));
    } catch(invalid_argument& error) {
        cout << error.what() << endl;
    }
    int option = 0;
    string vertex;
    string source, target;

    while (option != 6) {
        cout << "Menu de grafos" << endl;
        cout << "1. Agregar vértice" << endl;
        cout << "2. Agregar arista" << endl;
        cout << "3. Eliminar vértice" << endl;
        cout << "4. Eliminar arista" << endl;
        cout << "5. Mostrar lista de adyacencia" << endl;
        cout << "6. Mostrar matriz de adyacencia" << endl;
        cout << "7. DFS" << endl;
        cout << "8. BFS" << endl;
        cout << "9. Dijkstra" << endl;
        cout << "10. Salir" << endl;
        cout << "Opción: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Vértice: ";
                cin >> vertex;
                try {
                    graph.addVertex(vertex);
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 2:
                int weight;
                cout << "Vértice origen: ";
                cin >> source;
                cout << "Vértice destino: ";
                cin >> target;
                cout << "Peso: ";
                cin >> weight;
                try {
                    graph.addEdge(Edge<string>(source, target, weight));
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 3:
                cout << "Vértice: ";
                cin >> vertex;
                try {
                    graph.removeVertex(vertex);
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 4:
                cout << "Vértice origen: ";
                cin >> source;
                cout << "Vértice destino: ";
                cin >> target;
                try {
                    graph.removeEdge(Edge<string>(source, target, 0));
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 5:
                graph.print();
                break;
            case 6:
                graph.printMatrix();
                break;
            case 7:
                cout << "Vértice: ";
                cin >> vertex;
                try {
                    graph.DFS(vertex);
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 8:
                cout << "Vértice: ";
                cin >> vertex;
                try {
                    graph.BFS(vertex);
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 9:
                cout << "Vértice: ";
                cin >> vertex;
                try {
                    graph.Dijkstra(vertex);
                } catch(invalid_argument& error) {
                    cout << error.what() << endl;
                }
                break;
            case 10:
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
    }
    return 0;
}
