#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {

    unordered_set<string> wordSet;  // 끝말잇기 단어 저장소
    string currentWord;             // 가장 최근에 말한 단어
    int breakIndex = 0;             // 끝말잇기가 끝난 인덱스
    for (int i = 0; i < words.size(); i++)
    {
        // 예외 처리
        if (wordSet.find(words[i]) != wordSet.end() || (!currentWord.empty() && words[i][0] != currentWord.back()))
        {
            breakIndex = i;
            break;
        }
        wordSet.insert(words[i]);
        currentWord = words[i];
    }
    cout << breakIndex << endl;
    if (breakIndex != 0) return { (breakIndex+1) % n == 0 ? n : (breakIndex+1) % n, breakIndex / n + 1};
    else return {0,0};
}
