#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF -987654321

using namespace std;

int value[100][100]={0,};
int main(){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> value[i][j];
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){                
                if(value[i][k] && value[k][j])
                    value[i][j] = 1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << value[i][j] << " ";
        cout << endl;
    }
    return 0;
}