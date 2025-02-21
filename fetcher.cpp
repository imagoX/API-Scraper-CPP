#include <iostream>
#include <string>
#include <curl/curl.h>

int main()
{
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl)
    {
        for (int i = 1300; i <= 100000; i++)
        {
            std::string the_url = "https://images.rawpixel.com/image_" + std::to_string(i) + "/czNmcy1wcml2YXRlL3Jhd3BpeGVsX2ltYWdlcy93ZWJzaXRlX2NvbnRlbnQvbHIvcm0zMDYtcGF0dGVybi1rYXRpZS0wMV8xXzMuanBn.jpg";

            curl_easy_setopt(curl, CURLOPT_URL, the_url.c_str());
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);         // Use HEAD request to avoid downloading content
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirects if any
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);       // Timeout after 10 seconds

            res = curl_easy_perform(curl);

            if (res == CURLE_OK)
            {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
                if (http_code == 200)
                {
                    std::cout << "Valid: " << the_url << std::endl;
                }
                else if (http_code == 404)
                {
                    std::cout << "Not Found (404): " << i << std::endl;
                }
                else
                {
                    std::cout << "HTTP " << http_code << ": " << the_url << std::endl;
                }
            }
            else
            {
                std::cout << "CURL Error: " << curl_easy_strerror(res) << " for URL: " << the_url << std::endl;
            }
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}
