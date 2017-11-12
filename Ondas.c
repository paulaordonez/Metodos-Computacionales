#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
	float L;
	double c;
	float h;
	L=0.64;
	c=250.0;
	h=0.005000; //espaciamiento de tiempo
	FILE *datos;
	int lineas;
	int contador;
	int i; //para recorrido
	float in;
	float *pasado;
	int importando;
	// se cargan los datos y se debe tener r para leer los datos
	datos= fopen("cond_ini_cuerda.dat","r");
	//debo definir un FILE para poder contar el numero de datos
	
	lineas=0;
	while((contador=fgetc(datos)) != EOF)
		if (contador == '\n')
			lineas++;
	fclose(datos);
	//printf("%d\n",lineas);
	pasado = malloc(lineas*sizeof(float));
	// se corrio el programa y se obtuvo que hay 129 lineas
	//se necesita declarar cuantos espacios se necesitan para llenar el archivo
	fi=malloc(lineas*sizeof(float));
	datos= fopen("cond_ini_cuerda.dat","r");
	// se neceita sacar la columna de los archivos para leer todas las lineas se necesita un while
i=0;
	while(i<129){
		importando = fscanf(datos, "%f %f\n",&in,&pasado[i]);

		if(importando!=EOF){
			printf(" %f", pasado[i]);
			//printf("tiempo= %f\n", in);
				}
		
		i = i+1;
		
		
	}
	printf(" \n");
	fclose(datos);
	// se tiene que se deben hacer los recorridos para solucionar y esto se hace por medio del metodo de diferencias finitas
	// in es 
	
	
	int nt;
	float dt;
	dt= (h*0.7)/c;
	nt=(1.0/dt)+1.0; 
	float div;
	int k;
	div= (pow(c,2)*pow(dt,2))/(pow(h,2)); 
	float first;
	k =0;

	float uprest[129];
	int n;
	first =0;
	n = 0;
	float *futuro=malloc(lineas*sizeof(float));
	uprest[k]=pasado[0];
	uprest[lineas-1]=pasado[lineas-1];
	for (k=1; k<lineas-1; k++){				
			first = pasado[k-1] -2*pasado[k] + pasado[k+1];
			uprest[k] = pasado[k] + first*(div/2);
	}
	for(k=0; k<lineas; k++){
		printf(" %f", uprest[k]);
	}
	printf("\n");
	int j;
	int s;
	j=2;
	s=0;
	for(j=2; j<nt; j++)
	{
		futuro[0]=uprest[0];
		futuro[lineas-1]=uprest[lineas-1];
			for(s=1; s<lineas-1;s++){
				futuro[s]=2*uprest[s]-pasado[s]+((uprest[s-1]-2*uprest[s]+uprest[s-1])*div);
			}
	int g;
	g=0;
	for(g=0; g<lineas; g++){
		printf(" %f",futuro[g]);
	}
	printf("\n");
	int d;
	for(d=0; d<lineas; d++){
			pasado[d]= uprest[d];
			uprest[d]= futuro[d];
		}
	}
return 0;
}
/*int main(){
	float L;
	double c;
	float h;
	L=0.64;
	c=250.0;
	h=0.005000;
	int lineas;
	lineas=129;
	float dt;
	int nt;
	float *uprest2;
	float *futuro2;
	float *pasado2;
	#define PI 3.141592
	float futuro2= malloc(lineas*sizeof(float));
	float pasado2= malloc(lineas*sizeof(float));
	float uprest2= malloc(lineas*sizeof(float));
	dt= (h*0.7)/c;
	nt=(1.0/dt)+1.0; 
	float div;
	int k;
	div= (pow(c,2)*pow(dt,2))/(pow(h,2)); 
	float first2;
	k =0;
	int i;
	uprest2[0]=0;
	uprest2[lineas-1]=sin((2*PI*c)/L*dt);
	for(i=0; i<lineas; i++){
		pasado2[i]=0;
		printf(" %f",pasado2[i]);
	
	}
	for(k=0; k<lineas; k++){
		first2=pasado2[k-1]-2*pasado2[k]+pasado2[k+1];
		uprest2[k] = pasado2[k] + first2*(div/2);
	}
	for(k=0; k<lineas; k++){
		printf(" %f", uprest2[k]);
	}
	printf("\n");
	int j;
	int s;
	j=2;
	s=0;
	for(j=2; j<nt; j++)
	{
		futuro2[0]=uprest2[0];
		futuro2[lineas-1]=uprest2[lineas-1];
			for(s=1; s<lineas-1;s++){
				futuro2[s]=2*uprest2[s]-pasado2[s]+((uprest2[s-1]-2*uprest2[s]+uprest2[s-1])*div);
			}
	int g;
	g=0;
	for(g=0; g<lineas; g++){
		printf(" %f",futuro2[g]);
	}
	printf("\n");
	int d;
	for(d=0; d<lineas; d++){
			pasado2[d]= uprest2[d];
			uprest2[d]= futuro2[d];
		}
	}
return 0;
	
}*/

