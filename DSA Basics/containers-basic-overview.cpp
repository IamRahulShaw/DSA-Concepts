#include <bits/stdc++.h>

using namespace std;

// array<int, 3> arr; // initialize with 0 because declare in globally
int main()
{

  // array<int, 3> arr; // 3 size of array (uninitialized) because locally initialize
  // arr.fill(8); // fill array with value 8
  // array<array<int, 5>, 6> arr;
  // for (int i = 0; i < arr.size(); ++i)
  // {
  //   for (int j = 0; j < arr[0].size(); ++j)
  //   {
  //     arr[i][j] = 3;
  //   }
  // }

  // int arr[3] = {5, 2, 18}; // begin and other properties does not work with this syntax
  // array<int, 3> arr = {5, 2, 18};
  // array<int, 3> arr = {0}; // This is also initialized with 0
  // array<array<int, 5>, 5> arr = {0}; // This array of array is initialized with zeros
  // int arr[5][5] = {0}; // This array of array is initialized with zeros
  // cout << *(arr.begin()) << endl;
  // sort(arr.begin(), arr.end()); // sort work like this with array also

  // vector<int> vec;
  // vec[0] = 2; // can't assign value like this, because vec is empty now. You need to define vector<int> vec(1) like this. so vector created with size 1 and initialize with 0. Then you can define vec[0] = 2. Otherwise, if you define a 0 size vector, then you nedd to push_back to add value.
  // vector<int> vec(3); // size 3, initialize with 0 not like array
  // vector<int> vec(3, 7); // initialize with 7
  // vec.push_back(18);     // vec size become 4
  // auto it = vec.begin();
  // vec.insert(it + 1, 9); // add 9 in position 1 like vec become 7, 9, 7, 7, 18
  // for (auto value : vec) // range based loop
  // {
  //     cout << value << " "; // 7, 9, 7, 7, 18
  // }
  // vec.clear(); // clear the vector
  // cout << vec.size() << endl; // 0 size
  // it++ --> jump to the next iterator but it+1 jump to the next location
  // vec.erase(it + 2); // erase element at index 2
  // vec.erase(it + 2, it + 4); // erase element at index 2 to index 3, not including 4
  // vec.front() = 12; // return the reference to the first element. First element value change to 12
  // vector<vector<int>> vec(5, vector<int>(6, 3)); // The values of a vector of vectors is a vector. So, when we initialize a vector, we first define its size then initialize with a value. Same here, we define a size 5 and initialize with a vector of size 6 and value 3.

  // pair<int, string> p = {1, "Rahul"};
  // pair<int, string> p(1, "Subhajit"); // initialization with constructor
  // pair<int, string> p;
  // p = {1, "Rahul"};
  // p = make_pair(1, "Rahul");
  // pair<int, string> &p1 = p; // copy by reference not by value
  // cout << p.first << " " << p.second;

  // map<int, string> m = {{1, "Rahul"}, {2, "Subhajit"}};
  // m[1] = "Ananda";
  // cout << m[1] << " " << m[2] << endl;
  // for (auto it = m.begin(); it != m.end(); it++)
  // {
  //     cout << it->first << " " << it->second << endl;
  // }
  // m.insert({3, "Ananda"});
  // m.insert(pair<int, string>(4, "Sankha")); // Both methods of insert
  // for (auto value : m)
  // {
  //     cout << value.first << " " << value.second << endl;
  // }
  // auto it = m.find(3);
  // if (it != m.end())
  { // find return the iterator of the elem if present otherwise return end();
    // m.erase(it);
  }
  // cout << m.count(2) << endl; // return the count of the key. Because map has unique keys, so if key present return 1 otherwise 0

  // multiset<int> m_s;
  // m_s.insert(1);
  // m_s.insert(1);
  // cout << m_s.count(1) << endl;

  // We can not make unordered_map or unordered_set of complex data types
  // like unordered_set<pair<int, int> > <-- we can't make
}