#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define dim 4

#define MAXSTEP 50

int manhattan[dim*dim][dim*dim];
typedef vector<int>  TILE;
const int LEFT= -1;
const int RIGHT=1;
const int UP= -dim-1;
const int DOWN= dim+1;

void pre(){
    for (int i = 0; i < dim*dim; i++)
        for (int j = 0; j < dim*dim; j++){
            manhattan[i][j] = abs(i / dim - j / dim) +abs(i % dim - j % dim);
        }
}

bool solvable(TILE tiles){
    int sum = 0, row;
    for (int i = 0; i < tiles.size(); i++)
    {
        int tile = tiles[i];
        if (tile == 0){
            row = (i / dim + 1);
            continue;
        }

        for (int m = i; m < tiles.size(); m++)
            if (tiles[m] < tile && tiles[m] != 0)
                sum++;
    }

    return !((sum + row) % 2);
}

void solveAStar(){

}

int main(){

    pre();

    int kase,tmp;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){
        TILE initial;
        for (int i=0;i<dim*dim;++i){
            scanf("%d",&tmp);
            initial.push_back(tmp);
        }
        printf("Case %d: ",kk);
        if ( solvable(initial) ){
            solveAStar();
        }else{
            printf("This puzzle is not solvable.\n");
        }

    }

}
