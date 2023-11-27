#include"Header.h"
void Menu() {
    NodePtr ds;
    KhoiTao(ds);
    int choice;
    do {
        cout << "-----------------------------" << endl;
        cout << "----------- MENU ------------" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Nhap danh sach don hang" << endl;
        cout << "2. Xuat danh sach don hang" << endl;
        cout << "3. Tim don hang theo ma don" << endl;
        cout << "4. Tim don hang theo ma khach hang" << endl;
        cout << "5. Ghi danh sach vao file" << endl;
        cout << "6. Doc danh sach don hang tu file" << endl;
        cout << "7. Sap xep theo ma don hang (Buble Sort)" << endl;
        cout << "8. Sap xep theo ma khach hang (Selection Sort)" << endl;
        cout << "9. Sap xep theo so luong mon (Insertion Sort)" << endl;
        cout << "10. Xuat danh sach khach hang" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "-----------------------------" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            nhapDSDonHang(ds);
            break;
        case 2:
            XuatDonHang(ds);
            break;
        case 3:
            char maDH[10];
            cout << "Nhap ma don hang can tim: ";
            cin.getline(maDH, 10);
            if (timDonHangTheoMaDH(ds, maDH)) {
                cout << "Tim thay don hang." << endl;
            }
            else {
                cout << "Khong tim thay don hang voi ma don nay." << endl;
            }
            break;
        case 4:
            if (timDonHangTheoMaKH(ds)) {
                cout << "Tim thay don hang." << endl;
            }
            else {
                cout << "Khong tim thay don hang theo ma khach hang nay." << endl;
            }
            break;
        case 5:
            ghiFile("danh_sach_don_hang.bin", ds);
            break;
        case 6:
            docFile("danh_sach_don_hang.bin", ds);
            break;
        case 7:
            SapXepTheoMaDonHang(ds);
            break;
        case 8:
            SapXepTheoMaKhachHang(ds);
            break;
        case 9:
            SapXepTheoSoMonAn(ds);
            break;
        case 10:
            XuatDSKhachHang(ds);
            break;
        case 0:
            giaiPhong(ds);
            cout << "Da thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (choice != 0);
}

void KhoiTao(NodePtr& ds) {
    ds = NULL;
}

int isEmpty(NodePtr ds) {
    return ds == NULL;
}

void giaiPhong(NodePtr& ds) {
    NodePtr p;
    while (ds != NULL) {
        p = ds;
        ds = ds->link;
        delete p;
    }
}

NodePtr TaoNodeKH(KhachHang kh) {
    NodePtr p = new Node;
    p->dataKH = kh;
    p->link = NULL;
    return p;
}

NodePtr TaoNodeDH(DonHang& dh) {
    NodePtr p = new Node;
    p->dataDH = dh;
    p->link = NULL;
    return p;
}
NodePtr ThemDonHang(NodePtr& ds, DonHang& dh) {
    NodePtr p = TaoNodeDH(dh);
    p->link = ds;
    ds = p;
    return p;
}

NodePtr ThemKhachHang(NodePtr& ds, KhachHang& kh) {
    NodePtr p = TaoNodeKH(kh); 
    p->link = ds;
    ds = p;
    return p; 
}

bool kiemTra_TrungMa(NodePtr& ds, char* ma) {
    NodePtr p = ds;
    while (p != NULL) {
        if (strcmp(p->dataDH.MaDon, ma) == 0) {
            return true;
        }
        p = p->link;
    }
    return false;
}

void nhapDSDonHang(NodePtr& ds) {
    DonHang dh;
    KhachHang kh;
    int n;
    cout << "Nhap so luong don hang: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin don hang thu " << i + 1 << ":" << endl;
        cout << "Ma don(Nhap 0 de thoat): ";
        cin.getline(dh.MaDon, 10);
        while (kiemTra_TrungMa(ds, dh.MaDon)) {
            cout << "Ma don da ton tai. Vui long nhap lai: ";
            cin.getline(dh.MaDon, 10);
        }
        if (strcmp(dh.MaDon, "0") == 0)
            break;
        cout << "Ma khach hang: ";
        cin.getline(dh.MaKH, 10);
        cout << "Ten khach hang: ";
        cin.getline(kh.tenKH, 50);
        cout << "Dia chi: ";
        cin.getline(kh.DiaChi, 50);
        cout << "So dien thoai: ";
        cin >> kh.SDT;
        cin.ignore();   
        cout << "Trang thai don: ";
        cin.getline(dh.TrangThaiDon, 20);
        cout << "Nhap so luong mon an: ";
        cin >> dh.soLuongMonAn;
        cin.ignore();
        for (int j = 0; j < dh.soLuongMonAn; j++) {
            cout << "Nhap ten mon an thu " << j + 1 << ": ";
            cin.getline(dh.ctdonhang[j].mon.TenMon, 50);
            cout << "Nhap gia mon an thu " << j + 1 << ": ";
            cin >> dh.ctdonhang[j].mon.Gia;
            cout << "Nhap so luong mon an thu " << j + 1 << ": ";
            cin >> dh.ctdonhang[j].SoLuong;
            cin.ignore();
            dh.ctdonhang[j].DonGia = dh.ctdonhang[j].mon.Gia * dh.ctdonhang[j].SoLuong;
            cout << "Thanh tien: " << dh.ctdonhang[j].DonGia << endl;
        }
        ThemDonHang(ds, dh);
        ThemKhachHang(ds, kh);
    }
}

void XuatDonHang(NodePtr ds) {
    if (isEmpty(ds)) {
        cout << "Danh sach don hang rong!" << endl;
        return;
    }
    NodePtr p = ds;
    cout <<" "<< setfill('=') << setw(120) << "" << setfill(' ') << endl;
    cout << "| " << setw(13) << left << "Ma don hang" << " | "
        << setw(15) << left << "Ma khach hang" << " | "
        << setw(20) << left << "Trang thai don" << " | "
        << setw(7) << left << "So mon" << " | "
        << setw(13) << left << "Ten mon" << " | "
        << setw(5) << left << "Gia" << " | "
        << setw(13) << left << "So luong mon" << " | "
        << setw(10) << left << "Don gia" << " |" << endl;
    cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;

    while (p != NULL) {
        cout << "| " << setw(13) << right << p->dataDH.MaDon
            << " | " << setw(15) << right << p->dataDH.MaKH
            << " | " << setw(20) << right << p->dataDH.TrangThaiDon
            << " | " << setw(7) << right << p->dataDH.soLuongMonAn;
        for (int j = 0; j < p->dataDH.soLuongMonAn; j++) {
            cout << j<<"\n";
            if (j > 0) {
                cout<<"|" << setw(17) << right
                    << " | " << setw(18) << right 
                    << " | " << setw(23) << right
                    << " | " << setw(10) << right ;
            }
            cout << " | " << setw(13) << right << p->dataDH.ctdonhang[j].mon.TenMon
                << " | " << setw(5) << right << p->dataDH.ctdonhang[j].mon.Gia
                << " | " << setw(13) << right << p->dataDH.ctdonhang[j].SoLuong
                << " | " << setw(10) << right << p->dataDH.ctdonhang[j].DonGia << " |";
            cout << endl ;
        }
        cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
        p = p->link;
    }

    cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
}

void XuatDSKhachHang(NodePtr ds) {
    if (isEmpty(ds)) {
        cout << "Danh sach khach hang rong" << endl;
        return;
    }
    NodePtr p = ds;
    cout << " " << setfill('=') << setw(90) << "" << setfill(' ') << endl;
    cout << "|"<< setw(15) << left << "Ma khach hang" << " | "
        << setw(30) << left << "Ten khach hang" << " | "
        << setw(20) << left << "Dia chi" << " | "
        << setw(15) << left << "So dien thoai" << " |" << endl;
    cout << " " << setfill('=') << setw(90) << "" << setfill(' ') << endl;
    while (p!=NULL)
    {   
        cout << "| " << setw(14) << right << p->dataKH.MaKH
            << " | " << setw(30) << right << p->dataKH.tenKH
            << " | " << setw(20) << right << p->dataKH.DiaChi
            << " | " << setw(15) << right << p->dataKH.SDT << " |";
        cout << endl;
        cout << " " << setfill('=') << setw(90) << "" << setfill(' ') << endl;
        p = p->link;
    }
    cout << " " << setfill('=') << setw(90) << "" << setfill(' ') << endl;
}
bool timDonHangTheoMaDH(NodePtr ds, char* key) {
    NodePtr p = ds;
    while (p != NULL) {
        if (strcmp(p->dataDH.MaDon, key) == 0) {
            cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
            cout << "| " << setw(13) << left << "Ma don hang" << " | "
                << setw(15) << left << "Ma khach hang" << " | "
                << setw(20) << left << "Trang thai don" << " | "
                << setw(7) << left << "So mon" << " | "
                << setw(13) << left << "Ten mon" << " | "
                << setw(5) << left << "Gia" << " | "
                << setw(13) << left << "So luong mon" << " | "
                << setw(10) << left << "Don gia" << " |" << endl;
            cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
            cout << "| " << setw(13) << right << p->dataDH.MaDon
                << " | " << setw(15) << right << p->dataDH.MaKH
                << " | " << setw(20) << right << p->dataDH.TrangThaiDon
                << " | " << setw(7) << right << p->dataDH.soLuongMonAn;
            for (int j = 0; j < p->dataDH.soLuongMonAn; j++) {
                if (j > 0) {
                    cout << "|" << setw(17) << right
                        << " | " << setw(18) << right
                        << " | " << setw(23) << right
                        << " | " << setw(10) << right;
                }
                cout << " | " << setw(13) << right << p->dataDH.ctdonhang[j].mon.TenMon
                    << " | " << setw(5) << right << p->dataDH.ctdonhang[j].mon.Gia
                    << " | " << setw(13) << right << p->dataDH.ctdonhang[j].SoLuong
                    << " | " << setw(10) << right << p->dataDH.ctdonhang[j].DonGia << " |";
                cout << endl;
            }
            cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
            return true;
        }
        p = p->link;
    }
    return false;
}

bool timDonHangTheoMaKH(NodePtr ds) {
    char maKH[10];
    cout << "Nhap ma khach hang can tim: ";
    cin.getline(maKH, 10);
    NodePtr p = ds;
    while (p != NULL) {
        if (strcmp(p->dataDH.MaKH, maKH) == 0) {
            cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
            cout << "| " << setw(13) << left << "Ma don hang" << " | "
                << setw(15) << left << "Ma khach hang" << " | "
                << setw(20) << left << "Trang thai don" << " | "
                << setw(7) << left << "So mon" << " | "
                << setw(13) << left << "Ten mon" << " | "
                << setw(5) << left << "Gia" << " | "
                << setw(13) << left << "So luong mon" << " | "
                << setw(10) << left << "Don gia" << " |" << endl;
            cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
            cout << "| " << setw(13) << right << p->dataDH.MaDon
                << " | " << setw(15) << right << p->dataDH.MaKH
                << " | " << setw(20) << right << p->dataDH.TrangThaiDon
                << " | " << setw(7) << right << p->dataDH.soLuongMonAn;
            for (int j = 0; j < p->dataDH.soLuongMonAn; j++) {
                if (j > 0) {
                    cout << "|" << setw(17) << right
                        << " | " << setw(18) << right
                        << " | " << setw(23) << right
                        << " | " << setw(10) << right;
                }
                cout << " | " << setw(13) << right << p->dataDH.ctdonhang[j].mon.TenMon
                    << " | " << setw(5) << right << p->dataDH.ctdonhang[j].mon.Gia
                    << " | " << setw(13) << right << p->dataDH.ctdonhang[j].SoLuong
                    << " | " << setw(10) << right << p->dataDH.ctdonhang[j].DonGia << " |";
                cout << endl;
            }
            cout << " " << setfill('=') << setw(120) << "" << setfill(' ') << endl;
            return true;
        }
        p = p->link;
    }
    return false;
}
void docFile(const char* tenFile, NodePtr& ds) {
    FILE* file;
    errno_t file_in = fopen_s(&file, tenFile, "rb");
    if (file == NULL) {
        cout << "\nLoi doc file\n";
        return;
    }
    DonHang dh;
    while (fread(&dh, sizeof(DonHang), 1, file)) {
        NodePtr p = TaoNodeDH(dh);
        p->link = ds;
        ds = p;
    }
    fclose(file);
    cout << "\nDoc file thanh cong\n";
}

void ghiFile(const char* tenFile, NodePtr ds) {
    FILE* file;
    errno_t file_out = fopen_s(&file, tenFile, "wb"); 
    if (file == NULL) {
        cout << "Loi mo file" << endl;
        return;
    }
    NodePtr p = ds;
    while (p != NULL) {
        fwrite(&(p->dataDH), sizeof(DonHang), 1, file);
        p = p->link;
    }
    fclose(file);
    cout << "\nGhi file thanh cong\n";
}
void SapXepTheoMaDonHang(NodePtr ds) {
    if (ds == NULL) {
        cout << "Danh sach don hang rong!" << endl;
        return;
    }
    int chon = 0;
    do {
        cout << "\nSap xep theo giai thuat bubble sort" << endl;
        cout << "1. Sap xep theo ma don hang tang dan" << endl;
        cout << "2. Sap xep theo ma don hang giam dan" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long nhap: ";
        cin >> chon;

        switch (chon) {
        case 1: {
            NodePtr p, q;
            bool swapped;
            do {
                swapped = false;
                p = ds;
                while (p->link != NULL) {
                    q = p->link;
                    int num1 = atoi(p->dataDH.MaDon);
                    int num2 = atoi(q->dataDH.MaDon);
                    if (num1>num2) {
                        swap(p->dataDH, q->dataDH);
                        swapped = true;
                    }
                    p = p->link;
                }
            } while (swapped);
            cout << "Da sap xep danh sach theo ma don hang tang dan!" << endl;
            XuatDonHang(ds);
            break;
        }
        case 2: {
            NodePtr p, q;
            bool swapped;
            do {
                swapped = false;
                p = ds;
                while (p->link != NULL) {
                    q = p->link;
                    int num1 = atoi(p->dataDH.MaDon);
                    int num2 = atoi(q->dataDH.MaDon);
                    if (num1 < num2) {
                        swap(p->dataDH, q->dataDH);
                        swapped = true;
                    }
                    p = p->link;
                }
            } while (swapped);
            cout << "Da sap xep danh sach theo ma don hang giam dan!" << endl;
            XuatDonHang(ds);
            break;
        }
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (chon != 0);
}
void SapXepTheoMaKhachHang(NodePtr ds) {
    if (ds == NULL) {
        cout << "Danh sach don hang rong!" << endl;
        return;
    }

    NodePtr p, q, minNode, maxNode;
    int chon = 0;
    do {
        cout << "\nSap xep theo giai thuat selection sort" << endl;
        cout << "1. Sap xep theo ma khach hang giam dan" << endl;
        cout << "2. Sap xep theo ma khach hang tang dan" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long nhap: ";
        cin >> chon;

        switch (chon) {
        case 1: {
            for (p = ds; p->link != NULL; p = p->link) {
                minNode = p;
                int num1 = atoi(p->dataDH.MaKH);
                for (q = p->link; q != NULL; q = q->link) {
                    int num2 = atoi(q->dataDH.MaKH);
                    if (num1 < num2) {
                        minNode = q;
                        num1 = num2;
                    }
                }
                if (minNode != p)
                    swap(p->dataDH, minNode->dataDH);
            }
            cout << "Da sap xep danh sach theo ma khach hang giam dan!" << endl;
            XuatDonHang(ds);
            break;
        }
        case 2: {
            for (p = ds; p->link != NULL; p = p->link) {
                maxNode = p;
                int num1 = atoi(p->dataDH.MaKH);
                for (q = p->link; q != NULL; q = q->link) {
                    int num2 = atoi(q->dataDH.MaKH);
                    if (num1 > num2) {
                        maxNode = q;
                        num1 = num2;
                    }
                }
                if (maxNode != p)
                    swap(p->dataDH, maxNode->dataDH);
            }
            cout << "Da sap xep danh sach theo ma khach hang tang dan!" << endl;
            XuatDonHang(ds);
            break;
        }
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (chon != 0);
}
void SapXepTheoSoMonAn(NodePtr ds) {
    if (ds == NULL) {
        cout << "Danh sach don hang rong!" << endl;
        return;
    }
    int chon = 0;
    do {
        cout << "\nSap xep theo giai thuat insertion sort" << endl;
        cout << "1. Sap xep theo So luong mon tang dan" << endl;
        cout << "2. Sap xep theo So luong mon giam dan" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long nhap: ";
        cin >> chon;
        NodePtr p, q;
        switch (chon) {
        case 1:
            for (p = ds; p != NULL; p = p->link) {
                for (q = p->link; q != NULL; q = q->link) {
                    if (p->dataDH.soLuongMonAn > q->dataDH.soLuongMonAn) {
                        DonHang temp = p->dataDH;
                        p->dataDH = q->dataDH;
                        q->dataDH = temp;
                    }
                }
            }
            cout << "Da sap xep danh sach theo So luong mon tang dan!" << endl;
            XuatDonHang(ds);
            break;

        case 2:
            for (p = ds; p != NULL; p = p->link) {
                for (q = p->link; q != NULL; q = q->link) {
                    if (p->dataDH.soLuongMonAn < q->dataDH.soLuongMonAn) {
                        DonHang temp = p->dataDH;
                        p->dataDH = q->dataDH;
                        q->dataDH = temp;
                    }
                }
            }
            cout << "Da sap xep danh sach theo So luong mon giam dan!" << endl;
            XuatDonHang(ds);
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (chon != 0);
}