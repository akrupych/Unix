#include "dirfinder.h"
#include <QDirIterator>

// recursive search for the oldest subdirectory
void DirFinder::find_recursive (QString dir)
{
    QDirIterator subdirs(dir, QDir::AllDirs|QDir::NoDotAndDotDot,
                         QDirIterator::Subdirectories);

    while (subdirs.hasNext())
    {
        QString current = subdirs.next();
        if (the_oldest_path.size() == 0 ||
                subdirs.fileInfo().created() < the_oldest_time)
        {
            the_oldest_path = current;
            the_oldest_time = subdirs.fileInfo().created();
        }
        find_recursive(current);
    }
}

// returns the oldest subdirectory path
QString DirFinder::the_oldest_subdir (QString dir)
{
    // clear the path and call recursive method
    the_oldest_path.clear();
    find_recursive(dir);
    return the_oldest_path;
}
