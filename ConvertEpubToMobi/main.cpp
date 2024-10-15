#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "WindowsUtils.h"

void ConvertEpubToMobi(const std::string& epubPath, const std::string& mobiPath)
{
    std::string epubFolderAndPath = "Epub\\" + epubPath;
    std::string mobiFolderAndPath = "Mobi\\" + mobiPath;

    std::string command = "ebook-convert \"" + epubFolderAndPath + "\" \"" + mobiFolderAndPath + "\"";

    int result = system(command.c_str());

    if (result == 0) 
    {
        std::cout << "Conversion successful: " << mobiPath << std::endl;
    }
    else 
    {
        std::cerr << "Conversion failed. Please check the file paths and Calibre installation." << std::endl;
    }
}

int main() 
{
    std::vector<std::string> allEpubFiles;
    
    WindowsUtils().GetAllFilesFromFolder("Epub", allEpubFiles);

    for (std::string fileName : allEpubFiles) 
    {
        std::string fileNameWithNoExtension = WindowsUtils().RemoveExtension(fileName);

        std::string epubFile = fileNameWithNoExtension + ".epub";
        std::string mobiFile = fileNameWithNoExtension + ".mobi";

        ConvertEpubToMobi(epubFile, mobiFile);
    }

    std::cout << "Press Enter to exit...";
    std::cin.get(); 
    return 0;
}
