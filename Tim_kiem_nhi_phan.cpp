#include<iostream>
using namespace std;
void nhiphan(int a[],int n,int x){
	int l=0;
	int r=n-1;
	if (a[0]==x) {
		cout<<endl<<"so do o vi tri: 1";
		return;
	}
	if (a[n-1]==x){
		cout<<endl<<"so do o vi tri: "<<n;
		return;
	} 
	while (r>1){
		int mid=l+(r-1)/2;
		if (a[mid]==x){
			cout<<endl<<"so do o vi tri: "<<mid+1;
			return;
		}
		if (a[mid]>x) r=mid-1;
		if (a[mid]<x) l=mid+1;
	} 
}
void sapxep(int a[], int n){
	int temp;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (a[j]<a[i]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(){
	int n,x;
	int a[1000];
	cout<<"nhap vao so n phan tu: ";
	cin>>n;
	cout<<"nhap vao mang: ";
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"nhap vao so muon tim: ";
	cin>>x;
	sapxep(a,n);
	cout<<"mang sau khi sap xep lai: ";
	for (int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	nhiphan(a,n,x);
	return 0;
}
