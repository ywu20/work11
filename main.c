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

printf("Generating random numbers ...\n");
 //populates and prints th array
 for(i=0;i<10;i++){
  populate(rand+i);
  printf("random %d: %d\n", i,rand[i]);
 }

 printf("\nWriting numbers to file ...\n");
 int wr = open("write.txt",O_RDWR);
 int bytes_written = write(wr, rand, 10 * sizeof(int));
 //printf("writing file open: %d\n", wr);
 //printf("bytes written: %d\n", bytes_written);
 close(wr); // need to close and reopen to save changes

 int ree = open("write.txt",O_RDONLY);
 printf("\nReading numbers to file ...\n");
 int rd [10];
 int bytes_read = read(ree, rd, 10*sizeof(int));
 //printf("bytes read: %d\n", bytes_read);

  for(i=0;i<10;i++){
  printf("random %d: %d\n", i,rd[i]);
 }

 return 0;
}
