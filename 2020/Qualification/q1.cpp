#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector < vector <int> > a(n, vector<int>(n));
        vector<int> ex(101,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> a[i][j];
            }
        }
        int tr=0;
        int r=0,c=0;
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(ex[a[i][j]]){
                    flag=1;
                } else {
                    ex[a[i][j]]=1;
                }
                if(i==j){
                    tr+=a[i][j];
                }
            }
            if (flag) {
                r++;
            }
            flag=0;
            fill(ex.begin(), ex.end(), 0);
            
            for(int j=0;j<n;j++) {
                if(ex[a[j][i]]){
                    flag=1;
                    break;
                } else {
                    ex[a[j][i]]=1;
                }
            }
            if(flag){
                c++;
            }
            fill(ex.begin(), ex.end(), 0);
        }
        cout << "Case #" << i << ": " << tr << " " << r << " " << c << endl;
    }

    return 0;
}