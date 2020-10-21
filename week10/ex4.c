#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

unsigned int inode;
char* name;

int filt(const struct dirent* entry)
{
    if (entry->d_ino == inode && strcmp(entry->d_name, name)){return 1;}
    else {return 0;}
}

int main()
{
    DIR *is_open;
    struct dirent *directory;
    is_open = opendir("./tmp/");

    if (is_open) {
        while ((directory = readdir(is_open)) != NULL) {
            struct dirent **filenames = NULL;
            inode = directory->d_ino;
            name = directory->d_name;
            int a = scandir("./tmp/", &filenames, filt, NULL);

            while (a>0){
                printf("%s\t", filenames[a]->d_name);
                a--;
            }

            free(filenames);
        }
        closedir(is_open);
    }
    return 0;
}
