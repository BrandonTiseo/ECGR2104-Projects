#include <iostream>

using namespace std;

template <typename T>
struct Node{
    Node(T data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList{
    public:
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& other);
    ~DoublyLinkedList();
    void operator=(const DoublyLinkedList<T>& other);
    void push(T data);
    void pop();
    int size() const;
    void print() const;
    T& at(int idx) const;
    void insert(T data, int pos);
    void remove(int pos);

    
    private:
    Node<T>* head;
    Node<T>* tail;
    int numElements;
};



template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = tail = nullptr;
    numElements = 0;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other){
    cout << "Copy constructor called!" << endl;
    numElements = 0;
    head = tail = nullptr;
    for(int i = 0; i < other.size(); i++){
        push(other.at(i));
    }
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    cout << "Destructor called!" << endl;
    Node<T>*temp = head;
    while(head != nullptr){
        temp = temp->next;
        delete head;
        head = temp;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
}

template <typename T>
void DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other){
    cout << "Copy assignment operator override called!" << endl;
    if(this == &other)
        return;
    Node<T>* temp = head;
    while(head != nullptr){
        temp = temp->next;
        delete head;
        head = temp;
    }

    numElements = 0;
    for(int i = 0; i < other.size(); i++){
        push(other.at(i));
    }
}

template <typename T>
void DoublyLinkedList<T>::push(T data){
    numElements ++;
    Node<T>* newNode = new Node(data);

    //Linked List is empty.
    if(head == nullptr){
        head = newNode;
        tail = head;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

template <typename T>
void DoublyLinkedList<T>::pop(){
    //LinkedList is empty.
    if(head == nullptr){
        return;
    }

    numElements --;
    
    //LinkedList only has 1 element.
    if(head->next = nullptr){
        delete head;
        head = tail = nullptr;
        return;
    }

    tail = tail->prev;
    delete tail->next;
}

template <typename T>
int DoublyLinkedList<T>::size() const{
    return numElements;
}

template <typename T>
void DoublyLinkedList<T>::print() const{
    if(head == nullptr){
        cout << "No elements in the linked list." << endl;
        return;
    }

    Node<T>* temp = head;
    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <typename T>
T& DoublyLinkedList<T>::at(int idx) const{
    //If idx == head return the head's data.
    if(idx == 0){
        return head->data;
    }
    //If the idx == tail return the tail's data.
    if(idx == numElements - 1){
        return tail->data;
    }

    Node<T>* temp;
    //Loop based on whether idx is closer to head or tail.
    if(((numElements - 1) - idx) < idx){
        temp = tail;
        for(int i = numElements-1; i > idx; i--){
            temp = temp->prev;
        }
    }else{
        temp = head;
        for(int i = 0; i < idx; i++){
            temp = temp->next;
        }
    }
    
    return temp->data;
}

template <typename T>
void DoublyLinkedList<T>::insert(T data, int pos){
    if(pos < 0 || pos >= numElements){
        cout << "Invalid Index!" << endl;
        return;
    }
    numElements ++;
    Node<T>* newNode = new Node(data);

    Node<T>* temp;
    if(((numElements - 1) - pos) < pos){
        temp = tail;
        for(int i = numElements-1; i > pos; i--){
            temp = temp->prev;
        }
    }else{
        temp = head;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
    }

    temp->prev->next = newNode;
    newNode->next = temp;
}

template <typename T>
void DoublyLinkedList<T>::remove(int pos){
    if(pos < 0 || pos >= numElements){
        cout << "Invalid Index!" << endl;
        return;
    }

    numElements --;
    Node<T>* temp;
    if(pos == 0){
        temp = head->next;
        delete head;
        head = temp;
        return;
    }

    if(((numElements - 1) - pos) < pos){
        temp = tail;
        for(int i = numElements-1; i > pos; i--){
            temp = temp->prev;
        }
    }else{
        temp = head;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
    }
    Node<T>* aheadTemp = temp->next;
    Node<T>* behindTemp = temp->prev;
    delete temp;
    behindTemp->next = aheadTemp;
}


void test(){
    DoublyLinkedList<int> dll;
    dll.push(1);
    dll.push(2);
    dll.push(3);

    dll.print();

    DoublyLinkedList<int> dllCopy = dll;
    dllCopy.print();
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(5, 1);

    
    dll.print();
    dllCopy.print();

    dll = dllCopy;
    dll.print();
}

int main(){
    test();
    cout << "Tests done!" << endl;
    return 0;
}