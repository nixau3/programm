#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "text.txt"; 
    char line[1000]; 

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл %s\n", filename);
        return 1;
    }

    int line_number = 0;
    
    while (fgets(line, sizeof(line), file)) {
        int count = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != '\n' && line[i] != '\r') { 
                count++;
            }
        }
        printf("Строка %d содержит %d символов\n", ++line_number, count);
    }

    fclose(file);

    return 0;
}
