#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Filename{
    string head="",number="",tail="";
};

bool cmp(Filename a, Filename b){
    for (int i = 0; i < a.head.length(); i++)
        a.head[i] = tolower(a.head[i]);
    
    for (int i = 0; i < b.head.length(); i++) 
        b.head[i] = tolower(b.head[i]);
    
    if(a.head > b.head)
        return false;
    else if(a.head < b.head)
        return true;
    else
        return stoi(a.number) < stoi(b.number);
}

void divide(Filename& file, string str){
    int idx = 0;

    while (idx < str.length() && !isdigit(str[idx]))
        file.head += str[idx++];

    while (idx < str.length() && isdigit(str[idx]) && file.number.length() < 5)
        file.number += str[idx++];

    while (idx < str.length())
        file.tail += str[idx++];   
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Filename> nameDivList;
    
    for(int i=0;i<files.size();i++){
        Filename tmp;
        divide(tmp,files[i]);
        nameDivList.push_back(tmp);
    }
    
    stable_sort(nameDivList.begin(),nameDivList.end(),cmp);
    
    for(int i=0;i<nameDivList.size();i++)
        answer.push_back(nameDivList[i].head+nameDivList[i].number+nameDivList[i].tail);
      
    return answer;
}