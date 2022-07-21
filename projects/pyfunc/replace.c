
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static inline void* allocate(size_t _Count, size_t _Size) {
    void* tmp = calloc(_Count, _Size);
    if(tmp == NULL) 
        exit(EXIT_FAILURE);
    return tmp;
}

static inline void* reallocate(void* _Buffer, size_t _Size) {
    void* tmp = realloc(_Buffer, _Size);
    if(tmp == NULL) 
        exit(EXIT_FAILURE);
    return tmp;
}

/*
char* var = replace(_String, _Substring, _Substitute)
_______________________________________________________
replace() replaces all instances of _Substring from 
_String with _Substitute
*/
char* replace(char* _String, char* _Substring, char* _Substitute) {

    char* res = NULL, *ptr = _String;
    size_t _Sub_len = strlen(_Substitute), 
           _Substr_len = strlen(_Substring),
           _Length = strlen(_String);

    if(!strcmp(_Substring, "")){
        res = (char*)allocate(
            1, 
            _Length + (_Length*_Sub_len) + 1
        );

        strcat(res, _Substitute);
        for(size_t idx = 0; idx < _Length; idx++) {
            strncat(res, _String+idx, 1);
            strcat(res, _Substitute);
        }
    }

    else{
        res = strdup(_String);
        while ((ptr=strstr(ptr,_Substring))!=NULL) {
            
            size_t skip = strlen(res) - strlen(ptr), eval = strlen(ptr+_Substr_len);
            res = (char*)reallocate(res, skip+_Sub_len+eval+1);
            strcpy(res+skip, _Substitute);
            strncat(res, ptr+_Substr_len, eval);
            ptr++; 
        }
    }
    return res;
}

int validate(char* arg){
    if(arg == NULL || 
        !strcmp(arg, "-s") ||
        !strcmp(arg, "-f") || 
        !strcmp(arg, "-r")){
            return -1;
        }
    return 0;
}

void help() {
    fprintf(stdout, "Options:\n\
    \t-s  main data string\n\
    \t-f  old substring you want to replace\n\
    \t-r  new substring which would replace the old substring.\n"
    );
}

int main(int argc, char** argv) {

    if(argc == 1) {
        fprintf(stdout, "InputError: no data provided\n");
        help();
    } else if (argc == 7) {
        int i, status = 0, s_set, f_set, r_set;
        for(i = 0; i < argc; i++) {
            if(!strcmp(argv[i], "-s")){
                status += 1;
                if(validate(argv[i+1]) == -1){
                    fprintf(stderr, "InputError: no string detected\n");
                    help();
                    return 1;
                }
                s_set = i+1;

            }
        }
        for(i = 0; i < argc; i++) {
            if(!strcmp(argv[i], "-f")){
                status += 1;
                if(validate(argv[i+1]) == -1){
                    fprintf(stderr, "InputError: no string detected\n");
                    help();
                    return 1;
                }
                f_set = i+1;
            }
        }
        for(i = 0; i < argc; i++) {
            if(!strcmp(argv[i], "-r")){
                status += 1;
                if(validate(argv[i+1]) == -1){
                    fprintf(stderr, "InputError: no string detected\n");
                    help();
                    return 1;
                }
                r_set = i+1;
            }
        }
        if(status == 3) {
            char* mod = replace(argv[s_set], argv[f_set], argv[r_set]);
            puts(mod);
            free(mod);
            return 0;
        }
        return 1;
    }
}


