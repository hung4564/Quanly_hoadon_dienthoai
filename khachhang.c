#include "khachhang.h"

//cac ham voi khach hang
void khoitao_KH(List_KH *Q)    				// tao danh sanh Q rong
{
	Q->pdau=NULL;							// cho con tro khoi dau khong chi den dau
	Q->pcuoi=NULL;
	FILE *f;
	KH a;
	Node_KH *p;
	f=fopen("khachhang.txt","a+");
	if(!f)									// kiem tra file co ton tai khong
    {
    	printf("\nkhong ton tai file khachhang.text");
	}
	else while(!feof(f)) 					//doc du lieu vao danh sach lien ket
	{
		fscanf(f,"%[^|]|%d/%d/%d|",&a.sdt,&a.dk.ngay,&a.dk.thang,&a.dk.nam); // doc sdt va ngay dang ky(bat buoc co)
		fscanf(f,"%[^|]|",&a.ht);											 // doc ho ten				
		fscanf(f,"%d",&a.sinh.ngay);										 // doc ngay sinh	
		if(a.sinh.ngay!=0) fscanf(f,"/%d/%d",&a.sinh.thang,&a.sinh.nam);     // neu khong co ngay sinh
		fscanf(f,"|%[^\n]\n",a.diachi);										 // doc dia chi							
		p=tao_node_KH(a);													 //cap bo nho cho node
		chen_node_KH_sau(Q,p); 												 // chen node vao cuoi list Q
	}
	fclose(f);
}

void chen_node_KH_sau(List_KH *Q,Node_KH *p)		//chen Node_KH vao cuoi danh sach lien ket
{
	if(Q->pdau==NULL)					//xet List_KH neu rong thi cho Node_KH la Node_KH dau
	{
		Q->pdau=p;
	}
	else 
	{
		Q->pcuoi->ptiep=p;				//con tro cua Node_KH truoc tro vao Node_KH chen	
	}
	Q->pcuoi=p; 						//con tro cuoi la danh sach la Node_KH chen
}
Node_KH *tao_node_KH(KH a)    				// cap phat bo nho cho Node_KH KH
{
	Node_KH *p;
	p=(Node_KH *) malloc (sizeof(Node_KH)); 	// cap phat bo nho dong
	p->info=a;							// gan du lieu cua info cua Node_KH p
	p->ptiep=NULL;						// gan con tro tiep trong Node_KH p
	return p;							// tra ve Node_KH p
}

void in_KH(KH a)						//in ra du lieu cua 1 KH
{
	printf("\n\nThong tin thue bao %s",a.sdt);
//	printf("\n%-16s: %s","So dien thoai",a.sdt);
	printf("\n%-16s: %s","Ho ten",a.ht);
	printf("\n%-16s: %02d/%02d/%4d","Ngay dang ki",a.dk.ngay,a.dk.thang,a.dk.nam);
	if(a.sinh.ngay!=0) printf("\n%-16s: %02d/%02d/%4d","Ngay sinh",a.sinh.ngay,a.sinh.thang,a.sinh.nam); 
	else printf("\n%-16s: Khong ro","Ngay sinh");
	printf("\n%-16s: %s","Dia chi",a.diachi);
}

void inds_KH(List_KH Q)					//in du lieu cua nhieu KH dua tren in du lieu cua 1 KH
{
	Node_KH *p;
	p=Q.pdau;
	while(p!=NULL)					//in ra du lieu dung nguoi
	{
		in_KH(p->info);				//in ra du lieu cua Node_KH p(info)
		p=p->ptiep;					//gan con tro den Node_KH tiep
	}
}
Node_KH *timkiem_KH(List_KH Q,char sdt[12])
{
	Node_KH *p;
	p=Q.pdau;
	while(p!=NULL)					
	{
		if(strcmp(sdt,p->info.sdt)==0) break;
		p=p->ptiep;					
	}
	return p;
}
void nhap_KH(List_KH Q,char sdt[12])
{
	time_t rawtime;
	struct tm *tgg;
	time ( &rawtime );
	tgg = localtime ( &rawtime );
	Node_KH *p;
	KH a;
	p=timkiem_KH(Q,sdt);
	if(p==NULL)
	{
		strcpy(a.sdt,sdt);
		a.dk.ngay=tgg->tm_mday;
		a.dk.thang=tgg->tm_mon+1;
		a.dk.nam=tgg->tm_year+1990;
		printf("\nNhap thonng tin thue bao %s",a.sdt);
		printf("\nHo ten la ");
		fflush(stdin);
		gets(a.ht);
		printf("\nNgay sinh(nhan 0 de bo qua):");
		scanf("%d",&a.sinh.ngay);
		if(a.sinh.ngay!=0)
		{
			printf("\nThang sinh:");
			scanf("%d",&a.sinh.thang);
			printf("\nNam sinh:");
			scanf("%d",&a.sinh.nam);
		}
		printf("\nDia chi:");
		fflush(stdin);
		gets(a.diachi);
		printf("\nThong tin vua nhap");
		in_KH(a);
		printf("\nBan xac nhan muon tao thue bao nay\nAn Y de dong y\nAn E de chinh sua\nAn N de bo");
		switch(getch())
		{
		    case 'Y':
		    case 'y':
				p=tao_node_KH(a);
			   	chen_node_KH_sau(&Q,p);
				break;
			case 'E':
			case 'e':
				system("cls");
				nhap_KH(Q,sdt);
		    	break;
			case 'N':
			case 'n':
			break;									
		}
	}
	else
	{
		printf("\nThue bao %s ton tai, ban co muon chinh sua",sdt);
		printf("\nAn Y de sua\nAn N de quay ve");
		switch(getch())
		{
			case 'Y':
		    case 'y':
				in_KH(p->info);
t3:		    	printf("\nSua thong tin thue bao %s",p->info.sdt);
				printf("\nHo ten la(%s) ",p->info.ht);
				fflush(stdin);
				gets(p->info.ht);
				if(p->info.sinh.ngay==0)
				printf("\nNgay sinh(nhan 0 de bo qua)(Khong co):");
				else printf("\nNgay sinh(nhan 0 de bo)(%02d/%02d/%d)",p->info.sinh.ngay,p->info.sinh.thang,p->info.sinh.nam);
				scanf("%d",&p->info.sinh.ngay);
				if(p->info.sinh.ngay!=0)
				{
					printf("\nThang sinh:");
					scanf("%d",&p->info.sinh.thang);
					printf("\nNam sinh:");
					scanf("%d",&p->info.sinh.nam);
		  		}
				printf("\nDia chi:");
				fflush(stdin);
				gets(p->info.diachi);
				printf("\nThue bao %s sau khi chinh sua",p->info.sdt);
				in_KH(p->info);
				printf("\nBan co muon chinh sua lai");
				printf("\nAn Y de sua\nAnN de quay ve");
				if (toupper(getch()) == 'Y') goto t3;				
				break;
			case 'N':
			case 'n':
			    break;
		}
	}
	ghifile(Q);
}
void ghifile(List_KH Q)
{
	FILE *f;
	Node_KH *p;
	f=fopen("khachhang.txt","w+");
	p=Q.pdau;
	while(p!=NULL)					
	{
		fprintf(f,"%s|%d/%d/%d|",p->info.sdt,p->info.dk.ngay,p->info.dk.thang,p->info.dk.nam);
		fprintf(f,"%s|",p->info.ht);
		fprintf(f,"%d",p->info.sinh.ngay);
		if(p->info.sinh.ngay!=0) fprintf(f,"/%d/%d",p->info.sinh.thang,p->info.sinh.nam);
		fprintf(f,"|%s\n",p->info.diachi);		
		p=p->ptiep;					//gan con tro den Node_KH tiep
	}	
	fclose(f);
}
