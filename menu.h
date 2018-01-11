#ifndef __MENU_H
#define __MENU_H
#include <stdlib.h>
#include <stdio.h>
#include "cautruc.h"

extern List_KH Q;
// cac ham con menu
void menu_chinh();				//menu dau chuong trinh
void menu_KH();					//menu dang ky KH
void menu_TK();					//menu thong ke
void menu_TT();					//menu tra cuu
void menu_TB(Node_KH *p);		//menu tra hoat dong, hoa don cua tung thue bao
void quayve(int x);   			//0-menu chinh,1-menu KH,2-menu TB,3-menu TT,4-menu TK
void thoat();					//thoat khoi chuong trinh

#endif

