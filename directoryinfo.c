#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

int main(){
  int size;
  char* directory = ".";
  DIR *d;
  d = opendir(directory);
  struct dirent *directories;
  struct stat stats;
  printf("Info for %s\n", directory);
  directories = readdir(d);
  while (directories){
    if (directories -> d_type == DT_DIR){
      printf("d");
    }
    else{
      printf(" ");
    }
    printf("%s", directories -> d_name);
    stat(directories -> d_name, &stats);
    size = 0;
    size += stats.st_size;
    printf("%d\n", stats.st_size);
    directories = readdir(d);
  }
  printf("\n total size: %d\n", size);
  closedir(d);
}
