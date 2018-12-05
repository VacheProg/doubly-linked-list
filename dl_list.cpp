#include<iostream>

template<typename T>
class List{

    private:
    template<typename U>
    class Node{
        public:

        Node<T>* next;
        Node<T>* prev;
        U value;
        Node(U val = U(),Node<U>* pnext = nullptr,Node<U>* pprev = nullptr):value(val),next(pnext),prev(pprev){}
    };
    Node<T>* head;
    Node<T>* tail;
    int size;
   
    public:
    List(){
        
        head =nullptr;
        tail = nullptr;
        size = 0;
    }
    ~List(){
        while(head != nullptr){
        tail = nullptr;
        Node<T>* temp = head;
        temp->prev  = nullptr;
        head = head->next;
        delete temp;
        }
    }

     T operator [] (int index)
    {
        int k = 0;
        Node<T>* temp;
        if(index > size/2)
        {
            temp = tail;
            
            while((size-k) != index){
                temp = temp->prev;
            }
            

        }
        else
        {
            temp = head;
            while(k != index)
            {
                temp = temp->next;
            }
        }
        return temp->value;
    }

    void push_back(T data){
        if(head == nullptr){
            head  = new Node<T>(data);
            ++size;
        }
        else{
            if(tail == nullptr){
                tail = new Node<T>(data);
                tail->prev = head;
                ++size;
                head->next =tail;
            }
            else{
                Node<T>* curr  = new Node<T>(data);
                curr->next = nullptr;
                curr->prev = tail;
                tail->next = curr;
                tail = curr;
                ++size;
            }
        }        

    }



    int get_size(){
        return size;
    }


    void push_front(T data){
        if(head == nullptr){
            head = new Node<T>(data);
        }
        else{
            if(tail == nullptr){
                Node<T>* temp = new Node<T>(data);
                tail = head;
                tail->prev = temp;
                head = temp;
                head->next = tail;
            }
            else{
                Node<T>* curr  = new Node<T>(data);
                curr->next = head;
                head->prev = curr;
                head = curr;
            }
        }
        ++size;

    }

    void pop_front(){
        if (head == nullptr) return;
        else{
            if(head == tail){
                tail = nullptr;
                Node<T> * temp = head;
                head = nullptr;

            }
            else{
                Node<T>* temp = head;
                head = head->next;
                head->prev = nullptr;
                temp->next = nullptr;
                delete temp;
            }
            --size;
        }
    }
    void pop_back(){
        if(head == nullptr) return;
        else{
            if(head == tail){
                head = nullptr;
                Node<T> * temp = tail;
                tail = nullptr;
                delete temp;
            }
            else{
                Node<T>* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                temp->prev  = nullptr;
                delete temp;
            }
            --size;
            
        }
    }

    bool empty()
    {
        if(size == 0) return true;
        else return false;
    }

};
int main()
{
    List<int> ls;
    ls.push_back(10);
    ls.push_front(8);
    ls.push_back(1);
    ls.push_front(19); 
    std::cout<<ls[0]<<std::endl;
    std::cout<<"size- "<<ls.get_size()<<"     is empty - "<<ls.empty()<<std::endl;
    ls.pop_back();
    ls.pop_front();
    std::cout<<"size- "<<ls.get_size()<<"     is empty - "<<ls.empty()<<std::endl;
    ls.pop_front();
    ls.pop_back();
    std::cout<<"size- "<<ls.get_size()<<"     is empty - "<<ls.empty()<<std::endl;
    return 0;
}