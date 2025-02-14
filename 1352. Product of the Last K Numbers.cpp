class ProductOfNumbers {
    public:
        vector<int> v;
        int i;
        ProductOfNumbers() {
            i = -1;
        }
        
        void add(int num) {
            v.push_back(num);
            i++;
        }
        
        int getProduct(int k) {
            int mult = 1;
            for(int j = i;j>i-k;j--){
                mult = mult * v[j];
            }
    
            return mult;
        }
    };