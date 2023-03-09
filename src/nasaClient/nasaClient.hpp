#ifndef NasaClient_h
#define NasaClient_h

#define CURL_STATICLIB
#include <curl/curl.h>
#include <string>
#include <vector>
#include <glm/vec3.hpp>

class Body {
private:
    std::string name;
    long index;
    glm::vec3 pos;
    float radius;
    std::string dataDate;
    glm::vec3 color;
public:
    Body(std::string name, glm::vec3 color=glm::vec3(1, 1, 1));

    void updateData(glm::vec3 pos, float radius, std::string dataDate);
    std::string getDataDate();
    glm::vec3 getPos();
    float getRadius();
    std::string getName();
    long getIndex();
    glm::vec3 getColor();
};

/**
 * @brief Client object used to load and define a client interface to the NASA APIs
 * 
 */
class NasaClient {
private:
    /**
     * @brief storage of the curl object
     * 
     */
    CURL* curl;
    std::string endpoint;
    std::string apiKey;

    std::string getJulianDate(std::string calendarDate);
    std::string getCalendarDate(std::string julianDate);
    std::string convertDate(std::string date, std::string dateType, std::string returnDateType);

public:
    /**
     * @brief Construct a new Client object
     * 
     */
    NasaClient();

    /**
     * @brief Destroy the Nasa Client object
     * 
     */
    ~NasaClient();

    void setEndpoint(std::string endpoint);

    void setKey(std::string key);

    void getBodyData(Body &body, std::string date);

    /**
     * @brief Used to test if the client object works correctly with curl
     * 
     */
    void test();

};


#endif