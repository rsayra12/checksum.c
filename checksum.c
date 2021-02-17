#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte unsigned char



int main(int argc, char * argv[], char ** envp){

  int count = 10;
  int sum = 0;
  byte checksum;
  byte complement;
  int value;
  unsigned char header[10];
  byte buffer[10];
  int quotient;
  int remainder;

  read(STDIN_FILENO, &buffer, 10);
    for(int counter = 0; counter < 10; counter++){
        printf("%d ", buffer[counter]);
        printf("\n");
    }

    for(int counter = 0; counter < count; counter++){
      if(counter == 5){
        checksum = buffer[counter];
        buffer[counter] = 0;
      }
      sum += buffer[counter];
    }

    quotient = (sum / (max_int + 1));
    remainder = (sum % (max_int + 1));
    sum = quotient + remainder;
    complement = max_int - sum;

fprintf(stdout,"Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if(checksum != complement){
        fprintf(stderr, "Error Detected!\n");
        return 1;
        }
          return 0;
    }
