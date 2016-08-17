//Below code is used to generate strings from the particular characters set by user in "user" string

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 100;

//Output is space separated numbers 
void generate_strings(int n, string user) {
	int mod = user.length();

	for(int i=1; i<=n; ++i) {
		int number = rand() % mod;
		assert(number >= 0 && number < mod);
		char ch = user[number];
		printf("%c", ch);
	}
	printf("\n");
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "w", stdout);
	#endif
	srand(unsigned(time(0)));

	int test_cases = 2;
	//Comment below line if not needed
	printf("%d\n", test_cases);
	
	for(int t=1; t<=test_cases; ++t) {
	
		//get random value of "n" between (1, lim_n)
		int n = rand() % lim_n + 1;
		//Comment below line if not needed
		printf("%d\n", n);
	
		//for generating strings of only charcters wanted by user
		/* 
			NOTE: Make sure you enter valid characters only. Espace sequences should be followed after "\" only.
			For example: In string below "\\" denotes "\" as it is escape sequence.
		*/
		string user = "[]\\/()-+*.";
		generate_strings(n, user);
	}

	return 0;
}