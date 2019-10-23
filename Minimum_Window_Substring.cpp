/*
 * Problem Description
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 */

// 经典滑动窗口算法


// map 保存信息
string minWindow(string s, string t)
{
    if (s.empty() || t.empty() || s.size() < t.size())
    {
        return "";
    }

    unordered_map<char, int> map;
    for (auto& var : t)
    {
        map[var]++;
    }

    int cnt = map.size();
    int left = 0, right = 0;

    string res;
    while (right < s.size())
    {
        if (map.find(s[right]) != map.end())
        {
            map[s[right]]--;
            if (map[s[right]] == 0)
            {
                cnt--;
            }
        }

        right++;
        while (cnt == 0)
        {
            if (map.find(s[left]) != map.end())
            {
                map[s[left]]++;
                if (map[s[left]] > 0)
                {
                    cnt++;
                }
            }

            if (res.empty())
            {
                res = s.substr(left, right - left);
            }
            else
            {
                if (right - left < res.length())
                {
                    res = s.substr(left, right - left);
                }
            }
            left++;
        }
    }
    return res;
}


// 数组保存信息
string minWindow2(string s, string t)
{
    if (s.empty() || t.empty() || s.size() < t.size())
    {
        return "";
    }

    vector<int> info(256, 0);
    for (auto& var : t)
    {
        info[var]++;
    }

    int cnt = 0;
    for (auto& var : info)
    {
        if (var > 0)
        {
            cnt++;
        }
    }

    int left = 0;
    int cur_cnt = 0;
    int min_len = s.length();
    string res = "";
    for (int right = 0; right < s.size(); ++right)
    {
        info[s[right]]--;
        if (info[s[right]] == 0)
        {
            cur_cnt++;
        }
        if (cur_cnt < cnt)
        {
            continue;
        }
        while (cur_cnt >= cnt)
        {
            if (right-left+1 <= min_len)
            {
                min_len = right - left + 1;
                res = s.substr(left, min_len);
            }
            info[s[left]]++;
            if (info[s[left]] > 0)
            {
                cur_cnt--;
            }
            left++;
        }
    }
    return res;
}