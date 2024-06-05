#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;
unordered_map<string,char> mm = {{"C",'0'},{"C#",'1'},{"D",'2'},{"D#",'3'},{"E",'4'},{"F",'5'},{"F#",'6'},{"G",'7'},{"G#",'8'},{"A",'9'}, {"A#",'A'},{"B",'B'}};

int calTime(string s, string e) {
    int s_time = stoi(s) * 60 + stoi(s.substr(3));
    int e_time = stoi(e) * 60 + stoi(e.substr(3));
    return e_time - s_time;
}


string change(string str){
    int i = 0;
    string answer = "";
    while(i<str.length()){
        if(i+1<str.length() && str[i+1]=='#'){
            answer +=mm[str.substr(i,2)];
            i+=2;
        }
        else{
            answer +=mm[string(1,str[i])];
            i++;
        }
    }
    return answer;
}

string solution(string m, vector<string> musicinfos) {
    vector<vector<string>> musicinfo(musicinfos.size());
    int maxLength = -1;
    string answer="(None)";
    
    m = change(m);
    for(int i=0;i<musicinfos.size();i++){
        istringstream iss(musicinfos[i]);
        string buf;
        while (getline(iss, buf, ','))
            musicinfo[i].push_back(buf);
    }
    
    
    for(int i=0;i<musicinfo.size();i++){
        int runtime = calTime(musicinfo[i][0],musicinfo[i][1]);
        musicinfo[i][3] = change(musicinfo[i][3]);
        string detail = musicinfo[i][3];
        string tmp = "";

        if(detail.length()>=runtime)
            tmp = detail.substr(0,runtime);
        else{
            int repeat=runtime/detail.length() +1;          
            while(repeat!=0){
                tmp+=detail;
                repeat--;
            }
        }
        musicinfo[i][3] = tmp.substr(0,runtime);
        if(musicinfo[i][3].find(m) != string::npos){   
            int t = calTime(musicinfo[i][0],musicinfo[i][1]);
            if(maxLength < t){             
                answer = musicinfo[i][2];              
                maxLength = t;
            }
        }
    }
    
    return answer;
}