#include "movie.h"
#include "file.h"
#include <iostream>
#include <cstring>
#include "utils.h"


namespace seneca {
    Movie movies[50];

    bool loadMovies() {
        Movie mv;
        int mnum = 0;
        bool ok = openFile("movies.dat");
        if (ok) {
            while (mnum < 50 && readTitle(mv.m_title) && readYear(&mv.m_year) &&
                readMovieRating(mv.m_rating) && readDuration(&mv.m_duration) &&
                readGenres(mv.m_genres) && readConsumerRating(&mv.m_consumerRating)) {
                movies[mnum++] = mv;
            }
            closeFile();
        }
        return mnum == 50;
    }

    bool hasGenre(const Movie* mvp, const char genre[]) {
        char lowerGenre[11], lowerMovieGenre[11];
        for (int i = 0; mvp->m_genres[i][0]; i++) {
            toLowerCase(lowerGenre, genre);
            toLowerCase(lowerMovieGenre, mvp->m_genres[i]);
            if (strstr(lowerMovieGenre, lowerGenre)) return true;
        }
        return false;
    }

    void displayMovie(const Movie* mvp) {
        std::cout << mvp->m_title << " [" << mvp->m_year << "], " << mvp->m_rating
            << ", duration: " << mvp->m_duration << " minutes, Rating: "
            << mvp->m_consumerRating << "/10\n    (" << mvp->m_genres[0];
        for (int i = 1; mvp->m_genres[i][0]; i++) {
            std::cout << ", " << mvp->m_genres[i];
        }
        std::cout << ")" << std::endl;
    }

    void displayMoviesWithGenre(const char genre[]) {
        int count = 0;
        for (int i = 0; i < 50; i++) {
            if (hasGenre(&movies[i], genre)) {
                std::cout << ++count << "- ";
                displayMovie(&movies[i]);
            }
        }
        if (count == 0) std::cout << "No match found for: " << genre << std::endl;
    }
}
