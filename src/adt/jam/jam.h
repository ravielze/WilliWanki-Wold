/* Definisi ADT JAM */
#ifndef JAM_H
#define JAM_H

#include "../boolean.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */
typedef struct {
	int HH; /* integer [0..23] */
	int MM; /* integer [0..59] */
	int SS; /* integer [0..59] */
} JAM;

/* *** Notasi Akses: selektor JAM *** */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJamValid (int H, int M, int S);
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
void MakeJam (JAM* J, int HH, int MM, int SS);
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

void MakeJamFromDetik (JAM* J, long detik);
/* Membentuk sebuah JAM dari detik */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void TulisJam (JAM J);
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JamToDetik (JAM J);
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2);
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2);
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2);
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2);
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J);
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM NextNDetik (JAM J, int N);
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM PrevDetik (JAM J);
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM PrevNDetik (JAM J, int N);
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh);
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
#endif