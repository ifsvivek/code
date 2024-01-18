#include<stdio.h>
int main(){
	int time,bt[10],at[10],sbt=0,smallest,n,i;
	float sumt=0,sumw=0;
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("The AT of Process P%d: ",i+1);
		scanf("%d",&at[i]);
		printf("The BT of Process P%d: ",i+1);
		scanf("%d",&bt[i]);
	}
	bt[9]=9999;
	for(time=0;time<sbt;){
		smallest=9;
		for(i=0;i<n;i++){
			if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
				smallest=i;
		}
		printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+bt[smallest]-at[smallest],time-at[smallest]);
		sumt+=time+bt[smallest]-at[smallest];
		sumw+=time-at[smallest];
		time+=bt[smallest];
		bt[smallest]=0;
	}
	printf("\n\nAWT=%f\n",sumw*1.0/n);
	printf("\n\nATAT=%f\n",sumt*1.0/n);
	return 0;
}

