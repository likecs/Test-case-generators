// Below code is used to generate undirected graphs
//E ~ 2 * V but can be set accordingly

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int lim_n = 25;

vector<int> perm;
vector<int> adj[lim_n+1];
int visited[lim_n+1];
vector< pair<int,int> > graph;

//check whether the graph is connected or not
void check_graph(int n) {
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
			if (!visited[*it]) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	
	bool connected = true;
	for(int i=1; i<=n; ++i) {
		connected &= visited[i];
	}

	assert(connected);
}

void final_check_graph(int n, int m, int components) {
	memset(visited, false, sizeof(visited));
	for(int i=0; i<m; ++i) {
		int x = graph[i].first;
		int y = graph[i].second;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int check = 0;
	for(int i=1; i<=n; ++i) {
		if (visited[i]) {
			continue;
		}
		check += 1;
		queue<int> q;
		q.push(i);
		visited[i] = true;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(vector<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
				if (!visited[*it]) {
					visited[*it] = true;
					q.push(*it);
				}
			}
		}
	}
	printf("Comp = %d check = %d\n", components, check);
	// assert(check == components);
}

//Output is space separated vertices pairs which contain an edge
//There is extra line after every test case
void generate_unweighted_components(int start, int n, int m) {
	set< pair<int,int> > duplicates;

	//form spanning tree first
	for(int i=2; i<=n; ++i) {
		int x = i;
		int y = rand() % (i - 1) + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		assert (1 <= x <= n);
		assert (1 <= y <= n);
		assert (x != y);
		if (duplicates.find(make_pair(x, y)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		if (duplicates.find(make_pair(y, x)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		duplicates.insert(make_pair(x, y));
		adj[x].push_back(y);
		adj[y].push_back(x);
		graph.push_back(make_pair(x + start, y + start));
	}

	//add some extra edges
	for(int i=n; i<=m; ++i) {
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		if (i % 10 == 0) {
			swap(x, y);
		}
		assert (1 <= x <= n);
		assert (1 <= y <= n);
		while (x == y) {
			y = rand() % n + 1;
		}
		assert (x != y);
		if (duplicates.find(make_pair(x, y)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		if (duplicates.find(make_pair(y, x)) != duplicates.end()) {
			i -= 1;
			continue;
		}
		duplicates.insert(make_pair(x, y));
		adj[x].push_back(y);
		adj[y].push_back(x);
		graph.push_back(make_pair(x + start, y + start));
	}

	//check whether the graph made is connected or not
	check_graph(n);	

	for(int i=1; i<=n; ++i) {
		adj[i].clear();
	}
}

void permute_graph(int n, int m) {
	for(int i=0; i<m; ++i) {
		int x = graph[i].first;
		int y = graph[i].second;
		graph[i].first = perm[x-1];
		graph[i].second = perm[y-1];
	}
}

void print_graph(int n, int m) {
	random_shuffle(graph.begin(), graph.end());

	assert (graph.size() == m);
	for(int i=0; i<graph.size(); ++i) {
		printf("%d %d\n", graph[i].first, graph[i].second);
	}
	
	graph.clear();
	printf("\n");
}

void permute(int n) {
	for(int i=1; i<=n; ++i) {
		perm.push_back(i);
	}

	random_shuffle(perm.begin(), perm.end());
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
		
		permute(n);

		//store component sizes
		int components = 10;
		int sum_n = 0;
		int sum_m = 0;
		//generate number of vertices and edges in each component
		vector< pair<int,int> > comp;
		for(int i=1; i<=components; ++i) {
			int x = (rand() % n + 1) / (components);
			comp.push_back(make_pair(x, 0));
			sum_n += x;
		}
		if (sum_n < n) {
			int left = n - sum_n;
			for(int i=1; i<components; ++i) {
				int x = rand() % left + 1;
				left -= x;
				comp[i-1].first += x;
				if (left == 0) {
					break;
				}
			}
			if (left) {
				comp.back().first += left;
			}
		}
		for(int i=1; i<=components; ++i) {
			comp[i-1].second = comp[i-1].first;
			sum_m += comp[i-1].second;
		}

		int m = rand() % lim_n + 1 + n + n;
		
		if (sum_m < m) {
			int left = m - sum_m;
			for(int i=1; i<components; ++i) {
				int x = rand() % left + 1;
				left -= x;
				comp[i-1].second += x;
				int u = comp[i-1].second;
				int v = comp[i-1].first;
				if (u > ((v*(v-1))/2)) {
					comp[i-1].second = (v * (v-1)) / 2;
					left += u - (v*(v-1))/2;
				}
				if (left == 0) {
					break;
				}
			}
			if (left) {
				comp.back().second += left;
				int u = comp.back().second;
				int v = comp.back().first;
				if (u > ((v*(v-1))/2)) {
					comp.back().second = (v * (v-1)) / 2;
				}
			}
		}

		sum_n = 0;
		sum_m = 0;
		for(int i=1; i<=components; ++i) {
			sum_n += comp[i-1].first;
			sum_m += comp[i-1].second;
			if (comp[i-1].first > 2) {
				assert(comp[i-1].first <= comp[i-1].second);
			}
		}

		assert(sum_n == n);
		m = sum_m;

		printf("%d %d\n", n, m);

		vector< pair<int,int> > temp;
		for(int i=1; i<=components; ++i) {
			if (comp[i-1].first > 0) {
				temp.push_back(make_pair(comp[i-1].first, comp[i-1].second));
			}
		}
		comp.clear();
		components = (int)temp.size();

		int start = 1;
		for(int i=1; i<=components; ++i) {
			generate_unweighted_components(start, temp[i-1].first, temp[i-1].second);
			start += temp[i-1].first;
		}
		
		// permute_graph(n, m);

		final_check_graph(n, m, components);

		print_graph(n, m);
	}

	return 0;
}