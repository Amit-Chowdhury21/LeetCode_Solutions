/*
************************************************************ 383. Ransom Note ************************************************************

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

Approach
Solved using simple nested for loop and if statements.

Code */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int check,s1=ransomNote.length(),s2=magazine.length();
  
        for(int i=0;i<s1;i++)
        {
            check=0;
            for(int j=0;j<s2;j++)
            {
                if(ransomNote[i]==magazine[j])  // check if required char exist
                {
                    check++;         // check=1 if match is found
                    magazine[j]=64;  // replacing matched char with @ in magazine
                    break;
                }
            }
            if(check==0)   // if no match found exit program
            {
               return false;
            }  
        }
        return true;
    }
};
