class SmallestInfiniteSet {
public:
    int smallest;
    unordered_set<int>st;

    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        int x = smallest;

        st.insert(x);
        
        smallest++;
        while(st.find(smallest) != st.end()) smallest++;

        return x;
    }
    
    void addBack(int num) {
        if(st.count(num)) st.erase(num);

        smallest = min(smallest, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */