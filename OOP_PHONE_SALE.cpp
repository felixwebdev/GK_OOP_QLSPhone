#include <bits/stdc++.h>
using namespace std;

class DienThoai {
private:
	string TEN_SP;
	string TEN_HANG;
	int NAM_SX;
	long long DonGia;
public:
	DienThoai(string _TEN_SP = "", string _TEN_HANG = "", int _NAM_SX = 2000, long long _DonGia = 0) {
		TEN_SP = _TEN_SP;
		TEN_HANG = _TEN_HANG;
		NAM_SX = _NAM_SX;
		DonGia = _DonGia;
	}
	DienThoai(const DienThoai& dt) {
		TEN_SP = dt.TEN_SP;
		TEN_HANG = dt.TEN_HANG;
		NAM_SX = dt.NAM_SX;
		DonGia = dt.DonGia;
	}
	~DienThoai() {}
	void setTEN_SP(string s){TEN_SP = s;}
	string getTEN_SP() { return TEN_SP;}
	void setTEN_HANG(string s) { TEN_HANG = s;}
	string getTEN_HANG() { return TEN_HANG;}
	void setNAM_SX(int n) { NAM_SX = n; }
	int getNAM_SX() { return NAM_SX; }
	void setDonGia(long long l) { DonGia = l; }
	long long getDonGia() { return DonGia; }

	virtual long long TinhTien() = 0;
	virtual string LoaiDienThoai() = 0;

	virtual void Xuat() {
		cout << "Loai dien thoai: " << LoaiDienThoai() << endl;
		cout << "Ten dien thoai: " << TEN_SP << endl;
		cout << "Ten hang: " << TEN_HANG << endl;
		cout << "Nam san xuat: " << NAM_SX << endl;
		cout << "So tien phai tra: " << TinhTien() << endl;
	}
};

class NEW : public DienThoai {
private:
	int heSO_KM;
public:
	NEW(string _TEN_SP = "", string _TEN_HANG = "", int _NAM_SX = 2000, long long _DON_GIA = 0, int _heSO_KM = 0) :DienThoai(_TEN_SP, _TEN_HANG, _NAM_SX, _DON_GIA) {
		heSO_KM = _heSO_KM;
	}
	~NEW(){}
	void setHeSoKM(int n) { heSO_KM = n; }
	int getHeSoKM() { return heSO_KM; }
	string LoaiDienThoai() { return "New";}
	long long TinhTien() { return DienThoai::getDonGia() - ((DienThoai::getDonGia() * heSO_KM) / 100);}
};

class LIKE_NEW : public DienThoai {
private:
	int tiLeMOI;
public:
	LIKE_NEW(string _TEN_SP = "", string _TEN_HANG = "", int _NAM_SX = 2000, long long _DON_GIA = 0, int _tiLe_MOI = 0) :DienThoai(_TEN_SP, _TEN_HANG, _NAM_SX, _DON_GIA) {
		tiLeMOI = _tiLe_MOI;
	}
	~LIKE_NEW(){}
	void setTiLeMOI(int n) { tiLeMOI = n;}
	int getTiLeMoi() { return tiLeMOI; }
	string LoaiDienThoai() {return "Like New";}
    long long TinhTien() { return DienThoai::getDonGia() * tiLeMOI / 100;}
};

class OLD : public DienThoai {
private:
	int tiLe_HAOMON;
	int NAM_BAN;
	long long phiBaoHanh;
	int tiLe_GIAM;
public:
	OLD(string _TEN_SP = "", string _TEN_HANG = "", int _NAM_SX = 2000, long long _DON_GIA = 0, int _NAM_BAN = 2000, int _tiLe_HAOMON = 0, long long _phiBaoHanh = 0, int _tiLe_GIAM = 0) : DienThoai(_TEN_SP, _TEN_HANG, _NAM_SX, _DON_GIA) {
		tiLe_HAOMON = _tiLe_HAOMON;
		NAM_BAN = _NAM_BAN;
		phiBaoHanh = _phiBaoHanh;
		tiLe_GIAM = _tiLe_GIAM;
	}
	~OLD(){}
	void setTiLeHaoMon(int n) { tiLe_HAOMON = n;}
	int getTiLeHaoMon() { return tiLe_HAOMON;}
	void setNamBan(int n) { NAM_BAN = n;}
	int getNamBan() { return NAM_BAN; }
	void setPhiBaoHanh(long long n) { phiBaoHanh = n;}
	long long getPhiBaoHanh() { return phiBaoHanh; }
	void setTiLeGiam(int n) { tiLe_GIAM = n; }
	int getTiLeGiam() { return tiLe_GIAM; }
	string LoaiDienThoai() { return "Old";}
	long long TinhTien() {
		return DienThoai::getDonGia()+ phiBaoHanh - (DienThoai::getDonGia()*(NAM_BAN - DienThoai::getNAM_SX()) * tiLe_GIAM / 100)
			   - ((DienThoai::getDonGia() * tiLe_HAOMON) / 100);
	}
};

int main()
{
	string sLoaiDienThoai, sTenHang, sTenSP;
	long long  DonGia, PhiBaoHanh;
	int NamSX, HeSoKM, TiLeMOI, TiLeHaoMon, NamBan, TiLeGiam;
	vector<DienThoai*> dt;

	long long n; cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> sLoaiDienThoai;
		cin.ignore();
		getline(cin, sTenSP);
		getline(cin, sTenHang);
		cin >> NamSX;
		cin >> DonGia;
		if (sLoaiDienThoai == "NEW") {
			cin >> HeSoKM;
			dt.push_back(new NEW(sTenSP, sTenHang, NamSX, DonGia, HeSoKM));
		}
		else if (sLoaiDienThoai == "LIKENEW") {
			cin >> TiLeMOI;
			dt.push_back(new LIKE_NEW(sTenSP, sTenHang, NamSX, DonGia, TiLeMOI));
		}
		else {
			cin >> NamBan;
			cin >> TiLeHaoMon;
			cin >> PhiBaoHanh;
			cin >> TiLeGiam;
			dt.push_back(new OLD(sTenSP, sTenHang, NamSX, DonGia, NamBan, TiLeHaoMon, PhiBaoHanh, TiLeGiam));
		}
	}

	cout << "***HOA DON***" << endl;
	for (long long i = 0; i < n; i++) {
		cout << i + 1 << ". ";
		dt[i]->Xuat();
		cout << endl;
	}
	return 0;
}
