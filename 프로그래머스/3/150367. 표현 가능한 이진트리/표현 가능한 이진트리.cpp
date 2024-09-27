#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string MakeBinary(long long num)
{
    string str = "";
    
    while(num>0)
    {
        str+=((num%2)+'0');
        num/=2;
    }
    reverse(str.begin(),str.end());
    
    long long inc = 0;
    int i = 0;
    int len = str.length();
    while(1)
    {
        if(len <= inc)
            break;
        inc = inc + pow(2,i);
        i++;
    }
    
    for(int j=len;j<inc;j++)
        str = '0' + str;

    return str;
}

bool isAllZero(string str) {
    for (char c : str) {
        if (c != '0') return false;
    }
    return true;
}

bool canDraw(string str) {
    if (str.length() == 1 || isAllZero(str)) 
        return true;
 
    int midIdx = str.length() / 2;
    string left = str.substr(0, midIdx);
    string right = str.substr(midIdx + 1);
 
    if (str[midIdx] == '1' && canDraw(left) && canDraw(right)) 
        return true;
    else return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0;i<numbers.size();i++)
    {
        string str = MakeBinary(numbers[i]);
        answer.push_back(canDraw(str));     
    }
    
    return answer;
}