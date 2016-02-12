#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

int main() {
  char line[10000];
  
  int fd = open("image.ppm", O_WRONLY | O_APPEND | O_CREAT, 0644);

  sprintf(line, "%s", "P3 640 640 640 \n");
  write(fd, line, strlen(line));

  int i = 0;
  int j = 0;

  strcpy(line, ""); // To clear the string

  int r;
  
  for (i = 0; i < 640; i++) {
    for (j = 0; j < 640; j++) {
      char new_pixel[20];
      int r = i % 256;
      int g = (i * j) % 256;
      int b = j % 256;
      sprintf(new_pixel, "%d %d %d ", r, g, b);
      write(fd, new_pixel, strlen(new_pixel));
    }
  }

  return 0;
}
