#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int command;
    char* Buffer = NULL;
    char file_for_saving[100];
    char file_for_loading[100];
    char loaded_text[500] = {'\0'};
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
                size_t sizeFile = (Buffer == NULL) ? 0 : strlen(Buffer);
                size_t sizeFileNow = sizeText + sizeFile + 1;
                char* newFile = (char*)malloc(sizeFileNow);
                if (Buffer != NULL) {
                    strcpy(newFile, Buffer);
                }
                strcat(newFile, text);
                Buffer = newFile;
                printf("%s", Buffer);
                break;
            case 2:
                strcat(Buffer, "\n");
                printf("New line is started\n");
                break;
            case 3:
                printf("Enter the file name for saving:");
                scanf("%99s", file_for_saving);
                FILE* file;
                file = fopen(file_for_saving, "w");
                if (file != NULL)
                {
                    fputs(Buffer, file);
                    fclose(file);
                    printf("Text has been saved successfully\n");
                }
                break;

            case 4:
                printf("Enter the file name for loading:");
                scanf("%99s", file_for_loading);
                FILE* load_file;
                load_file = fopen(file_for_loading, "r");
                if (NULL == load_file) {
                    printf("Error opening file\n");
                } else {
                    size_t bytesRead = fread(loaded_text, sizeof(char), sizeof(loaded_text), load_file);
                    if (bytesRead > 0) {
                        printf("Text has been loaded successfully\n");
                    } else {
                        printf("Failed to read from the file\n");
                    }
                    fclose(load_file);
                }
                break;

            case 5:
                printf("%s", loaded_text);
                break;

            default:
                printf("The command is not implemented\n");
                break;
            }
        }
    }

