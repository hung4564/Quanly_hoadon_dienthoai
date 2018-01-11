
#include "menu.h"
char x;
int i;
Node_KH *p;
KH a;
void menu_chinh()
{
	do {
		system("cls");
	    for(i=1;i<26;i++) printf("* ");
	    printf("\n");
	    printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
	    printf("*|%-45s|*\n","  CHUONG TRINH QUAN LY HOA DON DIEN THOAI");
		printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
		printf("*|%3s| %-40s|*\n","Nt","            Chuc nang");
		printf("*|");
		for(i=1;i<46;i++) printf("-");
		printf("|*");
		printf("\n");
		printf("*| %s | %-40s|*\n","1","Dang ky thue bao moi"); 
	    printf("*| %s | %-40s|*\n","2","Tra cuu thue bao hien co");
	    printf("*| %s | %-40s|*\n","3","Thong ke");
	    printf("*| %s | %-40s|*\n","0","Thoat chuong trinh");
	    printf("*|");
		for(i=1;i<46;i++) printf("=");
		printf("|*");	    
		printf("\n");
		for(i=1;i<26;i++) printf("* ");
	    switch(x=getch())
	    {
	    case '1':
    		menu_KH();
	        break;
	    case '2':
	    	menu_TT();
	        break;
	    case '3':
	    	menu_TK();
	    	break;
	    case '0':
			thoat();		
	    	break;
	    default:
	        printf("\nBan phai lua chon cac yeu cau tuong ung voi cac so tuong ung.\n");
	        break;
	    }
	}while(x!='0');		
     
}
void menu_KH()
{
	char sdt[12];
    do
    {    
		{
		system("cls");
	    for(i=1;i<26;i++) printf("* ");
	    printf("\n");
	    printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
	    printf("*|%-45s|*\n","            Dang ky khach hang");
		printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
		printf("*|%3s| %-40s|*\n","Nut","            Chuc nang");
		printf("*|");
		for(i=1;i<46;i++) printf("-");
		printf("|*");
		printf("\n");
		printf("*| %s | %-40s|*\n","1","Dang ky thue bao moi");
	    printf("*| %s | %-40s|*\n","2","Danh sach thue bao hien co");
	    printf("*| %s | %-40s|*\n","0","Quay lai menu chinh");
	    printf("*|");
		for(i=1;i<46;i++) printf("=");
		printf("|*");	    
		printf("\n");
		for(i=1;i<26;i++) printf("* ");			
		}
		switch(x=getch())
	    {
	    case '1':
	    	system("cls");
	    	printf("\nNhap so dien thoai:");
	    	scanf("%s",sdt);
	    	nhap_KH(Q,sdt);
			quayve(1);	    	
	        break;  
	    case '2':
	    	system("cls");
	    	inds_KH(Q);
	    	quayve(0);
	    	break;
	    case '0':
	    	quayve(0);
	    	break;
	    default:
	        printf("\n Ban phai lua chon cac yeu cau tuong ung voi cac so tuong ung.\n");
    	}
    }while (x!='0');
}

void menu_TT()
{
	system("cls");
	char sdt[12];
	printf("\nSo thue bao can tim: ");
	scanf("%s",sdt);
	p=timkiem_KH(Q,sdt);
	if(p==NULL)
	{
		printf("\nKhong ton tai so thue bao %s",sdt);
		printf("\nBan co muon tao so thue bao %s(Y\\N)",sdt);
		printf("\nAn Y de tao\n An N de quay ve");
		if(toupper(getch())=='Y') 
		{
			nhap_KH(Q,sdt);
	    	quayve(3);
		}
		else quayve(0);
	}
	else menu_TB(p);	
}
void menu_TB(Node_KH *p)
{
	do
    {
	{
		system("cls");
	    for(i=1;i<26;i++) printf("* ");
	    printf("\n");
	    printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
	    printf("*|%-45s%s|*\n","      Quan ly thong tin thue bao",p->info.sdt);
		printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
		printf("*|%3s| %-40s|*\n","Nut","            Chuc Nang");
		printf("*|");
		for(i=1;i<46;i++) printf("-");
		printf("|*");
		printf("\n");
		printf("*| %s | %-40s|*\n","1","Chinh sua thue bao");
	    printf("*| %s | %-40s|*\n","2","Hoat dong cua thue bao");
	    printf("*| %s | %-40s|*\n","3","Hoa don cua thue bao");
	    printf("*| %s | %-40s|*\n","0","Quay lai menu chinh");
	    printf("*|");
		for(i=1;i<46;i++) printf("=");
		printf("|*");	    
		printf("\n");
		for(i=1;i<26;i++) printf("* ");			
	}     
    switch(x=getch())
	    {
	    case '0':		
	    	break;
	    case '1':
	    	nhap_KH(Q,p->info.sdt);
	        break;
	    case '2':
	    	tong_hop(p->info.sdt);
	    	quayve(2);
	        break;
	    default:
	        printf("\nBan phai lua chon cac yeu cau tuong ung voi cac so tuong ung.\n");
	        break;
	    }
	}while(x!='0');
    quayve(0);
}
void menu_TK()
{   
    do
    {
	{
		system("cls");
	    for(i=1;i<26;i++) printf("* ");
	    printf("\n");
	    printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
	    printf("*|%-45s|*\n","          THONG KE");
		printf("*|");		
		for(i=1;i<46;i++) printf("=");
		printf("|*");
	    printf("\n");
		printf("*|%3s| %-40s|*\n","Nut","            Chuc Nang");
		printf("*|");
		for(i=1;i<46;i++) printf("-");
		printf("|*");
		printf("\n");
		printf("*| %s | %-40s|*\n","1","Danh sach khach hang");
	    printf("*| %s | %-40s|*\n","2","");
	    printf("*| %s | %-40s|*\n","3","");
	    printf("*| %s | %-40s|*\n","0","Quay lai menu chinh");
	    printf("*|");
		for(i=1;i<46;i++) printf("=");
		printf("|*");	    
		printf("\n");
		for(i=1;i<26;i++) printf("* ");			
	}
    
	switch(x=getch())
	    {
	    case '1':
	    	system("cls");
	    	inds_KH(Q);
	    	quayve(4);
	        break;
	    case '2':
	    	system("cls");
	    	inds_KH(Q);
	    	quayve(4);
	        break;
	    case '3':
	    	system("cls");
	    	inds_KH(Q);
	    	quayve(4);
	    	break;
	    case '0':		
	    	break;
	    default:
	        printf("\nBan phai lua chon cac yeu cau tuong ung voi cac so tuong ung.\n");
	        break;
	    }
	}while(x!='0');
    quayve(0);
	system("cls");
}
void quayve(int x)
{
	int i;
	printf("\nBam phim bat ki de quay ve");
	getch();
//	printf("\nThuc hien xong thao tac,doi 5s de quay ve menu \n");
//	for(i=5;i>-1;i--)
//	{
//		sleep(1);
//		printf("%d..",i); 
//	}
	system("cls");
	switch(x)
	{
		case 0:
			menu_chinh();
			break;
		case 1:
			menu_KH();
			break;
		case 2:
			menu_TB(p);
			break;
		case 3:
			menu_TT();
		case 4:
			menu_TK();
	}
}
void thoat()
{  
	system("cls"); 	
	printf("\nBAN MUON THOAT CHUONG TRINH(Y\\N)");
	printf("\nAN Y DE THOAT");
	printf("\nAN N DE QUAY LAI");
	if(toupper(getch())=='Y') printf("\nTHOAT CHUONG TRINH");
	else menu_chinh();
}
