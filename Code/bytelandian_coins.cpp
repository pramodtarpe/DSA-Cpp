#include <bits/stdc++.h>
#define ll long long int
using namespace std;

unordered_map<ll, ll> mp;

ll ans(ll n){
	if(n / 2 + n / 3 + n / 4 < n)
		return n;
	else if(mp.count(n))
		return mp[n];
	else
		mp[n] = ans(n / 4) + ans(n / 3) + ans(n / 2);
	return mp[n];
}


int main() {

ll n;
while(cin>>n){
cout<<ans(n)<<endl;

}
	return 0;
}
