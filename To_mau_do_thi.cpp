#include<iostream>
using namespace std;
main(){
	int a[100][100],m[100];
	int n,mau=0;
	cout<<"nhap vao so dinh cua do thi: ";
	cin>>n;
	cout<<"Luy y chi nhap vao ma tran boolean"<<endl<<"nhap vao cac thanh phan cua ma tran: "<<endl;
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cin>>a[i][j];
			if(a[i][j]==0||a[i][j]==1){
				continue;
			}else {
				cout<<"nhap sai";
				return 0;
			}
		}
		cout<<endl;
	}
	cout<<"ma tran vua nhap: "<<endl;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			cout.width(4);
			cout<<a[i][j];
		}
		cout<<endl;
	}
	int marked[100][100];
	int color[100];
	int colored=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (marked[i][j]==0){
				color[i]=j;
				colored=j;
				break;
			}
		}
		for (int t=i+1;t<n;t++){
			if (a[i][t]==1){
				marked[t][colored]=1;
			}
		}
	}
	cout<<endl;
	for (int i=0;i<n;i++){
		cout.width(4);
		cout<<i+1;
	}
	cout<<endl;
	for (int i=0;i<n;i++){
		cout.width(4);
		cout<<color[i]+1;
	}
	return 0;
}

