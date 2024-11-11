#include <vector>
#include <string>
#include "Log.h"

class CountHeap {
private:
    std::vector<Log> data;
    
    void heapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < data.size() && data[left].getCount() > data[largest].getCount()) {
            largest = left;
        }
        else if (left < data.size() && data[left].getCount() == data[largest].getCount()) {
            if (data[left].getIp() > data[largest].getIp()) {
                largest = left;
            }
        }


        if (right < data.size() && data[right].getCount() > data[largest].getCount()) {
            largest = right;
        }
        else if (right < data.size() && data[right].getCount() == data[largest].getCount()) {
            if (data[right].getIp() > data[largest].getIp()) {
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

    

    void print() {
        for (const auto& log : data) {
            std::cout << log.getIp() << " - Count: " << log.getCount() << std::endl;
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



public:
    CountHeap() {}

    bool isEmpty() const {
        return data.empty();
    }

    int getSize() const {
        return data.size();
    }

    

    Log top() {
        if (!isEmpty()) {
            return data[0];
        }
        throw std::runtime_error("Heap is empty");
    }

    void push(const Log& entry) {
        data.push_back(entry);
        int index = data.size() - 1;
        while (index != 0 && (data[(index - 1) / 2].getCount() < data[index].getCount())) {
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
};
