#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void minNum(string x, string y);
int main() {
    string x = "wxhsffx";
    string y = "wtysffx";
    minNum(x, y);
	return 0;
}
void minNum(string x, string y){
	if(x==y) {
        cout<<"0"<<endl;
        return;
    }
    int xl=x.length();
    int yl=y.length();
    int n[xl + 1][yl + 1]={0};
    for(int i = 1;i <= xl;i++)
        n[i][0] = i;
    for(int j = 1;j <= yl;j++)
        n[0][j] = j;
    for(int i = 1;i <= xl;i++) {
        for(int j = 1;j <= yl;j++) {
            if(x.at(i - 1) == y.at(j - 1))
                n[i][j] = n[i - 1][j - 1];
            else {
                n[i][j] = min(n[i - 1][j] + 1,min(n[i][j - 1] + 1, n[i - 1][j - 1] + 1));
            }
        }
    }
    cout<<n[xl][yl];
    return;
}
