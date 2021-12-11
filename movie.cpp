#include <iostream>
#include <cstring>
#include <curl/curl.h>
#include <vector>
#include "movie.h"


Movie::Movie(std::string movie_data){
    movie_title = parse_string(movie_data, "\"Title\":","\",\"");
    movie_year = parse_string(movie_data, "\"Year\":","\",\"");
    movie_rated = parse_string(movie_data, "\"Rated\":","\",\"");
    movie_released = parse_string(movie_data, "\"Released\":","\",\"");
    movie_runtime = parse_string(movie_data, "\"Runtime\":","\",\"");
    movie_genre = parse_string(movie_data, "\"Genre\":","\",\"");
    movie_director = parse_string(movie_data, "\"Director\":","\",\"");
    movie_writer = parse_string(movie_data, "\"Writer\":","\",\"");
    movie_actors = parse_string(movie_data, "\"Actors\":","\",\"");
    movie_plot = parse_string(movie_data, "\"Plot\":","\",\"");
    movie_language = parse_string(movie_data, "\"Language\":","\",\"");
    movie_country = parse_string(movie_data, "\"Country\":","\",\"");
    movie_awards = parse_string(movie_data, "\"Awards\":","\",\"");
    movie_poster = parse_string(movie_data, "\"Poster\":","\",\"");
    movie_source = parse_string(movie_data, "\"Source\":","\",\"");
    movie_value = parse_string(movie_data, "\"Value\":","\"}],");
    movie_metascore = parse_string(movie_data, "\"Metascore\":","\",\"");
    movie_imdbrating = parse_string(movie_data, "\"imdbRating\":","\",\"");
    movie_imdbvotes = parse_string(movie_data, "\"imdbVotes\":","\",\"");
    movie_imdbid = parse_string(movie_data, "\"imdbID\":","\",\"");
    movie_type = parse_string(movie_data, "\"Type\":","\",\"");
    movie_dvd = parse_string(movie_data, "\"DVD\":","\",\"");
    movie_boxoffice = parse_string(movie_data, "\"BoxOffice\":","\",\"");
    movie_production = parse_string(movie_data, "\"Production\":","\",\"");
    movie_website = parse_string(movie_data, "\"Website\":","\",\"");
    movie_totalseasons = parse_string(movie_data, "\"totalSeasons\":","\",\"");
}


std::string Movie::parse_string(std::string data_to_parse, std::string str_i, std::string str_f){
    std::string info;
    int i, j;
    i = data_to_parse.find(str_i);
    if(i != -1){
        i = data_to_parse.find("\":\"", i+1)+3;
        j = data_to_parse.find(str_f, i+1);
        info = data_to_parse.substr(i,j-i);
    } else {
        info = "N/A";
    }
    return info;
}


std::string Movie::getMovie_type(){
    return movie_type;
}

void Movie::getMovie_description(){
    std::cout << "Título: " << movie_title << std::endl;
    std::cout << "Year: " << movie_year << std::endl;
    std::cout << "Rated: " << movie_rated << std::endl;
    std::cout << "Released: " << movie_released << std::endl;
    std::cout << "Runtime: " << movie_runtime << std::endl;
    std::cout << "Genre: " << movie_genre << std::endl;
    std::cout << "DIrector: " << movie_director << std::endl;
    std::cout << "Writer: " << movie_writer << std::endl;
    std::cout << "Actors: " << movie_actors << std::endl;
    std::cout << "Plot: " << movie_plot << std::endl;
    std::cout << "Language: " << movie_language << std::endl;
    std::cout << "Country: " << movie_country << std::endl;
    std::cout << "Awards: " << movie_awards << std::endl;
    std::cout << "Poster: " << movie_poster << std::endl;
    std::cout << "Source: " << movie_source << std::endl;
    std::cout << "Value: " << movie_value << std::endl;
    std::cout << "Metascore: " << movie_metascore << std::endl;
    std::cout << "imdbRating: " << movie_imdbrating << std::endl;
    std::cout << "imdbID: " << movie_imdbid << std::endl;
    std::cout << "Type: " << movie_type << std::endl;
    std::cout << "DVD: " << movie_dvd << std::endl;
    std::cout << "BoxOffice: " << movie_boxoffice << std::endl;
    std::cout << "Production: " << movie_production << std::endl;
    std::cout << "Website: " << movie_website << std::endl;
    std::cout << "Total Seasons: " << movie_totalseasons << std::endl;
}


Request::Request(std::string API_URL){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, API_URL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &info);
        res = curl_easy_perform(curl);
        curl_easy_strerror(res);
        curl_easy_cleanup(curl); 
    }
    curl_global_cleanup();
}

std::size_t Request::write_callback(char *in, size_t size, size_t nmemb, std::string *out){ 
    std::size_t total_size = size * nmemb;
    if(total_size){
        out->append(in, total_size);
        return total_size;
    }
    return 0;
}


std::string getHelp(){
    std::string info = "Your menu options are:\n";
    info += "-h or --help > Show the options list in the application.\n";
    info += "-s or --seach + movie title > Get information about some movie.\n";
    info += "-t or --type + movie title > Show if title choosed is a movie, serie or episode.\n";
    return info;
}


std::string build_movie_name(int argc_aux, char** argv_aux){
    std::string movie_name = "";
    for(int i = 2; i < argc_aux-1; i++){
        movie_name += argv_aux[i];
        movie_name += "+";
    }
    movie_name += argv_aux[argc_aux-1];
    return movie_name;
}


int main(int argc, char *argv[]){
    std::string api_url = "http://www.omdbapi.com/?apikey=555d2392&t=";
    std::string movie_name;
    if(argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        std::cout << getHelp();
    } else if(argc > 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        std::cout << "O parâmetro " << argv[1] << " não necessita de complemento.\n";
    } else if(argc >2 && (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--search") == 0)){
        movie_name = build_movie_name(argc, argv);
        Request site_data = Request(api_url+movie_name);
        if(site_data.res == 0){
            Movie testando = Movie(site_data.info);
            testando.getMovie_description();
        } else {
            std::cout << "Falha para conectar com o site.\n";
        }
    } else if(argc >2 && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--type") == 0)){
        movie_name = build_movie_name(argc, argv);
        Request site_data = Request(api_url+movie_name);
        if(site_data.res == 0){
            Movie testando = Movie(site_data.info);
            std::cout << "Type: " << testando.getMovie_type() << std::endl;
        } else {
            std::cout << "Falha para conectar com o site.\n";
        }
    } else {
        std::cout << "Opção inválida, utilize -h ou --help para verificar as opões\n";
    }
    return 0;
}
