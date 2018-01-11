#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "menu.h"
#include "cautruc.h"
#include "hoatdong.h"
#include "khachhang.h"
#include "hoadon.h"
List_KH Q;

int main()
{	
	
	khoitao_KH(&Q);	
	menu_chinh();
	return 0;	
}
