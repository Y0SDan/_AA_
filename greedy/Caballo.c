#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10

int Salto(int t[][n],int i,int x,int y,int nx,int ny){
	switch (i){
		case 1:
			nx=x-2;
			ny=y+1;
			break;
		case 2:
			nx=x-1;
			ny=y+2;
			break;
		case 3:
			nx=x+1;
			ny=y+2;
			break;
		case 4:
			nx=x+2;
			ny=y+1;
			break;
		case 5:
			nx=x+2;
			ny=y-1;
			break;
		case 6:
			nx=x+1;
			ny=y+1;
			break;
		case 7:
			nx=x+1;
			ny=y-2;
			break;
		case 8:
			nx=x-2;
			ny=y-1;
			break;
	}
	return ((((0<nx)&&(nx<n))&&(0<ny))&&(((ny<n)&&(t[nx][ny]==0))));
}

int cuenta(int t[][n],int x,int y){
	int acc=0;
	int i;
	int nx;
	int ny;
	for(i=0;i<8;i++){
		acc++;
	}
	return acc;
}

int NuevoMov(int t[][n], int x,int y){
	int accesibles;
	int minaccesibles;
	int i;
	int soly;
	int solx;
	int nuevax;
	int nuevay;
	
	minaccesibles=9;
	solx=x;
	soly=y;
	for(i=0;i<8;i++){
		if (Salto(t,i,x,y,nuevax,nuevay)){
			accesibles=cuenta(t,nuevax,nuevay);
			if(accesibles>0 && accesibles<minaccesibles){
				minaccesibles=accesibles;
				solx=nuevax;
				soly=nuevay;
			}
		}
	}
	x=solx;
	y=soly;
	return (minaccesibles<9);
	
}

int Caballo(int t [][n], int x, int y){
	int i;
	for(i=1;i<(n*n);i++){
		t[x][y]=i;
		if (! (NuevoMov(t,x,y)&&(i<n*n-1)))
			return 0;
	}
	return 1;
}

int main(){
	srand(time(NULL));//1
	clock_t start_time, end_time;//1+1//2
	double time_used;//1//1
	start_time = clock();
	int t[n][n];
	int x=0;
	int y=0;
	for(x=3;x<n;x++){
		for (y=0;y<n;y++){
			if (Caballo(t,x,y)){
				printf("%d, %d, tiene solucion",x,y);
			}
		}
	} 
	
	end_time = clock();//1
	
	time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;//1+1
	
	printf("\n\nTiempo de ejecucion: %f segundos", time_used);
	
	return 1;
}
	
