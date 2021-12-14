#include<bits/stdc++.h>
using namespace std;
int n,m;
int tot,ver[100010],edge[100010],head[100010],nxt[100010];
int x,y,z,ans,hhh;
char ch;
int f[101000];
bool v[1000010];
void add(int x,int y,int z)
{
    ++tot;
    ver[tot]=y;
    edge[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot;
}
inline long long read(){
    register long long x(0), f=1; register char c(getchar());
    while(c<'0'||'9'<c){ if(c=='-') f=-1; c=getchar(); }
    while('0'<=c&&c<='9')
        x=(x<<1)+(x<<3)+(c^48), c=getchar();
    return x*f;
}
void dfs(int x,int fa)
{
    for(int i=head[x];i;i=nxt[i])
    {
        int y=ver[i],z=edge[i];
        if(y==fa)continue;
            f[y]=f[x]+z;
            if(f[y]>ans)
            {
                ans=f[y];
                hhh=y;
            }
            dfs(y,x);
    }
}
int main()
{
    n=read();
    m=read();
    for(int i=1;i<=m;i++)
    {
        x=read();
        y=read();
        z=read();
        cin>>ch;
        add(x,y,z);
        add(y,x,z);
    }
    f[1]=0;
    dfs(1,0);
    f[hhh]=0;
    dfs(hhh,0);
    cout<<ans;
    return 0;
}
