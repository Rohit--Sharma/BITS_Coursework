#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

// The structure of the node for the A* algorithm
typedef struct node {
	int a, b, i, j, g, h;
} node;

// Comparator operation for priority queue
struct comparator
{
	bool operator()(const node& l, const node& r)
	{
		return (l.g + l.h) > (r.g + r.h);  			// Return the minimum of the two nodes based on the f cost (g + h)
	}
};

// Return if the node 'a' is goal node or not
bool isGoal (node a, int n)
{
	if (a.i == n-1 && a.j == n-1) {
		return true;
	}
	return false;
}

// Computes the heuristic
double computeHeuristic(struct node child, int n) {
	double h, i, j;
	if(child.a == 0 || child.a == 1) {
		i = n < (child.i + child.b) ? n : (child.i + child.b);
		j = n < (child.j + child.b) ? n : (child.j + child.b);
		i = n - i; j = n - j; child.j = n - child.j; child.i = n - child.i;
		h = min(sqrt(i * i + child.j * child.j), sqrt(child.i * child.i +  j * j)) / (n * n);
	}
	else if(child.a == -1) {
		i = 0 < (child.i - 1) ? 0 : child.i - 1;
		j = 0 < (child.j - 1) ? 0 : child.j - 1;
		i = n - i; j = n - j; child.j = n - child.j; child.i = n - child.i;
		h = min(sqrt(i * i + child.j * child.j), sqrt(child.i * child.i +  j * j)) / (n * n);
	}
	return h;
}

// The code for A* algorithm:
//		Input:  root node, grid
//		Output: minimum number of steps taken to reach the destination
int A_star_Search (node *start, int n, int **type, int **noSteps)
{
	// Initialization from line 37 to 60
	// A priority queue to store the frontier at any instant. The algorithm extracts the minimum f value node from this queue. (min-heap)
	priority_queue <node, vector <node>, comparator> frontier;
	
	// Initially the frontier is only the root node.
	frontier.push(*start);
	
	// A container to store the explored nodes.
	vector<node> exploredVector;
	
	// Two 2D arrays explored and open to quickly lookup the nodes which have been explored and which are in frontier at any instant
	bool **explored = new bool*[n], **open = new bool*[n];
	for (int i = 0; i < n; i += 1) {
		explored[i] = new bool[n];
		open[i] = new bool[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			explored[i][j] = false;
			open[i][j] = false;
		}
	}
	
	// First node is present in frontier set. Hence marking this node in the lookup array.
	open[0][0] = true;
	
	// The main algorithm:
	// Check if the frontier is empty
	while (!frontier.empty()) {
		// Extract the node with minimum 'f' from the min-heap (frontier)
		node top = frontier.top();
		frontier.pop();
		
		// If the extracted node is goal, return the 'g' value, which has the minimum number of steps.
		if (isGoal(top, n)) {
			return top.g;
		} else {				// Else explore the node's children
								// Generating children by computing all the reachable nodes from the current node (top)
			node *children = new node[4 * top.b];			// Maximum number of children for any position  of node is 4*b.
			int noChildren = 0;								// A variable to store the number of children of the node 'top'
			switch (top.a) {
					// Current node is of type '0'
				case 0: {
					for (int i = 0; i < top.b; i += 1) {
						if (top.i + i + 1 < n) {
							children[noChildren].a = type[top.i + i + 1][top.j];
							children[noChildren].b = noSteps[top.i + i + 1][top.j];
							children[noChildren].i = top.i + i + 1;
							children[noChildren].j = top.j;
							children[noChildren].g = top.g + 1;
							noChildren++;
						}
						if (top.i - i -1 >= 0) {
							children[noChildren].a = type[top.i - i - 1][top.j];
							children[noChildren].b = noSteps[top.i - i - 1][top.j];
							children[noChildren].i = top.i - 1 - i;
							children[noChildren].j = top.j;
							children[noChildren].g = top.g + 1;
							noChildren++;
						}
						if (top.j + i + 1 < n) {
							children[noChildren].a = type[top.i][top.j + i + 1];
							children[noChildren].b = noSteps[top.i][top.j + i + 1];
							children[noChildren].i = top.i;
							children[noChildren].j = top.j + 1 + i;
							children[noChildren].g = top.g + 1;
							noChildren++;
						}
						if (top.j - 1 - i >= 0) {
							children[noChildren].a = type[top.i][top.j - 1 - i];
							children[noChildren].b = noSteps[top.i][top.j - 1 - i];
							children[noChildren].i = top.i;
							children[noChildren].j = top.j - i - 1;
							children[noChildren].g = top.g + 1;
							noChildren++;
						}
					}
					break;
				}
					// Current node is a bridge
				case 1: {
					if (top.i + top.b < n) {
						children[noChildren].a = type[top.i + top.b][top.j];
						children[noChildren].b = noSteps[top.i + top.b][top.j];
						children[noChildren].i = top.i + top.b;
						children[noChildren].j = top.j;
						children[noChildren].g = top.g + 1;
						noChildren++;
					}
					if (top.j + top.b < n) {
						children[noChildren].a = type[top.i][top.j + top.b];
						children[noChildren].b = noSteps[top.i][top.j + top.b];
						children[noChildren].i = top.i;
						children[noChildren].j = top.j + top.b;
						children[noChildren].g = top.g + 1;
						noChildren++;
					}
					break;
				}
					// Current node is a tunnel
				case -1: {
					if (top.i - top.b >= 0) {
						children[noChildren].a = type[top.i - top.b][top.j];
						children[noChildren].b = noSteps[top.i - top.b][top.j];
						children[noChildren].i = top.i - top.b;
						children[noChildren].j = top.j;
						children[noChildren].g = top.g + 1;
						noChildren++;
					}
					if (top.j - top.b >= 0) {
						children[noChildren].a = type[top.i][top.j - top.b];
						children[noChildren].b = noSteps[top.i][top.j - top.b];
						children[noChildren].i = top.i;
						children[noChildren].j = top.j - top.b;
						children[noChildren].g = top.g + 1;
						noChildren++;
					}
					break;
				}
			}
			
			// For each child do the following:
			for (int i = 0; i < noChildren; i += 1) {
				// If the child is not in frontier and explored set, compute the heuristic and add the child to frontier queue.
				if (!open[children[i].i][children[i].j] && !explored[children[i].i][children[i].j]) {
					children[i].h = computeHeuristic(children[i], n);
					open[children[i].i][children[i].j] = true;
					frontier.push(children[i]);
				}
				// If the child is in frontier set, check if it can now be reached by a shorter path and if yes, then update the corresponding cost.
				else if (open[children[i].i][children[i].j]) {
					vector<node> tempaxcd;
					long fronSize = frontier.size();
					for (int k = 0; k < fronSize; k += 1) {
						node topMost = frontier.top();
						frontier.pop();
						if (topMost.i == children[i].i && topMost.j == children[i].j) {
							topMost.g = topMost.g < children[i].g ? topMost.g : children[i].g;
							tempaxcd.push_back(topMost);
							break;
						}
						tempaxcd.push_back(topMost);
					}
					for (int k = 0; k < tempaxcd.size(); k += 1) {
						frontier.push(tempaxcd[k]);
					}
				}
				// If the child is already explored, remove it from explored and add it in frontier.
				else if (explored[children[i].i][children[i].j] ) {
					for (int k = 0; k < exploredVector.size(); k += 1) {
						if (exploredVector[k].i == children[i].i && exploredVector[k].j == children[i].j && exploredVector[k].g > children[i].g) {
							exploredVector.erase(exploredVector.begin() + k);
							explored[children[i].i][children[i].j] = false;
							frontier.push(children[i]);
							open[children[i].i][children[i].j] = true;
							break;
						}
					}
				}
			}
			
		}
		// Mark the current node (top) as explored.
		explored[top.i][top.j] = true;
		exploredVector.push_back(top);
	}
	
	// If the frontier becomes empty and the destination is not reached then return -1 to indicate that the solution can't be found.
	return -1;
}

// The driver function for the program
int main (int argc, char const* argv[])
{
	// Read 'n', the size of the grid.
	int n; cin >> n;
	
	// Declaring two 2D arrays for storing the type of grid and no. of steps possible in each grid.
	int **type = new int*[n], **noSteps = new int*[n];
	for(int i = 0; i < n; i++) {
		type[i] = new int[n];
		noSteps[i] = new int[n];
	}
	
	// Fill the 2D arrays by reading the input
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1) {
			scanf("%d, %d", &type[i][j], &noSteps[i][j]);
		}
	}
	
	// Root node initialization to start the A* algorithm execution
	node *initialNode = new node();
	initialNode->a = type[0][0];	initialNode->b = noSteps[0][0];
	initialNode->i = 0;				initialNode->j = 0;
	initialNode->g = 1;				initialNode->h = 0;				// g = 1 initially because the cost to reach the (0, 0) position is 1.
	
	// Calling the A* algorithm and printing the minimum number of steps to reach the destination
	cout << A_star_Search(initialNode, n, type, noSteps) << endl;
	
	return 0;
}
