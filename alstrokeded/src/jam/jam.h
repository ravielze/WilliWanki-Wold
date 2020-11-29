/* Definisi ADT JAM */
#ifndef JAM_H
#define JAM_H

#include "../constant/adt.h"

/* *** Definisi TYPE JAM <HH:MM:SS> *** */

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJamValid (int H, int M);
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
void MakeJam (JAM* J, int HH, int MM);
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

void MakeJamFromMenit (JAM* J, int menit);
/* Membentuk sebuah JAM dari detik */
/* Catatan: Jika N >= 1440, maka harus dikonversi dulu menjadi jumlah menit yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 1440, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH.MM
   Jika jam / menit hanya satu digit, tuliskan satu digit 0 di depannya. */
void TulisJam (JAM J);

/* I.S. : J sembarang
   F.S. : Nilai J ditulis dg format Time Remaining: HH hour(s) MM minute(s)
   Jika jam / menit hanya satu digit, tidak tuliskan satu digit 0 di depannya,
   jika jam / menit adalah 0, jam / menit tersebut tidak akan dituliskan,
   jika tidak ada waktu yang tersisa, tuliskan Time Remaining: - */
void TimeRemain (JAM J);

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JamToMenit (JAM J);
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah menit dari pukul 0:0 */
/* Rumus : detik = 3600*HH + 60*MM*/
/* Nilai maksimum = 3600*23+59*60*/

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
JAM NextMenit (JAM J);
/* Mengirim 1 menit setelah J dalam bentuk JAM */
JAM NextNMenit (JAM J, int N);
/* Mengirim N menit setelah J dalam bentuk JAM */
JAM PrevMenit (JAM J);
/* Mengirim 1 menit sebelum J dalam bentuk JAM */
JAM PrevNMenit (JAM J, int N);
/* Mengirim N menit sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
int Durasi (JAM JAw, JAM JAkh);
/* Mengirim JAkh-JAw dlm Menit, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
#endif