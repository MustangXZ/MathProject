#include<iostream>
#include<conio.h>
#define MAX 200
using namespace std;
void nhap(int a[MAX][MAX], int b[MAX][MAX], int n){
    int bin;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            bin=getch();
            if (bin=='1'){
                a[i][j]=1;
				b[i][j]=a[i][j];
            }else a[i][j]=0;
            cout.width(3);
            cout<<left<<a[i][j];
        }
        cout<<endl;
    }
}
void xuatmt(int a[MAX][MAX], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout.width(3);
            cout<<left<<a[i][j];
        }
        cout<<endl;
    }
}
int kiemtra(int a[MAX][MAX],int n){
	int dem,bac=0;
	for (int i=0;i<n;i++){
		dem=0;
		for (int j=0;j<n;j++){
			dem+=a[i][j];
		}
		if (dem%2!=0) bac++;
	}
	if (bac>0) return 0;
	else return 1;
}
void xuly(int a[MAX][MAX], int n){
	int v,x,top,temp;
	int stack[MAX],CE[MAX];
	top=0;
	stack[top]=0;
	temp=0;
do{
	v=stack[top];
	x=0;
	while (x<=n-1&&a[v][x]==0)x++;
	if (x>n-1){
		temp++;
		CE[temp]=v;
		top--;
	} else{
		top++;
		stack[top]=x;
		a[v][x]=0;
		a[x][v]=0;
	}
}while (top!=-1);
	cout<<"co chu trinh Euler: ";
	for (int i=temp;i>0;i--){
		cout<<(char)(CE[i]+'A')<<" ";
	}
}
int main(){
	int a[MAX][MAX],b[MAX][MAX];
	int n,dem=0;
	int xuat[1000];
	cout<<"nhap vao so dinh cua do thi: ";
	cin>>n;
	nhap(a,b,n);
	if (kiemtra(a,n)==1)
	xuly(a,n);
	else cout<<"do thi khong ton tai chu trinh euler";
	getch();
	return 0;
} 
