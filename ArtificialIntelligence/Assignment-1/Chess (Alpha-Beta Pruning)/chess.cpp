#include <bits/stdc++.h>
using namespace std;

const int MAX = 12;
const int MAXDEPTH = 6;
const int INF = 123456789;


/* attributes of a piece */
struct Piece {
	int x, y;
	int moved;
	bool alive;
} White[MAX], Black[MAX];

int N;
char Board[MAX][MAX];
bool Captured[MAX][MAX];

/* function to print the current board state */
void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << Board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

/* function to initialize the board and piece attributes */
void init() {
	memset(Board, 0, sizeof(Board));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1) Board[i][j] = 'B';
			else if (i == N) Board[i][j] = 'W';
			else Board[i][j] = '.';
		}
	}
	for (int i = 1; i <= N; i++) {
		White[i].x = N;
		Black[i].x = 1;
		White[i].y = Black[i].y = i;
		White[i].moved = Black[i].moved = 0;
		White[i].alive = Black[i].alive = true;
	}
}

/* function to test validity of user's move */
bool test(int si, int sj, int ei, int ej) {
	if (ei != si + 1) return false;
	if (Board[si][sj] != 'B') return false;
	if (abs(sj - ej) == 1 && Board[ei][ej] == 'W') return true;
	if (sj == ej && Board[ei][ej] == '.') return true;
	return false;
}

/* function to test upward next move */
bool forward(int x, int y) {
	return Board[x - 1][y] == '.';
}

/* function to test downward next move */
bool backward(int x, int y) {
	return Board[x + 1][y] == '.';
}

void draw() {
	cout << "Game Draw!" << endl;
	exit(0);
}

void win(string s) {
	cout << s << " wins! :D" << endl;
	print();
	exit(0);
}

/* function to calculate number of black pieces that can be captured */
int captures() {
	int res = 0;
	memset(Captured, false, sizeof(Captured));
	for (int i = 1; i <= N; i++) {
		if (!White[i].alive) continue;
		int x = White[i].x;
		int y = White[i].y;
		if (Board[x - 1][y - 1] == 'B' && !Captured[x - 1][y - 1]) {
			res++; Captured[x - 1][y - 1] = true;
		}
		if (Board[x - 1][y + 1] == 'B' && !Captured[x - 1][y + 1]) {
			res++; Captured[x - 1][y + 1] = true;
		}
	}
	return res;
}

/* function to calculate number of white pieces that are vulnerable */
int deaths() {
	int res = 0;
	memset(Captured, false, sizeof(Captured));
	for (int i = 1; i <= N; i++) {
		if (!Black[i].alive) continue;
		int x = Black[i].x;
		int y = Black[i].y;
		if (Board[x + 1][y - 1] == 'W' && !Captured[x + 1][y - 1]) {
			res++; Captured[x + 1][y - 1] = true;
		}
		if (Board[x + 1][y + 1] == 'W' && !Captured[x + 1][y + 1]) {
			res++; Captured[x + 1][y + 1] = true;
		}
	}
	return res;
}

/* function to return utility value of a board state */
int utility(bool comp) {
	int res = 0;
	
	/* if current move is of computer */
	if (comp) {
		for (int i = 1; i <= N; i++) {
			if (White[i].alive) {
				res += White[i].moved;
				int x = White[i].x;
				int y = White[i].y;
				if (forward(x, y)) res++;
				
				/* max reward for win state of computer */
				if (x == 1) return 1000;
			}
			if (Black[i].alive) {
				res -= Black[i].moved;
				int x = Black[i].x;
				int y = Black[i].y;
				if (backward(x, y)) res--;
			}
		}
		/* reward captures and penalize deaths */
		res += 4 * captures();
		res -= 2 * deaths();
	} else {
	
		/* current move is human's */
		for (int i = 1; i <= N; i++) {
			if (Black[i].alive) {
				res += Black[i].moved;
				int x = Black[i].x;
				int y = Black[i].y;
				if (backward(x, y)) res++;
				
				/* max penalty for lose state of computer */
				if (x == N) return -1000;
			}
			if (White[i].alive) {
				res -= White[i].moved;
				int x = White[i].x;
				int y = White[i].y;
				if (forward(x, y)) res--;
			}
		}
		
		/* reward deaths and penalize captures */
		res += 2 * deaths();
		res -= 4 * captures();
	}
	return res;
}

/* function to ask the user for a move */
void prompt() {
	l:
	cout << "Please make a move: ";
	int si, sj, ei, ej;
	cin >> si >> sj >> ei >> ej;
	if (!test(si, sj, ei, ej)) {
		cout << "Invalid Move!\n";
		goto l;
	}
	Board[si][sj] = '.';
	for (int i = 1; i <= N; i++) {
		if (Black[i].alive && Black[i].x == si && Black[i].y == sj) {
			Black[i].x = ei;
			Black[i].y = ej;
			Black[i].moved++;
			break;
		}
	}
	if (Board[ei][ej] == 'W') {
		for (int i = 1; i <= N; i++) {
			if (White[i].alive && White[i].x == ei && White[i].y == ej) {
				White[i].alive = false;
				break;
			}
		}
	}
	Board[ei][ej] = 'B';
}

/* function to test if further move is possible for computer */
bool possibleWhite() {
	for (int i = 1; i <= N; i++) {
		if (!White[i].alive) continue;
		int x = White[i].x;
		int y = White[i].y;
		if (Board[x - 1][y - 1] == 'B') return true;
		if (Board[x - 1][y] == '.') return true;
		if (Board[x - 1][y + 1] == 'B') return true;
	}
	return false;
}

/* function to test if further move is possible for human */
bool possibleBlack() {
	for (int i = 1; i <= N; i++) {
		if (!Black[i].alive) continue;
		int x = Black[i].x;
		int y = Black[i].y;
		if (Board[x + 1][y - 1] == 'W') return true;
		if (Board[x + 1][y] == '.') return true;
		if (Board[x + 1][y + 1] == 'W') return true;
	}
	return false;
}

/* function to generate possible moves and choose the best move */
int playUtil(int depth) {
	
	/* end of recursion */
	if (depth == MAXDEPTH) return utility(true);
	
	/* human's move */
	if (depth & 1) {
		
		/* stop if computer has already won */
		for (int i = 1; i <= N; i++) {
			if (White[i].x == 1) return 1000;
		}
		
		int id = -1, worst = INF, bestx = -1, besty = -1;
		for (int i = 1; i <= N; i++) {
			if (!Black[i].alive) continue;
			int x = Black[i].x;
			int y = Black[i].y;
			for (int j = -1; j <= 1; j++) {
				int tox = x + 1;
				int toy = y + j;
				
				/* forward move with no kill */
				if (j == 0) {
					if (Board[tox][toy] == '.') {
						Board[x][y] = '.';
						Board[tox][toy] = 'B';
						Black[i].moved++;
						Black[i].x = tox;
						Black[i].y = toy;
						//print();
						
						/* recur for children and choose the minimum value */
						int res = playUtil(depth + 1);
						if (res < worst && res != -INF) {
							worst = res;
							id = i;
							bestx = tox;
							besty = toy;
						}
						Board[x][y] = 'B';
						Board[tox][toy] = '.';
						Black[i].moved--;
						Black[i].x = x;
						Black[i].y = y;
					}
				} else {
					
					/* forward move with kill */
					if (Board[tox][toy] == 'W') {
						int idw;
						for (int k = 1; k <= N; k++) {
							if (White[k].alive && White[k].x == tox && White[k].y == toy) {
								idw = k;
								break;
							}
						}
						Board[x][y] = '.';
						Board[tox][toy] = 'B';
						White[idw].alive = false;
						Black[i].moved++;
						Black[i].x = tox;
						Black[i].y = toy;
						//print();
						
						/* recur for children and choose the minimum value */
						int res = playUtil(depth + 1);
						if (res < worst && res != -INF) {
							worst = res;
							id = i;
							bestx = tox;
							besty = toy;
						}
						Board[x][y] = 'B';
						Board[tox][toy] = 'W';
						White[idw].alive = true;
						Black[i].moved--;
						Black[i].x = x;
						Black[i].y = y;
					}
				}
			}
		}
		//cout << worst << endl;
		return worst;
	} else {
	
		/* computer's move */
	
		/* stop if human has already won */
		for (int i = 1; i <= N; i++) {
			if (Black[i].x == N) return -1000;
		}
		
		int id = -1, best = -INF, bestx = -1, besty = -1;
		for (int i = 1; i <= N; i++) {
			if (!White[i].alive) continue;
			int x = White[i].x;
			int y = White[i].y;
			for (int j = -1; j <= 1; j++) {
				int tox = x - 1;
				int toy = y + j;
				if (j == 0) {
					if (Board[tox][toy] == '.') {
						Board[x][y] = '.';
						Board[tox][toy] = 'W';
						White[i].moved++;
						White[i].x = tox;
						White[i].y = toy;
						//print();
						
						/* recur for children and choose the maximum value */
						int res = playUtil(depth + 1);
						if (res > best && res != INF) {
							//cout << "Best Move: " << res << " " << i << endl;
							//cout << tox << ' ' << toy << endl;
							best = res;
							id = i;
							bestx = tox;
							besty = toy;
						}
						Board[x][y] = 'W';
						Board[tox][toy] = '.';
						White[i].moved--;
						White[i].x = x;
						White[i].y = y;
					}
				} else {
					if (Board[tox][toy] == 'B') {
						int idb;
						for (int k = 1; k <= N; k++) {
							if (Black[k].alive && Black[k].x == tox && Black[k].y == toy) {
								idb = k;
								break;
							}
						}
						Board[x][y] = '.';
						Board[tox][toy] = 'W';
						Black[idb].alive = false;
						White[i].moved++;
						White[i].x = tox;
						White[i].y = toy;
						//print();
						
						/* recur for children and choose the maximum value */
						int res = playUtil(depth + 1);
						if (res > best && res != INF) {
							//cout << "Best Move: " << res << " " << i << endl;
							//cout << tox << ' ' << toy << endl;
							best = res;
							id = i;
							bestx = tox;
							besty = toy;
						}
						Board[x][y] = 'W';
						Board[tox][toy] = 'B';
						Black[idb].alive = true;
						White[i].moved--;
						White[i].x = x;
						White[i].y = y;
					}
				}
			}
		}
		
		/* after generating all possible moves make the best found move */
		if (depth == 0) {
		
			/* game draw or lost */
			if (best == -INF) {
				bool alldead = true;
				for (int i = 1; i <= N; i++) {
					if (White[i].alive) {
						alldead = false;
						break;
					}
				}
				if (alldead) win("Black");
				else draw();
			} else {
			
				/* make a move */
				int x = White[id].x;
				int y = White[id].y;
				//cout << id << ' ' << x << ' ' << y << endl;
				Board[x][y] = '.';
				int idb;
				if (Board[bestx][besty] == 'B') {
					for (int i = 1; i <= N; i++) {
						if (Black[i].alive && Black[i].x == bestx && Black[i].y == besty) {
							idb = i;
							Black[i].alive = false;
							break;
						}
					}
				}
				Board[bestx][besty] = 'W';
				White[id].moved++;
				White[id].x = bestx;
				White[id].y = besty;
			}
		}
		//cout << best << endl;
		return best;
	}
}

/* function to start the game and continue until the result is known */
void play() {
	while (true) {
		
		/* draw the game if no white move is possible */
		if (!possibleWhite()) draw();
		playUtil(0);
		cout << "After Computer's Move:" << endl;
		print();
		
		/* white wins */
		for (int i = 1; i <= N; i++) {
			if (White[i].x == 1) win("White");
		}
		
		/* draw the game if no black move is possible */
		if (!possibleBlack()) draw();
		prompt();
		cout << "After Your Move:" << endl;
		print();
		
		/* black wins */
		for (int i = 1; i <= N; i++) {
			if (Black[i].x == N) win("Black");
		}
	}
}

int main() {
	cout << "Enter Board Size (Max: " << MAX - 2 << "): ";
	cin >> N;
	assert(N > 1 && N < MAX - 1);
	init();
	print();
	play();
	return 0;
}

