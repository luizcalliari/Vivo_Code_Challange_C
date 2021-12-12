#include <iostream>
#include "movie.h"
#include <curl/curl.h>
#include <cstring>

#define IS_TRUE(x) { if (!(x))std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; if ((x))std::cout << __FUNCTION__ << " succeed on line " << __LINE__ << std::endl; }



void test_movie(){
    std::string url = "http://www.omdbapi.com/?apikey=555d2392&t=matrix";
    Request test_request = Request(url);
    //Connection test
    IS_TRUE(test_request.res == 0);
    //Test info return information
    std::string info = "{\"Title\":\"Matrix\",\"Year\":\"1993\",\"Rated\":\"N/A\",\"Released\":\"01 Mar 1993\",\"Runtime\":\"60 min\",\"Genre\":\"Action, Drama, Fantasy\",\"Director\":\"N/A\",\"Writer\":\"Grenville Case\",\"Actors\":\"Nick Mancuso, Phillip Jarrett, Carrie-Anne Moss\",\"Plot\":\"Steven Matrix is one of the underworld's foremost hitmen until his luck runs out, and someone puts a contract out on him. Shot in the forehead by a .22 pistol, Matrix \\\"dies\\\" and finds himself in \\\"The City In Between\\\", where he is sho\",\"Language\":\"English\",\"Country\":\"Canada\",\"Awards\":\"1 win\",\"Poster\":\"https://m.media-amazon.com/images/M/MV5BYzUzOTA5ZTMtMTdlZS00MmQ5LWFmNjEtMjE5MTczN2RjNjE3XkEyXkFqcGdeQXVyNTc2ODIyMzY@._V1_SX300.jpg\",\"Ratings\":[{\"Source\":\"Internet Movie Database\",\"Value\":\"8.0/10\"}],\"Metascore\":\"N/A\",\"imdbRating\":\"8.0\",\"imdbVotes\":\"167\",\"imdbID\":\"tt0106062\",\"Type\":\"series\",\"totalSeasons\":\"N/A\",\"Response\":\"True\"}";
    IS_TRUE(test_request.info == info);
    Movie test_movie = Movie(info);
    //The next 4 tests will verify if some movie information
    IS_TRUE(test_movie.getMovie_title() == "Matrix");
    IS_TRUE(test_movie.getMovie_year() == "1993");
    IS_TRUE(test_movie.getMovie_type() == "series");
    IS_TRUE(test_movie.getMovie_title() == "Not Matrix");
    std::cout << "The last above should intentionally fail.\n";
}
    

int main() {
    test_movie();
}

