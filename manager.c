#include <stdio.h>

#define SO_MAY 40
#define DIEN_NANG_TIEU_THU 400
#define GIA_DIEN 750

int trangThaiMay[SO_MAY] = {0}; // 0: Trong, 1: Dang su dung
int dienNangTieuThu[SO_MAY] = {0};

void dungMay() {
    int soHieu;
    printf("Nhap so hieu may muon su dung: ");
    scanf("%d", &soHieu);

    if (soHieu >= 1 && soHieu <= SO_MAY) {
      if (trangThaiMay[soHieu - 1] == 0) {
            trangThaiMay[soHieu - 1] = 1;
            dienNangTieuThu[soHieu - 1] += DIEN_NANG_TIEU_THU;
            printf("Da cap may so %d.\n", soHieu);
        }
      else {
            printf("May so %d dang duoc su dung hoac khong hop le. Vui long chon may khac.\n", soHieu);
            dungMay(); 
        }
    }
    else {
        printf("So hieu may khong hop le.\n");
        dungMay(); 
    }
}

void roiMay() {
    int soHieu;
    printf("Nhap so hieu may muon roi: ");
    scanf("%d", &soHieu);

    if (soHieu >= 1 && soHieu <= SO_MAY) {
        if (trangThaiMay[soHieu - 1] == 1) {
            trangThaiMay[soHieu - 1] = 0;
            printf("May so %d da duoc tra.\n", soHieu);
        } else {
            printf("May so %d khong dang duoc su dung hoac khong hop le. Vui long chon may khac.\n", soHieu);
            roiMay(); 
        }
    } else {
        printf("So hieu may khong hop le.\n");
        roiMay(); 
    }
}

void inTrangThaiMay() {
    printf("Trang thai su dung cac may:\n");
    printf("|-------|----------|-------|----------|-------|----------|-------|----------|-------|----------|\n");
    printf("|So hieu|Trang thai|So hieu|Trang thai|So hieu|Trang thai|So hieu|Trang thai|So hieu|Trang thai|\n");
    printf("|-------|----------|-------|----------|-------|----------|-------|----------|-------|----------|\n");
    printf("|");

    for (int i = 0; i < SO_MAY; ++i) {
        if (i > 0 && i % 5 == 0) {
	    printf("\n");
            printf("|-------|----------|-------|----------|-------|----------|-------|----------|-------|----------|\n");
	    printf("|");
        }

        printf("  %2d   |   %-5s  |", i + 1, trangThaiMay[i] == 1 ? "Co" : "Khong");
    }

    printf("\n|-------|----------|-------|----------|-------|----------|-------|----------|-------|----------|\n");
}

void inDienNangTieuThu() {
    printf("Dien nang tieu thu tren cac may:\n");
    printf("|-------|-------------|-------|-------------|-------|-------------|-------|-------------|-------|-------------|\n");
    printf("|So hieu|Dien nang (W)|So hieu|Dien nang (W)|So hieu|Dien nang (W)|So hieu|Dien nang (W)|So hieu|Dien nang (W)|\n");
    printf("|-------|-------------|-------|-------------|-------|-------------|-------|-------------|-------|-------------|\n");
    printf("|");

    for (int i = 0; i < SO_MAY; ++i) {
        if (i > 0 && i % 5 == 0) {
	    printf("\n");
            printf("|-------|-------------|-------|-------------|-------|-------------|-------|-------------|-------|-------------|\n");
	    printf("|");
        }

        printf("  %2d   |   %4d      |", i + 1, dienNangTieuThu[i]);
    }

    printf("\n|-------|-------------|-------|-------------|-------|-------------|-------|-------------|-------|-------------|\n");
}

void inTongDienNangTieuThu() {
    int tongDienNang = 0;

    for (int i = 0; i < SO_MAY; ++i) {
        tongDienNang += dienNangTieuThu[i];
    }

    printf("Tong dien nang tieu thu: %d Watt\n", tongDienNang);
    printf("Tien dien thanh toan: %d VND\n", tongDienNang * GIA_DIEN / 1000);
}

void mayDungNhieuNhatVaItNhat() {
    int maxDung = 0, minDung = 0;

    for (int i = 0; i < SO_MAY; ++i) {
        if (trangThaiMay[i] == 1) {
            if (dienNangTieuThu[i] > maxDung) {
                maxDung = dienNangTieuThu[i];
	    }
            if (dienNangTieuThu[i] < minDung) {
                minDung = dienNangTieuThu[i];
            }
        }
    }

    printf("May dung nhieu nhat co so hieu: ");
    for (int i = 0; i < SO_MAY; ++i) {
      if (dienNangTieuThu[i] = maxDung) {
        printf(" %d ", i);
      }
    }  
    printf("\n");
    printf(" - Dien nang tieu thu: %d Watt\n", maxDung);
    printf("May dung it nhat co so hieu:");
    for (int i = 0; i < SO_MAY; ++i) {
      if (dienNangTieuThu[i] = minDung) {
        printf(" %d ", i);
      }
    }
    printf("\n");
    printf(" - Dien nang tieu thu: %d Watt\n", minDung);
}

int main() {
    int luaChon;

    do {
        printf("\nMenu:\n");
        printf("1. Dung may\n");
        printf("2. Roi may\n");
        printf("3. In trang thai may\n");
        printf("4. In dien nang tieu thu\n");
        printf("5. In tong dien nang tieu thu va tien thanh toan\n");
        printf("6. In so hieu may dung nhieu nhat va it nhat\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                dungMay();
                break;
            case 2:
                roiMay();
                break;
            case 3:
                inTrangThaiMay();
                break;
            case 4:
                inDienNangTieuThu();
                break;
            case 5:
                inTongDienNangTieuThu();
                break;
            case 6:
                mayDungNhieuNhatVaItNhat();
                break;
            case 7:
                printf("Thoat chuong trinh. Hen gap lai!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 7);

    return 0;
}
