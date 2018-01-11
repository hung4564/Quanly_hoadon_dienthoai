
#include "hoadon.h"

float tinh_nm(struct tg a)
{
	float tong1;
	tong1=60*a.gio*890+a.giay/60.0*890+a.phut*890;
	return tong1;
}
float tinh_lm(struct tg a)
{
	float tong2;
	tong2=60*a.gio*990+a.giay/60.0*990+a.phut*990;
	return tong2;
}	
void hoadon(char tenfile)
{
	FILE *f;
	f=fopen(tenfile,"r");
	
}
