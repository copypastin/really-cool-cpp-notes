// ********************************
// Description: Converts a sentence to Pig Latin 
// Aaron Nguyen
// COMSC-165-5065
// Date: October 26, 2025
// Status: Complete
// ********************************


#include <iostream>
#include <string>
using namespace std;

string leftTrim(string); 
string popWord(string &); 
string toPigLatin(string); 

int main() 
{
    string inputSentence;
    string pigLatinSentence = "";
    string currentWord;

    cout << "Enter a sentence:" << endl;
    getline(cin, inputSentence);
    
    while (inputSentence.size() > 0)
    {
        currentWord = popWord(inputSentence);

        if (currentWord.length() > 0) {
            string pigLatinWord = toPigLatin(currentWord);
            pigLatinSentence += pigLatinWord + " ";
        }
    }

    cout << "Pig Latin: " << pigLatinSentence << endl;
    
}

string leftTrim(string str)
{
    size_t start = str.find_first_not_of(" \t\n\r");

    if (start == string::npos) {
        return "";
    }
    
    return str.substr(start);
}

string popWord(string &sentence)
{
    sentence = leftTrim(sentence);
    size_t pos = sentence.find(' ');

    string word;
    if (pos == string::npos) { 
        word = sentence;
        sentence = "";
    } else {
        word = sentence.substr(0, pos);
        sentence = sentence.substr(pos);
    }
    return word;
}


string toPigLatin(string word) 
{
    if (word.empty()) {
        return "";
    }
    char firstLetter = word[0];

    string restOfWord = word.substr(1); 

    string pigLatinWord = restOfWord + firstLetter + "ay";

    return pigLatinWord;
}