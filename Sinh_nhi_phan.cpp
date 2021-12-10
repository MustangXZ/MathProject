#include<iostream>
using namespace std;
void xuat(int a[], int n){
	for (int i=0;i<n;i++){
		cout<<a[i]<<"";
	}
	cout<<endl;
}
void tim(int i,int n, int a[]){
	for (int j=0;j<2;j++){
		a[i]=j;
		if (i<n){
			tim(i+1,n,a);
		}else{
			xuat(a,n);
		}
	}
}
int main(){
	int n,t,a[100];
	cout<<"nhap vao so n: ";
	cin>>n;
	tim(0,n,a);
}
