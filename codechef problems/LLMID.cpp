/*struct Node {
	int val;
	struct Node* next;
	Node(int x){
		val = x;
		next = NULL;
	}
};*/

int getMiddleElement(Node* head) {
    Node* temp = head;
    
    while(head != NULL && head->next != NULL) {
        head = head->next->next;
        temp = temp->next;
    }
    
    int ans = temp->val;
    return ans;
}
