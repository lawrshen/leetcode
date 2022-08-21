#include <vector>
using namespace std;

int Find(vector<int> &parent, int index) {
    if (parent[index] != index) {
        parent[index] = Find(parent, parent[index]);
    }
    return parent[index];
}

void Union(vector<int> &parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);
}