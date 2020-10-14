#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
typedef long long ll;
using namespace std;
ifstream fin("/Users/vincent/Documents/code competition/poj/tt.txt");
struct bases
{
	int loc, range, lf;
};
bases b[100006];
int n, t, a, bb, l;
bool cmp(const bases& a1, const bases& a2){
	return a1.lf < a2.lf;
}
void solve(){
	bases tmp = b[0];
	int rs = tmp.loc + tmp.range, ls = max(b[0].lf, 0);
	ll ans = 0; 
	for(int i = 1; i < n; i++){
		if(b[i].lf <= rs){
			rs = max(b[i].loc + b[i].range, rs);
			if(rs >= l)break;
		}else{
			ans += rs - ls;
			ls = b[i].lf;
			rs = b[i].loc + b[i].range;
		}
	}
	ans += rs - ls;
	cout << ans << endl;
}
int main(int argc, char const *argv[])
{
	cin >> t;
	while(t--){
		memset(b, 0, sizeof(b));
		cin >> l >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> bb;
			b[i].loc = a;
			b[i].range = bb;
			b[i].lf = a-bb;
		}
		sort(b, b+n, cmp);
		solve();
	}
	return 0;
}