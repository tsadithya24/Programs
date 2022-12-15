// program for copying one raw file to another raw file

#include <fstream>
#include <iostream>
using namespace std;
  
int main()
{
    string line;
    int size = 640*480; 
    ifstream ini_file{"filename.rgb"}; 
    ofstream out_file{"filename.raw"};
    if (ini_file && out_file) {
  
        for(int i = 0; i < size; i++) 
        {
        getline(ini_file, line);  // used to read every line of the input file
        
            out_file << line << "\n"; // used to print everyline from the input file to the output file
        }
        cout << "write completed\n";
    }
    else { 
        printf("Cannot read File");
    }
    ini_file.close();
    out_file.close();
    return 0;
}
