problem link: https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-04/challenges
Problem name:Same Component
Problem Statement:
You will be given a 2D matrix of size  which will contain only dot() and minus() where dot() means you can go in that cell and minus() means you can't.
You can move in only 4 directions (Up, Down, Left and Right).
You will be given the indexes of two cells - (,) and (,). You need to tell if these  and  cells are in the same component or not. Same component means you can go from  to .

Input Format:
First line will contain  and .
Next you will be given the 2D matrix.
Next line will contain  and .
Last line will contain  and .

Output Format:
Output "YES" if those cell are in the same component, "NO" otherwise.
Sample Input 0

5 4
..-.
---.
..-.
--..
....
0 1
3 2
Sample Output 0
NO
Sample Input 1

5 4
....
---.
..-.
--..
....
0 1
3 2
Sample Output 1
YES


Solution:
///   ***   ---   |||         In the name of ALLAH        |||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
#define input(v) for(auto &x: v)cin>>x
#define SetBit(x,k) (x|=(1LL<<k))
#define ClearBit(x,k) (x&=~(1LL<<k))
#define CheckBit(x,k) ((x>>k)&1)
#define ChangeBit(x,k) (x^=(1LL<<k))
#define mod 1000000007
#define N 100005

// Directions: right, left, down, up
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
char grid[1005][1005];
bool visit[1005][1005];

// Checks if a position is within bounds and valid to visit
bool is_valid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    return grid[x][y] == '.'; // Only accessible if it's a dot (.)
}

// Depth-First Search (DFS) to explore the grid
void dfs(int x, int y) {
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (is_valid(newX, newY) && !visit[newX][newY]) {
            dfs(newX, newY);
        }
    }
}

int main() {
    optimize();

    // Input the grid dimensions
    cin >> n >> m;
    // Input the grid itself
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int a, b, c, d;
    // Starting cell (a, b)
    cin >> a >> b;
    // Destination cell (c, d)
    cin >> c >> d;

    // Perform DFS from the starting cell
    dfs(a, b);

    // Check if the destination cell was visited
    if (visit[c][d]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
