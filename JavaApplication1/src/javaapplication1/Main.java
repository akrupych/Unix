package javaapplication1;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    protected static String theOldestPath = null;
    protected static long theOldestTime = Long.MAX_VALUE;
    
    protected static String FindTheOldestSubdirectory(String mainDirPath)
    {
        File currentDir = new File(mainDirPath);
        if (currentDir.isDirectory())
        {
            File[] sublist = currentDir.listFiles();
            long modified;
            for(File file : sublist)
            {
                if (file.isDirectory())
                {
                    modified = file.lastModified();
                    if (modified < theOldestTime)
                    {
                        theOldestPath = file.getAbsolutePath();
                        theOldestTime = modified;
                    }
                    FindTheOldestSubdirectory(file.getAbsolutePath());
                }
            }
        }
        return theOldestPath;
    }

    public static void main(String[] args) throws IOException
    {
        // input block
        System.out.println("Program searches for the oldest subdirectory"
                + " within given directory");
        String input;
        do
        {
            System.out.println("Type the directory path to search in:");
            InputStreamReader converter = new InputStreamReader(System.in);
            BufferedReader in = new BufferedReader(converter);
            input = in.readLine();
        }
        while (!(new File(input)).isDirectory());
        
        // search block
        String result = FindTheOldestSubdirectory(input);
        if (result == null)
        {
            System.out.println("Sorry, no subdirectories can be found");
        }
        else
        {
            System.out.println("Result: " + result);
        }
    }
}
