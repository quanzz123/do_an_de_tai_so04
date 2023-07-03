#include "doAn04.h"
void timKiemThongTin_tg(const vector<Sach*>& danhSachSach, const string& TimKiemTG) {
    bool timThay = false;

    cout << "Thong tin cac sach tim thay:\n\n" << endl;
    for (const auto& Sach : danhSachSach) {
        if (Sach->getTacGia() == TimKiemTG) {
            Sach->hienThiThongTin();
            cout << endl;
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sach voi ten '" << TimKiemTG << "'" << endl << endl;
    }
}
void timKiemThongTin_ma(const vector<Sach*>& danhSachSach, const string& ma_sach) {
    bool timThay = false;

    cout << "Thong tin cac sach tim thay:\n\n" << endl;
    for (const auto& Sach : danhSachSach) {
        if (Sach->getMaSoSach() == ma_sach) {
            Sach->hienThiThongTin();
            cout << endl;
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sach voi ten '" << ma_sach << "'" << endl << endl;
    }
}
void timKiemThongTin_nxb(const vector<Sach*>& danhSachSach, const string& nxb) {
    bool timThay = false;

    cout << "Thong tin cac sach tim thay:\n\n" << endl;
    for (const auto& Sach : danhSachSach) {
        if (Sach->getNhaXuatBan() == nxb) {
            Sach->hienThiThongTin();
            cout << endl;
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay sach voi ten '" << nxb << "'" << endl << endl;
    }
}

void sap_xep_theo_so_trang_Sach_muon_doc_giamdan(vector<SachMuonDoc>& arr)
{
    for (int i = 0; i > arr.size() - 1; i++)
    {
        for (int j = i + 1; j > arr.size(); j++)
        {
            if (arr[j].getSoTrang() < arr[i].getSoTrang())
            {
                SachMuonDoc bientam = arr[i];
                arr[i] = arr[j];
                arr[j] = bientam;
            }
        }
    }
}
void sapXepTheoSoTrangSachMuonDocGiamDan(vector<Sach*>& danhSachSach) {
    for (int i = 0; i < danhSachSach.size() - 1; i++) {
        for (int j = i + 1; j < danhSachSach.size(); j++) {
            SachMuonDoc* sach1 = dynamic_cast<SachMuonDoc*>(danhSachSach[i]);
            SachMuonDoc* sach2 = dynamic_cast<SachMuonDoc*>(danhSachSach[j]);

            if (sach1 != nullptr && sach2 != nullptr) {
                if (sach1->getSoTrang() < sach2->getSoTrang()) {
                    swap(danhSachSach[i], danhSachSach[j]);
                }
            }
        }
    }
}
void sapXepTheoSoTrangSachMuonVeGiamDan(vector<Sach*>& danhSachSach) {
    for (int i = 0; i < danhSachSach.size() - 1; i++) {
        for (int j = i + 1; j < danhSachSach.size(); j++) {
            SachMuonVe* sach1 = dynamic_cast<SachMuonVe*>(danhSachSach[i]);
            SachMuonVe* sach2 = dynamic_cast<SachMuonVe*>(danhSachSach[j]);

            if (sach1 != nullptr && sach2 != nullptr) {
                if (sach1->getSoTrang() < sach2->getSoTrang()) {
                    swap(danhSachSach[i], danhSachSach[j]);
                }
            }
        }
    }
}
int main() {
    vector<Sach*>danhsachsach;
    int choice;
    do {
        cout << "\t\t\t\t===============MENU=================================\n";
        cout << "\t\t\t\t1.Nhap du lieu tu file!" << endl;
        cout << "\t\t\t\t2.hien thi danh sach muon doc" << endl;
        cout << "\t\t\t\t3.Hien thi danh sach muon ve" << endl;
        cout << "\t\t\t\t4.Tim kiem!" << endl;
        cout << "\t\t\t\t5.Thong ke theo tieu chi!" << endl;
        cout << "\t\t\t\t6.thoat!" << endl;
        cout << "\t\t\t\t====================================================" << endl;
        cout << "\t\t\t\tmoi nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            system("cls");
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
                cout << "\t\t\t\tKhong the mo file data.txt" << endl;
                return 0;
            }
            cout << "\t\t\t\tnap du lieu thanh cong!" << endl;
            break;
        }
        case 2: {
            system("cls");
            if (danhsachsach.empty()) {
                cout << "\t\t\t\tchua co du lieu! Hay them du lieu tu chuc nang 1!" << endl;
            }
            else {
                cout << "========= DANH SACH MUON VE =========\n\n" << endl;
                for (const auto& sach : danhsachsach) {
                    SachMuonVe* sachmuonve = dynamic_cast<SachMuonVe*>(sach);
                    if (sachmuonve != nullptr) {
                        sachmuonve->hienThiThongTin();
                        cout<< endl;
                    }
                }
            }
            cout << "---------------------------------------------------" << endl;
            cout << "Ban co muon in danh sach ra tep tin? (Y/N): ";
            char printChoice;
            cin >> printChoice;

            if (printChoice == 'Y' || printChoice == 'y') {
                ofstream outputFile("hienthi.txt");
                if (outputFile.is_open()) {
                    outputFile << "\t\t\t========= Hien thi danh sach muon doc =========" << endl;
                    for (const auto& sach : danhsachsach) {
                        SachMuonVe* sachmuonve = dynamic_cast<SachMuonVe*>(sach);
                        if (sachmuonve != nullptr) {
                            sachmuonve->hienthirafile(outputFile);
                            outputFile << endl;
                        }
                    }
                    outputFile.close();
                    cout << "\n\t\t\t\tDa hien thi ra tep hienthi.txt!" << endl;
                }
                else {
                    cout << "\t\t\t\tKhong the mo tep hienthi.txt" << endl;
                }
            }
            break;
        }
        case 3: {
            system("cls");
            if (danhsachsach.empty()) {
                cout << "\t\t\t\tchua co du lieu! Hay them du lieu tu chuc nang 1!" << endl;
            }
            else {
                cout << "============DACH SACH MUON DOC========\n\n" << endl;
                for (const auto& sach : danhsachsach) {
                    SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                    if (sachmuondoc != nullptr) {
                        sachmuondoc->hienThiThongTin();
                        
                        cout<< endl;
                    }
                }
            }
            cout << "---------------------------------------------------" << endl;
            cout << "Ban co muon in danh sach ra tep tin? (Y/N): ";
            char printChoice;
            cin >> printChoice;

            if (printChoice == 'Y' || printChoice == 'y') {
                ofstream outputFile("hienthi.txt");
                if (outputFile.is_open()) {
                    outputFile << "\t\t\t========= Hien thi danh sach muon doc =========" << endl;
                    for (const auto& sach : danhsachsach) {
                        SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                        if (sachmuondoc != nullptr) {
                            sachmuondoc->hienthirafile(outputFile);
                            outputFile << endl;
                        }
                    }
                    outputFile.close();
                    cout << "\n\t\t\t\tDa hien thi ra tep hienthi.txt!" << endl;
                }
                else {
                    cout << "\t\t\t\tKhong the mo tep hienthi.txt" << endl;
                }
            }
            break;
        }
        case 4: {
            system("cls");
            int choice4;
            do {
                cout << "TIM KIEM THEO TIEU CHI" << endl;
                cout << "1.tim kiem theo ten tac gia" << endl;
                cout << "2.tim kiem theo ma sach" << endl;
                cout << "3.tim kem theo nha xuat ban" << endl;
                cout << "4.quay lai" << endl;
                cout << "Nhap lua chon: ";
                cin >> choice4;
                switch (choice4)
                {
                case 1: {
                    system("cls");
                    string name_tg;
                    cout << "Nhap ten tac gia: ";
                    cin.ignore();
                    getline(cin, name_tg);
                    timKiemThongTin_tg(danhsachsach, name_tg);
                    break;
                }
                case 2: {
                    system("cls");
                    string ma;
                    cout << "Nhap ma can tim: ";
                    cin.ignore();
                    getline(cin, ma);
                    timKiemThongTin_ma(danhsachsach, ma);
                    break;
                }
                case 3: {
                    system("cls");
                    string name_nxb;
                    cout << "Nhap ten nxb can tim: ";
                    cin.ignore();
                    getline(cin, name_nxb);
                    timKiemThongTin_nxb(danhsachsach, name_nxb);
                }
                case 4: {
                    break;
                }
                default:
                    break;
                }
            } while (choice4 != 4);
            break;
        }
        case 5: {
            system("cls");
            int choice5;
            do {
                cout << "THONG KE THEO TIEU CHI" << endl;
                cout << "1.thong ke danh sach tang dan so trang sach muon doc" << endl;
                cout << "2.thong ke danh sach tang dan so trang sach muon ve" << endl;
                cout << "3.thoat" << endl;
                cout << "moi nhap lua chon: ";
                cin >> choice5;
                switch (choice5)
                {
                case 1: {
                    system("cls");
                    if (danhsachsach.empty()) {
                        cout << "\t\t\t\tchua co du lieu! Hay them du lieu tu chuc nang 1!" << endl;
                    }
                    else {
                        // Sắp xếp danh sách sách mượn đọc theo số trang tăng dần
                       /* vector<SachMuonDoc*> sachmuondocList;
                        for (const auto& sach : danhsachsach) {
                            SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                            if (sachmuondoc != nullptr) {
                                sachmuondocList.push_back(sachmuondoc);
                            }
                        }*/
                        // Bubble Sort để sắp xếp danh sách
                        sapXepTheoSoTrangSachMuonDocGiamDan(danhsachsach);
                        cout << "============DACH SACH SACH MUON DOC========\n\n" << endl;
                        for (const auto& sach : danhsachsach) {
                            SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                            if (sachmuondoc != nullptr) {
                                sachmuondoc->hienThiThongTin();

                                cout << endl;
                            }
                        }                        
                    }
                    break;
                }
                default:
                    break;
                }
            } while (choice5 != 3);
            break;
        }
        case 6:
            cout << "\t\t\t\tket thuc chuong trinh!" << endl;
            exit(1);
            break;
        default:
            cout << "\t\t\t\tlua chon khong hop le!" << endl;
        }
    } while (choice != 6);
    system("pause");
    return 0;
}