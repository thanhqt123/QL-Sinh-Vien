/*
xay dunng chuong trinh voi cac yeu cau sau 
1: nhap danh sach sinh vien ok
2: in ra danh sach sinh vien ok
3: tim kiem thong tin sinh vien theo ten ok
4: xoa sinh vien theo ten
5: sap xep sinh vien co gpa tang dan
6: in ra sinh vien co gpa cao nhat ok
*/ 
#include <iostream>
using namespace std;

struct sinhVien {
    string name;
    float gpa;
    int age;
    string address;
};

void nhap(sinhVien &sv) {
    cout << "Nhap ten sinh vien: ";
    getline(cin, sv.name);
    cout << "Nhap diem sinh vien: ";
    cin >> sv.gpa;
    cout << "Nhap tuoi sinh vien: ";
    cin >> sv.age;
    cin.ignore();
    cout << "Nhap dia chi sinh vien: ";
    getline(cin, sv.address);
}
void in( sinhVien sv) {
     cout<<"Name: "<<sv.name<<"\n";
     cout<<"Gpa: "<<sv.gpa<<"\n";
     cout<<"Age: "<<sv.age<<"\n";
     cout<<"Address: "<<sv.address<<"\n";
} 
void timKiem( sinhVien sv[], int n, string s ) {
     int found = 0;
     for(int i=0; i<n; i++) {
          if(sv[i].name== s){
               in(sv[i]);
               found=1;
          }
     }
     if(!found){
          cout<<"Khong tim thay sinh vien !";
     }
}
void maxGpa( sinhVien sv[], int n){
     int max=sv[0].gpa;
     int index=0;
     for(int i=0;i<n;i++){
          if(sv[i].gpa>max){
               max=sv[i].gpa;
               index=i;
          }
     }
     for(int i=0;i<n;i++){
          if(sv[i].gpa==max){
               in(sv[i]);
          }
     }
     // in(sv[index]);
}
void sapXep(sinhVien sv[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].gpa > sv[j].gpa) {
                // Swap entire sinhVien structures
                sinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        in(sv[i]);
    }
}
void xoaSV(sinhVien sv [], int &n, string s){
     for(int i=0;i<n;i++){
          if(sv[i].name == s){
               for(int j=i;j<n-1;j++){
                    sv[j]=sv[j+1];
               }
               n--;
               i--;
          }
     }
}
int main() {
    int n;
    sinhVien sv[1000];
    while (true) {
        cout << "------Quan li sinh vien--------" << "\n" << "\n";
        cout<<"Nhap lua chon:  "<<"\n";
        cout << "1: Nhap sinh vien " << "\n";
        cout << "2: In danh sach sinh vien " << "\n";
        cout << "3: Tim kiem thong tin sinh vien theo ten " << "\n";
        cout << "4: Sap xep sinh vien co gpa tang dan " << "\n";
        cout << "5: Chon sinh vien co Gpa cao nhat " << "\n";
        cout << "6: Xoa sinh vien " << "\n";
        cout<<"0: Thoat chuong trinh "<<"\n";
        int lc;
        cin >> lc;
          if (lc == 1) {
               cout << "Nhap so luong sinh vien: ";
               cin >> n;
               cin.ignore();
               for (int i = 0; i < n; i++) {
                    nhap(sv[i]);
               }
          }
          if (lc == 2) {
               for(int i = 0; i < n; i++){
                    in(sv[i]);
               }
          }
          if(lc==3){
               cout<<"Nhap ten sinh vien tim kiem: ";
               cin.ignore();
               string name;
               getline(cin, name);
               timKiem(sv,n,name);

          }
          if(lc==4){
               sapXep(sv,n);

          }
          if(lc==5){
               cout<<"Sinh vien co Gpa cao nhat la:"<<"\n";
               maxGpa(sv, n);
          }
          
          if(lc==6){
               cout<<"Nhap ten sinh vien can xoa:"<<"\n";
               cin.ignore();
               string s;
               getline(cin,s);
               xoaSV(sv, n,s);
          }
          if(lc==0){
               break;
          }
    }
    return 0;
}
