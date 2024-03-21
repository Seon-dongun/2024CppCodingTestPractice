#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

void divRecord(string record, string& command, string& id, string& nickname){
    stringstream ss(record);
    ss >> command;
    ss >> id;
    ss >> nickname;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string>> list;
    string command, id, nickname;
    unordered_map<string,string> m;
    for(int i=0;i<record.size();i++){
        divRecord(record[i],command,id,nickname);
        
        list.push_back({command,id});
        if(command!="Leave")
            m[id] = nickname;
    }
    
    for(int i=0;i<list.size();i++){
        string str = m[list[i].second];
        if(list[i].first=="Enter")
            str+="님이 들어왔습니다.";
        
        else if(list[i].first=="Leave")
            str+="님이 나갔습니다.";
        else if(list[i].first=="Change")
            continue;
        
        answer.push_back(str);
    }
    
    return answer;
}
