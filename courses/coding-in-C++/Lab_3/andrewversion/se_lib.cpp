#include <iostream>
#include <string>
#include <vector>

class WebResource{
    private:
        int address;
        std::string content;
        int ranking;
        int calls;
        int popularity;

    public: 
        WebResource(int address, std::string content, int ranking) :
        address(address), content(content), ranking(ranking){
            calls = 0;
            popularity = ranking + (ranking * calls);
        }

        int getAddress() const;

        std::string getContent() const;

        bool setContent(std::string newContent);

        void call();

        bool setRanking(int ranking);

        int getRanking() const;

        int getPopularity();
};

/** @brief Returns the address of a WebResource object
 * 
 * @return Address integer
*/
int WebResource::getAddress() const{
    return address;
}

/** @brief Returns the content of a WebResource object
 * 
 * @return COntent string
*/
std::string WebResource::getContent() const{
    return content;
}

/** @brief Sets the content of a WebResource object
 * 
 * @param[in] newContent String of new Content
 * @return success boolean, TRUE if succeeded else FAKLSE
*/
bool WebResource::setContent(std::string newContent){
    if(newContent.empty()){
        std::cout << "Failed to edit content!" << std::endl;
        return false;
    }
    content = newContent;
    return true;
}

/** @brief Increments the call counter of a WebResource object
 * 
 * @note Must be called when a user opens a website
*/
void WebResource::call(){
    calls++;
}

/** @brief Sets the ranking of a WebResource object
 * 
 * @param[in] ranking new ranking value as an integer
 * @return success boolean, TRUE if succeeded else FALSE
*/
bool WebResource::setRanking(int ranking){
    if(ranking < 0){
        return false;
    }
    if(ranking > 10){
        return false;
    }
    this->ranking = ranking;
    return true;
}

/** @brief Gets the ranking of a WebResource object
 * 
 * @return Ranking integer
*/
int WebResource::getRanking() const{
    return ranking;
}

/** @brief Calculates and gets the popularity of a WebResource object
 * 
 * @return Popularity integer
*/
int WebResource::getPopularity(){
    popularity = ranking + (ranking * calls);
    return popularity;
}


class Query{
    private: 
        std::string searchInput;
        int maxResults;
    
    public:
        Query(std::string searchInput, int maxResults) : 
        searchInput(searchInput), maxResults(maxResults)
        {

        }

        bool isValid();

        bool setSearchInput(std::string input);

        std::string getSearchInput();

        bool setMaxResults(int results);

        int getMaxResults();

};

bool Query::isValid(){
    if(searchInput.empty()){
        return false;
    }
    return true;
}

bool Query::setSearchInput(std::string input){
    if(input.empty()){
        return false;
    }
    searchInput = input;
    return true;
}

std::string Query::getSearchInput(){
    return searchInput;
}

bool Query::setMaxResults(int results){
    if(results < 0){
        return false;
    }
    maxResults = results;
    return true;
}

int Query::getMaxResults(){
    return maxResults;
}


class Engine{
    private:
        std::vector<WebResource*> pages;
        int numberPages;
        int executedQueries;
    
    public:
        Engine(){
            pages[0] = nullptr;
            numberPages = 0;
            executedQueries = 0;
        }
        
        void addWebResource(WebResource* page);

        WebResource* removeWebResource(int address);

        std::vector<WebResource*> executeQuery(Query* query);

        void printInfo();
};

void Engine::addWebResource(WebResource* page){
    pages.push_back(page);
    numberPages++;
}

WebResource* Engine::removeWebResource(int address){
    WebResource* temp;
    for(int i= 0; i < pages.size(); i++){
        if(pages[i]->getAddress() == address){
            temp = pages[i];
            pages.erase(pages.begin() + i);
            return temp;
        }
    }
    return nullptr;
} 

std::vector<WebResource*> Engine::executeQuery(Query* query){
    std::vector<WebResource*> temp;
    for(int i = 0; i < numberPages; i++){
        if(pages[i]->getContent().find(query->getSearchInput()) !=std::string::npos){
            temp.push_back(pages[i]);
        }
    }
    int lowest = 0;
    while(temp.size() > query->getMaxResults()){
        for(int i = 0; i < temp.size(); i++){

        }
            
    }



    
}