#include<bits/stdc++.h>
using namespace std;

int hashify(string query, int mod) {
        unsigned long long rad = 0;
        for(unsigned long long i = 1; query != ""; i *= 128) {
                rad += i * (int)query[query.size()-1];
		if(query.size() == 1) break;
                query = query.substr(0, query.size()-1);
        }
	return rad % mod;
}

int main() {
        string query;
	string hash[100003];
	int count = 0;
        while(cin >> query && query != "done") {
                int x = hashify(query, 100003);
		if (hash[x] != query) {
			hash[x] = query;
			count++;
		}
        }

	cout << "Total words: " << count << endl;
	return 0;
}

