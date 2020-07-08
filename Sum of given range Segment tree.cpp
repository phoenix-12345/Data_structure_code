#include<bits/stdc++.h>
using namespace std;
void buildtree(int *tree,int *a,int index,int s,int e)
{

    if(s>e)
    return ;
    //leaf node
    if(s==e)
    {
        tree[index]=a[s];
        return;
    }
    //intermediate nodes
    int mid=(s+e)/2;
    buildtree(tree,a,2*index,s,mid);
    buildtree(tree,a,2*index+1,mid+1,e);

    tree[index]=tree[2*index]+tree[2*index+1];
    return ;

}

//query
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    //no overlap
    if(e<qs||s>qe)
    {
        return 0;
    }
    //complete overlap
    if(qs<=s&&qe>=e)
    {
        return tree[index];
    }
    //partial overlap
    int mid=(s+e)/2;
    int left=query(tree,2*index,s,mid,qs,qe);
    int right=query(tree,2*index+1,mid+1,e,qs,qe);

    return left+right;
}

//update node of given index i by value val
void updatenode(int *tree,int index,int s,int e,int i,int val)
{
    //no overlap
    if(i<s||i>e)
    return ;

    //compete overlap
    if(s==e)
    {
        tree[index]=val;
        return;
    }
    //partial overlap
    int mid=(s+e)/2;
    updatenode(tree,2*index,s,mid,i,val);
    updatenode(tree,2*index+1,mid+1,e,i,val);
    tree[index]=tree[2*index]+tree[2*index+1];
    return ;

}
int main()
{
    int a[]={-1,2,3,-4,5,1};
    int n=sizeof(a)/sizeof(a[0]);

    int tree[4*n+1];

    int index=1;
    int s=0,e=n-1;
    //build tree
    buildtree(tree,a,index,s,e);

    //updatenode value
    int i,val;
    cin>>i>>val;
    updatenode(tree,index,s,e,i,val);
    int q;
    cin>>q;
    while(q--)
    {
        int qs,qe;
        cin>>qs>>qe;
        int sum=query(tree,index,s,e,qs,qe);
        cout<<sum<<endl;
    }
}
