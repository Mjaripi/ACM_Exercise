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

  int isSorted(unsigned int *data, unsigned int num){
      for(int i = 0;(i + 1) < num;i++){
          if(data[i] > data[i+1]) return 0;
      }
      return 1;
  }

  unsigned int * Massign1(unsigned int *data, unsigned int num){
      unsigned int *P;
      P = calloc(num/2,sizeof(unsigned int));
      for(int i = 0;i < num/2-1;i++)
        P[i] = data[i];
      return P;
  }

  unsigned int * Massign2(unsigned int *data, unsigned int num){
      unsigned int *P;
      P = calloc(num/2,sizeof(unsigned int));
      for(int i = num/2;i < num;i++)
        P[i] = data[i];
      return P;
  }

  unsigned int * Merge(unsigned int *A, unsigned int *B, unsigned int *data){
      
      return data;
  }

  unsigned int * MergeSort(unsigned int *data, unsigned int num){
      unsigned int *A, *B;

      if(num == 1) return data;

      A = Massign1(data, num);
      B = Massign2(data, num);

      A = MergeSort(A, num/2-1);
      B = MergeSort(B, num/2);

      return Merge(A,B,data);
  }

 int main() {

     double area = 0;
     unsigned int *value, date;

     scanf("%u",&date);
     value = calloc(date,sizeof(unsigned int));

     for(int i = 0;i < date;i++){

        scanf("%u",&value[i]);
        if(value[i]>100)
            value[i] = 100;
     }

     if(isSorted(value,date) == 0){

     }

     area = TotalArea(area, 2*M_PI/date, value, date);

     printf("%.3lf\n", area);
     return 0;
 }
