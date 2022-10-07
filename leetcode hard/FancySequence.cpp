class Fancy {
public:
    #define MOD 1000000007
    
    vector<pair<char,int>> op;       
  vector<pair<int,int>> table;      
    
  void append(int val) {
    table.push_back({op.size(), val});    
  }
    
  void addAll(int inc) {
    op.push_back({0, inc});    
  }
    
  void multAll(int m) {
    op.push_back({1, m});
  }
    
  int getIndex(int idx) {
    if(idx >= table.size())
        return -1;
    
    auto &[id , num] = table[idx];
    for(;id != op.size(); id++)
      if(op[id].first)
          num = (long(num) * op[id].second) % MOD;
      else
          num = (long(num) + op[id].second) % MOD;
    
    return num;
  }
};