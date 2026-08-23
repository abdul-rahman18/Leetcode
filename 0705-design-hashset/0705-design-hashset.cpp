class LL{
public:
    int data;
    LL* next;

    LL(int data) {this->data = data; this->next = nullptr;}
};

class MyHashSet {
public:
    LL* head;
    MyHashSet() { 
        head = nullptr;
    }
    
    void add(int key) {
        
        if(contains(key)) return;
        if(head == nullptr)
        {
            LL* node = new LL(key);
            head = node;
            return;
        }

        LL* temp = head;
        while(temp->next != nullptr) temp = temp->next;

        LL* node = new LL(key);
        temp->next = node;
    }
    
    void remove(int key) {

        if(head == nullptr) return;
        if(head->data == key)
        {
            LL* node = head;

            head = head->next;
            node->next = nullptr;
            delete node;
            return;
        }

        LL* temp = head;

        while(temp->next != nullptr)
        {
            if(temp->next->data == key)
            {
                LL* node = temp->next;
                temp->next = temp->next->next;
                node->next = nullptr;
                delete node;
                return;
            }
            temp = temp->next;
        }
    }
    
    bool contains(int key) {
        
        LL* temp = head;
        
        while(temp)
        {
            if(temp->data == key) return true;
            temp = temp->next; 
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */