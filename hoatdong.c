#include"hoatdong.h"
struct hdkh Nhapvao;

int tong_hop(char ten[12])          //Ham nay hien thi tong hop cac thong so: tong so cuoc goi, so tin nhan trong mot thang.
{
	int i,j=0;   int n;
	char ch;  
	int tg, T_gnm=0, T_glm=0, T_tnm=0, T_tlm=0;    //Bien trung gian, tong cuoc goi(nm va lm) va tong tin nhan(nm va lm).
	char x[20];
    struct hdkh *a;
	a = &Nhapvao;
	FILE *f;
	char tenfile[16];	
	strcpy(tenfile,ten);	
	strcat(tenfile,".txt");
	f=fopen(tenfile,"r");
	if(f==NULL) 
	{
		printf("\nThue bao %s chua co hoat dong nao",ten);
		f=fopen(tenfile,"w");
	}
	else 
	{
		fflush(f); fflush(stdin);
		fscanf(f,"%d/%d/%d;%d,%d;%[^;];%d,%d.\n", &a->hd.ngay, &a->hd.thang, &a->hd.nam, &a->goi_nm, &a->goi_lm, &x, &a->tin_nm, &a->tin_lm);
		tg = a->hd.thang;
		T_gnm+= a->goi_nm;	T_glm+= a->goi_lm;
		T_tnm+= a->tin_nm;  T_tlm+= a->tin_lm;
		printf("Hoat dong cua quy khach:\n");
		for(i=0; i<3; i++)                               //Neu muon kqua cua 5 thang thi thay 4 bang 5
		{
			printf("\nThang %d/%d:", a->hd.thang, a->hd.nam);    //Hien thi thang ra man hinh
			while(1)
			{
				fscanf(f,"%d/%d/%d;%d,%d;%[^;];%d,%d.\n",&a->hd.ngay, &a->hd.thang, &a->hd.nam, &a->goi_nm, &a->goi_lm, &x, &a->tin_nm, &a->tin_lm);
				if (feof(f)!=0){
		    		T_gnm += a->goi_nm; T_glm += a->goi_lm; 
					T_tnm += a->tin_nm; T_tlm += a->tin_lm;
					printf("\n\t*Cuoc goi: Da goi %d cuoc goi noi mang, %d cuoc goi ngoai mang", T_gnm, T_glm);
		    		printf("\n\t*Tin nhan: Da gui %d tin noi mang, %d tin ngoai mang\n", T_tnm, T_tlm);
		    		goto t;
				}
				else if(a->hd.thang==tg) 
				{ 
					T_gnm+= a->goi_nm; 
					T_glm+= a->goi_lm; 
					T_tnm+= a->tin_nm;  
					T_tlm+= a->tin_lm; 
					continue; 
				}
				else if (a->hd.thang!=tg )
				{
		    		printf("\n\t*Cuoc goi: Da goi %d cuoc goi noi mang, %d cuoc goi ngoai mang", T_gnm, T_glm);
		    		printf("\n\t*Tin nhan: Da gui %d tin noi mang, %d tin ngoai mang\n", T_tnm, T_tlm);
				}
				break;
		    }
		    
		    tg = a->hd.thang;
		    T_gnm = a->goi_nm; T_glm = a->goi_lm; 
			T_tnm = a->tin_nm; T_tlm = a->tin_lm;
		}
	}
	
t:	fclose(f);
	// DA XONG, CHI CO MOT LOI DUY NHAT LA KHI THANG CUOI CUNG CHI CO MOT DU LIEU, KHI DO SE GAP LOI
};

void chi_tiet(char ten[12])         //Ham nay hien thi chi tiet so cuoc goi, so tin nhan trong tung ngay.
{
	int i,j=0;   int n;
	char ch;                  //Bien dem
	int tg, T_gnm=0, T_glm=0, T_tnm=0, T_tlm=0;    //Bien trung gian, tong cuoc goi va tong tin nhan
    struct hdkh *a;
	a = &Nhapvao;
	FILE *f;
	
	system("cls");
	printf("Ban can bao nhieu ket qua, n= "); scanf("%d", &n);
	
	//ghep tu doan nay
	char tenfile[16];	
	strcpy(tenfile,ten);	
	strcat(tenfile,".txt");
	f=fopen(tenfile,"r");
	fflush(f); fflush(stdin);
	
	//Chay vong for doc du lieu tep
	for(j=0; j<n; j++){	
	//Ngay cap nhat va so cuoc goi noi-ngoai mang
	fscanf(f,"%d/%d/%d;%d,%d;",&a->hd.ngay, &a->hd.thang, &a->hd.nam, &a->goi_nm, &a->goi_lm);
	printf("\nNgay:%d/%d/%d\n\t*Thuc hien %d cuoc goi noi mang, %d cuoc goi ngoai mang", a->hd.ngay, a->hd.thang, a->hd.nam, a->goi_nm, a->goi_lm);
	
	//Noi mang va ngoai mang
	if(a->goi_nm>0&&a->goi_lm>0){
		printf("\n\t  +Thoi gian goi noi mang: ");
		for(i=0;i<a->goi_nm;i++){
	    	fscanf(f,"%d:%d:%d,", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
		    printf("%02d:%02d:%02d, ", a->tgg.gio, a->tgg.phut, a->tgg.giay);
	    }
		printf("\n\t  +Thoi gian goi lien mang: ");
	    for(i=0;i<a->goi_lm;i++){
	        if(i==a->goi_lm-1) fscanf(f,"%d:%d:%d", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
			else fscanf(f,"%d:%d:%d,", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
		    printf("%02d:%02d:%02d, ", a->tgg.gio, a->tgg.phut, a->tgg.giay);
	    }
	}
	else if(a->goi_nm>0&&a->goi_lm==0){
		printf("\n\t  +Thoi gian goi noi mang: ");
		for(i=0;i<a->goi_nm;i++)
		{
	        if(i==a->goi_nm-1) fscanf(f,"%d:%d:%d", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
			else fscanf(f,"%d:%d:%d,", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
		    printf("%02d:%02d:%02d, ", a->tgg.gio, a->tgg.phut, a->tgg.giay);
	    }
	}
	else if(a->goi_nm==0&&a->goi_lm>0){
		printf("\n\t  +Thoi gian goi lien mang: ");
	    for(i=0;i<a->goi_lm;i++)
		{
	        if(i==a->goi_lm-1) fscanf(f,"%d:%d:%d", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
			else fscanf(f,"%d:%d:%d,", &a->tgg.gio, &a->tgg.phut, &a->tgg.giay);
		    printf("%02d:%02d:%02d, ", a->tgg.gio, a->tgg.phut, a->tgg.giay);
	    }
    }
    else if(a->goi_nm==0&&a->goi_lm==0) printf("\n\t Khong co cuoc goi nao duoc thuc hien");
    
	////Tin nhan
	fscanf(f,";%d,%d.\n", &a->tin_nm, &a->tin_lm);
	printf("\n\t*Gui %d tin noi mang, Gui %d tin ngoai mang\n", a->tin_nm, a->tin_lm);
	if(!feof(f)) break;
    }
	fclose(f); 
};

