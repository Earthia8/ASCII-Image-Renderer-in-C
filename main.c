/* A menu-driven program to input a .pgm image, and:
    1) Convert it into ASCII art!
    2) Perform edge detection on it!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 530
#define MAX_HEIGHT 530

// Image structure
typedef struct {
    int width, height, maxVal;
    int pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

// Load PGM image (P2 format only)

Image loadPGM(const char *filename) {
    Image img;  // Creates a local Image struct

    FILE *file = fopen(filename, "r");  //Opens the file
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        img.width = img.height = -1;  // Checks for any error in opening image
        return img;
    }

    char format[3];
    fscanf(file, "%2s", format);       // Checks if file format is P2
    if (strcmp(format, "P2") != 0) {   // Raises an error if not
        printf("Error: Unsupported PGM format, only P2 format acceptable.\n");
        fclose(file);
        img.width = img.height = -1;
        return img;
    }

    int maxVal;
    fscanf(file, "%d %d %d", &img.width, &img.height, &maxVal);  //Get width, height
    printf("DEBUG: width = %d, height = %d, maxVal = %d\n", img.width, img.height, maxVal);
    //fscanf(file, "%d", &img.maxVal);  //Get max value
    img.maxVal = maxVal;
    //Reading the pixel values from given image, and storing them into the struct.
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fscanf(file, "%d", &img.pixels[i][j]);
            // if (i < 10 && j < 10){
            //     printf("DEBUG [%d][%d]: %d %d\n", i, j, img.pixels[i][j], img.maxVal);
            // }  // Only show top-left 10x10
        }
    }

    fclose(file);  //Closing the file
    return img;
}

char getAsciiChar(int pixelValue, int maxVal) {
    const char* asciiChars = " .:-=+*%@#";
    int numChars = strlen(asciiChars);
    int index = (pixelValue * (numChars - 1)) / maxVal;
    return asciiChars[index];
}

void asciiArt(Image img) {
    printf("\n===== ASCII ART =====\n");

    FILE *outputFile = fopen("ascii_art.txt", "w");
    if (!outputFile) {
        printf("Error: Could not open file to write ASCII art.\n");
        return;
    }

    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            //printf("%3d ", img.pixels[i][j]);
            //printf("%c  ", getAsciiChar(img.pixels[i][j], img.maxVal));
            char asciiChar = getAsciiChar(img.pixels[i][j], img.maxVal);
            printf("%c ", asciiChar);               // Print to console
            fprintf(outputFile, "%c", asciiChar);
        }
        printf("\n");
        fprintf(outputFile, "\n");
    }
    fclose(outputFile);  // Close the file
}

int main() {

    char filename[100];
    int choice;

    printf("Enter path to PGM image (P2 format): ");
    scanf("%s", filename);

    Image img = loadPGM(filename);
    if (img.width == -1 || img.height == -1) {
        printf("Image loading failed.\n");
        return 1;
    }

    printf("Image loaded successfully: %d x %d\n", img.width, img.height);

    printf("Converting to ASCII Art...\n");
    asciiArt(img);
    printf("Done!\n");

}
