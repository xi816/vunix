#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "vfs.h"

void shell() {
	char str[128];
	for(;;) {
		printf("root@vunix: ");
		fgets(str, sizeof(str), stdin);
		str[strcspn(str, "\n")] = '\0';
    if (!*str) {
      continue;
    }
		else if(!strcmp(str, "exit")) {
			break;
		} else if(!strncmp(str, "echo ", 5)) {
			printf("%s\n", str+5);
		} else if(!strcmp(str, "clear")) {
			fputs("\033[H\033[2J", stdout);
		} else if(!strcmp(str, "help")) {
			printf("  exit\t\texit\n  echo <str>\techo\n  ls\t\tlist files\n  cat <file>\tshow file contents\n  exec\t\texec binary\n  help\t\thelp\n");
		} else if(!strcmp(str, "ls")) {
			printf("total %if %id\n", file_count, dir_count);
			for(int i = 0; i < file_count; i++) {
				if(files[i].name[0] != '\0') {
					printf("  file %i %s\n", i, files[i].name);
				}
			} 
			for(int i = 0; i < dir_count; i++) {
				if(dirs[i].name[0] != '\0') {
					printf("  dir  %i %s/\n", i, dirs[i].name);
				}
			}
			putchar('\n');
		} else if(!strncmp(str, "cat", 3)){
      if (!*(str+4)) {
        puts("cat -- Output file content");
        puts("Usage: cat <file>");
      }
      else {
  			File* f = sys_open(str+4);
	  		if(f == NULL) {
		  		printf("File %s doesn`t exist\n", str+4);
			  } else {
				  printf("%s\n", f->content);
			  }
      }
		} else if(!strncmp(str, "exec", 4)) {
      if (!*(str+5)) {
        puts("exec -- Load v.out files to memory and execute them");
        puts("Usage: exec <file>");
      }
      else puts("fuck you");
		} else {
			printf("Unknown command: %s\n", str);
		}
	}
}
