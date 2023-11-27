#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include <cstdlib>
#include<fstream> 

using namespace std;
const int MAX = 100;
struct MonAn {
    char TenMon[50];
    double Gia;
};
struct KhachHang {
    char tenKH[50];
    char MaKH[10];
    char DiaChi[50];
    int SDT;
};
struct CTDonHang {
    char MaDon[10];
    MonAn mon;
    int SoLuong;
    float DonGia;
};
struct DonHang {
    char MaKH[10];
    char MaDon[10];
    int soLuongMonAn; 
    CTDonHang ctdonhang[MAX];
    char TrangThaiDon[20];
    KhachHang* kh;
};
struct Node {
    KhachHang dataKH;
    DonHang dataDH;
    Node* link;
};

typedef struct Node* NodePtr;
void Menu();
void KhoiTao(NodePtr& ds);
int isEmpty(NodePtr ds);
void giaiPhong(NodePtr& ds);
NodePtr TaoNodeKH(KhachHang kh);
NodePtr TaoNodeDH(DonHang& dh);
NodePtr ThemDonHang(NodePtr& ds, DonHang& dh);
NodePtr ThemKhachHang(NodePtr& ds, KhachHang& kh);
bool kiemTra_TrungMa(NodePtr& ds, char* ma);
void nhapDSDonHang(NodePtr& ds);
void XuatDonHang(NodePtr ds);
void XuatDSKhachHang(NodePtr ds);
bool timDonHangTheoMaDH(NodePtr ds, char* key);
bool timDonHangTheoMaKH(NodePtr ds);
void ghiFile(const char* tenFile, NodePtr ds);
void docFile(const char* tenFile, NodePtr& ds);
void SapXepTheoMaDonHang(NodePtr ds);
void SapXepTheoMaKhachHang(NodePtr ds);
void SapXepTheoSoMonAn(NodePtr ds);
void nhapkhachhang(NodePtr& ds);