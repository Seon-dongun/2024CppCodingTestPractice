#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int bandwith = 2 * w + 1;

    int s = 1, e = stations[0]-w-1;
    double dist;
    
    if(s<=e){
        dist = e - s +1;
        answer += ceil(dist/bandwith);
    }

    for(int i=0;i<stations.size()-1;i++){
        s = stations[i] + w + 1;
        e = stations[i+1] -w -1;
        if(s<=e){
            dist = e-s+1;
            answer += ceil(dist/bandwith);
        }
    }
    
    s = stations[stations.size()-1] + w + 1;
    if(s<=n){
        e = n;    
        dist = e-s+1;
        answer += ceil(dist/bandwith);    
    }
    
    return answer;
}