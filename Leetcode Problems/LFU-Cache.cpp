struct node{
    // public:
  int key, value, cnt;
    node* next;
    node* prev;
    
    node(int _key, int _value){
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List{
    // public:
  int size;
    node* head;
    node* tail;
    List(){
        head = new node(0,0);
        tail = new node(0,0);
        head->next = tail; //
        tail->prev = head;
        size = 0; //
    }
    
    void addfront(node* newn){
        node* temp = head->next;
        newn->next = temp;
        newn->prev = head;
        head->next = newn;
        temp->prev = newn;
        size++;
    }
    
    void removenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
    
    map<int, node*> keyNode;
    map<int, List*> freqList;
    int maxSizeCache;
    int minFreq;
    int currSize;
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }
    
   void updateFreq(node* noden){
        keyNode.erase(noden->key);
        freqList[noden->cnt]->removenode(noden);
        if(noden->cnt == minFreq && freqList[noden->cnt]->size == 0){
            minFreq++;
        }
        
        List* nextHighList = new List();
        if(freqList.find(noden->cnt + 1) != freqList.end()){
            nextHighList = freqList[noden->cnt + 1];
        }
        
        noden->cnt += 1;
        nextHighList->addfront(noden);
        freqList[noden->cnt] = nextHighList;
        keyNode[noden->key] = noden;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()){
            node* getnode = keyNode[key];
            int val = getnode->value;
            updateFreq(getnode);
            return val;
        }
        return -1;
    }
    
    
    void put(int key, int value) {
      if(maxSizeCache == 0){
          return;
      }  
        if(keyNode.find(key) != keyNode.end()){
            node* newn = keyNode[key];
            newn->value = value;
            updateFreq(newn);
        }
        else{
            if(currSize == maxSizeCache){
                List* listl = freqList[minFreq];
                keyNode.erase(listl->tail->prev->key);
                freqList[minFreq]->removenode(listl->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqList.find(minFreq) != freqList.end()){
                listFreq = freqList[minFreq];
            }
            
            node* newnode = new node(key, value);
            listFreq->addfront(newnode);
            keyNode[key] = newnode;
            freqList[minFreq] = listFreq;
        }
    }
};
