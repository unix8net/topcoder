//1606

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int Ca,Cb,N;
bool vst[1001][1001];
struct node{
	int a,b;
}Que[1000000];
/*
1-6 Operation
fill A
fill B
empty A
empty B
pour A B
pour B A
*/
const char* Ins[7]={
	"impossible",
	"FILL(1)",
	"FILL(2)",
	"DROP(1)",
	"DROP(2)",
	"POUR(1,2)",
	"POUR(2,1)"
};

int Opr[1000000];
int Prv[1000000];
int Cnt[1000000];
int head,tail;
bool fnd;

void enQ(int o,int a,int b){
	Que[tail].a=a;
	Que[tail].b=b;
	Opr[tail] =o;
	Prv[tail] =head;
	Cnt[tail] =Cnt[head]+1;
	vst[a][b]=1;
	tail++;
}

int print(int p){
	if(p<=0) return 0;
	print(Prv[p]);
	puts(Ins[Opr[p]]);
}

void bfs(){
	head=0,tail=1;
	fnd = false;
	vst[0][0]=1;
	while(head<tail){
		int a=Que[head].a;
		int b=Que[head].b;
		int c;
		if(a==N||b==N)break;
		if(!vst[Ca][b])enQ(1,Ca,b);
		if(!vst[a][Cb])enQ(2,a,Cb);
		if(!vst[0][b]) enQ(3,0,b);
		if(!vst[a][0]) enQ(4,a,0);
		c=min(Cb-b,a);
		if(!vst[a-c][b+c]) enQ(5,a-c,b+c);
		c=min(b,Ca-a);
		if(!vst[a+c][b-c]) enQ(6,a+c,b-c);
		head++;
	}
	head<tail?printf("%d\n",Cnt[head]),print(head):puts(Ins[0]);
}
int main(){
	while(~scanf("%d%d%d",&Ca,&Cb,&N)){
		memset(vst,0,sizeof(vst));
		memset(Prv,-1,sizeof(Prv));
		memset(Cnt,0,sizeof(Cnt));
		bfs();
	}
}