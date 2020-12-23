#include <iostream>
#include "Subsequences.h"

using namespace std;

void checkCase(string, string, string, bool);

int main()
{


    /**
        Add several more test cases to thoroughly test your data
        checkCase takes the following parameters (name, word, possible subsequence, true/false it would be a subsequence)
    **/

    checkCase("Case 1: First Letter", "pin", "programming", true);
    checkCase("Case 2: Skipping Letters", "ace", "abcde", true);
    checkCase("Case 3: Out of order", "bad", "abcde", false);
    checkCase("Case 4: As a Palindrome", "race", "racecar", true);
    checkCase("Case 5: All in order but 1 letter", "abcde", "abced", false);
    checkCase("Case 6: Empty String", "Program", "", false);
    checkCase("Case 7: Empty Subsequence", "", "Program", true);
    checkCase("Case 8: Longer Subsequence", "abcdefg", "abc", false);
    checkCase("Case 9: Non-letter Characters", "!.#$", "!@.*#$$", true);
    checkCase("Case 10: Working Backwards", "abcdefg", "gfedcba", false);

    return 0;
}


void checkCase(string testCaseName, string sub, string sentence, bool correctResponse){
    Subsequences s(sentence);
    if(s.isSubSequence(sub) == correctResponse){
        cout << "Passed " << testCaseName << endl;
    }
    else{
        cout << "Failed " << testCaseName << ": " << sub << " is " << (correctResponse? "": "not ") << "a subsequence of " << sentence << endl;
    }
}
