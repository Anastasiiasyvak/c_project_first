#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int command;
    char* File = NULL;
    while(true) {
        printf("Choose the command! \n");
        scanf("%d", &command);
        getchar();
        switch (command) {
            case 1:
                printf("Enter text to append: \n");
                char text[100];
                fgets(text, sizeof(text), stdin);
                size_t sizeText = strlen(text);
                size_t sizeFile = (File == NULL) ? 0: strlen(File);
                size_t sizeFileNow = sizeText + sizeFile + 1;
                char* newFile = (char*)malloc(sizeFileNow);
                if (File != NULL) {
                    strcpy(newFile, File);
                }
                strcat(newFile, text);
                File = newFile;
                printf("%s", File);
                break;
            case 2:
                strcat(File, "\n");
                printf("New line is started\n");
                break;

            default:
                printf("The command is not implemented\n");
                break;
            }
        }
    }

