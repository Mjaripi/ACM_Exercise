/*
 * FILE: DOL.c
 *
 * DESCRIPTION:
 *
 * AUTHOR: Alonso Maripi Vallejos & Silvana Cerda Aravena
 *
 * LAST REVISED: Santiago de Chile, 28/11/2016
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
        //if y comparas el ultimo pto con el primero
        area = area + CalcA(angle, data[i], data[i+1]);

     }
     area = area + CalcA(angle, data[0], data[num-1]);
 }
/*
  int isSorted(unsigned int *data, unsigned int num){
      for(int i = 0;(i + 1) < num;i++){
          if(data[i] > data[i+1]) return 0;
      }
      return 1;
  }

  unsigned int * Massign(unsigned int *data, unsigned int num, unsigned new){
      unsigned int *P;
      P = calloc(new,sizeof(unsigned int));
      for(int i = new;i < num;i++)
        P[i] = data[i];
      return P;
  }

  unsigned int * Copy(unsigned int *data, unsigned int *X, unsigned int num, unsigned int new){

  }

  unsigned int * Merge(unsigned int *A, unsigned int *B, unsigned int *data, unsigned int num){

      int i=0, j=0, k=0;
      while (i < num/2 - 1 && j < num/2){
          if(A[i] <= B[j]){
              data[k] = A[i];
              i = i + 1;
          }
          else{
              A[k] = B[j];
              j = j + 1;
          }
          k = k + 1;
          if(i = num/2 - 1)
      }
      return data;
  }

  unsigned int * MergeSort(unsigned int *data, unsigned int num){
      unsigned int *A, *B;

      if(num == 1) return data;

      A = Massign(data, num, num/2-1);
      B = Massign(data, num, num/2);

      A = MergeSort(A, num/2-1);
      B = MergeSort(B, num/2);

      return Merge(A,B,data, num);
  }

*/
/*
void ordena(unsigned int *data,unsigned int izq,unsigned int der ){
            int i = 0, j = 0;
            int x = 0, aux = 0;
            i = izq;
            j = der;
            x = data [ (izq + der) /2 ];
            do{
                while( (data[i] < x) && (j <= der) ){
                       i++;}
                while( (x < data[j]) && (j > izq) ){
                       j--;}
                if( i <= j ){
                    aux = data[i];
                    data[i] = data[j];
                    data[j] = aux;
                    i++;  j--;
                }
            }while( i <= j );
            if( izq < j )
                ordena( data, izq, j );
            if( i < der )
                ordena( data, i, der );
        }
*/
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
     //isSorted(value,date);
     ordena(date,izq,der);
     if(date>=3) { //si tenemos mas de 3 puntos
     int j=1; //corresponde a la segunda posicion del arreglo
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
