#pragma once 

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BracketCheck {
    public:
        BracketCheck(string exp) : bracket(exp){}
        bool arePairs(char open, char close);
        bool isBalanced();
        int numBrackets(int pairs);
        friend ostream &operator <<(ostream &out, BracketCheck &b);

    private:
        string bracket;
        
};

bool BracketCheck::arePairs(char open, char close){
    if(open == '(' && close == ')'){
        return true;
    }else if(open == '{' && close == '}'){
        return true;
    }else if(open == '[' && close == ']'){
        return true;
    } 

	return false;
}

bool BracketCheck::isBalanced(){
    stack<char>s;

    for(int i = 0; i <= bracket.length(); i++){
         if(bracket[i] == '(' || bracket[i] == '[' || bracket[i] == '{'){
             s.push(bracket[i]);

    }else if(bracket[i] == ')' || bracket[i] == ']' || bracket[i] == '}'){
        if(s.empty() || !arePairs(s.top(),bracket[i])){
            return false;
        }else{
            s.pop(); 
        }
    }
  }
     if(!s.empty()){
        return false;
    }

   return true; 
}

int BracketCheck::numBrackets(int pairs){
    pairs = 0;
    for (int i = 0; i < bracket.length(); i++) {
        if (bracket[i] == '(') pairs++;
        else if (bracket[i] == ')') pairs--;

        if (pairs < 0) break;
    }
  return pairs;    
}

ostream &operator <<(ostream &out, BracketCheck &b){
    out << b.bracket << " is ";
    if(!b.isBalanced() ){
        out << "not ";
    }
    out << "balanced";
    return out;
}