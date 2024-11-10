#ifndef DANHSACHSINHVIEN_H
#define DANHSACHSINHVIEN_H
#include "sinhvien.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class DanhSachSinhVien{
	private:
		vector<SinhVien> danhSach;
	public: 
		void themSinhVien(const SinhVien& sv){
			danhSach.push_back(sv);
		}
		void themSinhVien(){
			SinhVien x;
			cin>> x;
			danhSach.push_back(x);
		}
		void xuatDanhSach(){
			cout << "Danh Sach cac sinh vien:\n";
			for(const auto& sv: danhSach){
				cout << sv;
			}
		}
		void xuatSinhVien(int x){
			cout << danhSach[x];
		}
		void suaSinhVien(string masv){
			bool found=false;
			SinhVien* sv=timKiemBangMsv(masv);
			SinhVien x;
			cin >> x;
			*sv = x;
		}
		void docDanhSachTuFile(const string& tenFile){
			ifstream file(tenFile);
			if(!file.is_open()){
				cout << "Khong mo duoc file " << tenFile << endl;
        		return;
			}
			danhSach.clear();
			string msv,ten,lop;
			int tuoi;
			float diem;
			
			while(getline(file,msv)&&getline(file,ten)&& file >> lop >> tuoi >> diem){
				file.ignore();
				SinhVien sv(msv,ten,lop,tuoi,diem);
				danhSach.push_back(sv);
			}
			file.close();
			cout << "Da doc danh sach sinh vien tu file " << tenFile <<endl;
			
		}
		void xuatDanhSachRaFile(const string& tenFile){
			ofstream file(tenFile);
			if (!file.is_open()) {
		        cout << "Khong mo duoc file " << tenFile << endl;
		        return;
		    }
		    for(auto& sv: danhSach){
		    	file << sv.getMsv() <<endl << sv.getTen() << endl << sv.getLop() << " " << sv.getTuoi() << " " << sv.getDiem() <<endl;
			}
			file.close();
			cout << "Da xuat danh sach sinh vien ra file " << tenFile << endl;
		}
		void sapXep(){
			sort(danhSach.begin(),danhSach.end());
		}
		SinhVien maxDiem(){
			int vt=0;
			float max=danhSach[0].getDiem();
			for(int i=1;i<danhSach.size();i++){
				if(max<danhSach[i].getDiem()){
					max=danhSach[i].getDiem();
					vt=i;
				}
			}
			return danhSach[vt];
		}
		SinhVien minDiem(){
			int vt=0;
			float min=danhSach[0].getDiem();
			for(int i=1;i<danhSach.size();i++){
				if(min>danhSach[i].getDiem()){
					min=danhSach[i].getDiem();
					vt=i;
				}
			}
			return danhSach[vt];
		}
		SinhVien* timKiemBangMsv(string masv) {
			for(auto& sv:danhSach){
				if(sv.getMsv()==masv){
					return &sv;
				}
			}
			return nullptr;
		}

		void timKiemBangTensv(string ten){
			int count=0;
			cout << "Sinh vien co ten "<<ten<< " la :\n";
			for(int i=0;i<danhSach.size();i++){
				if(danhSach[i].getTen()==ten){
					cout << danhSach[i];
					count++;
				}
			}
			if(count==0){
				cout << "Khong co sinh vien nao ten "<< ten<<endl;
			}
		}
		void xoaSinhVien(string masv){
			bool found=false;
			for(int i=0;i<danhSach.size();i++){
				if(danhSach[i].getMsv()==masv){
					found=true;
					danhSach.erase(danhSach.begin()+i);
					cout << "Da xoa sinh vien co msv " <<masv<<endl;
				}
			}
			if(!found){
				cout << "Khong tim thay sinh vien co msv "<<masv <<endl;
			}
		}
};







#endif
