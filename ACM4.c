/*
 * FILE: DOL.c
 *
 * DESCRIPTION:
 *
 * AUTHOR: Alonso Maripi Vallejos & Silvana Cerda Aravena
 *
 * LAST REVISED: Santiago de Chile, 18/11/2016
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <time.h>
 #include <math.h>

 double CalcA(double An, unsigned int Va1, unsigned int Va2){
      return (0.5*Va1*Va2*An);
 }

 double TotalArea(double area, double angle, unsigned int *data, unsigned int num){

     angle = sin(angle);

     for(int i = 0;(i + 1) < num;i++){
        area = area + CalcA(angle, data[i], data[i+1]);

     }
     area = area + CalcA(angle, data[0], data[num-1]);
 }

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

 int main() {

     double area = 0;
     int izq, der;
     unsigned int *value,*value2, date;
     scanf("%u",&date);
     value = calloc(date,sizeof(unsigned int));
     value2 =calloc(date,sizeof(unsigned int)); 
     for(int i = 0;i < date;i++){

        scanf("%u",&value[i]);
        if(value[i]>100)
            value[i] = 100;
     }
     qsort(value, date,sizeof(unsigned int),cmpfunc);

     if(date>=3) { //si tenemos mas de 3 puntos
     int j=0; 
     int cont = date-1;  // corresponde a la posicion penultima
     value2[0]=value[0]; // respaldo
     for  (int i= 0; i<date;i++){  //recorremos
         if (i%2!=0){ //si es distinto a modulo de 2 tomamos el valor 
	     value2[j]=value[i]; //toman2 valor
	     j++; //avanzamos


	     
	}
     	else {
           value2[cont]=value[i];  //cuando se hayan acabado los distintos a modulo de 2 analizamos desde aca
	   cont--; //los enviamos al final de la lista


	     }
	
	} 
}
    
     area = TotalArea(area, 2*M_PI/date, value2, date);

     printf("%.3lf\n", area);
     return 0;
 }





