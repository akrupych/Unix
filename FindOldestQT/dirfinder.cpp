#include "dirfinder.h"


// recursive search for the oldest subdirectory
void DirFinder::find_recursive (string dir)
{
    DIR *opened;			// directory contents
    struct dirent *current;	// current file

    if ((opened = opendir(dir.c_str())) != NULL)
    {
        while ((current = readdir(opened)) != NULL)
        {
            if (current->d_type == DT_DIR)
            {
                // file is a directory, so we can proceed

                // compose and check directory full path
                string full_path = current->d_name;
                if (!full_path.compare(".") ||
                        !full_path.compare(".."))
                    continue;
                full_path = dir + "/" + full_path;

                // get directory attributes
                struct stat attr;
                stat(full_path.c_str(), &attr);

                // check conditions and reassign
                if (the_oldest_path.empty() ||
                        attr.st_ctime < the_oldest_time)
                {
                    the_oldest_path = full_path;
                    the_oldest_time = attr.st_ctime;
                }

                // search in next sublevel
                find_recursive(full_path);
            }
        }
    }
    closedir(opened);
}

// returns the oldest subdirectory path
string DirFinder::the_oldest_subdir (string dir)
{
    // can be used for initial assigning
    /*the_oldest_path = dir;
    struct stat attr;
    stat(dir.c_str(), &attr);
    the_oldest_time = attr.st_ctime;*/

    // clear the path and call recursive method
    the_oldest_path.clear();
    find_recursive(dir);
    return the_oldest_path;
}
