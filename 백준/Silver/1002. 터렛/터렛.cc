#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,cnt=0;
    int jx,jy,jd,bx,by,bd;
    cin >> n;
    while(n--){
        cin >> jx >> jy >> jd >> bx >> by >> bd;
        
        double d = sqrt((jx-bx)*(jx-bx) + (jy-by)*(jy-by));
        int sub = jd>bd ? jd-bd : bd-jd;
        if(d==0 && jd==bd)
            cout <<"-1" << endl;
        else if(d > jd+bd || sub>d)
            cout <<"0" << endl;
        else if(d==jd+bd||d==sub)
            cout <<"1" << endl;
        else if(sub<d&&d<jd+bd)
            cout <<"2" << endl;
    }
    
    return 0;
}