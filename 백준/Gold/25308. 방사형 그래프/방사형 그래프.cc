#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int answer = 0;
double num[8];
vector<int> order = { 0, 1, 2, 3, 4, 5, 6, 7 };

void check(){
    for(int i=0;i<8;i++){
        double x = num[order[i]];
        double y = num[order[(i+1)%8]]*sqrt(2.0)/2.0;
        double z = num[order[(i+2)%8]];
        
        if(y + (z/x)*y - z < 0)
            return;
    }
    answer++;
}

int main(){
    for(int i=0;i<8;i++)
        cin >> num[i];
    
    do{
        check();
    }while(next_permutation(order.begin(),order.end()));
    
    cout << answer << endl;
    
    return 0;
}