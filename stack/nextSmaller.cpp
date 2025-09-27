#include<iostream>
#include<stack>
using namespace std;
void print(vector<int>g,int n){
    
    for(int i=0;i<n;i++){
        cout<<g[i]<<" ";
    }
}
void nextSmaller (vector<int>g,int n){
    stack<int>st;
    vector<int>ans(n,-1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && g[st.top()] > g[i])
        {
            ans[st.top()] = g[i];
            st.pop();
        }
        st.push(i);
    }
    print(ans,n);

}
int main()
{
    vector<int>given={7,9,12,10,14,8,3,6,9};
    int n = given.size();
    nextSmaller(given,n);
    // print(given,n);

    return 0;
}