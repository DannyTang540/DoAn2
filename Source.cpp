#include"Header.h"
int main() {
	//Menu();
	NodePtr ds;
	DonHang dh;
	KhoiTao(ds);
	
	TaoNodeDH(dh);	
	dh.MaDon = "123";
	ThemDonHang(ds, dh);
	
	return 0;
}