#include "doAn04.h"
void timKiemThongTin(const vector<Sach*>& danhSachSach, const string& TimKiemTG) {
    bool timThay = false;

    cout << "Thong tin cac sach tim thay:\n\n" << endl;
    for (const auto& Sach : danhSachSach) {
        if (Sach->getTacGia() == TimKiemTG) {
            Sach->hienThiThongTin();
            cout << "-----------------";
            cout << endl;
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sach voi ten '" << TimKiemTG << "'" << endl << endl;
    }
}
int main() {
    vector<Sach*>danhsachsach;
    int choice;
    do {
        cout << "===============MENU==================\n";
        cout << "1.Nhap du lieu tu file!" << endl;
        cout << "2.hien thi danh sach muon doc" << endl;
        cout << "3.Hien thi vao tep!" << endl;
        cout << "4.thoat chuong trinh!" << endl;
        cout << "====================================================" << endl;
        cout << "moi nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {

            ifstream inputFile("data.txt");
            if (inputFile.is_open()) {
                string line;
                while (getline(inputFile, line)) {
                    // Xử lý và tạo đối tượng SachMuonVe từ dòng dữ liệu
                    // Ví dụ: 12345,Sach 1,Khoa hoc,Tac gia 1,Nha xuat ban kimdong,2022-01-01,200,5,2023-05-01,2023-05-15
                    // ... (phân tách dữ liệu và tạo đối tượng SachMuonVe) ...
                    // Sau đó, thêm đối tượng SachMuonVe vào danh sách danhSachSach
                    stringstream ss(line);
                    string maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, ngayMuon, ngayHenTra, gioMuon, gioTra;
                    int soTrang, soBanLuu;

                    getline(ss, maSo, ',');

                    getline(ss, ten, ',');

                    getline(ss, chuDe, ',');

                    getline(ss, tacGia, ',');

                    getline(ss, nhaXuatBan, ',');

                    getline(ss, ngayXuatBan, ',');

                    getline(ss, phuongthuc, ',');


                    ss >> soTrang;
                    ss.ignore();
                    ss >> soBanLuu;



                    if (phuongthuc == "doc") {
                        ss.ignore();
                        getline(ss, gioMuon, ',');

                        getline(ss, gioTra, ',');
                        danhsachsach.push_back(new SachMuonDoc(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu, gioMuon, gioTra));
                    }
                    else if (phuongthuc == "muon") {
                        ss.ignore();
                        getline(ss, ngayMuon, ',');

                        getline(ss, ngayHenTra, ',');

                        danhsachsach.push_back(new SachMuonVe(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu, ngayMuon, ngayHenTra));
                    }
                    else {

                        danhsachsach.push_back(new Sach(maSo, ten, chuDe, tacGia, nhaXuatBan, ngayXuatBan, phuongthuc, soTrang, soBanLuu));
                    }
                }

                inputFile.close();
            }
            else {
                cout << "Khong the mo file data.txt" << endl;
                return 0;
            }
            cout << "nap du lieu thanh cong!" << endl;
            break;
        }
        case 2: {
            cout << "========= DANH SACH MUON DOC =========\n\n" << endl;
            for (const auto& sach : danhsachsach) {
                SachMuonVe* sachmuonve = dynamic_cast<SachMuonVe*>(sach);
                if (sachmuonve != nullptr) {
                    sachmuonve->hienThiThongTin();
                    cout << "------------------------------------------------" << endl;
                }
            }
            break;
        }
        case 3: {
            ofstream outputfile("hienthi.txt");
            if (outputfile.is_open()) {
                outputfile << "\t\t\t=========hien thi danh sach muon ve =========" << endl;
                for (const auto& sach : danhsachsach) {
                    SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                    if (sachmuondoc != nullptr) {
                        outputfile << setw(5) << left << sachmuondoc->getMaSoSach()
                            << setw(10) << left << sachmuondoc->getTenSach()
                            << setw(15) << left << sachmuondoc->getChuDe()
                            << setw(10) << left << sachmuondoc->getTacGia()
                            << setw(25) << left << sachmuondoc->getNhaXuatBan()
                            << setw(15) << left << sachmuondoc->getNgayXuatBan()
                            << setw(5) << left << sachmuondoc->getphuongthuc()
                            << setw(5) << left << sachmuondoc->getSoTrang()
                            << setw(5) << left << sachmuondoc->getSoBanLuu()
                            << setw(7) << left << sachmuondoc->getGioMuon()
                            << setw(7) << left << sachmuondoc->getGioTra() << endl;
                    }
                }
            }

            outputfile.close();
            cout << "\nDA HIEN THI RA FILE HIENTHI.TXT!" << endl;
            break;
        }
        case 4:
            break;
        default:
            cout << "lua chon khong hop le!" << endl;
        }
    } while (choice != 4);
    system("pause");
    return 0;
}