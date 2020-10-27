#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n,i,j,k=0,l=0,m,t,p=1,temp;
    float awt=0.0,att=0.0;
    printf("Enter the no.of processes:\n");
    scanf("%d",&n);
    int pid[100],bt[100],at[100],pr[100],a[100],b[100],c[100],d[100],e[100],f[100];
    printf("Enter the processes-->\n");
    for(i=0; i<n; i++)
    {
        printf("Enter process id: ");
        scanf("%d",&pid[i]);
        printf("Enter arrival time: ");
        scanf("%d",&at[i]);
        printf("Enter burst time: ");
        scanf("%d",&bt[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(at[j]>at[j+1])
            {
                temp=at[j];
                at[j]=at[j+1];
                at[j+1]=temp;
                temp=pid[j];
                pid[j]=pid[j+1];
                pid[j+1]=temp;
                temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;


            }
        }
    }
    pr[l]=pid[0];
    a[l]=at[0];
    b[l]=bt[0];
    c[l]=0;
    d[l++]=t=bt[0];
    i=1;
    j=i;
    for(; i<n; i++)
    {
        for(; j<n; j++)
        {
            if(at[j]<=t && l<n)
            {
                pr[l]=pid[j];
                a[l]=at[j];
                b[l++]=bt[j];
            }
            else
                break;
        }
        for(m=p; m<l-1+p; m++)
            for(j=p; j<l-m-1+p; j++)
            {
                if(b[j]>b[j+1])
                {
                    temp=pr[j];
                    pr[j]=pr[j+1];
                    pr[j+1]=temp;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        c[i]=t;
        d[i]=t+=b[i];
        p=l-1;
        j=l;
    }
    for(i=0; i<n; i++)
    {
        f[i]=c[i]-a[i];
        e[i]=b[i]+f[i];
    }
    printf("\nPId\tAT\tBT\tTT\tWT\n");
    for(i=0; i<n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n",pr[i],a[i],b[i],e[i],f[i]);
    printf("\nGantt chart:\n");


    for(i=0; i<n; i++)
        printf("|\tP%d\t",pr[i]);
    printf("|\n");


    printf("\n");
    for(i=0; i<l; i++)
        printf("%d\t\t",c[i]);
    printf("%d\n\n",d[n-1]);
    for(i=0; i<n; i++)
    {
        awt+=f[i];
        att+=e[i];
    }
    awt/=n;
    att/=n;
    printf("Average turnaround time: %f\n", att);
    printf("Average waiting time: %f\n", awt);
}
