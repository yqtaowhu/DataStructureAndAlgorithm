//find the posion of substring in origin string
//if exit return posion in the origin string s
//else return -1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//get the next array
vector<int> getNext(string& p) {
   int n=p.size();
   vector<int>next(n,-1);
   int j=0,k=-1;
   while(j<n-1){ 
     if(k==-1||p[k]==p[j]) {
	j++;k++;
	if(p[k]!=p[j]) next[j]=k;
	else next[j]=next[k]; 
     }
     else k=next[k];
   }
   return next;
}
int kmp(string& s,string& p) {
   int m=s.size(),n=p.size();
   int i=0,j=0;
   vector<int>next=getNext(p);
   while(i<m&&j<n){
     if(j==-1||s[i]==p[j]) {
       ++i;++j;
     }
     else j=next[j];
   }
   return j==n ? i-j : -1;
}
int count_kmp(string& s,string &p){
   int m=s.size(),n=p.size();
   int i=0,j=0,count=0;
   vector<int>next=getNext(p);
   while(i<m){
     if(j==-1||s[i]==p[j]) {
       ++i;++j;
     }
     else j=next[j]; 
     if (j>=n-1) {
       count++;
       j=next[n-1];
     }
   }
   return count;
}
//AC :http://hihocoder.com/problemset/problem/1015?sid=875145
int main(){
 // string s="acbc",p="bc"; 
 // cout<<kmp(s,p)<<endl;
  int n;string s,p;
  cout<<"input the number to test"<<endl;
  cin>>n;             //test number
  while(n--){
    cout<<"input string"<<endl;
    cin>>p>>s;
    p+="#";
    cout<<count_kmp(s,p)<<endl;
  } 
}

