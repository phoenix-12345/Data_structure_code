//minimum Segment tree
#include<bits/stdc++.h>
using namespace  std;

//building tree
void buildtree(int *tree,int *a,int index,int s,int e)
{
    //base case
    if(s>e)
    return;
    //leaf node
    if(s==e)
    {
        tree[index]=a[s];
        return ;
    }

    //intermediate nodes
    int mid=(s+e)/2;
    buildtree(tree,a,2*index,s,mid);
    buildtree(tree,a,2*index+1,mid+1,e);

    tree[index]=min(tree[2*index],tree[2*index+1]);
}
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    //no overlap
    if(qs>e||qe<s)
    return INT_MAX;

    //complete overlap
    if(qs<=s&&qe>=e)
    return tree[index];

    //partial overlap
    int mid=(s+e)/2;

    int left=query(tree,2*index,s,mid,qs,qe);
    int right=query(tree,2*index+1,mid+1,e,qs,qe);

    return min(left,right);
}
//update the tree
void update(int *tree,int index,int s,int e,int ind,int value)
{
    //no overlap
    if(s>ind||e<ind)
    return;
    //complete overlap
    if(s==e)
    {
        tree[index]=val;
        return;
    }
    //partial overlaop - ind exist in node range
    int mid=(s+e)/2;
    update(tree,2*index,s,mid,ind,val);
    update(tree,2*index+1,mid+1,e,ind,val);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;

}
int main()
{
    int a[]={-1,2,3,-4,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    int tree[4*n+1];
    int index=1;
    int s=0,e=n-1;

    //build tree
    buildtree(tree,a,index,s,e);

    //update element of given array and then make changes in tree
    int ind,val;
    cin>>ind>>val;
    update(tree,index,s,e,ind,val)
    int q;
    cin>>q;
    while(q--)
    {
        int qs,qe;
        cin>>qs>>qe;
        //query on given array
        int ans=query(tree,1,s,e,qs,qe);
        cout<<ans<<endl;
    }
}
