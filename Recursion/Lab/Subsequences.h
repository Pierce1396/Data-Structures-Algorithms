#pragma once

#include <iostream>

using namespace std;

class Subsequences{
    public:
        Subsequences(string w) : word(w){}
        bool isSubSequence(string sub) const;
        bool isSubSequence(string sub, int m, int n) const;
        friend ostream &operator <<(ostream &out, const Subsequences &s);

    private:
        string word; 
       
};

bool Subsequences::isSubSequence(string sub) const{
    return isSubSequence(sub, 0, 0);
}

bool Subsequences::isSubSequence(string sub, int m, int n) const{
 
    
    //base case
    
    if(m == sub.length()) return true;
    if(n == word.length()) return false;

    //recursion 
    //if first characters are matching
    if(sub[m+1] == word[n+1]){
        return isSubSequence(sub, m+1, n+1);
    }

    //if first two characters are not matching
    return isSubSequence(sub, m, n+1);
}

ostream &operator <<(ostream &out, const Subsequences &s){
    out << s.word << " is a ";

    if(!s.isSubSequence(s.word)){
        out << "not ";
    }
    out << "subsequence";
    return out;
}

