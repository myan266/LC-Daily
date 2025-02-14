class ProductOfNumbers {
public:
    vector<int> prefProd;
    int size;

    ProductOfNumbers() {
        prefProd = {1}; 
        size = 0;
    }
    
    void add(int num) {
        if (num == 0){ 
            prefProd = {1}; size = 0;
        }
        else{ 
            prefProd.push_back(prefProd.back() * num); size++;
        }
    }
    
    int getProduct(int k) {
        return k > size ? 0 : prefProd.back() / prefProd[size - k];
    }
};
