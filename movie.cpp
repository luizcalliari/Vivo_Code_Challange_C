#include <iostream>
#include "movie.h"
#include <cstring>

Movie::Movie(std::string movie_data){
    if(parse_string(movie_data, "\"Response\":","\"}") == "True"){
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
        movie_value = parse_string(movie_data, "\"Value\":","\"}");
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
    } else {
        movie_title = "Filme não encontrado";
        movie_year = "Filme não encontrado";
        movie_rated = "Filme não encontrado";
        movie_released = "Filme não encontrado";
        movie_runtime = "Filme não encontrado";
        movie_genre = "Filme não encontrado";
        movie_director = "Filme não encontrado";
        movie_writer = "Filme não encontrado";
        movie_actors = "Filme não encontrado";
        movie_plot = "Filme não encontrado";
        movie_language = "Filme não encontrado";
        movie_country = "Filme não encontrado";
        movie_awards = "Filme não encontrado";
        movie_poster ="Filme não encontrado";
        movie_source ="Filme não encontrado";
        movie_value ="Filme não encontrado";
        movie_metascore = "Filme não encontrado";
        movie_imdbrating ="Filme não encontrado";
        movie_imdbvotes ="Filme não encontrado";
        movie_imdbid = "Filme não encontrado";
        movie_type = "Filme não encontrado";
        movie_dvd = "Filme não encontrado";
        movie_boxoffice = "Filme não encontrado";
        movie_production = "Filme não encontrado";
        movie_website = "Filme não encontrado";
        movie_totalseasons = "Filme não encontrado";
    }
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


std::string Movie::getMovie_title(){
    return movie_title;
}

std::string Movie::getMovie_year(){
    return movie_year;
} 

std::string Movie::getMovie_rated(){
    return movie_rated;
} 

std::string Movie::getMovie_released(){
    return movie_released;
} 

std::string Movie::getMovie_runtime(){
    return movie_runtime;
} 

std::string Movie::getMovie_genre(){
    return movie_genre;
} 

std::string Movie::getMovie_director(){
    return movie_director;
} 

std::string Movie::getMovie_writer(){
    return movie_writer;
} 

std::string Movie::getMovie_actors(){
    return movie_actors;
} 

std::string Movie::getMovie_plot(){
    return movie_plot;
} 

std::string Movie::getMovie_language(){
    return movie_language;
} 

std::string Movie::getMovie_country(){
    return movie_country;
} 

std::string Movie::getMovie_awards(){
    return movie_awards;
} 

std::string Movie::getMovie_poster(){
    return movie_poster;
} 

std::string Movie::getMovie_source(){
    return movie_source;
} 

std::string Movie::getMovie_value(){
    return movie_value;
} 

std::string Movie::getMovie_metascore(){
    return movie_metascore;
} 

std::string Movie::getMovie_imdbrating(){
    return movie_imdbrating;
} 

std::string Movie::getMovie_imdbvotes(){
    return movie_imdbvotes;
} 

std::string Movie::getMovie_imdbid(){
    return movie_imdbid;
} 

std::string Movie::getMovie_type(){
    return movie_type;
} 

std::string Movie::getMovie_dvd(){
    return movie_dvd;
} 

std::string Movie::getMovie_boxoffice(){
    return movie_boxoffice;
} 

std::string Movie::getMovie_production(){
    return movie_production;
} 

std::string Movie::getMovie_website(){
    return movie_website;
} 

std::string Movie::getMovie_totalseasons(){
    return movie_totalseasons;
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

void print_moviegets(Movie movie_info){
        std::cout << "Título: " << movie_info.getMovie_title() << std::endl;
        std::cout << "Year: " << movie_info.getMovie_year() << std::endl;
        std::cout << "Rated: " << movie_info.getMovie_rated() << std::endl;
        std::cout << "Released: " << movie_info.getMovie_released() << std::endl;
        std::cout << "Runtime: " << movie_info.getMovie_runtime() << std::endl;
        std::cout << "Genre: " << movie_info.getMovie_genre() << std::endl;
        std::cout << "DIrector: " << movie_info.getMovie_director() << std::endl;
        std::cout << "Writer: " << movie_info.getMovie_writer() << std::endl;
        std::cout << "Actors: " << movie_info.getMovie_actors() << std::endl;
        std::cout << "Plot: " << movie_info.getMovie_plot() << std::endl;
        std::cout << "Language: " << movie_info.getMovie_language() << std::endl;
        std::cout << "Country: " << movie_info.getMovie_country() << std::endl;
        std::cout << "Awards: " << movie_info.getMovie_awards() << std::endl;
        std::cout << "Poster: " << movie_info.getMovie_poster() << std::endl;
        std::cout << "Source: " << movie_info.getMovie_source() << std::endl;
        std::cout << "Value: " << movie_info.getMovie_value() << std::endl;
        std::cout << "Metascore: " << movie_info.getMovie_metascore() << std::endl;
        std::cout << "imdbRating: " << movie_info.getMovie_imdbrating() << std::endl;
        std::cout << "imdbID: " << movie_info.getMovie_imdbid() << std::endl;
        std::cout << "Type: " << movie_info.getMovie_type() << std::endl;
        std::cout << "DVD: " << movie_info.getMovie_dvd() << std::endl;
        std::cout << "BoxOffice: " << movie_info.getMovie_boxoffice() << std::endl;
        std::cout << "Production: " << movie_info.getMovie_production() << std::endl;
        std::cout << "Website: " << movie_info.getMovie_website() << std::endl;
        std::cout << "Total Seasons: " << movie_info.getMovie_totalseasons() << std::endl;
}

