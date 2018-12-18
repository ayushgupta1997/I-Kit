#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define rep(i, a, b)             for(int i = a; i < b; i++)
#define REP(i, a, b)             for(int i = a; i <= b; i++)
#define sc(n)                    scanf("%d",&n)
#define sc2(a,b)                 scanf("%d%d", &a, &b) 
#define pb                       push_back
#define ff                       first
#define ss                       second
//#define mp                       make_pair
#define mt                       make_tuple
#define SET(a, b)                memset(a,b,sizeof(a)) 
#define all(v)                   (v).begin(),(v).end()
#define rall(v)                  (v).rbegin(),(v),rend()
#define MAX 200005
#define MOD 1000000007

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef double ld;
map<int,string> mp;

 
 
  
void printOnes(int n) {
    cout << mp[n] << endl;
}

void  printTens(int n) {
    int unit = n%10;
    int tens = (n/10)%10;
    if(mp.find(n)!=mp.end()) {
        cout << mp[n] << endl;
    }
    else {
        cout << mp[tens*10] << " " << mp[unit] << endl;
    }
    
}

void printHundred(int n) {
    if(n==100) {
        cout << mp[100] << endl;
        return;
    }
    int hun = n/100;
    cout << mp[hun] <<" hundred";
    int ten = (n/10)%10;
    int unit = n%10;
    if(mp.find(10*ten+unit)!=mp.end()) {
        cout <<" and "<< mp[10*ten+unit] << endl;
        return;
    }
    if(mp.find(10*ten)!=mp.end())
    cout << " and "<<mp[ten*10];
    if(mp.find(unit)!=mp.end())
    cout <<" " <<mp[unit] ;
    cout << endl;
    
    
    
}

void printThousand(int n) {
    
    int thou = n/1000;
    cout << mp[thou] << " thousand ";
    int hun = (n/100)%10;
    if(hun) {
        cout << mp[hun] << " hundred";
    }
    int tens = (n/10)%10;
    if(tens) {
        cout << " and ";
        cout << mp[10*tens];
        int unit = n%10;
        if(unit) {cout << " ";
            cout << mp[unit];
        }
       
        
    }
    else if(!tens&&(n%10)){
        cout << " and ";
        int unit = n%10;
        cout << mp[unit];
    }
     cout << endl;
    
}

int main() {
    int t,n;
    mp[1]="one";
    mp[2]="two";
    mp[3]="three";
    mp[4]="four";
    mp[5]="five";
    mp[6]="six";
    mp[7]="seven";
    mp[8]="eight";
    mp[9]="nine";
    mp[10]="ten";
    mp[11]="eleven";
    mp[12]="twelve";
    mp[13]="thirteen";
    mp[14]="fourteen";
    mp[15]="fifteen";
    mp[16]="sixteen";
    mp[17]="seventeen";
    mp[18]="eighteen";
    mp[19]="nineteen";
    mp[20]="twenty";
    mp[30]="thirty";
    mp[40]="forty";
    mp[50]="fifty";
    mp[60]="sixty";
    mp[70]="seventy";
    mp[80]="eighty";
    mp[90]="ninety";
    mp[100]="hundred";
    mp[1000]="thousand";
    
      cin >> t;
    
    while(t--) {
        cin >> n;
        int num=n;
        int cnt=0;
        while(num!=0) {
            num/=10;
            cnt++;
        }
        if(cnt == 4) {
            printThousand(n);
        }
        else if(cnt == 3) {
           printHundred(n);
        }
        else if(cnt == 2) {
           printTens(n);
        }
        else {
            printOnes(n);
        }
        
    }

return 0;
}
