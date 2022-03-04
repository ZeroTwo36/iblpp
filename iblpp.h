#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

class BotClient {        // The class
  public: 
    string name; // The name of the Bot
    string tags;
    string prefix;
    string owner;
    bool staff_bot;
    string short_description;
    string long_description;
    string library;
    bool nsfw;
    BotClient(string name,string tags, string prefix, string owner, bool staff_bot,string short_description, string long_description, string library, bool nsfw) {
        name = name;
        tags = tags;
        prefix = prefix;
        owner = owner;
        staff_bot = staff_bot;
        short_description = short_description;
        long_description = long_description;
        library = library;
        nsfw = nsfw;
    }
};

BotClient getBotByID(long long int id) {
    CURL *curl;
    CURLcode response;

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    string url = "https://api.infinitybots.com/bots/";
    url.append(id);
    BotClient bc;
    Json::Reader reader;
    Json::Value obj;
    if(curl){
        curl_easy_setopt(curl, CURLOPT_URL, url);

        response = curl_easy_perform(curl);
        reader.parse(response,obj);
        if(response != CURLE_OK){
            bc = BotClient::BotClient("not found","null","null","null",false,"null","null","null",false);
            std::cout << "Request Failed";
        } else {
            bc = BotClient::BotClient(obj["name"].asString(),obj["tags"].asString(),obj["prefix"].asString(),obj["owner"].asString(),obj["staff_bot"].asBool(),obj["short"].asString(),obj["long"].asString(),obj["library"].asString(),obj["nsfw"].asBool());
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return bc;
}
