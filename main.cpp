
/* 
 * File:   main.cpp
 * Author: Attila Varga
 *
 * Created on 19 October 2017, 14:34
 */

#include "tree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

   
void Usage();

int main (int argc, char *argv[]) {
  bool print_tree = false;
  
  if (argc < 4) {
      Usage();
      return -1;
  }
  else if (argc == 5)
    print_tree = true; 

  std::string input_name(*++argv);
 
  if (*(*++argv) != '-'&& *(*++argv)+1 != 'o') {
  	Usage();
  	return -1;
  }

  std::fstream input_stream (input_name, std::ios_base::in);

   if (!input_stream)  {
      std::cout << " The file " << input_name << " doesn't exist!" << std::endl;
      return -1;
   }
  std::string output_name(*++argv);
  std::fstream output_stream (output_name, std::ios_base::out);

  Tree lzwbtree;
  char read;
  bool is_comment = false;

  while (input_stream.read((char *) &read, sizeof (char)))  {
  	//  '<' 
    if (read == 0x3e) {
 	  	is_comment = true;
 	  }
 	  // newline ends the comment
  	if (read == 0x0a) {
    	is_comment = false;
    }
//0x4e = N
    if ((!is_comment) && (read != 0x0a)  && (read != 0x4e)) {
      for (int i = 0x80; i > 0x00; i >>= 1) {
        lzwbtree << ((read & i) ? '1' : '0');
			}
    }
  }

  input_stream.close();

  if (print_tree)
    output_stream << lzwbtree;

  output_stream << "depth = " << lzwbtree.get_max_depth() << std::endl
                << "mean = " << lzwbtree.Mean() << std::endl
  		<< "var = " << lzwbtree.Variance() << std::endl;

  output_stream.close();

  return 0;
}

void Usage() {
	std::cout << "Usage: lzw input -o output [-tree]" << std::endl
                  << "-tree: print tree into output" << std::endl;
}

