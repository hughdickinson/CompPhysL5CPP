// LECTURE 5: MORE OBJECT ORIENTATION

// Include some C++ standard library header files
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

/* THE "this" POINTER:
 * ===================
 * When used within a class method definition, the RESERVED KEYWORD 
 * "this" is an IDENTIFIER that refers to A POINTER to the INSTANCE
 * of the class being for which the currently executing method was 
 * called. This instance will subsequently be refered to as the CURRENT 
 * INSTANCE.
 *
 * RECALL that classes provide a DESCRIPTION that is used to INSTANTIATE
 * DISTINCT OBJECTS that behave according to that description. Each 
 * object is a distinct INSTANCE of the class that maintains its own 
 * INDEPENDENT member data. 
 *
 * We will see other uses of "this" in subsequent examples, but  a common use 
 * of the this pointer is to disambiguate the identifiers CURRENT INSTANCE's
 * member data e.g.
 */
class UsingTheThisPointer{ 

  int intVar;
  double doubleVar;
  
public :

  // Method to set member data.
  void setVars(int intVar, double doubleVar){
    /*Use the this pointer to disambiguate the instance member data
     * and the method arguments. This removes the requirement to contrive
     * argument identifiers that are distinct from those of member data.
     */
    this->intVar = intVar + 1;
    this->doubleVar = doubleVar + 1.0;

    /* Print values of arguments and member data. Without explicitly
     * referring to the this pointer, the method arguments SHADOW the 
     * instance's member data.
     */
    std::cout << "Arguments:\n"
	      << "intVar => " << intVar << "\n"  
	      << "doubleVar => " << doubleVar << "\n\n"
	      << "Member Data:\n"
	      << "this->intVar => " << this->intVar << "\n"  
	      << "this->doubleVar => " << this->doubleVar
	      << std::endl;
  }
  
};

void usingThisDemo(){ // Invoke with option 0.

  /* Declare and default-initialize an instance of the UsingTheThisPointer
   * class.
   */
  UsingTheThisPointer usingThis;

  // Call the setVars method.
  usingThis.setVars(41, 2.14);
  
} // end of usingThisDemo()

/* USER DEFINED TYPES:
 * ===================
 * As we have already seen, a COMPLETE class definition in C++ 
 * IMPLICITY defines a NEW TYPE that can be specified in SUBSEQUENT
 * variable or constant declaration statements e.g.
 */

// Minimal complete class definition
class MinimalCompleteClass{
  /* A code block is required for a complete definition.
   *
   * The C++ compiler will AUTOMATICALLY provide a DEFAULT CONSTRUCTOR
   * and DESTRUCTOR.
   */
};

void minimalClassDemo(){
  std::cout << "minimalClassDemo():\n" << std::endl;

  /* Legal DECLARATION of a variable with the MinimalCompleteClass type-
   * specifier. Recall, this statement calls the DEFAULT CONSTRUCTOR.
   */
  MinimalCompleteClass completeClassVar;

  /* This DECLARATION of a constant with the MinimalCompleteClass type-
   * specifier is legal ONLY if a USER-SPECIFIED DEFAULT CONSTRUCTOR
   * is defined.
   */
#ifdef PARSE_ILLEGAL_CODE
  const MinimalCompleteClass completeClassConst;
#endif
  
  /* By analogy with BUILT-IN types like double, int etc., USER-DEFINED
   * types can also be INITIALIZED. 
   * 
   * We have already seen one way to initialize a user defined type by
   * calling the class constructor. This is analogous to using the 
   * CONSTRUCTOR-STYLE initialization syntax for BUILT-IN types e.g.
   */

} // end of minimalClassDemo()

// Define a class with a non-default constructor
class ClassWithConstructor {

public :
  
  // public member data - two integer values
  int intMember1;
  int intMember2;
  
  /* The C++ compiler will AUTOMATICALLY provide a DEFAULT CONSTRUCTOR
   * and DESTRUCTOR.
   *
   * The DEFAULT CONSTRUCTOR will DEFAULT-INITIALIZE member data by calling
   * their DEFAULT CONSTRUCTORS.
   */

  /* In class definition of non-default constructor accepting two integer 
   * variables.
   */
  ClassWithConstructor(int intArg1, int intArg2):
    intMember1(intArg1),
    intMember2(intArg2)
  {}
  
};

void constructorClassDemo(){ // Invoke with option 1.
  std::cout << "constructorClassDemo():\n" << std::endl;

  /* Legal DECLARATION and CONSTRUCTOR-STYLE initialization of a variable 
   * with the ClassWithConstructor type-specifier.
   */
  ClassWithConstructor constructorClassVar(1, 2);

  /* Legal DECLARATION of a constant with the CompleteClass type-
   * specifier. Recall, this statement calls the DEFAULT CONSTRUCTOR.
   */
  const ClassWithConstructor constructorClassConst(3, 4);

  /* We know that PREVIOUSLY DECLARED, BUILT-IN types can also be
   * initialized by ASSIGNING value to them using the ASSIGNMENT OPERATOR
   * e.g.
   */

  /* Declare a double-precision variable (MAY result in DEFAULT-
   * INITIALIZATION)
   */
  double approximatePi;

  // Print post-DECLARATION value
  std::cout << approximatePi << std::endl;
 
  // Initialize approximatePi using the ASSIGNMENT OPERATOR
  approximatePi = 3.14;

  // Print post-INITIALIZATION value
  std::cout << approximatePi << std::endl;
  
  /* IDENTICAL SYNTAX is also LEGAL for USER-DEFINED types.
   */
  // Print post-DECLARATION member data values
  std::cout << constructorClassVar.intMember1
	    << "\t" 
	    << constructorClassVar.intMember2
	    << std::endl;

  /* EXPLICITLY initialize constructorClassVar using the ASSIGNMENT
   * OPERATOR.
   */
  constructorClassVar = constructorClassConst;

  // Print post-INITIALIZATION member data values
  std::cout << constructorClassVar.intMember1
	    << "\t" 
	    << constructorClassVar.intMember2
	    << std::endl;
  
  /* HOWEVER, for USER-DEFINED types it is NOT ALWAYS OBVIOUS what 
   * the outcome of such a statement should be.
   */

} // end of constructorClassDemo()

/* OVERLOADING OPERATORS:
 * ======================
 * 
 * The ability to OVERLOAD OPERATORS in C++ is simultaneously one of
 * the language's most POWERFUL FEATURES, and one of its most CONFUSING
 * features for novice programmers. 
 *
 * OPERATOR OVERLOADING allows programmers to explicitly define the way
 * that the familiar C++ operators (+, -, ==, etc.) behave when used
 * in conjunction with user-defined types. 
 *
 * For example, when applied to instances of the std::string class, the 
 * "+" operator performs string concatenation
 */

void stringConcatDemo(){ // Invoke with option 2.
  // Declare and initialize two instances of std::string
  std::string leftHandSide("Computational ");
  std::string rightHandSide("Physics");

  // Concatenate two strings using the OVERLOADED "+" operator
  std::string bothSides = leftHandSide + rightHandSide;

  std::cout << "Left => " << leftHandSide << "\n"
	    << "Right => " << rightHandSide << "\n"
	    << "Both => " << bothSides
	    << std::endl;
  
} // end of stringConcatDemo()

/* OVERLOADED ASSIGNMENT OPERATORS:
 * ================================
 * 
 * An operator that is VERY COMMONLY OVERLOADED by C++ programmers
 * is the ASSIGNMENT OPERATOR.
 *
 * If the programmer DOES NOT define an overload of the assignment 
 * operator, then the C++ compiler will provide a DEFAULT ASSIGNMENT
 * OPERATOR that will simply COPY THE FACE VALUES OF EACH MEMBER 
 * DATUM. This MAY NOT be desirable for POINTER-TYPE member data.
 *
 * In particular, copying the FACE VALUE of a pointer simply COPIES 
 * THE MEMORY ADDRESS stored by the pointer. This is called making a 
 * SHALLOW COPY. Shallow copying DOES NOT allocate new memory nor 
 * does it copy the VALUES of the POINTED-TO DATA. 
 *
 * QUESTION: What problems could result from shallow copying of pointer-
 * type member data? 
 *
 * In contrast, DEEP COPYING of pointer-type member data DOES entail 
 * allocation of new memory AND copying the VALUES of the POINTED-TO DATA. 
 * One of the main motivations for explicit definition of an assignment 
 * operator overload for your class is the implementation of deep copying
 * semantics for pointer-type member data. 
 */

/* DEFINING OVERLOADED ASSIGNMENT OPERATORS:
 * =========================================
 *
 * To OVERLOAD THE ASSIGNMENT OPERATOR in C++ your class definition
 * must include a SPECIAL METHOD DEFINITION.
 *
 * The special method MUST have the identifier "operator=". It MUST
 * return a REFERENCE to THE CURRENT INSTANCE of the class being DEFINED. 
 *
 * It MAY have several signatures (since it might make sense to assign
 * an instance of several different classes to the class being defined), 
 * but the MOST COMMON accepts a SINGLE PARAMETER that corresponds to a 
 * CONSTANT REFERENCE to ANOTHER INSTANCE of the class being defined.
 *
 * The following example defines a class that implements a custom 
 * OVERLOAD OF THE ASSIGNMENT OPERATOR.
 */

class ClassWithAssignmentOperator{
  
  // Dynamically allocated array of double-precision values
  double * doubleArray;
  // The number of elements in doubleArray
  int arraySize;

 public :

  // Rely on default constructor provided by the compiler
  
  // Class constructor allocates and initializes doubleArray
  ClassWithAssignmentOperator(double doubleArray[], int arraySize):
    /* Identifiers used in an initialization list are assumed to
     * refer to member data - shadowing will not occur.
     */
    arraySize(arraySize),
    doubleArray(new double[arraySize])
      {
	// Copy elements from array argument to member datum.
	for(int index = 0; index < this->arraySize; ++index){
	  this->doubleArray[index] = doubleArray[index];
	}
      }
  
  // Overloaded assignment operator performs a DEEP COPY of doubleArray.
  ClassWithAssignmentOperator & operator=(ClassWithAssignmentOperator const & otherInstance)
    {
      /* NOTE: Overloaded assignment operators should verify that the
       * supplied argument DOES IN FACT correspond to ANOTHER INSTANCE 
       * of the class being defined and NOT THE CURRENT INSTANCE. If the
       * supplied argument does reference the CURRENT instance, then NO
       * COPYING OPERATIONS should be performed.
       */
      /* Check if the MEMORY ADDRESSES of the supplied argument equals
       * the memory address of the CURRENT INSTANCE. Assume that this is a 
       * sufficient condition to test for equality between OBJECT INSTANCES.
       * Recall the ADDRESS-OF OPERATOR "&".
       */ 
      if(&otherInstance == this){
	/* Return a reference to the CURRENT INSTANCE by dereferencing the
	 * this pointer.
	 */
	return *this;
      }
      
      
      /* Print a line to show that the copy constructor was actually
       * called!
       */
      std::cout << "ClassWithAssignmentOperator copying..." << std::endl;

    /* (Re-)Initialize arraySize to match the corresponding member of
     * "otherInstance"
     * NOTE: Copy constructor has access to PRIVATE member of 
     * "otherInstance".
     * NOTE: There is no need to explicitly refer to the this pointer
     * when referencing the arraySizeor doubleArray member data of the 
     * CURRENT INSTANCE within this method (although one could), since
     * there is no ambiguity with the method arguments.
     */
      arraySize = otherInstance.arraySize;
      
      // Deallocate doubleArray IF IT HAS ALREADY BEEN ALLOCATED.
      if(doubleArray != nullptr){
	delete[] doubleArray;
      }
      
      // (Re-)allocate memory for doubleArray
      doubleArray = new double[arraySize];
      
      /* Initialize the elements of doubleArray to match the
       * corresponding member of "otherInstance"
       */
      for(int index = 0; index < arraySize; ++index){
	doubleArray[index] = otherInstance.doubleArray[index];
      }
      /* Return a reference to the CURRENT INSTANCE by dereferencing the
       * this pointer.
       */
      return *this;
    }
  
  // Destructor frees doubleArray IF IT HAS BEEN ALLOCATED.
  ~ClassWithAssignmentOperator()
    {
      if(doubleArray != nullptr){
	/* NOTE: must use delete[] operator since new[] operator was
	 * used for allocation.
	 */
	delete[] doubleArray;
      }
    }

  /* Getter method to obtain a pointer to the first element of
   * doubleArray. Retrieve the array size using a reference-type 
   * argument.
   */
  double * getDoubleArray(int & arraySizeArg){
    // modify the supplied reference to reflect the actual array size
    arraySizeArg = arraySize;
    return doubleArray;
  }
  
};

void assignmentOperatorOverloadDemo(){ // Invoke with option 3.

  std::cout << "assignmentOperatorOverloadDemo():\n" << std::endl;
  
  // Declare and initialize two arrays of double precision values.
  double doubleArray1[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
  double doubleArray2[5] = {2.0, 4.0, 6.0, 8.0, 10.0};

  // Declare and initialize two instances of ClassWithCopyConstructor
  ClassWithAssignmentOperator assignableClassVar1(doubleArray1, 5);
  ClassWithAssignmentOperator assignableClassVar2(doubleArray2, 5);

  // Retrieve and print post-CONSTRUCTION member data values.
  // First instance
  int memberArraySize1(0);
  double * memberDoubleArray1 = assignableClassVar1.getDoubleArray(memberArraySize1);
  for(int index = 0; index < memberArraySize1; index++){
    std::cout << memberDoubleArray1[index] << " ";
  }
  std::cout << std::endl;
  
  // Second instance
  int memberArraySize2(0);
  double * memberDoubleArray2 = assignableClassVar2.getDoubleArray(memberArraySize2);

  for(int index = 0; index < memberArraySize2; index++){
    std::cout << memberDoubleArray2[index] << " ";
  }
  std::cout << std::endl;

  /* Use the ASSIGNMENT OPERATOR to reset copyConstructorClassVar1's
   * member data to match those of copyConstructorClassVar2.
   */
  assignableClassVar1 = assignableClassVar2;

  // Retrieve and print post-COPY member data values.
  // First instance.
  // QUESTION: Why don't we delete memberDoubleArray1 first? 
  memberDoubleArray1 = assignableClassVar1.getDoubleArray(memberArraySize1);
  for(int index = 0; index < memberArraySize1; index++){
    std::cout << memberDoubleArray1[index] << " ";
  }
  std::cout << std::endl;
  
  // Second instance
  memberDoubleArray2 = assignableClassVar2.getDoubleArray(memberArraySize2);

  for(int index = 0; index < memberArraySize2; index++){
    std::cout << memberDoubleArray2[index] << " ";
  }
  std::cout << std::endl;
  
} // end of assignmentOperatorOverloadDemo()


/* INHERITENCE:
 * ============
 * INHERITENCE in OBJECT ORIENTED programming is a VERY powerful mechanism 
 * for REUSING and EXTENDING the functionality of PREEXISTING classes.
 *
 * Fundamentally, INHERITENCE allows programmers to define a class that 
 * incorporates (or INHERITS) the (non-constructor) method and member 
 * data definitions of another.
 * 
 * By utilizing this capability, C++ programmers NEED NOT REDEFINE methods
 * and member data that perform identical functions. 
 *
 * The class that DEFINES the INHERITED functionality is called the PARENT 
 * (or BASE) class and the class that INHERITS the functionality is called
 * the CHILD (or DERIVED) class.
 *
 * Derived classes MAY inherit functionality from SEVERAL base classes
 * and MULTIPLE derived classes MAY inherit from THE SAME base class. 
 * 
 * Derived classes CAN also act as the base class for further derivation,
 * and PROPAGATE their inherited functionality to their children.  
 *
 * OVERRIDING INHERITED METHODS:
 * =============================
 * Inheritance also enables derived classes to REFINE THE FUNCTIONALITY 
 * of the methods they inherit by PROVIDING CUSTOMIZED DEFINITIONS of 
 * those methods.
 *
 * This mechanism is called METHOD OVERRIDING.
 *
 * To override an inherited method when defining a derived class, simply 
 * define a new method with an identical signature to the base-class method 
 * to be overridden
 *
 * Derived classes may override any number of the methods they inherit.
 */

/* A simple "Printer" base class generic print() and powerSwitch() 
 * methods
 */
class PrinterClass{

  // Boolean member datum to monitor the device power status.
  bool powerIsOn;
  
public :

  /* NOTE: Rely on COMPILER-GENERATED default constructor.
   */

  /* A generic powerSwitch() method that is relevant for all
   * electronic devices.  
   */
  void powerSwitch(){
    std::cout << "PrinterClass::powerOn(): Switching: "
	      << (powerIsOn ? "Off" : "On" ) << std::endl;

    // toggle power status
    powerIsOn = !powerIsOn;
  }
  
  /* A generic print() method that is relevant for all devices
   * that are able to print.  
   */
  void print(){
    std::cout << "PrinterClass::print()" << std::endl;
  }
  
};


/* A "PhotoCopier" class that INHERITS the print() and powerSwitch() 
 * methods from PrinterClass and also implements a copy() method.
 *
 * SPECIFYING THE INHERITANCE RELATIONSHIP:
 * ========================================
 * To specify that PhotoCopierClass INHERITS FROM PrinterClass we
 * insert the three tokens ": public PrinterClass" IMMEDIATELY AFTER
 * The PhotoCopierClass IDENTIFIER in the PhotoCopierClass DEFINITION.
 *
 * NOTE: NO MODIFICATION to the definition of PrinterClass is required. 
 */
class PhotoCopierClass : public PrinterClass {
  
public :

  /* A specialized copy() method that only applies to photocopiers.
  */
  void copy(){
      std::cout << "PhotoCopierClass::copy()" << std::endl;
  }
  
};

/* A "Colour Printer" class that INHERITS the generic powerSwitch() 
 * method from PrinterClass but OVERRIDES the generic print() method
 * with a more specialized implementation.
 */
class ColourPrinterClass : public PrinterClass {

public :

  /* Override the print() method of PrinterClass with a more specialized
   * implementation.
   */
  void print(){
    std::cout << "ColourPrinterClass::print()" << std::endl;
  }

  /* A more specialized printColour() method that only applies to
  * colour printers.
  */
  void printColour(){
    std::cout << "ColourPrinterClass::printColour()" << std::endl;
  }
  
};

void inheritenceDemo(){ // Invoke with option 5. 

  // Instantiate Printer, PhotoCopier and ColorPrinter objects
  PrinterClass printer;
  PhotoCopierClass photoCopier;
  ColourPrinterClass colourPrinter;

  // Switch on the devices! Calls the generic method in all cases.
  std::cout << "Printer => ";
  printer.powerSwitch();
  std::cout << "Photocopier => ";
  photoCopier.powerSwitch();
  std::cout << "ColourPrinter => ";
  colourPrinter.powerSwitch();

  // Call the print method for all three devices
  std::cout << "\nPrinter => ";
  printer.print();
  std::cout << "Photocopier => ";
  photoCopier.print(); // uses generic method provided by PrinterClass
  std::cout << "ColourPrinter => ";
  colourPrinter.print(); // uses the method provided by ColourPrinterClass

  // Call the device-specific methods where appropriate
  std::cout << "\nPhotocopier => ";
  photoCopier.copy();
  std::cout << "ColourPrinter => ";
  colourPrinter.printColour();

  // Switch off the devices
  std::cout << "\nPrinter => ";
  printer.powerSwitch();
  std::cout << "Photocopier => ";
  photoCopier.powerSwitch();
  std::cout << "ColourPrinter => ";
  colourPrinter.powerSwitch();
  
}

/* BASE CLASS INITIALIZATION:
 * ==========================
 * Derived classes INHERIT the member data and methods of their
 * parent classes. Depending upon their definitions the member data
 * of the parent class may require INITIALIZATION in order for their 
 * methods to function as expected. If any of those methods are called
 * by the DERIVED class during its initialization, it is essential that 
 * the BASE class is ALREADY properly initialized.
 *
 * When a derived class is instantiated, C++ initializes all of its
 * parent classes BEFORE it initializes the derived class.
 * NOTE: This behaviour propagates upwards through the inheritance
 *       hierarchy, ensuring that all the parent classes of particular
 *       class in the hierarchy are properly initialized before the 
 *       initialization of that class proceeds.
 * 
 * The previous example used a base class (PrinterClass) that relied on 
 * the compiler-generated default constructor for initialization. By 
 * default C++ will AUTOMATICALLY initialize PARENT classes of a DERIVED
 * class using their DEFAULT CONSTRUCTORS.
 * 
 * It is also possible to specify that a PARAMETERIZED CONSTRUCTOR of
 * the base class be used for its initialization. The following example 
 * demonstrates how to do this. 
 */

/* Base class "MassiveParticle" defines two generic member data: A 
 * string to contain the particle name, and a double-precision real
 * number to encode its mass.
 */
class MassiveParticle {

  // The name of the particle
  std::string name;
  // The mass of the particle (kg)
  double mass;

public :

  /* Parameterized constructor initializes member data
   * NOTE: Specifying and IMMUTABLE reference to a std::string as
   * enables a LITERAL STRING to be passed to the constructor invocation.
   */
  MassiveParticle(const std::string & name, double mass):
    name(name),
    mass(mass)
  {}

  /* NOTE: If a NON-DEFAULT constructor is defined, the compiler
   * WILL NOT automatically generate a DEFAULT constructor. If you
   * need one (e.g. ROOT users who want serialization), you must 
   * explicitly define one.
   */
  MassiveParticle()
  {}
  
  // Getter method for the particle name
  std::string getName(){
    /* Use empty() method of std::string to check if name has been set
     * If so, return the name. Otherwise return the string "Mystery!". 
     * NOTE: The use of the TERNARY OPERATOR "?".   
     */
    return name.empty() ? "Mystery!" : name;
  }
  
  // Getter method for the particle mass
  double getMass(){
    return mass;
  }
  
};

class ChargedMassiveParticle : public MassiveParticle {

  // The charge of the particle (C).
  double charge;

public :

  /* Parameterized constructor overrides the default behaviour (i.e. 
   * inializing the base class using the default constructor) by calling 
   * the PARAMETERIZED CONSTRUCTOR of MassiveParticle BEFORE initializing
   * its own member datum. 
   *
   * This ensures that the base class is properly initialized BEFORE
   * initialization of the derived class proceeds.
   */
  ChargedMassiveParticle(const std::string & name, double mass, double charge):
    // Call PARAMETERIZED CONSTRUCTOR of MassiveParticle
    MassiveParticle(name, mass), 
    charge(charge)
  {
    // Check that MassiveParticle component has ALREADY been initialized.
    std::cout << "\nParameterized:\n\n"
	      << "ChargedMassiveParticle: name => " << getName() << "\n"
	      << "ChargedMassiveParticle: mass => " << getMass() << " kg\n"
	      << "ChargedMassiveParticle: charge => " << getCharge() << " C"
	      << std::endl;
  }

  /* Default constructor will automatically initialize the base class using
   * its default constructor IF IT DEFINES ONE. If it doesn't define one,
   * your DEFAULT CONSTRUCTOR must call a PARAMETERIZED CONSTRUCTOR of the
   * base class, specifying "sensible" default arguments.
   */
  ChargedMassiveParticle()
  {
    // Print default initialization state.
    std::cout << "\nDefault:\n\n"
	      << "ChargedMassiveParticle: name => " << getName() << "\n"
	      << "ChargedMassiveParticle: mass => " << getMass() << " kg\n"
	      << "ChargedMassiveParticle: charge => " << getCharge() << " C"
	      << std::endl;
  }
  
  // Getter method for the particle charge
  double getCharge(){
    return charge;
  }

};

void baseInitDemo(){ // Invoke with option 6. 
  // IMPLICITLY invoke DEFAULT CONSTRUCTORS.
  ChargedMassiveParticle darkMatter;
    
  // EXPLICITLY invoke PARAMETERIZED CONSTRUCTORS.
  ChargedMassiveParticle electron("electron", 9.1e-31, -1.6e-19);
}


// main function that calls all demonstration functions
int main (int argc, char * argv[]){

  /* Use the std::atoi method defined in <cstdlib> to convert character
   * arrays to integer values if possible.
   */
  int option = std::atoi(argv[1]);
  // Call requested demonstration function
  switch (option){
  case 0:
    usingThisDemo();
    break;
    
  case 1:
    minimalClassDemo();
    break;
    
  case 2:
    constructorClassDemo();
    break;

  case 3:
    stringConcatDemo();
    break;
    
  case 4:
    assignmentOperatorOverloadDemo();
    break;

  case 5:
    inheritenceDemo();
    break;

  case 6:
    baseInitDemo();
    break;
    
  default:
    std::cout << "Unknown Option" << std::endl;
  }// end of switch statement
  return 0;
}
