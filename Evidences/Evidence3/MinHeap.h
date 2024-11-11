class MinHeap {
private:
    std::vector<Log> data;

    void heapify(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < data.size() && (data[left].getIp() < data[smallest].getIp())) {
            smallest = left;
        } else if (left < data.size() && (data[left].getIp() == data[smallest].getIp())) {
            if (data[left].getKey() < data[smallest].getKey()) {
                smallest = left;
            }
        }

        if (right < data.size() && (data[right].getIp() < data[smallest].getIp())) {
            smallest = right;
        } else if (right < data.size() && (data[right].getIp() == data[smallest].getIp())) {
            if (data[right].getKey() < data[smallest].getKey()) {
                smallest = right;
            }
        }




        if (smallest != index) {
            std::swap(data[index], data[smallest]);
            heapify(smallest);
        }
    }

    void downsort() {
        int lastIndex = data.size() - 1;
        std::swap(data[0], data[lastIndex]);
        data.pop_back();
        heapify(0);
    }

public:
    MinHeap() {}

    bool isEmpty() const {
        return data.empty();
    }

    int getSize() const {
        return data.size();
    }

    void push(const Log& entry) {
        data.push_back(entry);
        int index = data.size() - 1;
        while (index != 0 && (data[(index - 1) / 2].getIp() > data[index].getIp() || (data[(index - 1) / 2].getIp() == data[index].getIp() && data[(index - 1) / 2].getKey() > data[index].getKey()))) {
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
            std::cout << log.convertFromMonth(log.month) << " "
                      << log.day << " "
                      << log.year << " "
                      << log.time << " "
                      << log.ip << " "
                      << log.issue << std::endl;
        }
    }


};
