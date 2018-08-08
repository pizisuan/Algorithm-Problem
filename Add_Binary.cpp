/*
 * Problem Description
 *
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 *
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 */
 
 // 大神的代码！！！
string addBinary(string a, string b)
{
    string s = "";
    
    int c = 0, i = a.size() - 1, j = b.size() - 1;
    while(i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? a[i --] - '0' : 0;
        c += j >= 0 ? b[j --] - '0' : 0;
        s = char(c % 2 + '0') + s;
        c /= 2;
    }
    
    return s;
}



// 自己的代码：思路是先转换为数字，求和，再转换为二进制字符串(未通过所有测试实例，原因是数字的范围太小不够长，所以这种方法具有局限性)

string addBinary(string a, string b)
{
    unsigned long long sum_a = 0, sum_b = 0;
    for (auto var : a)
    {
      sum_a = 2 * sum_a + (int)(var - '0');
    }
    for (auto var : b)
    {
      sum_b = 2 * sum_b + (int)(var - '0');
    }
    unsigned long long sum = sum_a + sum_b;

    string res;
    if (sum == 0)
    {
      return "0";
    }
    while (sum)
    {
      res.insert(res.begin(), (char)(sum % 2 + '0'));
      sum = sum / 2;
    }

    return res;
}
