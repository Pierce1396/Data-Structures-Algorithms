#pragma once

#include <iostream>
#include "LinkedList.h"

using namespace std;


template<class Type>
class OrderedLinkedList : public LinkedList<Type> {
    public:
        void insert(Type t);
        OrderedLinkedList<Type>& operator+(Type t);
        Type operator[](int);

};

template<class Type>
void OrderedLinkedList<Type>::insert(Type t){

    //I declared the pointer as I was using it instead of wasting the allocated memory
    auto temp = make_shared<Node<Type>>();
    auto prev = make_shared<Node<Type>>();
    temp->data = t;
    //I added the case of an empty list
    if(this->front == nullptr){
        this->front = temp;

    }else{
        //I fixed the logic to add to the middle of the list
        auto curr = this->front;
        prev = nullptr;

        //I set r to 0 instead of nullptr
        //I changed the logic of my while statement 
        while(curr != nullptr){
            if(curr->data >= temp->data){  

            break;

            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        //I set the logic if we were to add anywhere else in the list

        if(curr == this->front){
            temp->next = this->front;
            this->front = temp;
        }else{
            temp->next = curr;
            prev->next = temp;    
        }    

    }
    //I set the count to increment
    this->count++;

}
 

template<class Type>
//I needed to change the function type from Type to OrderedLinkedList<Type> and pass it by reference
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator+(Type t){
    //I changed the insert method to include the overridden one in this class rather than the one in the linked list class 
    insert(t);

    //I needed to make the return type *this
    return *this;
}


template<class Type>
Type OrderedLinkedList<Type>::operator[](int i){
    LinkedList<Type>::peek(i);

    //I needed to make it return the peek() function instead of *this
    return LinkedList<Type>::peek(i);
}



