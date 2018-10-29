#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int random_num(){
  //create file descriptor
  int fd = open("/dev/random", O_RDONLY);
  if(fd == -1){
     printf("Errno number: %d\n", errno);
  }
  //reading from file descriptor
  int random;
  read(fd,&random,sizeof(int));
  close(fd);
  return random;
}

int main(){
  //populates an array with 10 random numbers
  printf("Populating array:\n");
  int random[10];
  int i;
  for(i = 0; i < 10; i++){
   random[i] = random_num();
   printf("\random [%d]: %d\n", i, random[i]);
 }

  //writes the array to a file
  printf("Writing numbers into the file...\n");
  int new_fd = open("num.txt", O_WRONLY | O_CREAT, 0777);
  write(new_fd, random, sizeof(random));
  close(new_fd);

  //reads that file into a different array
  printf("Reading numbers from the file...\n");
  int read_array[10];
  new_fd = open("num.txt", O_RDONLY);
  read(new_fd,read_array, sizeof(random));
  close(new_fd);

  printf("Verifying that written numbers are the same...\n");
  //prints out the contents of the second array to verify
  int j;
  for(j = 0; j < 10; j++){
    printf("\random %d: %d\n", j, read_array[j]);
   }
	 return 0;

}
