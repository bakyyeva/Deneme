/*
NxN platformda bilgisayar rastgele koordinatlar belirleyecek. Ekranda Platform 2 saniye gözüktükten sonra kaybolacak.
Oyuna katýlan oyuncular sýrasýyla belirlenen koordinatý bulmaya çalýþacaklar.
Doðru koordinatý bulduklarýnda puanlarý 10 puan aratacak ve puaný 50 yeten ilk oyuncu, oyunun kazananý olacak. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

main() {
    
 char oyuncu1[25], oyuncu2[25];
 int i, j, platform[50][50];
 int b_x, b_y, bo_x, bo_y, puan_a=0, adim_a=0; 
 int i_x, i_y, io_x, io_y, puan_b=0, adim_b=0;
 int b, b1;
  srand(time(NULL));
  
    printf("********HAFIZA OYNUNA HOSHGELDINIZ********");
    printf("\n\n");
    
    printf("Oyun tahtasini (NxN) sheklinde giriniz: ");
    scanf("%d %d", &b, &b1);
   
    printf("\n1.oyuncunun adini giriniz: ");
    scanf("%s", &oyuncu1);
    
    printf("2.oyuncunun adini giriniz: ");
    scanf("%s", &oyuncu2);
     
    printf("\n\n");
    
 while (1) {
  
       b_x = rand() % b;
       b_y = rand() % b1;  
     
       for(i=0;i<b;i++) 
           for(j=0;j<b1;j++) 
             platform[i][j] = '.';
             
     if(b_x >= 0 && b_x < b && b_y >= 0 && b_y < b1) {
         platform[b_x][b_y] = 'X';
          
        for(i=0;i<b;i++) {
            for(j=0;j<b1;j++) {
                 printf("%c ", platform[i][j]);
              }
              printf("\n"); 
          }
      }
        
      Sleep(2000);
      system("cls");
      
       printf("%s'in cevabi: ", oyuncu1);
       scanf("%d %d", &bo_x, &bo_y);
       
       if(bo_x == b_x+1 && bo_y == b_y+1) {
            printf("Dogru cevap:)\n");
            puan_a = puan_a + 10;  
         }
        else
          printf("Yanlis cevap...\n");
          
         printf("Puanin: %d ", puan_a);
         printf("\n\n");
         
         if(puan_a == 50) {
            break;
          }
          
         i_x =  rand() % b;
         i_y =  rand() % b1;  
     
       for(i=0;i<b;i++) 
           for(j=0;j<b1;j++) 
             platform[i][j] = '.';
             
     if(i_x >= 0 && i_x < b && i_y >= 0 && i_y < b1) {
          platform[i_x][i_y] = 'X';
          
         for(i=0;i<b;i++) {
             for(j=0;j<b1;j++) {
                 printf("%c ", platform[i][j]);
               }
             printf("\n"); 
           }
        } 
        
      Sleep(2000);
      system("cls");
      
         printf("%s'in cevabi: ", oyuncu2);
         scanf("%d %d", &io_x, &io_y);
         
         if(io_x == i_x+1 && io_y == i_y+1) {
               printf("Dogru cevap:)\n");
               puan_b = puan_b + 10;  
          }
          else
          printf("Yanlis cevap...\n");
          
         printf("Puanin: %d ", puan_b);
         printf("\n\n");
         
          if (puan_b == 50) {
           break;
          }
   }
  
   if(puan_a==50) {
     printf("\n\nTEBRIKLER!");
     printf("\nKazanan oyuncu: %s\n", oyuncu1);
    }
    
  else {
     printf("\n\nTEBRIKLER!");   
     printf("\nKazanan oyuncu: %s\n", oyuncu2);
    }
    
 getch();
 }
