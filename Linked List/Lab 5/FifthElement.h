#pragma once
#include <iostream>
#include <memory>
#include "LinkedList.h"

using namespace std;

template<class T>
class FifthElement : public LinkedList<T>{
    public:
        T getFifthElement();
        void insertNewFifthElement(const T& value);
        void deleteFifthElement();
        void swapFourthAndFifthElement();

};

template<class T>
T FifthElement<T>::getFifthElement(){
    int count = 0; 
    auto curr = make_shared<Node<T>>();
    curr = this->front;
    while(curr != nullptr){
        if (count == 4) {
            return(curr->data); 
        } 
        count++;  
        curr = curr->next;     
    }

    if(curr == nullptr){
        throw runtime_error("No fifth Element!");
    }
    return curr->data;
}

template<class T>
void FifthElement<T>::insertNewFifthElement(const T& value){
    auto val = make_shared<Node<T>>(value);
    auto p = make_shared<Node<T>>();
    auto next = make_shared<Node<T>>();
    p = this->front;
    for(int i = 0; i < 3; i++){
        p = p->next;
    }
    next = p->next;
    p->next = val;
    val->next = next;
}

template<class T>
void FifthElement<T>::deleteFifthElement(){
    auto currNode = make_shared<Node<T>>();
    auto currNext = make_shared<Node<T>>();
    auto temp = make_shared<Node<T>>();

    currNode = this->front;
    currNext = this->front->next;
    for(int i = 0; i < 3; i++){
        currNode = currNode->next;
        currNext = currNext->next;
    }

    temp = currNext->next;
    currNext->next = currNode->next;
    currNode->next = temp;
}

template<class T>
void FifthElement<T>::swapFourthAndFifthElement(){ 
    auto prevFourth = make_shared<Node<T>>();
    auto fourth = make_shared<Node<T>>();
    auto prevFifth = make_shared<Node<T>>();
    auto fifth = make_shared<Node<T>>();
    auto temp = make_shared<Node<T>>();

    prevFourth = this->front->next->next;
    fourth = prevFourth->next;
    prevFifth = fourth->next;
    fifth = prevFifth->next;

    prevFourth->next = prevFifth;
    fourth->next = fourth;
    fourth->next = fifth;
    prevFifth->next = fourth;

    if(fourth == nullptr || fifth == nullptr){
        throw runtime_error("No fifth Element!");
    }    
}

