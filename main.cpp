#include<string>
#include "MyClass.h"


int main()
{
  //Basic strings (were given in the exercise)
  const char    *szTestString1 =  "Ni nl Nl nl Ni";
  const wchar_t *szTestString2 = L"Ni nl Nl nl Ni";

  //My strings (for testing)
  const char    *szTestString3 = "";
  const wchar_t *szTestString4 = L"";
  const char    *szTestString5 = "N";
  const wchar_t *szTestString6 = L"N";
  const char    *szTestString7 = NULL;
  const wchar_t *szTestString8 = NULL;

  //Print the information which was asked in the exercise
  MyClass::printInformation(szTestString1);
  MyClass::printInformation(szTestString2);

  //Begin printing my tests results
  std::cout << std::endl;
  std::cout << "Results of my custom tests:" << std::endl;
  MyClass::printInformation(szTestString3);
  MyClass::printInformation(szTestString4);
  MyClass::printInformation(szTestString5);
  MyClass::printInformation(szTestString6);
  MyClass::printInformation(szTestString7);
  MyClass::printInformation(szTestString8);

  return 0;
}
