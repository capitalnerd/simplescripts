#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;

    char fileUrl[256];
    printf("File URL: ");
    fgets(fileUrl, 256, stdin);
    fileUrl[strcspn(fileUrl, "\r\n")] = 0;

    char *fileName = strrchr(fileUrl, '/');
    if (fileName == NULL) {
        fprintf(stderr, "Error\n");
        return 1;
    }
    fileName++;

    char programPath[256];
    char *lastSlash = strrchr(__FILE__, '/');
    if (lastSlash != NULL) {
        strncpy(programPath, __FILE__, lastSlash - __FILE__ + 1);
        programPath[lastSlash - __FILE__ + 1] = '\0';
    } else {
        programPath[0] = '\0';
    }

    char filePath[256];
    snprintf(filePath, 256, "%s%s", programPath, fileName);

    curl = curl_easy_init();
    if (curl) {
        fp = fopen(filePath, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, fileUrl);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
            return 1;
        } else {
            printf("Sucess:", filePath);
        }
    } else {
        fprintf(stderr, "Error when initialising cURL.\n");
        return 1;
    }

    return 0;
}
