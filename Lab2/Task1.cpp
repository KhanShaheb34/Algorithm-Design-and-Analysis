#include<bits/stdc++.h>
using namespace std;

int m = 100003;
unsigned long long p = 1000081, q = 642791, r = 843883;

unsigned long long radix(string query, int mod) {
    unsigned long long rad = 0;
    for(unsigned long long i = 1; query != ""; i *= 128) {
        rad += i * (int)query[query.size()-1];
		if(query.size() == 1) break;
        query = query.substr(0, query.size()-1);
    }
	return rad;
}

int hashify(unsigned long long rad) {
	unsigned long long a, b, hash;
	a = rad % q + 1;
	b = rad % r;
	hash = ((a*rad + b) % p) % m;
	return (int) hash;
}

int main() {
    string query;
	string hash[m];

    while(cin >> query && query != "done") {
		unsigned long long rad = radix(query, 100003);
		cout << rad << endl;
		int x = hashify(rad);
		cout << x << endl;
  	}

	return 0;
}

