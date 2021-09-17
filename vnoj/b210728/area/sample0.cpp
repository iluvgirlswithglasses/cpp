#include<cassert>
#include<cstdio>
#include<vector>
#define MAX   30030
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
class SegmentTree {
    private:
    vector<int> cnt,add;
    int n;
    void update(int i,int l,int r,int u,int v,int c) {
        if (l>v || r<u || l>r || v<u) return;
        assert(0<=i && i<cnt.size());
        if (u<=l && r<=v) {
            add[i]+=c;
            return;
        }
        int m=(l+r)>>1;
        update(2*i,l,m,u,v,c);
        update(2*i+1,m+1,r,u,v,c);
        int L=add[2*i]>0?m-l+1:cnt[2*i];
        int R=add[2*i+1]>0?r-m:cnt[2*i+1];
        cnt[i]=L+R;
    }
    public:
    SegmentTree() {
        n=0;
    }
    SegmentTree(int n) {
        this->n=n;
        cnt.assign(4*n+7,0);
        add.assign(4*n+7,0);
    }
    void update(int l,int r,int v) {
        update(1,1,n,l,r,v);
    }
    int countCell(void) const {
        return (add[1]>0?n:cnt[1]);
    }
};
struct Event {
    int l,r,v;
    Event() {
        l=r=v=0;
    }
    Event(int _l,int _r,int _v) {
        l=_l;r=_r;v=_v;
    }
};
struct Rectangle {
    int x1,y1,x2,y2;
    Rectangle() {
        x1=y1=x2=y2=0;
    }
    void input(void) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1++;y1++;
    }
    bool valid(void) const {
        return (x1<=x2 && y1<=y2);
    }
};
Rectangle rec[MAX+7];
vector<Event> event[MAX+7];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) rec[i].input();
}
void process(void) {
    FOR(i,1,n) if (rec[i].valid()) {
        event[rec[i].x1].push_back(Event(rec[i].y1,rec[i].y2,1));
        event[rec[i].x2+1].push_back(Event(rec[i].y1,rec[i].y2,-1));
    }
    SegmentTree segTree(MAX);
    int res=0;
    FOR(i,1,MAX) {
        REP(j,event[i].size()) segTree.update(event[i][j].l,event[i][j].r,event[i][j].v);
        res+=segTree.countCell();
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    int c; scanf("%d", &c);
    return 0;
}
