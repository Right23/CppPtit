#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	stack<ll> st;
	string s;
	while(cin >> s){
		ll n;
		if(s == "push"){
			cin >> n;
			st.push(n);
		}
		else if(s == "pop"){
			if(!st.empty()){
				st.pop();
			}else{
				cout <<"empty"<< endl;
//				break;
			}
		}
		else if(s == "show"){
			if(st.empty()){
				cout <<"empty"<< endl;
//				break;
			}
			vector <ll> v;
			while(!st.empty()){
				ll top = st.top();
				v.push_back(top);
				st.pop();
			}
			for(int i = v.size() - 1; i >= 0; i--){
				cout << v[i] <<" ";
				st.push(v[i]);
			}
			cout << endl;
		}
	}
}