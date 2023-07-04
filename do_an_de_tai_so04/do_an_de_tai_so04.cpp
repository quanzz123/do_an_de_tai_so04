#include "doAn04.h"
void timKiemThongTin_tg(const vector<Sach*>& danhSachSach, const string& TimKiemTG) {
    bool timThay = false;

    cout << "Thong tin cac sach tim thay:\n\n" << endl;
    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(10) << left << "MSS";
    cout << "|" << setw(10) << left << "NAME";
    cout << "|" << setw(10) << left << "TOPIC";
    cout << "|" << setw(10) << left << "TG";
    cout << "|" << setw(15) << left << "NXB";
    cout << "|" << setw(15) << left << "DATEXB";
    cout << "|" << setw(15) << left << "STA";
    cout << "|" << setw(5) << left << "ST";
    cout << "|" << setw(5) << left << "SBL";
    cout << "|" << setw(15) << left << "MUON";
    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
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
    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(10) << left << "MSS";
    cout << "|" << setw(10) << left << "NAME";
    cout << "|" << setw(10) << left << "TOPIC";
    cout << "|" << setw(10) << left << "TG";
    cout << "|" << setw(15) << left << "NXB";
    cout << "|" << setw(15) << left << "DATEXB";
    cout << "|" << setw(15) << left << "STA";
    cout << "|" << setw(5) << left << "ST";
    cout << "|" << setw(5) << left << "SBL";
    cout << "|" << setw(15) << left << "MUON";
    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
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
    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(10) << left << "MSS";
    cout << "|" << setw(10) << left << "NAME";
    cout << "|" << setw(10) << left << "TOPIC";
    cout << "|" << setw(10) << left << "TG";
    cout << "|" << setw(15) << left << "NXB";
    cout << "|" << setw(15) << left << "DATEXB";
    cout << "|" << setw(15) << left << "STA";
    cout << "|" << setw(5) << left << "ST";
    cout << "|" << setw(5) << left << "SBL";
    cout << "|" << setw(15) << left << "MUON";
    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
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
// hàm sắp xếp so trang giảm dần của loại sách mượn đọc
// sử dụng thuật toán sắp xếp Bubble Sort
// chả khác gì sắp xếp trong mảng một chiều cả ở trong mảng một chiều sẽ là for(int i=0; i<n;i++ )
// còn ở đây arr.size() là một phương thức của kiểu vector nhằm trả về kích thước hay còn gọi là số phần tử giống như n phần tử
// đối tượng so sánh đây là số trang thì cho chấm dến số trang bằng phương thức getter để lấy dữ liệu
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
// dười này cũng là hàm sắp xếp của sách muọn đọc tiếp mà đổi gió thôi
// cơ bản vẫn dùng lại thuật toán sắp xếp bubble sort
// khác ở đây là ở trên kia thì duyệt các phần tử ngay trong sachmuondoc 
// còn ở dưới này thì duyệt các phần tử trong kiểu Sach và ép kiể sách sang kiểu sachmuondoc để so sánh
// ở dây ta có hàm swap là hàm đổi chỗ, ở trên kia phải ử dụng biến tạm để làm trung gian thì mới đổi chỗ được
// hai vị trí còn ở đây dùng hàm swap trong thư viện algorithm để đổi chỗ hai phần tử trong mảng
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
// tương tự chúng ta dùng để sắp xếp sachmuonve
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
void displaymenu1() {
    cout << "\t\t\t\t===============MENU=================================\n";
    cout << "\t\t\t\t1.Nhap du lieu tu file!" << endl;
    cout << "\t\t\t\t2.hien thi danh sach muon ve" << endl;
    cout << "\t\t\t\t3.Hien thi danh sach muon doc" << endl;
    cout << "\t\t\t\t4.Tim kiem!" << endl;
    cout << "\t\t\t\t5.Thong ke theo tieu chi!" << endl;
    cout << "\t\t\t\t6.thoat!" << endl;
    cout << "\t\t\t\t====================================================" << endl;
    cout << "\t\t\t\tmoi nhap lua chon: ";
}
void displaymenu2() {
    cout << "\n\n\t\t\t\t============================" << endl;
    cout << "\t\t\t\tTIM KIEM THEO TIEU CHI" << endl;
    cout << "\t\t\t\t1.tim kiem theo ten tac gia" << endl;
    cout << "\t\t\t\t2.tim kiem theo ma sach" << endl;
    cout << "\t\t\t\t3.tim kem theo nha xuat ban" << endl;
    cout << "\t\t\t\t4.quay lai" << endl;
    cout << "\t\t\t\t5.exitnow" << endl;
    cout << "\t\t\t\t============================" << endl;
    cout << "\t\t\t\tNhap lua chon: ";
}
void displaymenu3() {
    cout << "\n\n\t\t\t\t==========================================================" << endl;
    cout << "t\t\t\t\tTHONG KE THEO TIEU CHI" << endl;
    cout << "\t\t\t\t1.thong ke danh sach giam dan so trang sach muon doc" << endl;
    cout << "\t\t\t\t2.thong ke danh sach giam dan so trang sach muon ve" << endl;
    cout << "\t\t\t\t3.quay lai" << endl;
    cout << "\t\t\t\t4.exitnow" << endl;
    cout << "\t\t\t\t==========================================================" << endl;
    cout << "\t\t\t\tmoi nhap lua chon: ";
}
int main() {
    /*lí do tại sao lại dùng kiểu Vector mà lại không dùng mảng động hay mảng tĩnh
    -vector được cài đặt dựa trên mảng động, nó cũng có thể coi là mảng động tuy nhiên
        +vector có khả năng thay đổi kích thước, thêm bớt các phần tử theo mong muốn
        giúp quản lí bộ nhớ tốt hơn
        + có nhiều phương thưc để can thiệp vào dữ liệu ví dụ như: push_back them dữ liệu vào cuối...*/
    vector<Sach*>danhsachsach;
    int menu1 = 1; // mục đích để kiểm tra xem đang ở menu nào?
    int menu2 = 2;
    int menu3 = 3;
    int luaChon;
    while (true) {
        if (menu1 == 1) { // menu1 = 1 thức hiện các chức năng của menu1 tức là menu cha
            displaymenu1();
            
            cin >> luaChon;

            switch (luaChon) {
            case 1: {
                system("cls"); // hàm xoá màn hình
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
                // phương thức empty trong vector ở đay nhắm kiểm tra xem trong vector đã có dữ liệu hay chưa
                if (danhsachsach.empty()) {
                    cout << "\t\t\t\tchua co du lieu! Hay them du lieu tu chuc nang 1!" << endl;
                }
                else {
                    cout << "\n\n\t\t\t========= DANH SACH MUON VE =========\n\n" << endl;
                    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                    cout << setfill(' ');
                    cout << "|" << setw(10) << left << "MSS";
                    cout << "|" << setw(10) << left << "NAME";
                    cout << "|" << setw(10) << left << "TOPIC";
                    cout << "|" << setw(10) << left << "TG";
                    cout << "|" << setw(15) << left << "NXB";
                    cout << "|" << setw(15) << left << "DATEXB";
                    cout << "|" << setw(15) << left << "STA";
                    cout << "|" << setw(5) << left << "ST";
                    cout << "|" << setw(5) << left << "SBL";
                    cout << "|" << setw(15) << left << "MUON";
                    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
                    /*duyệt qua các phần tử có trong vector danhsachsach, const auto dung để tự suy luận kiểu 
                    dữ liệu trong danh sách, sau đó ta thử ép kiểu thành kiểu sachmuonve , cho phép kiểm tra  xem đối tượng
                    trong danh sách có phải là dối tượng thuộc SachMuonVe hay không, nếu đúng thì trả về kiểu SachMuonDoc
                    sau khi em được kiểu mà đúng rồi thì kiểm tra dối tượng con trỏ đó xem nếu mà không rỗng thì trỏ đến hiên thị thông tin*/
                    for (const auto& sach : danhsachsach) {
                        SachMuonVe* sachmuonve = dynamic_cast<SachMuonVe*>(sach);
                        if (sachmuonve != nullptr) {
                            sachmuonve->hienThiThongTin();
                            cout << endl;
                        }
                    }
                }
                /*tạo lựa chọn xem có muốn in dữ liệu ra tệp hienthi.txt hay không
                đồng ý ấn y hoặc Y không đồng ý cấn n*/
                cout << "---------------------------------------------------" << endl;
                cout << "Ban co muon in danh sach ra tep tin? (Y/N): ";
                char printChoice;
                cin >> printChoice;
                if (printChoice == 'Y' || printChoice == 'y') {
                    ofstream outputFile("hienthi.txt");
                    if (outputFile.is_open()) {
                        outputFile << "\t\t\t========= HIEN THI DANH SACH MUON VE =========\n\n" << endl;
                        outputFile << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                        outputFile << setfill(' ');
                        outputFile << "|" << setw(10) << left << "MSS";
                        outputFile << "|" << setw(10) << left << "NAME";
                        outputFile << "|" << setw(10) << left << "TOPIC";
                        outputFile << "|" << setw(10) << left << "TG";
                        outputFile << "|" << setw(15) << left << "NXB";
                        outputFile << "|" << setw(15) << left << "DATEXB";
                        outputFile << "|" << setw(15) << left << "STA";
                        outputFile << "|" << setw(5) << left << "ST";
                        outputFile << "|" << setw(5) << left << "SBL";
                        outputFile << "|" << setw(15) << left << "MUON";
                        outputFile << "|" << setw(15) << left << "TRA" << "|" << endl;
                        for (const auto& sach : danhsachsach) {
                            /*các giải tích tương tự với ác giải thích trên tuy nhiên ở đây không không trỏ đến hienthi thông thường
                            mà là trỏ đến phương thức hiển thị có đối chính là file output, hiểu nôm na là trỏ đến phương
                            thức hiển thị ra file*/
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
                    cout << "\n\n\t\t\t\t============DACH SACH MUON DOC========\n\n" << endl;
                    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                    cout << setfill(' ');
                    cout << "|" << setw(10) << left << "MSS";
                    cout << "|" << setw(10) << left << "NAME";
                    cout << "|" << setw(10) << left << "TOPIC";
                    cout << "|" << setw(10) << left << "TG";
                    cout << "|" << setw(15) << left << "NXB";
                    cout << "|" << setw(15) << left << "DATEXB";
                    cout << "|" << setw(15) << left << "STA";
                    cout << "|" << setw(5) << left << "ST";
                    cout << "|" << setw(5) << left << "SBL";
                    cout << "|" << setw(15) << left << "MUON";
                    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
                    for (const auto& sach : danhsachsach) {
                        SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                        if (sachmuondoc != nullptr) {
                            sachmuondoc->hienThiThongTin();

                            cout << endl;
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
                        outputFile << "\t\t\t========= Hien thi danh sach muon doc =========\n\n" << endl;
                        outputFile << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                        outputFile << setfill(' ');
                        outputFile << "|" << setw(10) << left << "MSS";
                        outputFile << "|" << setw(10) << left << "NAME";
                        outputFile << "|" << setw(10) << left << "TOPIC";
                        outputFile << "|" << setw(10) << left << "TG";
                        outputFile << "|" << setw(15) << left << "NXB";
                        outputFile << "|" << setw(15) << left << "DATEXB";
                        outputFile << "|" << setw(15) << left << "STA";
                        outputFile << "|" << setw(5) << left << "ST";
                        outputFile << "|" << setw(5) << left << "SBL";
                        outputFile << "|" << setw(15) << left << "MUON";
                        outputFile << "|" << setw(15) << left << "TRA" << "|" << endl;
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
                menu1 = menu2;
                system("cls");
                break;
            }
            case 5: {
                menu1 = menu3;
                system("cls");
                break;
            }
            case 6:
                cout << "\n\n\t\t\t\tTHOAT CHUONG TRINH" << endl;
                exit(1);
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
        else if (menu1 == menu2) {
            displaymenu2();
            
            cin >> luaChon;

            switch (luaChon) {
            case 1: {
                // Thuc hien lua chon 1 trong menu con 1
                system("cls");
                string name_tg;
                cout << "Nhap ten tac gia: ";
                cin.ignore();
                getline(cin, name_tg);
                timKiemThongTin_tg(danhsachsach, name_tg);
                break;
            }
            case 2: {
                // Thuc hien lua chon 2 trong menu con 1
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
                break;
            }
            case 4: {
                menu1 = 1; // Quay lai menu cha

                break;
            }
            case 5:
                exit(1);
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
        else if (menu1 == menu3) {
            displaymenu3();
            
            cin >> luaChon;

            switch (luaChon) {
            case 1: {
                // Thuc hien lua chon 1 trong menu con 2
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
                    cout << "\t\t\t\t============DACH SACH SACH MUON DOC GIAM DAN THEO SO TRANG========\n\n" << endl;
                    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                    cout << setfill(' ');
                    cout << "|" << setw(10) << left << "MSS";
                    cout << "|" << setw(10) << left << "NAME";
                    cout << "|" << setw(10) << left << "TOPIC";
                    cout << "|" << setw(10) << left << "TG";
                    cout << "|" << setw(15) << left << "NXB";
                    cout << "|" << setw(15) << left << "DATEXB";
                    cout << "|" << setw(15) << left << "STA";
                    cout << "|" << setw(5) << left << "ST";
                    cout << "|" << setw(5) << left << "SBL";
                    cout << "|" << setw(15) << left << "MUON";
                    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
                    for (const auto& sach : danhsachsach) {
                        SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                        if (sachmuondoc != nullptr) {
                            sachmuondoc->hienThiThongTin();

                            cout << endl;
                        }
                    }
                    cout << "\n\n--------------------------------------------" << endl;
                    cout << "\nBan co muon in danh dach ra tep hienthi.txt ? (Y/N) : ";
                    char choicep;
                    cin >> choicep;
                    if (choicep == 'Y' || choicep == 'y') {
                        ofstream outputfile("hienthi.txt");
                        if (outputfile.is_open()) {
                            outputfile << "\n\t\t\tHIEN THI DANH SACH MUON DOC TANG GIAM DAN THEO SO TRANG\n\n" << endl;
                            outputfile << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                            outputfile << setfill(' ');
                            outputfile << "|" << setw(10) << left << "MSS";
                            outputfile << "|" << setw(10) << left << "NAME";
                            outputfile << "|" << setw(10) << left << "TOPIC";
                            outputfile << "|" << setw(10) << left << "TG";
                            outputfile << "|" << setw(15) << left << "NXB";
                            outputfile << "|" << setw(15) << left << "DATEXB";
                            outputfile << "|" << setw(15) << left << "STA";
                            outputfile << "|" << setw(5) << left << "ST";
                            outputfile << "|" << setw(5) << left << "SBL";
                            outputfile << "|" << setw(15) << left << "MUON";
                            outputfile << "|" << setw(15) << left << "TRA" << "|" << endl;
                            for (const auto& sach : danhsachsach) {
                                SachMuonDoc* sachmuondoc = dynamic_cast<SachMuonDoc*>(sach);
                                if (sachmuondoc != nullptr) {
                                    sachmuondoc->hienthirafile(outputfile);
                                    outputfile << endl;
                                }
                            }
                            outputfile.close();
                            cout << "\n\t\t\t\tDA HIEN THI DU LIEU RA TEP thietbi.txt" << endl;
                        }
                        else {
                            cout << "\n\t\t\t\tKHONG THE MO TEP hienthi.txt" << endl;
                        }
                    }

                }
                break;
            }
            case 2: {
                // Thuc hien lua chon 2 trong menu con 2
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
                    sapXepTheoSoTrangSachMuonVeGiamDan(danhsachsach); // gọi hàm sắp xếp các dữ liệu trong danh sách sách
                    cout << "\t\t\t\t============DACH SACH SACH MUON VE GIAM DAN THEO SO TRANG========\n\n" << endl;
                    cout << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                    cout << setfill(' ');
                    cout << "|" << setw(10) << left << "MSS";
                    cout << "|" << setw(10) << left << "NAME";
                    cout << "|" << setw(10) << left << "TOPIC";
                    cout << "|" << setw(10) << left << "TG";
                    cout << "|" << setw(15) << left << "NXB";
                    cout << "|" << setw(15) << left << "DATEXB";
                    cout << "|" << setw(15) << left << "STA";
                    cout << "|" << setw(5) << left << "ST";
                    cout << "|" << setw(5) << left << "SBL";
                    cout << "|" << setw(15) << left << "MUON";
                    cout << "|" << setw(15) << left << "TRA" << "|" << endl;
                    for (const auto& sach : danhsachsach) {
                        SachMuonVe* sachmuonve = dynamic_cast<SachMuonVe*>(sach);
                        if (sachmuonve != nullptr) {
                            sachmuonve->hienThiThongTin();

                            cout << endl;
                        }
                    }
                    cout << "\n\n--------------------------------------------" << endl;
                    cout << "\nBan co muon in danh dach ra tep hienthi.txt ? (Y/N) : ";
                    char choicep;
                    cin >> choicep;
                    if (choicep == 'Y' || choicep == 'y') {
                        ofstream outputfile("hienthi.txt");
                        if (outputfile.is_open()) {
                            outputfile << "\n\t\t\tHIEN THI DANH SACH MUON VE GIAM DAN THEO SO TRANG\n\n" << endl;
                            outputfile << "+" << setfill('-') << setw(135) << "-" << "+" << endl;
                            outputfile << setfill(' ');
                            outputfile << "|" << setw(10) << left << "MSS";
                            outputfile << "|" << setw(10) << left << "NAME";
                            outputfile << "|" << setw(10) << left << "TOPIC";
                            outputfile << "|" << setw(10) << left << "TG";
                            outputfile << "|" << setw(15) << left << "NXB";
                            outputfile << "|" << setw(15) << left << "DATEXB";
                            outputfile << "|" << setw(15) << left << "STA";
                            outputfile << "|" << setw(5) << left << "ST";
                            outputfile << "|" << setw(5) << left << "SBL";
                            outputfile << "|" << setw(15) << left << "MUON";
                            outputfile << "|" << setw(15) << left << "TRA" << "|" << endl;
                            for (const auto& sach : danhsachsach) {
                                SachMuonVe* sachmuonve = dynamic_cast<SachMuonVe*>(sach);
                                if (sachmuonve != nullptr) {
                                    sachmuonve->hienthirafile(outputfile);
                                    outputfile << endl;
                                }
                            }
                            outputfile.close();
                            cout << "\n\t\t\t\tDA HIEN THI DU LIEU RA TEP thietbi.txt" << endl;
                        }
                        else {
                            cout << "\n\t\t\t\tKHONG THE MO TEP hienthi.txt" << endl;
                        }
                    }

                }
                break;
            }
            case 3: {
                menu1 = 1; // Quay lai menu cha
                break;
            }
            case 4: {
                exit(1);
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
    }

    return 0;
}
    