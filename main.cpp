#include<string>
#include "MyClass.h"


int main()
{
  //Basic strings (were given in the exercise)
  const char    *szTestString1 =  "Ni nI NI nI Ni";
  const wchar_t *szTestString2 = L"Ni nI NI nI Ni";

  //My strings (for testing)
  const char    *szTestString3 = "N i Ni  N  I ni IN Ni  Ni  n i Ni";
  const wchar_t *szTestString4 = L"N i Ni  N  I ni IN Ni  Ni  n i Ni";
  const char    *szTestString5 = "";
  const wchar_t *szTestString6 = L"";
  const char    *szTestString7 = "N";
  const wchar_t *szTestString8 = L"N";
  const char    *szTestString9 = NULL;
  const wchar_t *szTestString10 = NULL;


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
  MyClass::printInformation(szTestString9);
  MyClass::printInformation(szTestString10);

  getchar();

  return 0;
}
