#pragma once

template <class T>
struct Edge {
    T source;
    T target;
    int weight;
    Edge();
    Edge(T source, T target, int weight);
};

template <class T>
Edge<T>::Edge() {
    weight = 0;
}

template <class T>
Edge<T>::Edge(T source, T target, int weight) {
    this->source = source;
    this->target = target;
    this->weight = weight;
}

template <class T>
bool operator==(const Edge<T>& lhs, const Edge<T>& rhs) {
    return lhs.source == rhs.source && lhs.target == rhs.target;
}

template <class T>
bool operator!=(const Edge<T>& lhs, const Edge<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator<(const Edge<T>& lhs, const Edge<T>& rhs) {
    return lhs.weight < rhs.weight;
}

template <class T>
bool operator>(const Edge<T>& lhs, const Edge<T>& rhs) {
    return rhs < lhs;
}

template <class T>
bool operator<=(const Edge<T>& lhs, const Edge<T>& rhs) {
    return !(lhs > rhs);
}

template <class T>
bool operator>=(const Edge<T>& lhs, const Edge<T>& rhs) {
    return !(lhs < rhs);
}

template <class T>
ostream& operator<<(ostream& os, const Edge<T>& edge) {
    os << edge.source << " -> " << edge.target << " (" << edge.weight << ")";
    return os;
}

template <class T>
istream& operator>>(istream& is, Edge<T>& edge) {
    is >> edge.source >> edge.target >> edge.weight;
    return is;
}

