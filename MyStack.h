//Kyle Luster
//This is my own work; with source code from instructor

template<class T>
struct Node{
      T data;
      Node(T newData) {
        data = newData;
        next = nullptr;
      }
      struct Node* next;
};
template<class T>
class MyStack 
{
    private:
        Node<T>*head;
        int length;
    public:
        MyStack(): head(nullptr), length(0){}    //defualt constructor
        void push(T);
        void pop();
        bool empty(){return length == 0;}
        int size(){return length;}
        T top(){return head->data;}
        // T& top(){}             
};

template<class T>
void MyStack<T>::push(T val){
  Node<T>* n_node = new Node<T>(val);
  n_node->next=head;
  head = n_node;
  length++;
}
template<class T>
void MyStack<T>::pop(){
  if (empty()) return;

  Node<T>*temp=head;
  head=temp->next==nullptr ? nullptr : temp->next;
  length--;
}
