#ifndef _MYCLASS_H_
#define _MYCLASS_H_

#include <iostream>
#include <string>

class MyClass {

private:

/**
 * set a pattern of "Ni" to a variable - for either char or wchar_t in order to find this pattern in a given string
 * @param pat - a pattern variable which will hold the "Ni" string
 */
static void getNiPattern(std::basic_string<char> &pat) {pat = "Ni";} 
static void getNiPattern(std::basic_string<wchar_t> &pat) {pat = L"Ni";} 

/**
 * set a pattern of "I" - for either char or wchar_t in order to replace i after N with I in a given string
 * @param pat - a pattern variable which will hold the "I" string
 */
static void getReplacementChar(std::basic_string<char> &pat) {pat = "I";} 
static void getReplacementChar(std::basic_string<wchar_t> &pat) {pat = L"I";}

/**
 * prints a string. Used for printing a new string, after all "Ni" have been replaced with "NI"
 * Can be used for char or wchar_t
 * @param str - the new string to print to the console
 */
static void printNewString(std::basic_string<char> str) {std::cout << str;} 
static void printNewString(std::basic_string<wchar_t> str) {std::wcout << str;}

public:

/**
 * calculates the number of times that "Ni" appears in a given string
 * @param src - a pointer to the string (which is either char or wchar_t) to be checked 
 * @return the number of appearences of "Ni" in a given string. Throws an exception for a null pointer
 */
template <typename charType>
static int getNiCount(const charType *src);

/**
 * Given a string, this method returns a string in which all of the "Ni" is replaced with "NI"
 * @param src - a pointer to the string (which is either char or wchar_t) to be given for replacement 
 * @return a string in which all of the "Ni" is replaced with "NI". Throws an exception for a null pointer
 */
template <typename charType> 
static std::basic_string<charType> replaceNiWithNI(const charType *src);

/**
 * Prints  the information on a given string - how many times "Ni" appeared in a string and replaced string
 * according to replaceNiWithNI
 * @param src - a pointer to the string (which is either char or wchar_t) to be used for printing information
 */
template <typename charType>
static void printInformation(const charType *src);

}; 

template <typename charType>
static int MyClass::getNiCount(const charType *src)
{   
	 //Throw an exception for a null pointer
	 if(src == NULL)
		 throw std::invalid_argument("A null pointer was received (MyClass::getNiCount)");

	 int numOfNi = 0;
	 std::basic_string<charType> sourceString = src;

	  //Strings of sizes 0-1 have 0 appearences of Ni
	 if(sourceString.length() < 2)
		 return numOfNi;

	 std::basic_string<charType> patternNi;
	 getNiPattern(patternNi);    
	 std::string::size_type currentLocation = sourceString.find(patternNi);

	 //Going through the string and finding all appearences of Ni
     while(currentLocation != std::basic_string<charType>::npos)
	 {
		 currentLocation = sourceString.find(patternNi, currentLocation + 2);
		 ++numOfNi;
	 }
	 return numOfNi;
}

template <typename charType> 
static std::basic_string<charType> MyClass::replaceNiWithNI(const charType *src)
{
	//Throw an exception for a NULL pointer
	if (src==NULL)
		throw std::invalid_argument("A null pointer was received (MyClass::replaceNiWithNI)");

    std::basic_string<charType> sourceString = src;

	//Srings with length of 0-1 do not need any change
    if(sourceString.length() < 2)
      return sourceString;

    std::basic_string<charType> stringWithNIOnly(sourceString);
    std::basic_string<charType> patternNi , replacementChar;
    getReplacementChar(replacementChar); 
    getNiPattern(patternNi);    
    std::string::size_type currentLocation = stringWithNIOnly.find(patternNi);

    //Going through the string and replacing all the Ni with NI, by replacing i after N with I
    while(currentLocation != std::basic_string<charType>::npos)
    {
		stringWithNIOnly.replace((currentLocation + 1), 1, replacementChar);
        currentLocation = stringWithNIOnly.find(patternNi, currentLocation + 2);
	}
    return stringWithNIOnly;
  
}

template <typename charType>
static void MyClass::printInformation(const charType *src)
{
	try
	{
		std::cout << "Found " << getNiCount(src) << " occurrences of Ni. New string: " ;
		std::basic_string<charType> stringWithNIOnly = replaceNiWithNI(src);
		printNewString(stringWithNIOnly);
		std::cout << std::endl;
	}
	catch(const std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

}

#endif
