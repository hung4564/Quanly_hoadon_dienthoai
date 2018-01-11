#ifndef __CAUTRUC_H
#define __CAUTRUC_H

struct ngay{
	int ngay, thang, nam;
};

struct tg{
	int gio, phut, giay;
};
typedef struct dd
{
	char ht[30];
	char diachi[100];
	char sdt[12];
	struct ngay dk,sinh;
}KH;
typedef struct ee
{
	KH info;
	struct ee *ptiep;	
}Node_KH;
typedef struct ff
{
	Node_KH *pdau;
	Node_KH *pcuoi;	
} List_KH;


struct hdkh
{
	struct ngay hd;
	int goi_nm;
	int goi_lm;
	unsigned int tgg_lm,tgg_nm;
	int tin_nm, tin_lm;
};
struct node
{
	struct hdkh info;
	struct node *ptiep;
};
struct list
{
	struct node *pdau;
	struct node *pcuoi;
};

#endif

