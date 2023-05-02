# 算法模板

[toc]



## 基础算法
### bignum 大数的加减乘除
## 数学相关
### is_prime 输入一个数n，判断它是否是质数
### divide_prime 输入一个数n，求它的质因子
### prime_nums 输入一个数n及一个空数组，求1-n的所有质数
### divide_factors 输入一个数n，求它的所有约数
### divide_factors_num 输入一个数n，求它的约数个数
### divide_factors_sum 输入一个数n，求它的约数之和
### gcd 输入一个数a,b 求他们的最大公约数
### quick_mi 输入一个a,k,p 快速求出a^k%p 

## 图论

### 深度优先遍历

```
//void dfs(中间容器，数据)
//{
//    if(临界走到末尾)
//    {
//        中间容器加到最终容器
//        return；
//    }
//    for(做选择)
//    {
//        改变中间容器
//        dfs(中间容器，数据)
//        撤回对中间容器的改变
//    }
//}
```

#### 全排列例题



<img src="/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427102703089.png" alt="image-20230427102703089" style="zoom:33%;" />



```c++

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void dfs(string &rs,vector<string> &rss,vector<int> &choose,int n)
{
    if(rs.size()==n)
    {
        rss.push_back(rs);
        return;
    }
    for(int i=0;i<choose.size();i++)
    {
        int temp=choose[i];
        rs.push_back(temp+'0');
        choose.erase(choose.begin()+i);
        dfs(rs,rss,choose,n);
        rs.pop_back();
        choose.insert(choose.begin()+i,temp);
    }
}

int main()
{
    int n=0;
    cin>>n;
    string rs;
    vector<string > rss;
    vector<int> choose;
    for(int i=1;i<=n;i++)
    {
        choose.push_back(i);
    }
    dfs(rs,rss,choose,n);
    sort(rss.begin(),rss.end());
    for(int i=0;i<rss.size();i++)
    {
        for(int j=0;j<rss[i].size();j++)
        {
            cout<<rss[i][j]<<" ";
        }
        cout<<endl;
    }
}
```

#### n皇后问题

![image-20230427105217237](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427105217237.png)

<img src="/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427105232143.png" alt="image-20230427105232143" style="zoom:35%;" />



从第一行看皇后 能看到放在哪一列 

走的过程中 判断是否在

> 剪枝有两种
>
> 可信性剪枝是判断  走的过程提前判断 ,非法的就没必要走了
>
> 最优性剪枝 比其他路优秀 不用走那条路了

用三个map作为中间变量

第一个map。 key是列,value是行

第二个map 存储x+y的截距

第三个map 存储x-y的解决

> 因为斜线的斜率是1,所以 y=x+b. y=-x+b 即可 算出两个方向的截距,通过截距可以唯一确定一条直线

```c++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
using namespace std;


void dfs(map<int,int> &kv,map<int,int> &kv2,map<int,int> &kv3,vector<map<int,int> > &rss,int k,int n)
{
    if(kv.size()==n)
    {
        rss.push_back(kv);
    }
    for(int i=0;i<n;i++) // 在第k行选择哪一列
    {
        if(kv.count(i))
        {
            continue;
        }
        if(kv2.count(k+i))
        {
            continue;
        }
        if(kv3.count(k-i))
        {
            continue;
        }
        kv[i]=k;
        kv2[k+i]=1;
        kv3[k-i]=1;
        dfs(kv,kv2,kv3,rss,k+1,n);
        kv.erase(i);
        kv2.erase(k+i);
        kv3.erase(k-i);
    }
}

int main()
{
    int n=0;
    cin>>n;
    map<int,int> kv;// key 是列，value是行
    map<int,int> kv2;// 存储第一种截距 +
    map<int,int> kv3;// 存储第二种截距 -
    vector<map<int,int> > rss;
    dfs(kv,kv2,kv3,rss,0,n);
    for(auto item:rss)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(item.count(j)&&item[j]==i)
                {
                    cout<<"Q";
                }
                else
                {
                    cout<<".";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }

}
```

### 广度优先遍历

有 “最短路” 的概念, 当图的权重都是为1的时候, 图先找到的都是bfs,最短的 

最短 看好广搜  记得边的权重为1

但是费空间 o(2^N). 深搜只用o(n)

```
quene <- 初始状态
while(queue 不空)
{
	t<- 对头拿出来
	扩展队头
	压入队列
}
```

#### 走迷宫例题 用广搜

需要额外的数据存储  vis表示是否访问过  dis表示距离



<img src="/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427152209391.png" alt="image-20230427152209391" style="zoom:30%;" />

<img src="/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427152227002.png" alt="image-20230427152227002" style="zoom:40%;" />

```c++
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
int bfs(vector<vector<int> > &mapit)
{
    int n=mapit.size();
    int m=mapit[0].size();
    queue<pair<int,int> > ls;
    vector<vector<int> > dis(n,vector<int>(m));
    vector<vector<int> > vis(n,vector<int>(m));
    ls.push(make_pair(0,0));
    while(ls.size()!=0)
    {
        pair<int,int> it=ls.front();
        ls.pop();
        int qs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<4;i++)
        {
            if(it.first+qs[i][0]<n&&it.first+qs[i][0]>=0&&it.second+qs[i][1]<m&&it.second+qs[i][1]>=0&&vis[it.first+qs[i][0]][it.second+qs[i][1]]==0&&mapit[it.first+qs[i][0]][it.second+qs[i][1]]==0)
            {
                dis[it.first+qs[i][0]][it.second+qs[i][1]]=dis[it.first][it.second]+1;
                vis[it.first+qs[i][0]][it.second+qs[i][1]]=1;
                ls.push(make_pair(it.first+qs[i][0],it.second+qs[i][1]));
            }
        }
    }
    return dis[n-1][m-1];
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > mapit(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mapit[i][j];
        }
    }
    cout<<bfs(mapit)<<endl;

}
```

### 树与图的存储

树是一种特殊的图  无环连通图

图 有向图 无向图(看成特殊的有向图即可,两条边)

存储方式,邻接矩阵(一般不用耗费空间比较大)  or 邻接表 n个节点 开n个单链表

邻接表 每个单链表 存储到达每个点

个人喜欢使用vector实现邻接表

```c++


struct Edge
{
	int next;
	int val;
	Edge(int next_,int val_):next(next_),val(val_){;}
}
vector<vector<Edge> > vec(N); 

加入一个边。从2指向5 权重为8
vec[2].push_back(Node(5,8));

```

### 树与图在邻接表上的深度优先遍历

树和无向图都是一种有向图

就看有向图的遍历即可

<img src="/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427165929048.png" alt="image-20230427165929048" style="zoom:50%;" />

```c++
int vis[n];
void dfs(int u)
{
	vis[u]=1;//表明该节点访问过 是一个全局所用的 ,不用恢复
	for(int i=0;i<vec[i].size();i++)
	{
		Edge* e=vec[u][i];
		if(vis[e.next]) dfs(e.next); //如果下一个点未访问过,则进行访问
	}
}
```

图的深度遍历,特点就是 不会再走之前走过的路  不用管有向边或者无向边

有向图的深度遍历过程中 可以知道每个子树的大小

![image-20230427161704194](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230427161704194.png)





### 树与图在邻接表上的广度优先遍历

一层层搜 广度搜

### 拓扑排序(用广搜的框架来写)

https://www.acwing.com/problem/content/850/

突破口为入度为0的节点,环无法拓扑排列

```
当前入度为0的点作为起点

queue 《- 所有入度为0的点

while(queue不为空)

{

	t<- 队头

	枚举所有t的出边 

			删除t->j

			如果j的入度为0 则加入队列

}
```

![image-20230428092435182](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230428092435182.png)

![image-20230428092445615](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230428092445615.png)

```c++
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//https://www.acwing.com/problem/content/850/
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
void topological_order(vector<vector<Edge> >& graph,vector<int> &in)
{
    queue<int> ls;
    vector<int> vis(graph.size()+1);
    vector<int> rs;
    for(int i=1;i<in.size();i++)
    {
        if(in[i]==0)
        {
            ls.push(i);
        }
    }
    while(ls.size()!=0)
    {
        int t=ls.front();
        vis[t]=1;
        rs.push_back(t);
        ls.pop();
        for(int j=0;j<graph[t].size();j++)
        {
            if(vis[graph[t][j].next]==0)
            {
                // 删除t->graph[t][j].next
                in[graph[t][j].next]-=1;
                if(in[graph[t][j].next]==0)
                {
                    ls.push(graph[t][j].next);
                }
            }
        }
    }
    if(rs.size()==graph.size()-1)
    {
        for(int i=0;i<rs.size();i++)
        {
            cout<<rs[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<Edge> > graph(n+1);
    vector<int> in(n+1,0);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        //a->b
        graph[a].push_back(Edge(b,1));
        in[b]+=1;
    }
    topological_order(graph,in);

}
```

### 最短路. 单源先用spfa 被卡再用dij   

> 源点 ==起点
>
> 汇点  ==终点
>
> m个边长,n个点

最短路 常见的可以分为两大类

1. 单源最短路  从一个点到所有点的最短路径

   (1) 所有边的权重都是正数

   ​		朴素dijkstra o(n^2)

   ​		堆优化版的dijskstra. o(mlogn)

   (2) 存在负权边

   ​		Bellman-Ford o(mn)

   ​		SPFA 一般:O(m) 最坏:O(nm)

2. 多源汇最短路  

   ​       floyd o(n^3) 

![image-20230428093935510](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230428093935510.png)

#### 朴素版dijsktra -单源最短路-所有边权重都是正数 基于 稠密图(邻接矩阵)

s:当前已经确定最短路径距离的点

1. dis[0 ]=0 dis[i]=+OO 只有起点被确定到了 

2.   for(i 1 ..n)   

   ​		t《- 不在s中的距离最近的点

   ​		s〈-t

   ​		用t更新其他点的距离(看下)

> dij实现的时候是通过 将距离设置成无穷大 来表达 不可达
>
> dij 由于边很多, 稠密图 所以用邻接矩阵存即可
>
> dij 需要找n个点 所以外层是一个for循环x

```
总结下来:
	1. 把未加入的最近的加进来
	2. 标记加入
	3. 根据加入的点更新距离

```

https://leetcode.cn/problems/network-delay-time/

![image-20230428171601548](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230428171601548.png)

```c++
#include<iostream>
#include<vector>
using namespace std;
#define INA INT_MAX
//https://leetcode.cn/problems/network-delay-time/
int networkDelayTime(vector<vector<int> >& times, int N, int k) {
   // 因为点的坐标是从1开始 , 所以开N+1个
   // 直接在graph上更新 方便很多
   // graph要采用long long  INT_MAX+某个数 不会变成负数
 
    vector<vector<long long> > graph(N+1,vector<long long>(N+1,INT_MAX));
    for(int i=1;i<=N;i++)    graph[i][i]=0;
    for(auto e:times)    graph[e[0]][e[1]]=e[2];
    vector<int> vis(graph.size(),0);
    vis[k]=1;
    // 只要找下除了起点的接下来的点
    for(int i=1;i<graph.size()-1;i++)
    {
        int minid=0,minx=INA;
        // 在没有使用过的检查最短的距离
        for(int j=1;j<graph.size();j++)
        {
            if(vis[j]==0&&graph[k][j]<minx)
            {
                minid=j;
                minx=graph[k][j];
            }
        }
        vis[minid]=1;
        // 更新
        // 根据这个点更新其他所有距离
        for(int j=1;j<graph.size();j++)
        {
            graph[k][j]=min(graph[k][j],graph[k][minid]+ graph[minid][j]);
        }
    }
    int ans=0;
    for(int i=1;i< graph.size();i++)
    {
        if(graph[k][i]==INT_MAX) return -1;
        ans=max(ans, (int)graph[k][i]);
    }
    return ans;
}
int main()
{

    vector<vector<int> > times={{2,1,1},{2,3,1},{3,4,1}};
    int rs=networkDelayTime(times,4,2);
    cout<<rs<<endl;

}
```

#### dijstra 稀疏图(邻接表)  -我更喜欢的方式!!!



```
求点k到其他点的距离
与上面不同的情况是, 采用邻接表+最小堆
最小堆 的格式是(点k到该点的距离,该点的id)
dis[] 存储的是点k到达每个点的最短距离
st[] 存储的是否能确定点k到达每个点的距离

while(队列不为空)
{
	队列弹出一个
	如果该点确定了最短距离,就不管它 if(st[]) continue
	把弹出的这个点加入最短距离
	根据这个点进行扩展,遍历这个点指向其他点的边
				如果比div小,则更新距离
				加入队列中
}
```

![image-20230428201127290](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230428201127290.png)

https://leetcode.cn/problems/network-delay-time/

![image-20230428171601548](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230428171601548.png)



```c++
typedef long long ll;
typedef pair<ll,ll> pll;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge> > graph(n+1);
        for(auto item:times)
        {
            int a=item[0];
            int b=item[1];
            int c=item[2];
            graph[a].push_back(Edge(b,c));
        }
        vector<ll> dis(graph.size(),INT_MAX);
        vector<int> st(graph.size(),0);
        priority_queue<pll,vector<pll>,greater<pll> > ls;
        ls.push(pll(0,k));
        dis[k]=0;
        while(ls.size())
        {
            auto item=ls.top();
            ls.pop();
            ll distance=item.first;
            int id=item.second;
            // 保证未加入
            if(st[id]) continue;
            // 加入
            st[id]=1;
            // 扩展更新
            for(int i=0;i<graph[id].size();i++)
            {
                // k->id->id2
                //  distance distance2

                int id2=graph[id][i].next;
                int distance2=graph[id][i].val;
                if(distance+distance2<dis[id2])
                {
                    dis[id2]=distance+distance2;
                    // 加入队列
                    ls.push(pll(dis[id2],id2));
                }
            }
        }
        int rs=(int)*max_element(dis.begin()+1,dis.end());
        if(rs==INT_MAX) return -1;
        else return rs;
        }
};
```

#### spfa-超级万能 说不定比dijsktra还快

dis[] 代表第k到某一点的最短距离

queue 代表刚被更新的点  它有可能更新其他路径 所以检查它的出边

isin代表该点是否在queue中

```
队列放入起点 <-k
while(队列不为空)
	取出队头
	遍历所有t的出边  t-w>b
		如果dis[b]>dis[t]+w[t,b],更新,如果b不在队列中,加入b
```



![image-20230430134932625](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230430134932625.png)

```c++
typedef long long ll;
typedef pair<ll,ll> pll;
struct Edge
{
    int next;
    int val;
    Edge(int next_,int val_):next(next_),val(val_){;}
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Edge> > graph(n+1);
        for(auto item:times)
        {
            int a=item[0];
            int b=item[1];
            int c=item[2];
            graph[a].push_back(Edge(b,c));
        }
        vector<ll> dis(graph.size(),INT_MAX);
        vector<int> isin(graph.size(),0);
        queue<int> ls;
        ls.push(k);
        dis[k]=0;
        isin[k]=1;
        while(ls.size())
        {
            int t=ls.front();
            ls.pop();
            isin[t]=0;
            for(int i=0;i<graph[t].size();i++)
            {
                // k->t->id
                int distance=graph[t][i].val;
                int id=graph[t][i].next;
                if(dis[t]+distance<dis[id]){
                    dis[id]=dis[t]+distance;
                    if(isin[id]==0)
                    {
                        ls.push(id);
                        isin[id]=1;
                    }
                }
               
            }
        }
        int rs= *max_element(dis.begin()+1,dis.end());
        if(rs==INT_MAX) return -1;
        else return rs;
        }
};
```



#### 多源最短路问题 

邻接矩阵  存储

```c++
for(int k=1;k<=n;k++)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			 graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
		}
	}
}
```



### 最小生成树

对应的图都是无向图

#### 普里姆算法 o(n^2) --稠密图

```
dist[i]<-+oo
for(i=0;i<n;i++)
	t<- 找到集合外距离最近的点
	用t更新其他点 到 集合 的距离
	st[t]=true
```



#### 克鲁斯卡尔算法 o(mlogn) --稀疏图

![image-20230502102121811](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230502102121811.png)





### 二分图

#### 染色法

判断一个图是否是二分图,当且仅当图中不含奇数环

![image-20230502113106613](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230502113106613.png)

#### 1.算法实现思路

- 我们规定1或2代表一个点属于两个集合。
- 首先我们任选一个点染色成1，把和它相连的所有点染色成2。
- 然后再把所有和染色成2的点相邻的点染色成1
- 在每一次染色点时首先要判断一下这个点是否被染色过，如果被染色过并且和上一个点颜色相同，则代表染色失败，该图不是二分图。





#### 匈牙利算法

 最大匹配 男女匹配![image-20230502120756586](/Users/huangchenghao/CLionProjects/acwing/assets/image-20230502120756586.png)



```
比如 一个男生看上一个女生 ,但这个女生已经心有所属
这个男生不撞南墙不罢休, 看这个女生配的谁 找那个男生换一个人
就成了 

叫 “撬墙角”算法
```



## 动态规划

### 01背包 每个商品只有1个
### 完全背包问题 每个商品不限量
### 多重背包问题 每个商品有固定的数量
### 分组背包问题 每组有很多商品，每组只能选择一个商品购买