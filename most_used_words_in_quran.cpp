// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <cmath>
// #include <unordered_map>
// #include <algorithm>

// using namespace std;

// // make Word struct {counter,id,text}
// struct Word{
//     int counter =0;
//     string text;
// };

// void removeSpecialCharacter(string& s)
// {
//     string ans = "";
//     for (auto ch : s) {
//         // if the current character is an alphabet
//         if (isalpha(ch))
//             ans += ch;
//     }
//     s = ans;
// }


// float getWords(vector<Word> & words) {
//     // read the file
//     ifstream file_input("quran.txt");
//     if(!file_input.is_open()){
//         cout<<"this file cannot open";
//         return -1;
//     };

//     unordered_map<string,int> wordCount;
//     string word;
//     float words_len = 0;
//     while (file_input >> word) { 
//         words_len++;
//         removeSpecialCharacter(word);
//         if(word.size()<=1)continue;
//         bool check = false;
//         int id= 0;

//         for(int i = 0;i<words.size();i++){
//             // cout <<word<< "&& "<<words[i].text<<"is "<<(word.compare(words[i].text) == 0)<<endl;
//             if(word.compare(words[i].text) == 0){
//                 check =true;
//                 id =i;
//             }
//         }
//         // if the word already there
//         if(check)
//             words[id].counter++;
//         else{ // else add it
//             Word new_word;
//             new_word.text = word;
//             words.push_back(new_word);
//         }
//     };
//     return words_len;
// }


// bool words_sorter(Word const& lw, Word const& rw) {
//     return lw.counter >= rw.counter;
// }

// int main(){
//     // make words array of Word 
//     vector<Word> words;
//     float words_len = getWords(words);

//     // sort the array by counter
//     sort(words.begin(), words.end(), &words_sorter);

//     // show info
//     for(int i =0;i<words.size();i++){
//         cout<<"rank: "<<i<<" ";
//         cout<<"counter: "<<words[i].counter<<" ";;
//         cout<<"word: "<<words[i].text<<" ";;
//         cout <<" "<< round((words[i].counter/words_len)*100.0)<< "%";
//         cout <<endl;
//     }
//     return 0;
// }

 
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

// make Word struct {counter,id,text}
struct Word{
    int counter =0;
    string text;
};

void removeSpecialCharacter(string& s)
{
    s.erase(remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); }), s.end());
}


float getWords(vector<Word> & words) {
    // read the file
    ifstream file_input("quran.txt");
    if(!file_input.is_open()){
        cout<<"this file cannot open";
        return -1;
    };

    unordered_map<string,int> wordCount;
    string word;
    float words_len = 0;
    while (file_input >> word) { 
        words_len++;
        removeSpecialCharacter(word);
        if(word.size()<=1)continue;
        wordCount[word]++;
    };

    //fill the array
    for(const auto& entry : wordCount){
        Word new_word; 
        new_word.text = entry.first;
        new_word.counter = entry.second;
        words.push_back(new_word);
    }
    return words_len;
}


int main(){
    // make words array of Word 
    vector<Word> words;
    float words_len = getWords(words);

    // sort the array by counter
    sort(words.begin(), words.end(), [](const Word& lw, const Word& rw) {
        return lw.counter > rw.counter;
    });

    // show info
    for(int i =0;i<10;i++){
        cout<<"rank: "<<i+1<<" ";
        cout<<"times: "<<words[i].counter<<" ";;
        cout<<"word: '"<<words[i].text<<"' ";;
        cout <<"per: "<< round((words[i].counter/words_len)*100)<< "%";
        cout <<endl;
    }
    return 0;
}

 