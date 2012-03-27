#ifndef DIRFINDER_H
#define DIRFINDER_H

#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <QDateTime>

using namespace std;

// Directories search class
class DirFinder
{
    QString the_oldest_path;	// current result directory
    QDateTime the_oldest_time;		// directory status change time

    // recursive search for the oldest subdirectory
    void find_recursive (QString dir);

public:

    // returns the oldest subdirectory path
    QString the_oldest_subdir (QString dir);
};

#endif // DIRFINDER_H
