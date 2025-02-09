class NumberContainers {
private:
    unordered_map<int, int> container;
    unordered_map<int, set<int>> revContainer;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int prev = container[index];
        if (prev != 0) revContainer[prev].erase(index);
        container[index] = number;
        revContainer[number].insert(index);
    }
    
    int find(int number) {
        if (revContainer[number].empty()) return -1;
        return *revContainer[number].begin();
    }
};
