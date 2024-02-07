#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <climits>

using namespace std;
    
map<pair<string,string>, int> m = {
        {{"dia", "diamond"}, 1}, {{"dia", "iron"}, 1}, {{"dia", "stone"}, 1},
        {{"iron", "diamond"}, 5}, {{"iron", "iron"}, 1}, {{"iron", "stone"}, 1},
        {{"stone", "diamond"}, 25}, {{"stone", "iron"}, 5}, {{"stone", "stone"}, 1}
};

int findMin(int a, int b, int c) {
    int min_ab = (a < b) ? a : b;
    return (min_ab < c) ? min_ab : c;
}

int getCost(int idx,int dia,int iron, int stone,int cost, vector<string>& minerals){
    if(dia==0 && iron==0 && stone==0)
        return cost;
       
    if(idx>=minerals.size())
        return cost;
    
    int i,dCost=0,iCost=0,sCost=0,a=INT_MAX,b=INT_MAX,c=INT_MAX;
    for(i=idx;i<minerals.size() && i<idx+5;i++){
        dCost += m[{"dia",minerals[i]}];
        iCost += m[{"iron",minerals[i]}];
        sCost += m[{"stone",minerals[i]}];
    }    
        
    if(dia!=0)
        a=getCost(idx+5,dia-1,iron,stone,cost+dCost,minerals); 
    if(iron!=0)
        b=getCost(idx+5,dia,iron-1,stone,cost+iCost,minerals);
    if(stone!=0)
        c=getCost(idx+5,dia,iron,stone-1,cost+sCost,minerals);
                
    return findMin(a,b,c);   
}

int solution(vector<int> picks, vector<string> minerals) {
    return getCost(0,picks[0],picks[1],picks[2],0,minerals);
}