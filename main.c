#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main() {
    int command;
    char* Buffer = NULL;
    char file_for_saving[100];
    char file_for_loading[100];
    char word_for_adding[100];
    char text_to_search[100];
    int index1, index2;
    char loaded_text[500] = {'\0'};
    bool has_text = false;
    while(true) {
        printf("\nChoose the command! \n");
        scanf("%d", &command);
        getchar();
        switch (command) {
            case 1:
                printf("Enter text to append:");
                char text[100];
                fgets(text, sizeof(text), stdin);
                size_t len= strlen(text);
                if (len > 0 && text[len -1] == '\n'){
                    text[len - 1] = '\0';
                }
                size_t sizeText = strlen(text);
                size_t sizeBuffer = (Buffer == NULL) ? 0 : strlen(Buffer);
                size_t sizeBufferNow = sizeText + sizeBuffer + 1;
                char* newBuffer = (char*)malloc(sizeBufferNow);
                if (Buffer != NULL) {
                    strcpy(newBuffer, Buffer);
                }
                if (has_text){
                    strcat(newBuffer, " ");
                }
                strcat(newBuffer, text);
                has_text = true;
                Buffer = newBuffer;
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
                }
                else {
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

            case 6:
                printf("Choose line and index:");
                scanf("%d %d", &index1, &index2);
                printf("Enter text to insert:\n");
                scanf(" %[^\n]", word_for_adding);
                char* lines[20];
                int num_lines = 0;
                char* line = strtok(Buffer, "\n");
                while (line != NULL) {
                    lines[num_lines] = line;
                    num_lines++;
                    line = strtok(NULL, "\n");
                }

                char new_line[100];
                strcpy(new_line, lines[index1]);
                strcpy(new_line + index2, word_for_adding);
                strcat(new_line, lines[index1] + index2);


                free(Buffer);
                Buffer = (char*)malloc(100);


                for (int i = 0; i < num_lines; i++) {
                    if (i == index1) {
                        strcat(Buffer, new_line);
                    } else {
                        strcat(Buffer, lines[i]);
                    }
                    if (i < num_lines - 1) {
                        strcat(Buffer, "\n");
                    }
                }

                Buffer[strlen(Buffer)] = '\0';
                break;

            case 7:
                printf("Enter text to search: ");
                scanf("%99s", text_to_search);

                int row = -1;
                int position = -1;

                char* linee = strtok(Buffer, "\n");
                while (linee != NULL) {
                    row++;
                    char* word_in_line = strstr(linee, text_to_search);

                    if (word_in_line != NULL) {
                        position = word_in_line - linee;
                        break;
                    }
                    linee = strtok(NULL, "\n");
                }

                if (position == -1) {
                    printf("The word '%s' is not found in the Buffer.\n", text_to_search);
                } else {
                    printf("Text is present in this position '%d' '%d' \n", row, position);
                }
                break;



            case 8:
                printf(Buffer);
                system("clear");
                break;


            default:
                printf("The command is not implemented\n");
                break;
        }

    }

}

