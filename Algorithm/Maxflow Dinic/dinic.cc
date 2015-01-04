#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX 1000

struct edge{
    int to, cap, rev;
};

vector<edge> G[MAX];
int level[MAX];
int iter[MAX];

void add_edge(int from, int to, int cap){
    //forward
    G[from].push_back((edge){to,cap,G[to].size()});
    //backward
    G[to].push_back((edge){from,0,G[from].size()-1 });
}


void BFS(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int i = 0; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i = iter[v]; i< G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap +=d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t){
    int flow = 0;
    for(;;){
        BFS(s);
        if(level[t] < 0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        int INF = (int)1e9;
        while((f = dfs(s , t , INF)) > 0){
            flow+=f;
        }
    }
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        int from,to,cap;
        for(int i=0; i<n; i++){
            scanf("%d %d %d",&from,&to,&cap);
            add_edge(from-1,to-1,cap);
        }
        printf("%d\n",max_flow(0,m-1));
        for(int i=0; i<m; i++)
            G[i].clear();
    }
    return 0;
}
