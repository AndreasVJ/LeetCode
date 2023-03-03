
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:

    Node* head = nullptr;

    MyLinkedList() {
        
    }
    
    int get(int index) {
        
        Node* curr = head;

        for (int i = 0; i < index; i++) {
            if (curr->next == nullptr) return -1;
            curr = curr->next;
        }
        if (curr == nullptr) return -1;
        return curr->val;
    }
    
    void addAtHead(int val) {
        if (head == nullptr) head = new Node(val);
        else {
            Node* newHead = new Node(val);
            newHead->next = head;
            head = newHead;
        }
    }
    
    void addAtTail(int val) {
        if (head == nullptr) head = new Node(val);
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = new Node(val);
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr->next == nullptr && i != index - 2) return;
            curr = curr->next;
        }
        if (curr == nullptr) return;
        Node* temp = curr->next;
        curr->next = new Node(val);
        curr->next->next = temp;
    }
    
    void deleteAtIndex(int index) {
        if (head == nullptr) return;
        if (index == 0) {
            head = head->next;
            return;
        }
        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr->next == nullptr) return;
            curr = curr->next;
        }
        if (curr->next == nullptr) return; 
        curr->next = curr->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */