interview2
==========
In your solution you should:

1. Use templates so as to avoid code duplication

2. Use STL/boost algorithm types
 
e.g: basic_string and basic_regex

3. avoid dynamic memory utilisation: new,delete,malloc,free

4. ensure a clear and compact class interface using const&, const and static

5. ensure a secure interface without crashes when delivering short strings or zero pointers

6. using test cases is an advantage

C++ template:

class MyClass
{
public:
    getNiCount(...)
    {
    }
      
   replaceNiWithNI(...)
    {
    }
};

int main()
{

const char *szTestString1 = "Ni nI NI nI Ni";
const wchar_t *szTestString2 = L"Ni nI NI nI Ni";

//Invoke getNiCount(...) of class MyClass
//Invoke replaceNiWithNI(...) of class MyClass

//Display on screen: "Found X occurrences of Ni. New string: Y"

}

Task description:

1. Implement the 2 functions getNiCount and replaceNiWithNI of the class MyClass:
 - getNiCount should return the number of occurrences of "Ni" within szTestString1/2 (case sensitive)
 - replaceNiWithNI should replace all occurrences of "Ni" in szTestString1/2 with "NI" (case sensitive)

2. invoke the 2 functions getNiCount and replaceNiWithNI.

3. Display the string given in the last comment on screen. X and Y should be replaced with the real values

4. the class MyClass should be able to deal both with szTestString1 (ASCII) and szTestString2 (Unicode).


You code should be:

 - easy to understand and maintain (priority 1)
 - techincally elegant (priority 2)
 - as (CPU) efficent as possible (priority 3).

you are allowed to use all technics, toolkits and frameworks which are based on the C++ language
