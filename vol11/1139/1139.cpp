#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;
/*
void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }
*/

struct NODE{
    int words;
    int prefix;

    NODE* edge[10];
    NODE(){
        words = 0;
        prefix = 0;
        for (int i=0;i<10;++i){
            edge[i]=NULL;
        }
    }
    ~NODE(){
        for (int i=0;i<10;++i){
            if ( edge[i]!=NULL ){
                delete edge[i];
            }
        }
    }
}*root;

void add(NODE *v,char* word,int dep,int b){
    if ( dep == 9 ){
        v->words= max( v->words,b );
    }else{
        v->prefix++;
        if ( v->edge[ word[0] ]== NULL ){
            v->edge[ word[0] ]=new NODE();
        }
        add(v->edge[ word[0] ],word+1,dep+1,b);
    }
}

bool find_trie(NODE *v,char* word,int dep,int b){
    //show( char(word[0]+'0') );
    if ( dep == 9 ){
        return v->words >= b;
    }else{
        if ( v->prefix ==0 )return false;

        if ( v->edge[ word[0] ]== NULL ){
            return false;
        }
        return find_trie(v->edge[ word[0] ],word+1,dep+1,b);
    }
}


struct node{
    char str[3][3];
    int h;
    int x,y;
}goal;



int dx[]={-1,0,1,0};
int dy[]={ 0,-1,0,1};

int get_next( node & v,int g,int bound ){

    int f = v.h/2+g;
    if ( f>bound )return f;

    if ( v.h == 0 )return 0;

    int min_move= (1<<29);

    add( root,&v.str[0][0],0,bound );

    for (int i=0;i<4;++i){
        int xx= v.x+dx[i];
        int yy= v.y+dy[i];
        if ( xx>=0 && xx<3 && yy>=0 && yy<3 ){
            node tmp = v;
            tmp.h += tmp.str[tmp.x][tmp.y]== goal.str[tmp.x][tmp.y];
            tmp.h += tmp.str[xx][yy]== goal.str[xx][yy];

            tmp.h -= tmp.str[tmp.x][tmp.y]== goal.str[xx][yy];
            tmp.h -= tmp.str[xx][yy]== goal.str[tmp.x][tmp.y];

            swap( tmp.str[xx][yy],tmp.str[tmp.x][tmp.y] );

            tmp.x = xx;
            tmp.y = yy;

            if ( find_trie( root,&tmp.str[0][0],0,bound ) )continue;


            min_move= min( min_move, get_next( tmp , 1+g,bound ) );
        }
    }
    return min_move;
}

int ida( node &start ){

    int bound = start.h/2;
    while ( true ){
        int t = get_next( start,0,bound );
        if ( t  == 0 )return bound;
        else if ( t > 18 )return -1;
        bound = t;
    }

}

int main(){

    FRO

    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            goal.str[i][j] = ( i*3+j+1 )%9;
        }
    }

    int kase;
    scanf("%d",&kase);

    root = new NODE();

    for (int kk=1;kase--;++kk){
        node tar;

        int tmp;
        tar.h = 0;
        for (int i=0;i<3;++i){
            for (int j=0;j<3;++j){
                scanf("%d",&tmp);
                tar.str[i][j] = tmp;
                tar.h += ( tar.str[i][j] != goal.str[i][j] );
                if ( tmp == 0 ){
                    tar.x = i;
                    tar.y = j;
                }
            }
        }

        //show( tar.x,tar.y,tar.h );



        int ans = ida( tar );
        printf("Case %d: ",kk);
        if ( ans == -1 )printf("impossible\n");
        else printf("%d\n",ans);

        if ( kase%30 == 0 ){
            delete root;
            root = new NODE();
        }

    }


    return 0;
}
