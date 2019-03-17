#include <bits/stdc++.h>
using namespace std;

int users, items;
vector < vector <int> > matrix;
vector <double> avg;
vector <double> sim;
vector < vector <int> > adj;
vector < pair <double, int> > res;

/*
	compute similarity between two users
	using pearson correlation
	
	          			sigma((r_a,p - ra_avg) * (r_b,p - rb_avg))
	sim(a, b) = -------------------------------------------------------------
				sqrt(sigma(r_a,p - ra_avg)^2) * sqrt(sigma(r_b,p - rb_avg)^2)
*/

double similarity(int a, int b) {
	double num = 0, dena = 0, denb = 0;
	for (int j = 1; j <= items; j++) {
		if (matrix[a][j] && matrix[b][j]) {
			double x = matrix[a][j] - avg[a];
			double y = matrix[b][j] - avg[b];
			num += x * y;
			dena += x * x;
			denb += y * y;
		}
	}
	return num / sqrt((dena * denb));
}

// computes the similarity of all users with query user
void preprocess(int uid) {
	for (int i = 1; i <= users; i++) {
		if (i == uid) continue;
		sim[i] = similarity(i, uid);
	}
}

// function to give the top recommendations to the user
void recommend(int uid) {
	int top;
	cin >> top;
	for (int i = 0; i < top; i++) {
		cout << uid << ' ' << res[i].second << ' ' << res[i].first << '\n';
	}
	cout << endl;
}

/*
	calculate the expected ratings for movies
	
    					  sigma((sim(a, b) * (r_b,p - rb_avg))
	pred(a, p) = ra_avg + ------------------------------------
									sigma((sim(a, b))
*/

void calculate(int uid) {
	res.clear();
	for (int j = 1; j <= items; j++) {
		if (adj[j].size() == 0) continue;
		double num = 0, den = 0;
		for (int i = 0; i < adj[j].size(); i++) {
			int k = adj[j][i];
			double x = sim[k];
			num += x * (matrix[k][j] - avg[k]);
			den += abs(x);
		}
		double rating = avg[uid] + num / den;
		res.push_back(make_pair(rating, j));
	}
	
	// sort the ratings in decreasing order
	sort(res.rbegin(), res.rend());
	recommend(uid);
}

void query() {
	
	// run indefinitely
	while (true) {
		int uid;
		cin >> uid;
		if (uid == -1) break;
		assert(uid >= 1 && uid <= users);
		sim.resize(users + 1);
		adj.resize(items + 1);
		preprocess(uid);
		
		// store for every movie j, a list of
		// ids of users who have already rated j
		for (int j = 1; j <= items; j++) {
			for (int i = 1; i <= users; i++) {
				if (matrix[i][j] && matrix[uid][j] == 0) {
					adj[j].push_back(i);
				}
			}
		}
		calculate(uid);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> users >> items;
	matrix.resize(users + 1);
	avg.resize(users + 1);
	for (int i = 1; i <= users; i++) {
		matrix[i].resize(items + 1);
	}
	for (int i = 1; i <= users; i++) {
		int count = 0, sum = 0;
		for (int j = 1; j <= items; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j]) count++;
			sum += matrix[i][j];
		}
		if (count == 0) continue;
		avg[i] = 1.0 * sum / count;
	}
	query();
	return 0;
}

