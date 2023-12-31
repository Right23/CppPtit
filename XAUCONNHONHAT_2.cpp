//https://www.geeksforgeeks.org/smallest-window-contains-characters-string/?ref=gcse
// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;

//const int MAX_CHARS = 256;
//
//// Function to find smallest window containing
//// all distinct characters
//string findSubString(string str)
//{
//	int n = str.length();
//
//	// if string is empty or having one char
//	if (n <= 1)
//		return str;
//
//	// Count all distinct characters.
//	int dist_count = 0;
//	bool visited[MAX_CHARS] = { false };
//	for (int i = 0; i < n; i++) {
//		if (visited[str[i]] == false) {
//			visited[str[i]] = true;
//			dist_count++;
//		}
//	}
//
//	// Now follow the algorithm discussed in below
//	// post. We basically maintain a window of characters
//	// that contains all characters of given string.
//	int start = 0, start_index = -1, min_len = INT_MAX;
//
//	int count = 0;
//	int curr_count[MAX_CHARS] = { 0 };
//	for (int j = 0; j < n; j++) {
//		// Count occurrence of characters of string
//		curr_count[str[j]]++;
//
//		// If any distinct character matched,
//		// then increment count
//		if (curr_count[str[j]] == 1)
//			count++;
//
//		// if all the characters are matched
//		if (count == dist_count) {
//			// Try to minimize the window i.e., check if
//			// any character is occurring more no. of times
//			// than its occurrence in pattern, if yes
//			// then remove it from starting and also remove
//			// the useless characters.
//			while (curr_count[str[start]] > 1) {
//				if (curr_count[str[start]] > 1)
//					curr_count[str[start]]--;
//				start++;
//			}
//
//			// Update window size
//			int len_window = j - start + 1;
//			if (min_len > len_window) {
//				min_len = len_window;
//				start_index = start;
//			}
//		}
//	}
//
//	// Return substring starting from start_index
//	// and length min_len
//	return str.substr(start_index, min_len);
//}
//
void solve(){
	string s; cin >> s;
	map<char, int> mp;
	for(char x : s){
		mp[x]++;
	}
	int len = mp.size();//so luong ki tu khac nhau trong s;
	int ans = INT_MAX, left = 0, cnt = 0, index = -1;
	int dem[256] = {0};
	for(int i = 0; i < s.length(); i++){
		dem[s[i]]++;
		if(dem[s[i]] == 1) cnt++;
		if(cnt == len){
			while(dem[s[left]] > 1){
				dem[s[left]]--;
				left++;
			}
			ans = min(ans, i - left + 1);
			index = left;
		}
	}
	cout << ans  << endl;
//	cout << s.substr(index, ans);
}
// Driver code
int main()
{
	int t; cin >> t;
	while(t--){
//		string s; cin >> s;
//		cout << findSubString(s).length() << endl;
		solve();
	}
	return 0;
}
