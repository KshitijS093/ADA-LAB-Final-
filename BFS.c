#include<stdio.h>
#include<conio.h>
void insert_rear(int q[],int *r, int item, int size)
{
    if(*r==size)
    printf("Queue overflow!\n");
    else
    {
        *r=*r+1;
        q[*r]=item;
    }
}
int delete_front(int q[],int *r, int *f)
{
    int del_item=-1;
    *f=*f+1;
    del_item=q[*f];


    return del_item;
} 
int isEmpty(int q[], int *r, int *f)
{
    if(*r==-1 || *r==*f)
    return 1;
    else
    return 0;
}
void main()
{
    int n,i,j,r=-1,f=-1;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix representing the graph:\n");
    int graph[n][n];
    int vis[n],q[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        vis[i]=0;                                                                               
    }
    printf("The BFS traversal is:\n");
    int k=0;
    printf("%d ",k); // print the first node
    vis[k]=1; //Make the first node visited
    insert_rear(q,&r,k,n); // Insert the node in the queue
    while(isEmpty(q,&r,&f)==0) // if queue is not empty
    {
        int node=delete_front(q,&r,&f); //remove node from queue
        for(j=0;j<n;j++)
        {
            if(graph[node][j]==1 && vis[j]==0) /*if the child of node removed exits and is not visited, make it visited.
                                                     1.print the child 
                                                     2.make the node visited.
                                                     3.insert the child into the queue*/
            {
                printf("%d ",j);
                vis[j]=1;
                insert_rear(q,&r,j,n); 
            }
        }
    }
}