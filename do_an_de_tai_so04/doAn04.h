#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include<iomanip>

using namespace std;

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
        cout << "ma so sach: " << maSoSach << endl;
        cout << "Ten sach: " << tenSach << endl;
        cout << "Chu de: " << chuDe << endl;
        cout << "Tac gia: " << tacGia << endl;
        cout << "nha xuat ban: " << nhaXuatBan << endl;
        cout << "ngay xuat ban: " << ngayXuatBan << endl;
        cout << "phuong thuc: " << phuongthuc << endl;
        cout << "So trang: " << soTrang << endl;
        cout << "So ban luu thu vien: " << soBanLuu << endl;
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
        Sach::hienThiThongTin();
        cout << "Ngay muon: " << ngayMuon << endl;
        cout << "Ngay hen tra: " << ngayHenTra << endl;
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
        Sach::hienThiThongTin();
        cout << "Gio muon doc: " << gioMuon << endl;
        cout << "Gio tra: " << gioTra << endl;
    }
    string getGioMuon() {
        return gioMuon;
    }
    string getGioTra() {
        return gioTra;
    }
};