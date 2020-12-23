#include <iostream>

using namespace std;

template<class Type>
struct Node{
	Node(Type data): data(data), next(nullptr){}
	Type data;
	shared_ptr<Node<Type>> next;

};

template<class Type>
class Queue;

template<class Type>
ostream& operator <<(ostream&, const Queue<Type> &);

template<class Type>
class Queue{
    public:
        Queue(); //constructor
        Queue(const Queue<Type>&q); //copy constructor
        Queue<Type>& operator=(const Queue<Type>&q); //to create a deep copy of the queue
        void enqueue(Type data); //inserts data back into the queue
        Type peek(); //Looks at the value at the front of the queue
        void dequeue(); //removes the front of the queue
        bool isEmpty(); //returns true if the queue is empty
        void clear(); //empties everything out of the queue
        friend ostream& operator << <>(ostream&, const Queue<Type> &);



    private:
        shared_ptr<Node<Type>> front;
        shared_ptr<Node<Type>> back;
	    int count;
};

template<class Type> 
Queue<Type>::Queue(){
    front = nullptr;
    back = nullptr;
    count = 0;
}

template<class Type> 
Queue<Type>::Queue(const Queue<Type>&q){
    count = 0;
	auto temp = q.front;
	

    for(int i = 0; i < q.count; i++){
		auto newPtr = make_shared<Node<Type>>(temp->data);
		curr->next = newPtr;
		curr = curr->next;
		temp = temp->next;
		enqueue(temp->data);
	}
}

template<class Type>
Queue<Type>& Queue<Type>::operator=(const Queue<Type>&q){
    clear();
    count = 0;
	auto temp = q.front;
	front = make_shared<Node<Type>>(temp->data);
	count++;
	auto curr = front;

	for(int i = 0; i < q.count; i++){
		auto newPtr = make_shared<Node<Type>>(temp->data);
		curr->next = newPtr;
		curr = curr->next;
		temp = temp->next;
		count++;
	}

	return *this;
}

template<class Type>
void Queue<Type>::enqueue(Type data){
    auto temp = make_shared<Node<Type>>(data);

    //case empty queue
    if(count == 0){
        front = temp;
        back = temp;   
    }else{ //case not empty queue
        back->next = temp;
        back = temp;
    }
    count++;
}

template<class Type>
Type Queue<Type>::peek(){
    if(back == nullptr || count == 0){
		throw runtime_error("Empty");
	}
	return front->data;
}

template<class Type> 
void Queue<Type>::dequeue(){
    if(front == nullptr){
		throw runtime_error("Empty Stack");
	}
    front = front->next;
    count--;
}

template<class Type>
bool Queue<Type>::isEmpty(){
    return count == 0;
}

template<class Type>
void Queue<Type>::clear(){
    front = nullptr;
    back = nullptr;
	count = 0;
}

template<class Type>
ostream& operator << (ostream& out, const Queue<Type> &q){
    auto c = q.front;
    while(c){
        out << c->data << " ";
        c = c->next;
    }

    return out;
}
