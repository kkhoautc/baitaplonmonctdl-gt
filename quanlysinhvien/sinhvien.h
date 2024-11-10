#ifndef SINHVIEN_H
#define SINHVIEN_H
#include <iostream>
#include <string>
using namespace std;

class SinhVien{
	private:
		string msv;
		string ten;
		string lop;
		int tuoi;
		int diem;
	public:
		SinhVien(){
		}
		SinhVien(string ma,string tensv,string lopsv,int tuoisv,int diemsv){
			msv=ma,ten=tensv,lop=lopsv,tuoi=tuoisv,diem=diemsv;
		}
		string getMsv(){
			return msv;
		}
		string getTen(){
			return ten;
		}
		float getDiem(){
			return diem;
		}
		string getLop(){
			return lop;
		}
		int getTuoi(){
			return tuoi;
		}
		friend istream& operator>>(istream& is,SinhVien& sv){
			cout << "Nhap ma sinh vien: "; is>>sv.msv;
			cout << "Nhap ten sinh vien: "; is.ignore();getline(is,sv.ten);
			cout << "Nhap lop sinh vien: "; is>>sv.lop;
			cout << "Nhap tuoi: ";is>>sv.tuoi;
			cout << "Nhap diem: ";is>> sv.diem;
			return is;
		}
		friend ostream& operator<<(ostream& os,const SinhVien& sv){
			os << "Ma SV: " << sv.msv << "\t Ten:" << sv.ten << "\t Lop:" << sv.lop
		    	<< "\tTuoi:" << sv.tuoi << "\tDiem:" << sv.diem<<endl;
		    return os;
		}
		bool operator<(const SinhVien& sosanh){
			return diem<sosanh.diem;
		}
		bool operator>(const SinhVien& sosanh){
			return diem>sosanh.diem;
		}
};
#endif
