/*
 * https://github.com/luciocf/Problems/blob/master/POI/POI%202005/banknotes.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int N , K ; 
int Val [209] , Num [209] , Ans [209] , Dp [209][20009] ;
//
deque < pi > DQ [20009] ;
int Already [20009] , R [20009] , L [20009] ;
int Sz ( int Id ) {
	return R [Id] - L [Id] ;
}
int Mn ( int Id ) {
	return ( DQ [Id].size() ? DQ [Id][0] .fi + Already [Id] : 1e9 ) ; 
}
void In ( int Id , int X ) {
	while ( DQ [Id] .size() && X < DQ [Id] .back () .fi + Already [Id] ) DQ [Id] .ppb () ;
	DQ [Id] .pb ( { X - Already [Id] , R [Id] } ) ;
	R [Id] ++ ;
}
void Out ( int Id ) {
	if ( DQ [Id] .size() && DQ [Id] .front() .se == L [Id] ) DQ [Id] .pop_front () ;
	L [Id] ++ ;
}
void Clear ( int Id ) {
	DQ [Id] .clear () ;
	L [Id] = R [Id] = Already [Id] = 0 ;
}
int main () {
	cin >> N ;
	for ( int i = 1 ; i <= N ; i ++ ) scanf("%d",&Val[i]) ;
	for ( int i = 1 ; i <= N ; i ++ ) scanf("%d",&Num[i]) ;
	cin >> K ; 
	for ( int i = 0 ; i <= N ; i ++ ) {
		for ( int j = 1 ; j <= K ; j ++ ) {
			Dp [i][j] = 1e9 ; 
		}
	}
	for ( int i = 1 ; i <= N ; i ++ ) {
		for ( int j = 0 ; j < Val [i] ; j ++ ) Clear ( j ) ;
		for ( int j = 0 ; j <= K ; j ++ ) {
			int It = j % Val [i] ; 
			if ( Sz ( It ) > Num [i] ) Out ( It ) ;
			Already [It] ++ ;
			In ( It , Dp [i-1][j] ) ;
			Dp [i][j] = Mn ( It ) ;
		}
	}
	printf("%d\n",Dp [N][K]) ;
	int Goal = K ; 
	for ( int i = N ; i >= 2 ; i -- ) {
		for ( int j = 0 ; j <= Num [i] ; j ++ ) {
			int Last = Goal - j * Val [i] ;
			if ( Last >= 0 && Dp [i-1][Last] + j == Dp [i][Goal] ) {
				Goal = Last ;
				Ans [i] = j ;
				break ; 
			}
		}
	}
	Ans [1] = Goal / Val [1] ;
	for ( int i = 1 ; i <= N ; i ++ ) printf("%d ",Ans[i]) ;
	cout << endl ; 
}
