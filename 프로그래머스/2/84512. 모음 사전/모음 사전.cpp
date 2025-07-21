#include <string>
#include <vector>
#include <set>

using namespace std;


char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
set<string> vowel_set;

void dfs(int word_cnt, string word)
{
    if (word_cnt == word.size())
    {
        vowel_set.insert(word);
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        string new_word = word + vowels[i];
        dfs(word_cnt, new_word);        
    }    
}

int solution(string word) {
    int answer = 1;
    
    dfs(1, "");
    dfs(2, "");
    dfs(3, "");
    dfs(4, "");
    dfs(5, "");

    for (auto vowel : vowel_set)
    {
        if (vowel == word) return answer;
        answer++;       
    }
    return answer;
}
