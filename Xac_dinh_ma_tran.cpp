#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;
void nhap(int a[MAX][MAX], int b[MAX][MAX], int &n){
    cout<<"nhap vao so don vi cua ma tran: ";
    cin>>n;
    cout<<"nhap vao gia tri cho ma tran: "<<endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
            b[i][j]=a[i][j];
            if (a[i][j]!=0&&a[i][j]!=1) a[i][j]=1;
        }
        cout<<endl;
    }
}
void xuat(int a[MAX][MAX], int n){
    cout<<"in ra mang: "<<endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout.width(2);
            cout<<left<<a[i][j];
        }
        cout<<endl;
    }
}
int phanxa(int a[MAX][MAX], int n){
    for (int i=0;i<n;i++){
        if (!a[i][i]){
            return 0;
        }
    }
    return 1;
}
int doixung(int a[MAX][MAX], int n){
    int temp;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            temp=a[i][j];
            if (temp==a[j][i]) continue;
            else {
                return 0;
            }
        }
    }
    return 1;
}
void baophanxa(int a[MAX][MAX], int n){
    if (phanxa(a,n)) {
        cout<<endl<<"ma tran co phan xa";
    }
    else { 
        cout<<endl<<"ma tran khong phan xa";
        cout<<endl<<"bao dong phan xa cua ma tran la: R=";
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (a[i][j]){
                    cout<<" ("<<i+1<<","<<j+1<<"),";
                }
            }
        if (!a[i][i]) cout<<" ("<<i+1<<","<<i+1<<"),";
        }
    }
}
void baodoixung(int a[MAX][MAX], int b[MAX][MAX], int n){
    int t=0;
    for (int i=0; i<n;i++){
        for (int j=0;j<n;j++){
            a[i][j]=b[i][j];
        }
    }
    if (doixung(a,n)){
        cout<<endl<<"ma tran nay co doi xung";
        return;
    } else {
        cout<<endl<<"ma tran nay khong doi xung";
        cout<<endl<<"bao dong doi xung cua ma tran la: R=";
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (a[i][j]){
                    cout<<" ("<<i+1<<","<<j+1<<"),";
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (a[i][j]!=a[j][i]&&a[i][j]==1){
                    a[j][i]=1;
                    cout<<" ("<<i+1<<","<<j+1<<"),";
                }
            }
        }
    }
}
void baobaccau(int a[MAX][MAX], int b[MAX][MAX], int n){
    for (int i=0; i<n;i++){
        for (int j=0;j<n;j++){
            a[i][j]=b[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int t=0;t<n;t++){
                if (a[j][i]*a[i][t]==1) a[j][t]=1;
            }
        }
    }
    cout<<endl<<"bao bac cau cua ma tran la: ";
    for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (a[i][j]){
                    cout<<" ("<<i+1<<","<<j+1<<"),";
                }
            }
        }
    cout<<endl;
    xuat(a,n);
    return;
}
int main(){
    int a[MAX][MAX], b[MAX][MAX];
    int n;
    nhap(a,b,n);
	xuat(a,n);
    baophanxa(a,n);
    baodoixung(a,b,n);
    baobaccau(a,b,n);    
    getch();
    return 0;    
}
