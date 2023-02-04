#include <iostream>     //library untuk menampilkan input dan output
#include <stdlib.h>     //library untuk menggunakan fungsi clear screes : system("cls")
#include <string>       //library untuk manipulasi string

using namespace std;    //standar library agar tidak perlu menuliskan std:: di tiap baris kode

//Pendeklarasian konstanta yang akan menjadi maksimal nilai yang bisa ditampung array
#define maxType 5
#define maxFeatures 16

//Pendeklarasian array-aray pada struct wedding
struct Wedding{
    string types[maxType];
    string features[maxFeatures];
    int prices[maxFeatures];
};
//Pendeklarasian variable yang terikat pada struct wedding
Wedding style, outdoor, indoor, army, cheap;

//Pendeklarasian variable-variable yang akan digunakan
string name, password, realName("Dikry"), realPassword("55555");
int uang, no,nomor, select, totalPrice;
char kembali, beli;

//Pendeklarasian fungsi-fungsi yang akan digunakan
void menuUtama();
void userLogIn();
void outdoorStyle();
void indoorStyle();
void armyStyle();
void cheapStyle();
void ending();
int moneyChange();
int moneyLack();

//Fungsi awal eksekusi program
int main()
{
  menuUtama();
}

//Pendefinisian fungsi-fungsi yang akan digunakan
void menuUtama(){
    /*  Fungsi untuk:
    1. Menampilkan fitur login, dan fitur-fitur pada wedding app
    2. Memberikan pilihan pada user terkait fitur-fitur yang tersedia
    */
    userLogIn();    //Menampilkan fungsi login
    do{
        system("cls");
        style.types[0]="Outdor Style";
        style.types[1]="Indor Style";
        style.types[2]="Army Style";
        style.types[3]="Cheap Style";
        style.types[4]="Keluar";
        cout<<"==========================================="<<endl;
        cout<<"<><>WELCOME TO THE WEDDING PLANING APP<><>"<<endl;
        cout<<"==========================================="<<endl;
        for(int i=0;i<maxType;i++){
        int no = i+1;
        cout<<no<<". "<<style.types[i]<<endl;
        }
        cout<<"=========================================="<<endl;

        cout<<"Pilih\t:";
        cin>>select;
        switch(select){
        case 1:
            outdoorStyle();
            break;
        case 2:
            indoorStyle();
            break;
        case 3:
            armyStyle();
            break;
        case 4:
            cheapStyle();
            break;
        default:
            ending();
            break;
        }
        cout<<"Kembali ke menu utama ? (y/n)\t:";
        cin>>kembali;
    }while(kembali =='y' || kembali =='Y');
        system("cls");
        cout<<"Program Selesai"<<endl;
}
void userLogIn(){
    do{ system("cls");
        cout<<"========================================"<<endl;
        cout<<"*******WEDDING PLANING IS LOCKED********"<<endl;
        cout<<"========================================"<<endl;
        cout<<"            ======                      "<<endl;
        cout<<"           /      \\                    "<<endl;
        cout<<"          ||      ||                    "<<endl;
        cout<<"          ==========                    "<<endl;
        cout<<"          ====  ====                    "<<endl;
        cout<<"          === = ====                    "<<endl;
        cout<<"          ==========                    "<<endl;
        cout<<"========================================"<<endl;
        cout<<"Masukan Nama\t\t:";
        getline(cin,name);
        cout<<"Masukan Password\t:";
        getline(cin,password);
    }while(name != realName || password != realPassword);
}
void outdoorAtribute(){
    //Fitur di outdoor style
    outdoor.features[0] = "Lapangan";
    outdoor.features[1] = "Lighting";
    outdoor.features[2] = "Dekorasi";
    outdoor.features[3] = "Ketring";
    outdoor.features[4] = "Seserahan";
    outdoor.features[5] = "MUA service";
    outdoor.features[6] = "Musik";
    outdoor.features[7] = "Upacara Adat";
    outdoor.features[8] = "Dokumentasi";
    outdoor.features[9] = "Amil";
    outdoor.features[10] = "Kebaya";
    outdoor.features[11] = "Jas Pria";
    outdoor.features[12] = "Bridesmaid";
    outdoor.features[13] = "Undangan";
    outdoor.features[14] = "Tenda";
    outdoor.features[15] = "MC service";

    //Harga tiap fitur outdoor style
    outdoor.prices[0]=12000000;
    outdoor.prices[1]=5000000;
    outdoor.prices[2]=9000000;
    outdoor.prices[3]=45000000;
    outdoor.prices[4]=2000000;
    outdoor.prices[5]=1500000;
    outdoor.prices[6]=4000000;
    outdoor.prices[7]=6000000;
    outdoor.prices[8]=2000000;
    outdoor.prices[9]=700000;
    outdoor.prices[10]=1200000;
    outdoor.prices[11]=500000;
    outdoor.prices[12]=2100000;
    outdoor.prices[13]=150000;
    outdoor.prices[14]=10000000;
    outdoor.prices[15]=1000000;
}
int changeMoney(int money, int total){
    //Fungsi untuk menghitung nilai uang kembalian
    int changeMoney = money-total;
    return changeMoney;
}
int moneyLack(int money,int total){
    //Fungsi untuk menghitung nilai kekurangan uang
    int moneyLack = total-money;
    return moneyLack;
}
void outdoorStyle(){
    /*  Fungsi untuk:
    1. Menampilkan fitur outdoor
    2. Menjumlahkan total harga fitur outdoor
    3. Menerima input sebagai persetujuan dan pembayaran
    4. Memproses input
    5. Menghasilkan output, apakah bisa dibeli atau tidak berdasarkan nominal input yang diberikan
*/

    system("cls");
    outdoorAtribute();
    cout<<"========================================"<<endl;
    cout<<">>>>>>>>>>>>>Outdoor Service<<<<<<<<<<<<"<<endl;
    cout<<"========================================"<<endl;
    //Menampilkan dan menghitung total biaya outdoor
    totalPrice = 0;
    for(int i=0;i<maxFeatures;i++){
            no = i+1;
            totalPrice+=outdoor.prices[i];
            cout<<no<<". "<<outdoor.features[i]<<"\t\tIdr. "<<outdoor.prices[i]<<endl;
    }
    cout<<"----------------------------------------"<<endl;
    cout<<"Total Price\t\t:"<<"Idr."<<totalPrice<<endl;
    cout<<"========================================"<<endl;

    //Bertanya kepada user, apakah mau membeli fitur outdoor atau tidak, lalu memproses nilai masukannya.
    cout<<"Beli? (y/n)\t\t:";
    cin>>beli;
    cout<<"========================================"<<endl;
    if(beli=='y'){
    cout<<"Masukan nominal uang\t: Idr. ";
    cin>>uang;
    cout<<"========================================"<<endl;

    //Penentuan status pembelian berdasarkan uang yang diberikan
    if(uang==totalPrice){
        system("cls");
        cout<<"Pembelian berhasil"<<endl;
        cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
    }else if(uang>totalPrice){
        system("cls");
        cout<<"Pembelian berhasil"<<endl;
        cout<<"Total Kembalian\t\t: idr."<<changeMoney(uang,totalPrice)<<endl;
        cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
    }else{
        system("cls");
        cout<<"Pembelian gagal"<<endl;
        cout<<"Total Kekurangan\t: idr."<<moneyLack(uang,totalPrice)<<endl;
        cout<<"Maaf Nominal Yang Anda Berikan Belum Cukup"<<endl;
    }
    cout<<"========================================"<<endl;
    }
}
void indoorStyle(){
     /*  Fungsi untuk:
    1. Menampilkan fitur indoor
    2. Menjumlahkan total harga fitur indoor
    3. Menerima input sebagai persetujuan dan pembayaran
    4. Memproses input
    5. Menghasilkan output, apakah bisa dibeli atau tidak berdasarkan nominal input yang diberikan
    */

    outdoorAtribute();  //Mengambil nilai atribut outdoor

    system("cls");
    cout<<"========================================"<<endl;
    cout<<">>>>>>>>>>>>>Indoor Service<<<<<<<<<<<<<"<<endl;
    cout<<"========================================"<<endl;

    //Manipulasi array outdoor ke array indoor
    totalPrice = 0;
    for(int i=0;i<maxFeatures;i++){
            no=i+1;
            if(i==0){
                indoor.features[i]="Gedung";    //Memasukan nilai "gedung" pada array indoor.features di index ke-0.
                indoor.prices[i]=15000000;      //Memasukan nilai 15000000 pada array indoor.prices di index ke-0
            }else{
                indoor.features[i]=outdoor.features[i]; //Memasukan nilai yang ada pada array outdoor.features ke array indoor.features sesuai index masing2, kecuali pada index ke 0
                indoor.prices[i]=outdoor.prices[i];     //Memasukan nilai yang ada pada array outdoor.prices ke array indoor.prices sesuai index masing2, kecuali pada index ke 0
            }
            totalPrice+=indoor.prices[i];   //Menjumlahkan total nilai pada array indoor.prices

        cout<<no<<". "<<indoor.features[i]<<"\t\tIdr. "<<indoor.prices[i]<<endl; //Menampilkan no, nilai pada array indoor.features dan indoor.prices berdasarkan urutan index.
    }
    cout<<"----------------------------------------"<<endl;
    cout<<"Total Price\t\t:"<<"Idr."<<totalPrice<<endl;     //Menampilkan hasil penjumlahan total nilai pada array indoor.prices
    cout<<"========================================"<<endl;

    //Menawarkan kepada pembeli
    cout<<"Beli? (y/n)\t\t:";
    cin>>beli;      //Mengambil nilai masukan dari pembeli,sebagai persetujuan pembelian
    cout<<"========================================"<<endl;

    if(beli=='y'){  //Memproses nilai masukan dari pembeli
        cout<<"Masukan nominal uang\t: Idr. ";
        cin>>uang;      //Mengambil nilai masukan dari pembeli,nominal pembayaran
        cout<<"========================================"<<endl;

    //Memproses dan pengkondisian berdasarkan nominal yang pembeli berikan
    if(uang==totalPrice){
        system("cls");
        cout<<"Pembelian berhasil"<<endl;
        cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
    }else if(uang>totalPrice){
        system("cls");
        cout<<"Pembelian berhasil"<<endl;
        cout<<"Total Kembalian\t\t: idr."<<changeMoney(uang,totalPrice)<<endl;
        cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
    }else{
        system("cls");
        cout<<"Pembelian gagal"<<endl;
        cout<<"Total Kekurangan\t: idr."<<moneyLack(uang,totalPrice)<<endl;
        cout<<"Maaf Nominal Yang Anda Berikan Belum Cukup"<<endl;
    }
    cout<<"========================================"<<endl;
    }
}
void armyStyle(){
    /*  Fungsi untuk:
    1. Menampilkan fitur army
    2. Menjumlahkan total harga fitur army
    3. Menerima input sebagai persetujuan dan pembayaran
    4. Memproses input
    5. Menghasilkan output, apakah bisa dibeli atau tidak berdasarkan nominal input yang diberikan
    */
    outdoorAtribute();  //Mengambil atribut fitur dan harga di outdoor
    system("cls");
    cout<<"========================================"<<endl;
    cout<<">>>>>>>>>>>>>>Army Service<<<<<<<<<<<<<<"<<endl;
    cout<<"========================================"<<endl;
    //Manipulasi fitur dan harga yang berasal dari outdoor
    totalPrice = 0;
    for(int i=0;i<maxFeatures;i++){
            no=i+1;              //Pembuatan nomor secara berurutan
            if(i==7){
                army.features[i]="Marine form"; //Memasukan nilai "Marine form" ke array army.features ketika index ke-6, agar array outdoor.features ke-6 dengan nilai "Upacara adat" diganti
                army.prices[i]=22000000;        //Memasukan nilai "22.000.000" ke array army.features ketika index ke-6, agar array outdoor.features ke-6 dengan nilai "6.000.000" diganti
            }else{
                army.features[i]=outdoor.features[i];   //Memasukan semuan nilai array outdoor.features ke array army.features kecuali pada index ke-6
                army.prices[i]=outdoor.prices[i];       //Memasukan semuan nilai array outdoor.features ke array army.features kecuali pada index ke-6
            }
            totalPrice+=army.prices[i];     //Penjumlahan total harga

        cout<<no<<". "<<army.features[i]<<"\t\tIdr. "<<army.prices[i]<<endl;    //Menampilkan fitur army service beserta harganya
    }
        cout<<"----------------------------------------"<<endl;
        cout<<"Total Price\t\t:"<<"Idr."<<totalPrice<<endl;     //Menampilkan total harga
        cout<<"========================================"<<endl;

        //Bertanya kepada pembeli
        cout<<"Beli? (y/n)\t\t:";
        cin>>beli;
        cout<<"========================================"<<endl;
        if(beli=='y'){
        cout<<"Masukan nominal uang\t: Idr. ";
        cin>>uang;
        cout<<"========================================"<<endl;

        //penentuan status pembelian berdasarkan uang yang dimasukan
        if(uang==totalPrice){
        system("cls");
        cout<<"Pembelian berhasil"<<endl;
        cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
        }else if(uang>totalPrice){
        system("cls");
        cout<<"Pembelian berhasil"<<endl;
        cout<<"Total Kembalian\t\t: idr."<<changeMoney(uang,totalPrice)<<endl;
        cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
    }else{
        system("cls");
        cout<<"Pembelian gagal"<<endl;
        cout<<"Total Kekurangan\t: idr."<<moneyLack(uang,totalPrice)<<endl;
        cout<<"Maaf Nominal Yang Anda Berikan Belum Cukup"<<endl;
    }
    cout<<"========================================"<<endl;
    }
}
void cheapStyle(){
    /*  Fungsi untuk:
    1. Menampilkan fitur cheap
    2. Menjumlahkan total harga fitur cheap
    3. Menerima input sebagai persetujuan dan pembayaran
    4. Memproses input
    5. Menghasilkan output, apakah bisa dibeli atau tidak berdasarkan nominal input yang diberikan
    */
    outdoorAtribute();
    system("cls");

    cout<<"========================================"<<endl;
    cout<<"<><><><><><> CHEAP SERVICE  <><><><><><>"<<endl;
    cout<<"========================================"<<endl;
    totalPrice = 0;
        for(int i=0;i<maxFeatures;i++){
            //Pengkondisian
            if(i>=0 && i<=7 || i==12 || i==14){ //Menghapus data array ke-1 sampai ke-6 dan ke-13 pada array outdoor.features dan outdoor prices
                continue;
            }else{
                cheap.features[i]=outdoor.features[i];  //substitusi sisa data array outdoor.features ke array indoor features
                cheap.prices[i]=outdoor.prices[i];
            }
            totalPrice+=cheap.prices[i];    //Menjumlahkna total harga
            nomor++;  //mengurutkan no kembali dri 1
        cout<<nomor<<".  "<<cheap.features[i]<<"\t\tIdr. "<<cheap.prices[i]<<endl; //Menampilkan fitur yg ada di cheap service
        }
        cout<<"----------------------------------------"<<endl;
        cout<<"Total Price\t\t:"<<"Idr."<<totalPrice<<endl;        //Menampilkan total harga
        cout<<"========================================"<<endl;

        //Bertanya kepada konsumen
        cout<<"Beli? (y/n)\t\t:";
        cin>>beli;
        cout<<"========================================"<<endl;
        if(beli=='y'){
            cout<<"Masukan nominal uang\t: Idr. ";
            cin>>uang;
            cout<<"========================================"<<endl;

        //Penentuan status pembelian berdasarkan uang yang dimasukan konsumen
        if(uang==totalPrice){
            system("cls");
            cout<<"Pembelian berhasil"<<endl;
            cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
        }else if(uang>totalPrice){
            system("cls");
            cout<<"Pembelian berhasil"<<endl;
            cout<<"Total Kembalian\t\t: idr."<<changeMoney(uang,totalPrice)<<endl;
            cout<<"Terimakasih Telah Percaya Pada Layanan Kami"<<endl;
        }else{
            system("cls");
            cout<<"Pembelian gagal"<<endl;
            cout<<"Total Kekurangan\t: idr."<<moneyLack(uang,totalPrice)<<endl;
            cout<<"Maaf Nominal Yang Anda Berikan Belum Cukup"<<endl;
            }
            cout<<"========================================"<<endl;
        }
    }
void ending(){
    //Fungsi untuk menampilkan fitur dari pilihan keluar
    system("cls");
    cout<<"SILAHKAN KEMBALI LAIN WAKTU"<<endl;
}
