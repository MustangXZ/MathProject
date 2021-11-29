#include<iostream>
using namespace std;
int n,k,a[100],cou=0,b[100];
void xem(){
	cout<<"To hop thu: "<<++cou<<" la: ";
	for (int i=1;i<=k;i++) cout<<" "<<b[a[i]];
	cout<<endl;
}
void tinh(){
	int i=k;
	xem();
	while(a[i]==n-k+i) i--;
	if (i>0){
		a[i]++;
		for (int j=i+1;j<=k;j++) a[j]=a[i]+j-i;
		tinh();
	}
	else return;
}	
int main(){
	cout<<"nhap n: ";
	cin>>n;
	cout<<"nhap k: ";
	cin>>k;
	cout<<"nhap day so muon to hop: ";
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++) a[i]=i;	
	tinh();
	return 0;
} 
