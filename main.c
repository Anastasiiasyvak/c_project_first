#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int command;
    char* File;
    char text[100];
    File = (char* )malloc(sizeof(char));

    while(true) {
        printf("Choose the command! \n");
        scanf("%d", &command);
        getchar();
        switch (command) {
            case 1:
                printf("Enter text to append: \n", text);
                fgets(text, sizeof(text), stdin);
                File = (char *) realloc(File, strlen(File) + strlen(text) + 1);
                strcat(File, text);
                printf("%s", File);
                break;
            case 2:
                strcat(File, "\n");
                printf("New line is started\n");
                break;
        }
    }
}