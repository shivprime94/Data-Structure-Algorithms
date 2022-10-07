class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {
        while(st.empty() == false) st.pop();
        min = INT_MAX;
    }
    void push(int value) {
        long long val  = value;
        if(st.empty()){
        min = val;
        st.push(val);
        }else{
            
        if(val < min){
            st.push(2 * val * 1LL - min);
            min = val;
        }else{
            st.push(val);
        }
    }
} 
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        
        if(el < min){
            min = (2 * min - el);
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long el  = st.top();
        if(el < min) return min;
        
        return el;
    }
    
    int getMin() {
        return min;
    }
};
