#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Log.h"
#include "MaxHeap.h"
#include "MinHeap.h"
#include "BST.h"
#include "CountHeap.h"

using namespace std;
void loadLogData(const string& filename, vector<Log>& logs) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error opening input file " << filename << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        string month, year, day, time, ip, issue;
        istringstream iss(line);
        iss >> month >> day >> year >> time >> ip;
        getline(iss, issue);
        logs.push_back(Log(year, month, day, time, ip, issue));
    }
    inFile.close();
}

int getIPCount(const vector<Log>& logs, const string& ip) {
    int count = 0;
    for (const auto& log : logs) {
        if (log.ip == ip) {
            count++;
        }
    }
    return count;
}



void saveLogsToFile(const vector<Log>& logs, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error opening output file " << filename << endl;
        return;
    }

    for (const auto& log : logs) {
        outFile << log.convertFromMonth(log.month) << " "
                << log.day << " "
                << log.year << " "
                << log.time << " "
                << log.ip << " "
                << log.issue << "" << endl;
    }
    outFile.close();
}

int main() {
    vector<Log> logs;
    MaxHeap maxHeap;
    MinHeap minHeap;
    BST bst;
    CountHeap countHeap;

    loadLogData("log608-3.txt", logs);

    for (const auto& log : logs) {
        maxHeap.push(log);
        minHeap.push(log);
        bst.insert(log.ip);
    }

    vector<Log> uniqueLogs;
    for (const auto& log : logs) {
        bool isDuplicate = false;
        for (const auto& uniqueLog : uniqueLogs) {
            if (log.ip == uniqueLog.ip) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueLogs.push_back(log);
        }
    }

    for (auto& log : uniqueLogs) {
        log.setCount(getIPCount(logs, log.ip));
        countHeap.push(log);
    }


    
    int choice;
        cout << "\nMenu:\n";
        cout << "1. Desplegar datos por IP, fecha y hora (mayor a menor)\n";
        cout << "2. Generar archivo output608-1.out (ordenado de mayor a menor, Por IP luego por tiempo)\n";
        cout << "3. Generar archivo output608-2.out (ordenado de menor a mayor, Por IP luego por tiempo)\n";
        cout << "4. Desplegar las 10 IPs con mayor numero de registros\n";
        cout << "5. Buscar una IP en el arbol binario de busqueda\n";
        cout << "6. Salir\n";
        cout << "Elige una opcion: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Desplegar datos de mayor a menor por IP, fecha y hora...\n";
                vector<Log> sortedLogs;
                while (!maxHeap.isEmpty()) {
                    sortedLogs.push_back(maxHeap.top());
                    maxHeap.pop();
                }
                for (const auto& log : sortedLogs) {
                    cout << log.convertFromMonth(log.month) << " " 
                         << log.day << " " 
                         << log.year << " " 
                         << log.time << " " 
                         << log.ip << " " 
                         << log.issue << endl;
                }
                break;
            }
            case 2: {
                cout << "Generando archivo output608-1.out (ordenado de mayor a menor)...\n";
                vector<Log> sortedLogs;
                while (!maxHeap.isEmpty()) {
                    sortedLogs.push_back(maxHeap.top());
                    maxHeap.pop();
                }
                saveLogsToFile(sortedLogs, "output608-1.out");
                break;
            }
            case 3: {
                cout << "Generando archivo output608-2.out (ordenado de menor a mayor)...\n";
                vector<Log> sortedLogs;
                while (!minHeap.isEmpty()) {
                    sortedLogs.push_back(minHeap.top());
                    minHeap.pop();
                }
                saveLogsToFile(sortedLogs, "output608-2.out");
                break;
            }
            case 4: {
                cout << "Desplegando las 10 IPs con mayor numero de registros usando un MaxHeap...\n";
                for (int i = 0; i < 10; i++) {
                    Log log = countHeap.top();
                    cout << log.ip << " - Count: " << log.count << endl;
                    while (countHeap.top().ip == log.ip) {
                        countHeap.pop();
                    }
                }





                break;
            }
            case 5: {
                string ipToSearch;
                cout << "Ingresa la IP a buscar: ";
                cin >> ipToSearch;
                int occurrences = bst.search(ipToSearch);
                if (occurrences > 0) {
                    cout << "La IP " << ipToSearch << " se encuentra " << occurrences << " veces en el archivo.\n";
                } else {
                    cout << "La IP " << ipToSearch << " no se encuentra en el archivo.\n";
                }
                break;
            }
            case 6: {
                cout << "Saliendo del programa.\n";
                break;
            }
            default:
                cout << "Opcion invalida. Por favor, intenta de nuevo.\n";
                break;

        }

    return 0;
};



