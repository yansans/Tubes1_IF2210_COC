# Tubes1_IF2210_COC

Implementasi Kompetisi Kartu ala Kerajaan Permen dengan konsep Pemrograman Berorientasi Objek

## Kompetisi Kartu ala Kerajaan Permen

> Program ini dibuat untuk mengimplementasi konsep object oriented programming untuk membuat sebuah permainan kartu dengan combo seperti pair dan full house dan ability unik pemain seperti reverse dan swap.

Konsep OOP yang digunakan

1. Inheritance dan Polymorphism
2. Exception dan Exception Handling
3. Function Overloading dan Operator Overloading
4. Abstract Class dan Virtual Function
5. Generic Function atau Generic Class
6. STL (Standard Template Library)

## Table of Contents

- [Tubes1\_IF2210\_COC](#tubes1_if2210_coc)
  - [Kompetisi Kartu ala Kerajaan Permen](#kompetisi-kartu-ala-kerajaan-permen)
  - [Table of Contents](#table-of-contents)
  - [Setup](#setup)
  - [Usage](#usage)
  - [Project Status](#project-status)

## Setup

Program membutuhkan C++11 ke atas dengan bantuan `make` untuk meng-compile program

## Usage

Cara menjalankan program

1. Clone repository

   ```bash
    git clone https://github.com/yansans/Tubes1_IF2210_COC.git
   ```

2. Masuk ke root folder program

   ```bash
    cd Tubes1_IF2210_COC
   ```

3. Menjalankan program

   ```bash
    make run
   ```

Pemakaian program

1. Menu pertama

    ```c++
    Compiling...
    Compilation Done!
    Starting program
    Pilih permainan:
    1. Main Kerajaan Permen
    2. Main Blackjack
    Pilihan :
    ```

2. Prompt untuk permainan kerajaan permen input user

    ```c++
    Masukan nama player 1 : a
    Masukan nama player 2 : b
    Masukan nama player 3 : c
    Masukan nama player 4 : d
    Masukan nama player 5 : e
    Masukan nama player 6 : f
    Masukan nama player 7 : g
    Pilih opsi membentuk urutan kartu:
    1. random
    2. baca dari file
    Masukan angka :
    ```

3. Contoh hasil permainan kerajaan permen

    ```c++
    Kartu meja: 5 (merah) && 7 (biru) && 2 (merah) && 12 (hijau) && 9 (merah)
    Kartu a: 2 (biru) && 6 (kuning)
    Kartu b: 3 (kuning) && 4 (biru)
    Kartu c: 6 (biru) && 2 (hijau)
    Kartu d: 8 (merah) && 7 (kuning)
    Kartu e: 12 (kuning) && 7 (merah)
    Kartu f: 4 (merah) && 4 (kuning)
    Kartu g: 1 (hijau) && 9 (hijau)
    e menang, dan mendapat poin sebanyak : 64
    ```

4. Prompt untuk permainan kerajaan permen input user

   ```c++
    Permainan blackjack dimulai!
    Name: a
    Keadaan setelah pengambilan kartu awal
    Pemain a
    Kartu: 4 heart && 5 spade

    Dealer Bot 1
    Kartu: *HIDDEN* && K spade

    =======================
    a's turn
    =======================
    Kartu: 4 heart && 5 spade
    Commands:
    - hit (ambil satu kartu)
    - stand (stop mengambil kartu)
    Perintah anda:
   ```

5. Contoh permainan blackjack

    ```c++
    Perintah anda: hit
    Anda mendapat kartu 8 diamond

    Kartu: 4 heart && 5 spade && 8 diamond
    Commands:
    - hit (ambil satu kartu)
    - stand (stop mengambil kartu)
    Perintah anda: stand
    Giliran dilanjutkan
    =======================
    Bot 1's turn
    =======================
    Giliran Bot selesai
    Status akhir:
    Pemain a
    Kartu: 4 heart && 5 spade && 8 diamond
    Skor: 17

    Dealer Bot 1
    Kartu: 8 club && K spade
    Skor: 18
    ```

## Project Status

 Disusun Oleh :

- 13521049 / Brian Kheng
- 13521110 / Yanuar Sano Nur Rasyid
- 13521112 / Rayhan Hanif Maulana Pradana
- 13521137 / Michael Utama
- 13521173 / Dewana Gustavus Haraka Otang

Project is: _complete_

<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->