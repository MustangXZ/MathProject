#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;
void nhap(int a[MAX][MAX], int n){
    char bin;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            bin=getch();
            if (bin=='1'){
                a[i][j]=1;
            }else a[i][j]=0;
            cout.width(3);
            cout<<left<<a[i][j];
        }
        cout<<endl;
    }
}
void xuat(int a[MAX][MAX], int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout.width(3);
            cout<<left<<a[i][j];
        }
        cout<<endl;
    }
}
void kiemtra(int a[MAX][MAX], int n, int soluong, int soat[MAX], int nhay[MAX], int i){
    int vtdau=0;
    int vtsau=0;
    int t;
    nhay[vtsau]=i; soat[i]=soluong;
    while (vtsau>=vtdau){
        t=nhay[vtsau];
        vtdau++;
        for (int j=0;j<n;j++){
            if(a[t][j]==1&&soat[j]==0){
                vtsau++;
                nhay[vtsau]=j;
                soat[j]=soluong;   
            }
        }
    }
}
void xuat2( int a[MAX][MAX], int n, int soluong, int soat[MAX]){
    if (soluong==1){
        cout<<"do thi nay la do thi lien thong";
        getch();
        return;
    }
    for (int i=0;i<soluong;i++){
        cout<<"thanh phan lien thong thu "<<i+1<<": ";
        for (int j=0;j<n;j++){
            if (soat[j]==i+1) cout<<j+1<<"  ";
        }
        cout<<endl;
    }
    getch();
}
int main(){
    int a[MAX][MAX], soat[MAX]={0}, nhay[MAX];
    int n,soluong=0;
    cout<<"nhap vao n: ";
    cin>>n;
    nhap(a,n);
    cout<<"mang vua nhap: "<<endl;
    xuat(a,n);
    for (int i=0;i<n;i++){
        if (soat[i]==0){
            soluong++;
            kiemtra(a,n,soluong,soat,nhay,i);
        }
    }
    xuat2(a,n,soluong,soat);
	return 0;
}
