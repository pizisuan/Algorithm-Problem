/*
 * Problem Description
 * We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
 * A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
 * Return a list of all uncommon words. You may return the list in any order.
 *
 * Example 1
 * Input: A = "this apple is sweet", B = "this apple is sour"
 * Output: ["sweet","sour"]
 *
 * Example 2
 * Input: A = "apple apple", B = "banana"
 * Output: ["banana"]
 *
 */
 
 
class Solution 
{
public:
    vector<string> uncommonFromSentences(string A, string B) 
    {
        string s = A + " " + B;
        vector<string> words;
        string word;

        for (auto letter : s)
        {
            if (letter != ' ')
            {
                word += letter;
            }
            else
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word = "";
                }
            }
		}
		if (!word.empty())
		{
        words.push_back(word);
		}


		int count = 0;
		vector<string> res;
		for (auto word : words)
		{
        for (auto item : words)
        {
            if (item == word)
            {
              count++;
            }
        }
        if (count == 1)
        {
            res.push_back(word);
        }
        count = 0;
		}
		
		return res;
    }
};



// 实际上可用采用下面的函数完成字符串的按空格分隔

// 按照空格分隔字符串
vector<string> split(string& words)
{
    stringstream ss(words);
    string word;
    vector<string> res;
    while (ss >> word)
    {
        res.push_back(word);
    }
    return res;
}

