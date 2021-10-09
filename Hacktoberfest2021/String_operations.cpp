#include <iostream>
#include <string>
using namespace std;

int main()
{

    // using cout to print the string.
    cout << "Hola!" << endl;

    //creating a variable 'string' and assinging a value to it.
    string greeting = "Hello";
    cout << greeting << endl;

    //--------CONCATENATION--------------

    string a = "fruit: ";
    string b = "Apple";
    string c = a + b; // '+' operator can be used to concatenate(i.e add) 2 strings together.
    cout << c << endl;

    string c1 = a + " " + b; // Also " " a space with quotes can be used to concatenate 2 strings.
    cout << c1 << endl;

    string c2 = a.append(b); // Similarly append() function can be used to concatenate 2 strings.
    cout << c2 << endl;

    //-----STRING LENGTH-------
    string s1 = "Welcome to C++";
    cout << "Length of string is: " << s1.length() << endl; // To find the length of the string length() is used.

    cout << "Length of string is: " << s1.size() << endl; // size() function is also used to find the length of the string;

    //---SUBSTRING,INDEXING-----

    string myString = "Hello";
    cout << myString[0] << endl; // this gives us H
    //Note: String indexes start with 0: [0] is the first character.

    string myString1 = "Hello";
    myString[0] = 'J';
    cout << myString << endl; // Outputs Jello instead of Hello
    cout << endl;

    //----------------------------------------------------------------------------

    //  GETLINE :- This function is used to store a stream of characters as entered by the user in the object memory.

    string str;

cout<<"Enter the string: ";
    getline(cin, str); // Taking string input using getline()
    cout << "The string is : ";
    cout << str << endl;

    // PUSHBACK :- This function is used to input a character at the end of the string.
    str.push_back('s');
    cout << "The string after push_back operation is : ";
    cout << str << endl;

    //  POPBACK :- This function is used to delete the last character from the string.
    str.pop_back();
    cout << "The string after pop_back operation is : ";
    cout << str << endl;

    //  CAPACITY :- This function returns the capacity allocated to the string, which can be equal to or more than the size of the string. Additional space is allocated so that when the new characters are added to the string, the operations can be done efficiently.

    string str1 = "These are the string operations in C++";

    cout << "The string is : ";
    cout << str1 << endl;

    cout << "The capacity of string is : ";
    cout << str1.capacity() << endl;

    cout << "The length of the string is :" << str1.length() << endl;

    // RESIZE :- This function changes the size of string, the size can be increased or decreased.

    str1.resize(13); // Resizing string using resize()
    cout << "The string after resize operation is : ";
    cout << str1 << endl;
    cout << "The length of the string is :" << str1.length() << endl;

    // SHRINK_TO_FIT :- This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This operation is useful to save additional memory if we are sure that no further addition of characters have to be made.

    str1.shrink_to_fit(); // using shrink_to_fit()

    cout << "The new capacity after shrinking is : ";
    cout << str1.capacity() << endl;

    // BEGIN :- This function returns an iterator to beginning of the string.
    // END :- This function returns an iterator to end of the string.
    // RBEGIN :- This function returns a reverse iterator pointing at the end of string.
    // REND :- This function returns a reverse iterator pointing at beginning of string.
    string str3 = "welcome to programming";

    std::string::iterator it; // Declaring iterator

    std::string::reverse_iterator it1; // Declaring reverse iterator

    cout << "The string using forward iterators is : ";
    for (it = str.begin(); it != str.end(); it++)
        cout << *it;
    cout << endl;

    cout << "The reverse string using reverse iterators is : "; //Reverse string
    for (it1 = str.rbegin(); it1 != str.rend(); it1++)
        cout << *it1;
    cout << endl;

    // COPY(“char array”, length, position) :- This function copies the substring in target character array mentioned in its arguments. It takes 3 arguments, target char array, length to be copied and starting position in string to start copying.
    string str11 = "Hello";

    string str22 = "World"; // Declaring 2nd string

    char ch[98]; // Declaring character array

    str11.copy(ch, 13, 0); // using copy() to copy elements into char array

    cout << "The copied character array is : ";
    cout << ch << endl;
    cout << endl;

    // SWAP :- This function swaps one string with other.
    cout << "The 1st string before swapping is : ";
    cout << str11 << endl;
    cout << "The 2nd string before swapping is : ";
    cout << str22 << endl;

    str1.swap(str22); // using swap() to swap string content

    cout << "The 1st string after swapping is : ";
    cout << str11 << endl;
    cout << "The 2nd string after swapping is : ";
    cout << str22 << endl;

    return 0;
}
