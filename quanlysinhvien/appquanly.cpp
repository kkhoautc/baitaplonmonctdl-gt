#include "sinhvien.h"
#include "danhsachsinhvien.h"
#include <iostream>

class App{
	private:
		DanhSachSinhVien dssv;
	public:
		void menu(){
			int choice;
			do{
				cout << "\n--- MENU ---\n";
	            cout << "1. Them 1 sinh vien\n";
	            cout << "2. Them nhieu sinh vien\n";
	            cout << "3. Xuat danh sach\n";
	            cout << "4. Sua sinh vien\n";
	            cout << "5. Tim sinh vien diem cao nhat\n";
	            cout << "6. Tim sinh vien diem thap nhat\n";
	            cout << "7. Tim kiem sinh vien theo ma\n";
	            cout << "8. Tim kiem sinh vien theo ten\n";
	            cout << "9. Xoa sinh vien theo ma\n";
	            cout << "10. Sap xep theo diem\n";
	            cout << "11.Them danh sach sinh vien tu file\n";
	            cout << "12.Xuat danh sach sinh vien ra file\n";
	            cout << "0. Thoat\n";
	            cout << "Lua chon cua ban: ";
	            cin >> choice;
	            
	            switch(choice){
	            	case 1:{
	            		dssv.themSinhVien();
						break;
					}
					case 2: {
						int n;
						cout << "Nhap so luong sinh vien muon them: ";
						cin >> n;
						for(int i=0;i<n;i++){
							cout << "Nhap sinh vien thu "<<i+1 << " :\n";
							dssv.themSinhVien();
						}
						break;
					}
					case 3:{
						dssv.xuatDanhSach();
						break;
					}
					case 4:{
						cout << "Nhap ma sinh vien muon sua: ";
						string x;
						cin >> x;
						dssv.suaSinhVien(x);
						break;
					}
					
					case 5:{
						cout << "Sinh vien co diem cao nhat la: \n";
						SinhVien a = dssv.maxDiem();
						cout << a <<endl;
						break;
					}
					case 6:{
						cout << "Sinh Vien co diem thap nhat la: \n";
						SinhVien b= dssv.minDiem();
						cout << b <<endl;
						break;
					}
					case 7:{
						cout << "Nhap msv can tim kiem: ";
						string x;
						cin >> x;
						SinhVien *a = dssv.timKiemBangMsv(x);
						if(a==nullptr){
							cout << "Khong co sinh vien nao co msv "<< x;
						}
						else cout << *a;
						break;
					}
					case 8:{
						cout << "Nhap ten sinh vien can tim kiem: ";
						string x;
						cin.ignore();
						getline(cin,x);
						dssv.timKiemBangTensv(x);
						break;
					}
					case 9:{
						string x;
						cout << "Nhap msv can xoa: ";
						cin >> x;
						dssv.xoaSinhVien(x);
						break;
					}
					case 10:{
						dssv.sapXep();
						break;
					}
					case 11:{
						cout << "Nhap ten file nhap: ";
						string x;cin >> x;
						dssv.docDanhSachTuFile(x);
						break;
					}
					case 12: {
						cout << "Nhap ten file xuat: ";
						string x;cin >> x;
						dssv.xuatDanhSachRaFile(x);
						break;
					}
					case 0:{
						cout << "---Cam on ban da su dung chuong trinh---";
						break;
					}
					default:
						cout << "Lua chon khong hop le.\n";
				}
			}while(choice!=0);
		}
};

int main() {
    App app;
    app.menu();
    return 0;
}
