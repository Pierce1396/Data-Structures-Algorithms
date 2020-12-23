#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using namespace std;
template <class Type>
class Range;

template <class Type>
ostream &operator<<(ostream &, const Range<Type> &);

template <class Type>
class Range{
    private:
        Type start = 1;
        Type end = 1;
        Type step = 1;

    public:
        Range(){start; end; step;}
        Range(Type start, Type end): start(start), end(end){}
        Range(Type start, Type end, Type step): start(start), end(end), step(step){}


        int length();
        Type sum();
        Type average();
        Type min();
        Type max();
        friend ostream &operator<< <>(ostream &, const Range<Type> &);

};

template<class Type>
int Range<Type>::length(){
    //initialize an array and set it equal to the range.
    list<Type> range;
    if(start < end){
    for(Type i = start; i<= end; i += step){
         range.push_back(i);
        }
    }else if(start > end){
        for(Type i = start; i>= end; i += step){
         range.push_back(i);
    }
   
    }
   return range.size();  
}

template <class Type>
Type Range<Type>::sum(){
    Type sum = 0;
    if(start < end){
        for(Type i = start; i <= end; i += step){ 
            sum += i;
        }
    }else if(start > end){
        for(Type i = start; i >= end; i += step){ 
            sum += i;
        }    

        
    }
   return sum; 
}

template<class Type>
Type Range<Type>::average(){

    return sum() / length();
}

template<class Type>
 Type Range<Type>::min(){
 Type newMin;
    if(start < end){ 
        return start;      
    }else if(start > end){
        for(Type i = start; i >= end; i += step){
                newMin = i;
         }
      return newMin;      
    }
}

template<class Type>
Type Range<Type>::max(){
    Type newMax;
    if(start < end){
        for(Type i = start; i <= end; i += step){
                newMax = i;
            }    
    }else if(start > end){
        return start;
    }
    
    return newMax; 
}

template<class Type>
ostream &operator<<(ostream &out, const Range<Type> &range){

     Range<Type>r();
     out << r;
   

    return out;

}


