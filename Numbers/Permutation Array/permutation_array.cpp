//Below code is used to generate array filled with permutation of from 1 to size of array

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 10;

//Output is space separated numbers 
void generate_permutation_array(int n) {
	vector<int> perm(n);

	for(int i=0; i<n; ++i) {
		perm[i] = i+1;
	}
	
	random_shuffle(perm.begin(), perm.end());

	for(int i=0; i<n; ++i) {
		printf("%d ", perm[i]);
	}
	printf("\n");
	
	vector<int> mark(n);

	for(int i=0; i<n; ++i) {
		mark[perm[i] - 1] = 1;
	}

	bool all_marked = true;

	for(int i=0; i<n; ++i) {
		all_marked &= mark[i];
	}

	assert(all_marked);
	assert(perm.size() == n);
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
	
		//set the limits of the range array elements
		generate_permutation_array(n);
	}
	
	return 0;
}