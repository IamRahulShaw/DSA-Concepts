#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string str1, str2; // string declaration
    // cin >> str1;       // cin break at space and newline and ignore all the spaces and newlines before it takes a new character --> If I give Rahul Shaw as a input it only takes Rahul
    // cin >> str2;       // It takes shaw and ignore the previous space before shaw
    // str1[0] = 'P'; // change of characters
    // cout << str1 + " " + str2 << endl;
    // cin.ignore(); // ignore the buffer that store in input stream. If we did not use that then
    // Rahul Shaw <-- this is the input but after that we press enter means \n (new line character). The value of \n stores in cin buffer and getline takes it as a input and breaks. So, we get a blank line. cin.ignore() ignore the buffer.
    // string str3;
    // getline(cin, str3); // It inputs full lines and break only at new line character
    // cout << str3 << endl;

    // string::size_type sz;
    // string strToNum = "2001 is birthday";
    // int num = stoi(strToNum); // output -> 2001 // stoi parses string to integer
    // int num = stoi(strToNum, &sz, 10); // &sz is optional. It is a pointer of size_type. 10 is the base. Same as the parseInt function in javascript. Base denote string's number is in which base.
    // cout << num << endl;

    // int num2 = 10;
    // string intToStr = to_string(num2); // to_string used to convert into string
    // cout << intToStr << endl;

    // string strNew = "Rahul";
    // string::iterator it = strNew.begin();
    // string::iterator it = strNew.end(); // last character is \0 (null character)
    // string::reverse_iterator it = strNew.rbegin();
    // cout << *it << endl;
    // cout << *(it + 1) << endl;
    // cout << *(it - 1) << endl;

    // string strNew(10, 'R'); // create a string of size
    // cout << strNew << endl;
    // cout << strNew.size() << endl;
    // cout << strNew.length() << endl;   // size and length are same
    // cout << strNew.max_size() << endl; // maximum of size that a string can be
    // cout << strNew.capacity() << endl; // The total capacity of the string. Here it is 15. It is given by the compiler.
    // strNew.resize(5);                  // resize the size to 5
    // cout << strNew << endl;
    // cout << strNew.capacity() << endl; // capacity would be same
    // cout << strNew.size() << endl;
    // strNew.shrink_to_fit();            // shrink the capacity of the string to the size
    // cout << strNew.capacity() << endl; // capacity would be 5

    // string strNew = "Rahul";
    // cout << strNew.at(2) << endl;
    // cout << strNew.front() << " " << strNew.back() << endl; // return the reference to the front and back

    // string strNew = "Rahul";
    // string strAdd = " is a good boy.";
    // string strAssign;
    // cout << strNew.append(strAdd) << endl;
    // cout << strNew.append(strAdd, 0, 10) << endl; // 0 to 10 length of characters
    // cout << strAssign.assign(strNew, 0, 3) << endl; // assign value to a string
    // cout << strAdd.insert(0, strNew, 0, 3) << endl; // insert strNew before index 0. Next 3 characters are for the strNew. So it would be same like append "Rah";

    // cout << strAdd.erase(6, 4) << endl; // erase the string 6 is the starting pos and erase after 4 elems.
    // string repl = "owplt";
    // cout << strNew.replace(1, 3, repl, 1, 2) << endl; // "ahu" replaced with "wp" of repl
    // strNew.swap(strAdd);
    // cout << strNew << " " << strAdd << endl;

    // strNew.push_back('s'); // push a character after the string
    // cout << strNew << endl;
    // strNew.pop_back(); // pops out a character from the string
    // cout << strNew << endl;

    // cout << string::npos << endl; // npos is the maximum size of a string

    // string str = "apple is a apple";
    // string str2 = "apple";
    // cout << str.find(str2, 1) << endl; // 1 denote the starting position of finding
    // cout << str.find("is", 3) << endl;

    // string str = "Rahul Shaw";
    // cout << str.substr(1, 3) << endl; // print "ahu", start from 1 and go for 3 characters

    // string str1 = "apple", str2 = "boy";
    // cout << str1.compare(str2) << endl; // if str1 is small then -1 and equal then 0 if big then 1
    string str1 = "apple2", str2 = "apple";
    cout << str1.compare(str2) << endl; // +1
}