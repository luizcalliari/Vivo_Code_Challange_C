#include <curl/curl.h>

class Movie{
    private:
        std::string movie_title;
        std::string movie_year;
        std::string movie_rated;
        std::string movie_released;
        std::string movie_runtime;
        std::string movie_genre;
        std::string movie_director;
        std::string movie_writer;
        std::string movie_actors;
        std::string movie_plot;
        std::string movie_language;
        std::string movie_country;
        std::string movie_awards;
        std::string movie_poster;
        std::string movie_source;
        std::string movie_value;
        std::string movie_metascore;
        std::string movie_imdbrating;
        std::string movie_imdbvotes;
        std::string movie_imdbid;
        std::string movie_type;
        std::string movie_dvd;
        std::string movie_boxoffice;
        std::string movie_production;
        std::string movie_website;
        std::string movie_totalseasons;

    public:
        Movie(std::string movie_data);
        std::string parse_string(std::string data_to_parse, std::string str_i, std::string str_f);
        std::string getMovie_title();
        std::string getMovie_year();
        std::string getMovie_rated();
        std::string getMovie_released();
        std::string getMovie_runtime();
        std::string getMovie_genre();
        std::string getMovie_director();
        std::string getMovie_writer();
        std::string getMovie_actors();
        std::string getMovie_plot();
        std::string getMovie_language();
        std::string getMovie_country();
        std::string getMovie_awards();
        std::string getMovie_poster();
        std::string getMovie_source();
        std::string getMovie_value();
        std::string getMovie_metascore();
        std::string getMovie_imdbrating();
        std::string getMovie_imdbvotes();
        std::string getMovie_imdbid();
        std::string getMovie_type();
        std::string getMovie_dvd();
        std::string getMovie_boxoffice();
        std::string getMovie_production();
        std::string getMovie_website();
        std::string getMovie_totalseasons();
};

class Request{
    private:
        std::string API_URL;
        CURL *curl;
        static std::size_t write_callback(char *in, size_t size, size_t nmemb, std::string *out);
    public:
        Request(std::string API_URL);
        CURLcode res;
        std::string info;
};


std::string getHelp();
std::string build_movie_name(int argc_aux, char** argv_aux);
void print_moviegets(Movie movie_info);
