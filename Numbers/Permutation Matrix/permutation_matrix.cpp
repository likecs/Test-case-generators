//Below code is used to generate matrix filled with permutation of from 1 to size of matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 10;
const int lim_m = 10;

//Output is space separated numbers 
void generate_permutation_array(int n, int m) {
	int limit = n*m;

	vector<int> perm(limit);

	for(int i=0; i<limit; ++i) {
		perm[i] = i+1;
	}
	
	random_shuffle(perm.begin(), perm.end());

	int counter = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j) {
			printf("%d ", perm[counter]);
			counter += 1;
		}
		printf("\n");
	}

	vector<int> mark(limit);

	for(int i=0; i<limit; ++i) {
		mark[perm[i] - 1] = 1;
	}

	bool all_marked = true;

	for(int i=0; i<limit; ++i) {
		all_marked &= mark[i];
	}

	assert(all_marked);
	assert(perm.size() == limit && counter == limit);
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
		//get random value of "m" between (1, lim_m)
		int m = rand() % lim_m + 1;
		//Comment below line if not needed
		printf("%d %d\n", n, m);
	
		//set the limits of the range array elements
		generate_permutation_array(n, m);
	}
	
	return 0;
}