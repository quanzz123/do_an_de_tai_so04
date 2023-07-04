#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<iomanip>
#include <algorithm>

using namespace std;
bool check1;
class Sach {
protected:
    string maSoSach;
    string tenSach;
    string chuDe;
    string tacGia;
    string nhaXuatBan;
    string ngayXuatBan;
    string phuongthuc;
    int soTrang;
    int soBanLuu;

public:
    Sach(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, string phuongthuc, int soTrang, int soBanLuu) {
        maSoSach = maSo;
        tenSach = ten;
        this->chuDe = chuDe;
        this->tacGia = tacGia;
        this->nhaXuatBan = nhaXuatBan;
        this->ngayXuatBan = ngayXuatBan;
        this->phuongthuc = phuongthuc;

        this->soTrang = soTrang;
        this->soBanLuu = soBanLuu;
    }

    virtual void hienThiThongTin() {
        
        cout << "|" << setw(10) << left << maSoSach;
        cout << "|" << setw(10) << left << tenSach;
        cout << "|" << setw(10) << left << chuDe;
        cout << "|" << setw(10) << left << tacGia;
        cout << "|" << setw(15) << left << nhaXuatBan;
        cout << "|" << setw(15) << left << ngayXuatBan;
        cout << "|" << setw(15) << left << phuongthuc;
        cout << "|" << setw(5) << left << soTrang;
        cout << "|" << setw(5) << left << soBanLuu;

    }
    virtual void hienthirafile(ofstream& file) {
      
        file << "|" << setw(10) << left << maSoSach
        << "|" << setw(10) << left << tenSach
        << "|" << setw(10) << left << chuDe
        << "|" << setw(10) << left << tacGia
        << "|" << setw(15) << left << nhaXuatBan
        << "|" << setw(15) << left << ngayXuatBan
        << "|" << setw(15) << left << phuongthuc
        << "|" << setw(5) << left << soTrang
        << "|" << setw(5) << left << soBanLuu;
    }
    // Getter và Setter cho các thuộc tính

    string getMaSoSach() {
        return maSoSach;
    }

    void setMaSoSach(string maSo) {
        maSoSach = maSo;
    }

    string getTenSach() {
        return tenSach;
    }

    void setTenSach(string ten) {
        tenSach = ten;
    }

    string getChuDe() {
        return chuDe;
    }

    void setChuDe(string chuDe) {
        this->chuDe = chuDe;
    }

    string getTacGia() {
        return tacGia;
    }

    void setTacGia(string tacGia) {
        this->tacGia = tacGia;
    }

    string getNhaXuatBan() {
        return nhaXuatBan;
    }

    void setNhaXuatBan(string nhaXuatBan) {
        this->nhaXuatBan = nhaXuatBan;
    }

    string getNgayXuatBan() {
        return ngayXuatBan;
    }

    void setNgayXuatBan(string ngayXuatBan) {
        this->ngayXuatBan = ngayXuatBan;
    }
    string getphuongthuc() {
        return phuongthuc;
    }
    void setphuongthuc(string phuongthuc) {
        this->phuongthuc = phuongthuc;
    }

    int getSoTrang() {
        return soTrang;
    }

    void setSoTrang(int soTrang) {
        this->soTrang = soTrang;
    }

    int getSoBanLuu() {
        return soBanLuu;
    }

    void setSoBanLuu(int soBanLuu) {
        this->soBanLuu = soBanLuu;
    }

};

class SachMuonVe : public Sach {
private:
    string ngayMuon;
    string ngayHenTra;

public:
    SachMuonVe(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, string phuongthuc, int soTrang, int soBanLuu, string ngayMuon, string ngayHenTra)
        : Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu) {
        this->ngayMuon = ngayMuon;
        this->ngayHenTra = ngayHenTra;
    }

    void hienThiThongTin() override {
        cout << "|" << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(5) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(5) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|" << endl;
        cout << setfill(' ');
        Sach::hienThiThongTin();
        cout << "|" << setw(15) << left << ngayMuon;
        cout << "|" << setw(15) << left << ngayHenTra << "|";
    }
    void hienthirafile(ofstream& file) {
        file << "|" << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(5) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(5) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|" << endl;
        file << setfill(' ');
        Sach::hienthirafile(file);
        file << "|" << setw(15) << left << ngayMuon
            << "|" << setw(15) << left << ngayHenTra << "|";
    }
    string getNgayMuon() {
        return ngayMuon;
    }
    string getNgayHenTra() {
        return ngayHenTra;
    }
};

class SachMuonDoc : public Sach {
private:
    string gioMuon;
    string gioTra;

public:
    SachMuonDoc(string maSo, string ten, string chuDe, string tacGia, string nhaXuatBan, string ngayXuatBan, string phuongthuc, int soTrang, int soBanLuu, string gioMuon, string gioTra)
        : Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu) {
        this->gioMuon = gioMuon;
        this->gioTra = gioTra;
    }
    void hienThiThongTin() override {
        cout << "|" << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(10) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(5) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(5) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|";
        cout << setfill(' ');
        cout << setfill('-') << setw(15) << "-" << "|" << endl;
        cout << setfill(' ');
        Sach::hienThiThongTin();
        
    }
    void hienthirafile(ofstream& file) {
        file << "|" << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(10) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(5) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(5) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|";
        file << setfill(' ');
        file << setfill('-') << setw(15) << "-" << "|" << endl;
        file << setfill(' ');
        Sach::hienthirafile(file);
        file << "|" << setw(10) << left << gioMuon
            << "|" << setw(10) << left << gioTra << "|";
    }
    string getGioMuon() {
        return gioMuon;
    }
    string getGioTra() {
        return gioTra;
    }
   

};