//
//  main.cpp
//  cppAPIcall
//
//  Created by Bhavay anand on 09/11/18.
//  Copyright © 2018 Bhavay anand. All rights reserved.
//

#include <iostream>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        std::cout << readBuffer << std::endl;
    }
    return 0;
}
