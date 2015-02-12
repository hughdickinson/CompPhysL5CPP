// The <iostream> header file enables TERMINAL input/output
#include <iostream>
// The <fstream> header file enables FILE input/output
#include <fstream>
/* The <vector> header file provides the std::vector<X> container.
 * a vector is like a supercharged array that can change its size
 * at program runtime. 
 */
#include <vector>
/* The <algorithm> header provides all of the STL data processing 
 * algorithms 
 */
#include <algorithm>

/* This short example of the capabilities of the STL perorms the following
 * functions:
 * 1) Reads an unsorted list of numbers from a text file specified using 
 * the first command line argument.
 * 2) Stores the numbers in a STL container called a vector.
 * 3) Sorts the numbers using an STL algorithm.
 * 4) Writes the sorted numbers into an output file specified
 * using the second command line argument.
 */
int main(int argc, char * argv[]){

  /* Instantiate a vector of double-precision values to store the
   * the numbers that are read from the input file.
   *
   * NOTE: The default constructor instantiates a vector with zero 
   *       elements but a vector provides methods to append elements 
   *       that handle memory allocation automatically.
   */
  std::vector<double> numberVector;
  
  /* The std::ifstream class is provided by the <fstream> header
   * file and is used to READ from files.
   * 
   * The following statement constructs a std::ifstream instance and
   * initializes it by attempting to open the file whose name is
   * specified as the constructor argument for READING.
   */
  std::ifstream inputFile(argv[1]); // File name is the first command line arg.

  /* The std::ifstream class provides many methods to check the state
   * and readability of the file. Let's check that the file opened 
   * successfully and is in a readable state.
   */
  if(inputFile.is_open() && inputFile.good()){
    /* Declare and initialize a double variable to recieve each number
     * as it is read from the input file.
     */
    double tempNumberStore(0.0);
    
    /* To actually read the data from the file one can use the STREAM
     * INPUT operator ">>".
     *
     * NOTE: The STREAM INPUT operator looks like the mirror image of
     *       the STREAM OUTPUT operator that we have been using with 
     *       std::cout to OUTPUT text to the terminal. This is an 
     *       example of the UNIFORM INTERFACE provided by the STL.
     *
     * BY DEFAULT the stream input operator reads WHITESPACE-SEPARATED
     * blocks of characters from the input file and attempts to 
     * AUTOMATICALLY CONVERT those characters to the type of the variable
     * that is being READ INTO.
     *
     * The following while loop will read every WHITESPACE-SEPARATED
     * character string (or token) from the input file, convert that 
     * string into a double precision value and store that value in a 
     * std::vector.
     *
     * The eof() method provided by std::ifstream evaluates to true ONLY
     * when the end of the file has been reached and there are no more
     * data to read.
     */
    /* Keep going until we run out of data or something goes wrong!
     * NOTE: IF your input file ends with newline, numberVector will
     *       contain two copies of the final number. 
     */
    while(!inputFile.eof() && inputFile.good()){ 
      /* Read a single token from the input file using the stream
       * input operator. Convert this token to a double precision value
       * and temporarily assign that value to tempNumberStore.
       */
      inputFile >> tempNumberStore; // it really is that simple!

      /* Now use the push_back() method provided by std::vector<X>
       * to append the value stored in tempNumberStore to the END
       * of the array, allocating memory AUTOMATICALLY if required. 
       */
      numberVector.push_back(tempNumberStore);
    } // end of while loop to read data from input file

    /* Now that the data have been read, call the close() method 
     * that is provided by std::ifstream to safely close the input
     * file.
     */
    inputFile.close();

    /* Use the STANDARD FOR-LOOP SYNTAX to print the contents of 
     * numberVector. 
     */
    
    std::cout << "Unsorted Values:\n";
    /* instantiate an iterator that is compatible with a vector of
    * double precision values.
    */
    std::vector<double>::iterator numberIterator;
    /* Loop between the first and last elements of numberVector. 
     */
    for(std::vector<double>::iterator numberIterator = numberVector.begin();
	numberIterator != numberVector.end(); // QUESTION: Why "!=" ?
	++numberIterator){ // OVERLOADED prefix increment operator.
      // OVERLOADED dereference operator provides element access. 
      std::cout << *numberIterator << " ";
    }
    std::cout << std::endl;

    /* Use the std::sort algorithm provided by the <algorithm> header
     * file to sort the numbers stored in numberVector
     */
    std::sort(numberVector.begin(), numberVector.end());

    /* Use the COMPACT FOR-LOOP SYNTAX to print the sorted contents of 
     * numberVector. This syntax is ONLY available for containers that
     * implement the STL ITERATOR INTERFACE.
     */
    std::cout << "Sorted Values:\n";
    for(double number : numberVector){
      std::cout << number << " ";
    }
    std::cout << std::endl;

    /* The std::ofstream class is provided by the <fstream> header
     * file and is used to WRITE from files.
     * 
     * The following statement constructs a std::ofstream instance and
     * initializes it by attempting to open the file whose name is
     * specified as the constructor argument for WRITING.
     */
    // File name is the second command line arg.
    std::ofstream outputFile(argv[2]);

    /* std::ofstream also provides is_open() and good() methods to 
     * verify that the file is open and ina writeable state.
     */
    if(outputFile.is_open() && outputFile.good()){
    
      /* To actually write the data to the file one can use the STREAM
       * OUTPUT operator "<<".
       *
       * NOTE: Writing textual data to a file is EXACTLY the same as
       *       writing data to the terminal except that the identifier 
       *       of an instance of std::ifstream replaces std::cout.
       * 
       * Use the compact for loop syntax once again to iterate over the
       * vector of (now) sorted values.
       */
      for(double number : numberVector){
	outputFile << number << "\n";
      }
      /* std::ofstream also provides a close() method. Closing the output 
       * file AUTOMATICALLY flushes the stream buffer. There is no need to 
       * invoke std::flush or std::endl.
       */
      outputFile.close();
      
      // return 0 to indicate success
      return 0;
    }
    else{ // Failed to open output file.
      /* If control reaches this point then the input file did not open
       * Return a non-zero value to indicate a failure state.
       */
      return 2; // 2 indicates output file failure.
    }
  }
  else{ // Failed to open input file.
    /* If control reaches this point then the input file did not open
     * Return a non-zero value to indicate a failure state.
     */
    return 1; // 1 indicates input file failure.
  }
}
