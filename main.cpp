#include <iostream>
#include "movie.h"
#include <cstring>

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
            Movie movie_info = Movie(site_data.info);
            print_moviegets(movie_info);
        } else {
            std::cout << "Falha para conectar com o site.\n";
        }
    } else if(argc >2 && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--type") == 0)){
        movie_name = build_movie_name(argc, argv);
        Request site_data = Request(api_url+movie_name);
        if(site_data.res == 0){
            Movie movie_info = Movie(site_data.info);
            std::cout << "Type: " << movie_info.getMovie_type() << std::endl;
        } else {
            std::cout << "Falha para conectar com o site. Erro: " << site_data.res << std::endl;
        }
    } else {
        std::cout << "Opção inválida, utilize -h ou --help para verificar as opões\n";
    }
    return 0;
}
