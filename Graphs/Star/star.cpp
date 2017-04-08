//Below code is used to generate undirected star graph

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 100005;

//Output is space separated vertices pairs which contain an edge
//There is extra line after every test case
void generate_unweighted_star(int n) {
	int node = rand() % n + 1;

	vector< pair<int,int> > graph;
	for(int i=1; i<=n; ++i) {
		if (i == node) {
			continue;
		}
		int x = node;
		int y = i;
		if (rand() % 3 == 0) {
			swap(x, y);
		}
		graph.push_back(make_pair(x, y));
	}

	random_shuffle(graph.begin(), graph.end());

	for(int i=0; i<n-1; ++i) {
		printf("%d %d\n", graph[i].first, graph[i].second);
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
		printf("%d\n", n);
	
		generate_unweighted_star(n);
	}

	return 0;
}