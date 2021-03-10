#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

const char tex_fname[] = "build/doc.tex";

int main( int argc, char *argv[] )
{
  if (argc < 3)
  {
    std::cout << "USAGE: " << argv[0] << " IN_FILE OUT_FILE" << std::endl;
    return 0;
  }
  system("mkdir -p build");
  
  std::ofstream file{tex_fname, std::ios_base::out | std::ios_base::trunc};
  if (!file.is_open())
  {
    std::cout << "Problems with openning file '" << tex_fname << "'" << std::endl;
    return 1;
  }

  file << "\\documentclass{scrartcl}" << std::endl << "\\usepackage{pdfpages}";
  file << "\\begin{document}" << std::endl << "\\includepdf[pages=-,booklet,turn=false,landscape]{";
  file << argv[2] << "}" << std::endl << "\\end{document}";
  

  file.close();
  

  return 0;
}

