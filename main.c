#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>


//generates a random number and return
int populate(int * rand){
 int file = open("/dev/random",O_RDONLY); 
 read(file, rand, sizeof(int));
 return *rand;
}

int main(){
 int rand[10];
 int i;

 //populates and prints th array
 for(i=0;i<10;i++){
  populate(rand+i);
  printf("rand[%d]: %d\n", i,rand[i]);
 }
 
 printf("\nWriting numbers to file ...\n");
 int wr = open("write.txt", O_RDWR);
 write(wr, rand, 10 * sizeof(int));
 
 printf("\nReading numbers to file ...\n");
 int rd [10];
 read(wr, rd, 10*sizeof(int));
 
  for(i=0;i<10;i++){
  printf("rd[%d]: %d\n", i,rd[i]);
 }
 
 return 0;
}
