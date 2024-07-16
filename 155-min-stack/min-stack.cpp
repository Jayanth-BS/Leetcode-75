class MinStack {
public:
    long long cur_min=LONG_MAX;
    stack<long long> st;

    MinStack(){
    }
    
    void push(int val){
        if(st.empty()){
            cur_min = val;
            st.push(val);
        }
        else if(val < cur_min){
                st.push(2*1ll*val - cur_min);
                cur_min = val;
            }
        else{
                st.push(val);
        }
    }
    
    void pop() {
        if(st.top() < cur_min) 
        cur_min = 2*1ll*cur_min - st.top();
        st.pop();
    }
    
    int top() {
        if(st.top()<cur_min) 
            return cur_min;
        return st.top();
    }
    
    int getMin() {
        return cur_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */