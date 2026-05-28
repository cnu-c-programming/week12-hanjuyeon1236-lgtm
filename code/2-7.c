#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config* config_ptr) {
    FILE* fp = fopen("config.txt", "r");
    if (fp == NULL) return;

   while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "InputFileName=", 14) == 0) {
            sscanf(line, "InputFileName=%s", config_ptr->InputFileName);
        } else if (strncmp(line, "Options=", 8) == 0) {
            sscanf(line, "Options=%d", &config_ptr->Options);
        } else if (strncmp(line, "SectionName=", 12) == 0) {
            sscanf(line, "SectionName=%s", config_ptr->SectionName);
        } else if (strncmp(line, "Address=", 8) == 0) {
            sscanf(line, "Address=%lli", &config_ptr->Address);
        }
    }
    
    fclose(fp);
}

int main(int argc, const char* argv[]) {
    Config config;
    config_parser(&config);

    printf("config: %s %d %s %llu\n", 
        config.InputFileName, 
        config.Options,
        config.SectionName,
        config.Address);
    return 0;
}

