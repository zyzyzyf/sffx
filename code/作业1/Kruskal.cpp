#include <stdio.h>
#define MAXE 100
#define MAXV 100
typedef struct{
	int vex1;                     
	int vex2;                      
	int weight;                    
}Edge;
void kruskal(Edge E[],int n,int e)
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	int vset[n+1];
	for(i=1;i<=n;i++)       
		vset[i]=i;
	k=1;
  	j=0;
   while(k<e)
   {
       m1=E[j].vex1;
       m2=E[j].vex2;
       sn1=vset[m1];
       sn2=vset[m2];                           	       
	    if(sn1!=sn2)
	    {
			printf("V%d-V%d=%d\n",m1,m2,E[j].weight);
			sum+=E[j].weight;
			k++;                
			if(k>=n)
				break;
			for(i=1;i<=n;i++)    
				if (vset[i]==sn2)  
					vset[i]=sn1;
	    }
     j++;                  
   }
    printf("最小权值之和=%d\n",sum);
}
int fun(Edge arr[],int low,int high)
 {
 	int key;
 	Edge lowx;
 	lowx=arr[low];
 	key=arr[low].weight;
 	while(low<high)
 	{
 		while(low<high && arr[high].weight>=key)
 			high--;
 		if(low<high)
 			arr[low++]=arr[high];

 		while(low<high && arr[low].weight<=key)
 			low++;
 		if(low<high)
 			arr[high--]=arr[low];
	 }
	 arr[low]=lowx;
	 return low;
  } 
void quick_sort(Edge arr[],int start,int end)
{
	int pos;
	if(start<end)
	{
	pos=fun(arr,start,end);
	quick_sort(arr,start,pos-1);
	quick_sort(arr,pos+1,end);
	}
}
int main()
{
	Edge E[MAXE];
	int nume,numn;
	printf("输入顶数和边数:\n");
	scanf("%d%d",&numn,&nume);
	for(int i=0;i<nume;i++)
		scanf("%d%d%d",&E[i].vex1,&E[i].vex2,&E[i].weight);
	quick_sort(E,0,nume-1);
	kruskal(E,numn,nume);
}
