#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int CCW(int x1,int y1,int x2,int y2, int x3,int y3){
    return (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
}

int main(){
    vector<pair<int,int>> dots;
    int x,y;
    for(int i=0;i<3;i++){
        cin >> x >> y;
        dots.push_back({x,y});
    }
    
    int ccw = CCW(dots[0].first,dots[0].second,dots[1].first,dots[1].second,dots[2].first,dots[2].second);
    if(ccw==0)
        cout << 0;
    else if(ccw<0)
        cout << -1;
    else
        cout << 1;
    return 0;
    
}