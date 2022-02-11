class CustomStack {
public:
    int capacity, size;
    int *stack;
    CustomStack(int maxSize) {
        capacity = maxSize;
        size = 0;
        stack = new int[capacity];
    }
    
    void push(int x) {
        if(size<capacity){
            stack[size]=x;
            size++;
        }
    }
    
    int pop() {
        if(size==0)
            return -1;
        else{
            int temp = stack[size-1];
            size--;
            return temp;
        }
    }
    
    void increment(int k, int val) {
        k = min(k, size);
        for(int i=0;i<k;i++){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */