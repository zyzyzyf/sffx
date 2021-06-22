#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 10;
int n;
string a;
string b;
int dp[maxn][maxn] = { 0 };
void lcs(int lena,int lenb) {
	for (int i = 0; i < lena; ++i) {
		for (int j = 0; j < lenb; ++j) {
			if (a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[lena - 1][lenb - 1] << endl;
}
int main() {
	cin >> a >> b;
	int lena = a.length();
	int lenb = b.length();
	cout << "The ans is ";
	lcs(lena, lenb);
	return 0;
}
