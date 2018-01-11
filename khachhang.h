#ifndef __KHACHHANG_H
#define __KHACHHANG_H
#include "cautruc.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// cac ham node
void khoitao_KH(List_KH *Q);              		//tao list moi rong va doc tu lieu tu file cho vao dslk
Node_KH *tao_node_KH(KH a);						//tra lai Node_KH p moi chua du lieu cua KH a					
void chen_node_KH_sau(List_KH *Q,Node_KH *p);	//chen Node_KH p vao vi tri cuoi cua List_KH

//cac ham con cho 1 nguoi
void in_KH(KH a);								//in du lieu cua 1 KH
void nhap_KH(List_KH Q,char sdt[12]);						//nhap du lieu cua 1 KH, 0 la thue bao moi, 1 la sua du lieu cu
// cac ham con cho nhieu nguoi	
void inds_KH(List_KH Q);						//in du lieu cua nhieu Kh
Node_KH *timkiem_KH(List_KH Q,char x[]);							//tim kiem va tra lai node co sdt can tim
void ghifile(List_KH Q);						//ghi lai du lieu trong dslk ra file
#endif









