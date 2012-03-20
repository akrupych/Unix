#ifndef DIRFINDER_H
#define DIRFINDER_H

#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

using namespace std;

// Directories search class
class DirFinder
{
    string the_oldest_path;	// current result directory
    int the_oldest_time;		// directory status change time

    // recursive search for the oldest subdirectory
    void find_recursive (string dir);

public:

    // returns the oldest subdirectory path
    string the_oldest_subdir (string dir);
};

#endif // DIRFINDER_H
