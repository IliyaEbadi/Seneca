#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
#include <cstdio>

namespace seneca {
    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != nullptr;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool readTitle(char title[]) {
        return fscanf(fptr, "%[^(](", title) == 1;
    }

    bool readYear(int* year) {
        return fscanf(fptr, "%d)", year) == 1;
    }

    bool readMovieRating(char rating[]) {
        return fscanf(fptr, " %[^|]|", rating) == 1;
    }

    bool readDuration(int* duration) {
        return fscanf(fptr, "%d|", duration) == 1;
    }

    bool readGenres(char genres[][11]) {
        char genreString[256];
        int gi = 0, i = 0, j = 0;
        if (fscanf(fptr, " %[^|]|", genreString) == 1) {
            while (genreString[gi]) {
                if (genreString[gi] != ',') {
                    genres[i][j++] = genreString[gi];
                }
                else {
                    genres[i][j] = '\0';
                    i++;
                    j = 0;
                }
                gi++;
            }
            genres[i][j] = '\0';
            genres[i + 1][0] = '\0';
            return true;
        }
        return false;
    }

    bool readConsumerRating(float* rating) {
        return fscanf(fptr, "%f\n", rating) == 1;
    }
}
