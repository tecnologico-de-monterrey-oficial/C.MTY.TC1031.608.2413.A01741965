#include <vector>
#include <iostream>
#include "Log.h"

class MaxHeap {
private:
    std::vector<Log> data;

    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < data.size() && data[left].getIp() > data[largest].getIp()) {
            largest = left;
        }
        else if (left < data.size() && data[left].getIp() == data[largest].getIp()) {
            if (data[left].getKey() > data[largest].getKey()) {
                largest = left;
            }
        }

        if (right < data.size() && data[right].getIp() > data[largest].getIp()) {
            largest = right;
        }
        else if (right < data.size() && data[right].getIp() == data[largest].getIp()) {
            if (data[right].getKey() > data[largest].getKey()) {
                largest = right;
            }
        }

        if (largest != index) {
            std::swap(data[index], data[largest]);
            heapify(largest);
        }
    }


    void downsort() {
        int lastIndex = data.size() - 1;
        std::swap(data[0], data[lastIndex]);
        data.pop_back();
        heapify(0);
    }

public:
    MaxHeap() {}

    bool isEmpty() const {
        return data.empty();
    }

    int getSize() const {
        return data.size();
    }

    void push(const Log& entry) {
        data.push_back(entry);
        int index = data.size() - 1;
        while (index != 0 && (data[(index - 1) / 2].getIp() < data[index].getIp() || (data[(index - 1) / 2].getIp() == data[index].getIp() && data[(index - 1) / 2].getKey() < data[index].getKey()))) {
            std::swap(data[index], data[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }



    void pop() {
        if (!isEmpty()) {
            downsort();
        }
    }

    Log top() const {
        if (!isEmpty()) return data[0];
        throw std::out_of_range("Heap is empty");
    }

    void print() {
        for (const auto& log : data) {
            std::cout << log.getIp() << endl;
        }
    }


    std::vector<Log> heapSort() {
        std::vector<Log> list;
        while (!isEmpty()) {
            Log aux = top();
            list.push_back(aux);
            pop();
        }
        return list;
    }
};
                      
