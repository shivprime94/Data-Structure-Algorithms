/*struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};*/

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL) {
        head = curr->next;
        curr->next = prev;
        prev = curr;
        curr = head;
    }
    
    return prev;
}