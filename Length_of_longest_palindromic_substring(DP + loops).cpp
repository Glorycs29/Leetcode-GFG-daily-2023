// A C++ dynamic programming
// solution for longest palindrome

#include <bits/stdc++.h>
using namespace std;

// Function to print a substring
// str[low..high]
void printSubStr(
	string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length of
// the longest palindrome
int longestPalSubstr(string str)
{
	// get length of input string
	int n = str.size();

	// table[i][j] will be false if substring
	// str[i..j] is not palindrome.
	// Else table[i][j] will be true
	bool table[n][n];

	memset(table, 0, sizeof(table));

	// All substrings of length 1
	// are palindromes
	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	// Check for lengths greater than 2.
	// k is length of substring
	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to
			// jth index if str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	// return length of LPS
	return maxLength;
}

// Driver Code
int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: "
		<< longestPalSubstr(str);
	return 0;
}




//METHOD 3: Using loops

//APPROACH: First we will run a loop for iterating every character. Then we will run another loop inside it to check that is there any other character similar to the current character. If it is, then it is possible that they both are first and last character of longest substring. We will store that substring and check whether that substring is longest or not. If yes then we will store that substring and keep iterating.


// A C++ solution for longest palindrome
#include <bits/stdc++.h>
using namespace std;
// This function prints the
// longest palindrome substring
// It also returns the length
// of the longest palindrome
int longestPalSubstr(string str)
{
    //Stores Longest Pallidrome Substring
    string longest = "";
    int n = str.length();
    int j;
    //To store substring which we think can be a pallindrome
    string subs = "";
    //To strore reverse of substring we think can be pallidrome
    string subsrev = "";
    for(int i = 0; i < n; i++){
        j = n-1;
        while(i < j){
            //Checking whether the character at i and j are same. If they are same then that substring can be LPS
            if((str[i] == str[j]) && (longest.length() < (j-i+1))){
               subs = str.substr(i,(j-i+1));
               //cout<<subs<<" ";
               subsrev = subs;
               reverse(subsrev.begin(), subsrev.end());
               if(subs == subsrev){
                  longest = subs;
               }
            }
            j--;
        }
    }
   //If no longest substring then we will return first character(In Leetcode it was a testcase so...)
    if(longest.length() == 0){
        longest = str[0];
    }
    cout << "Longest palindrome substring is: " << longest;
 
    // return length of LPS
    return longest.length();
}
 
// Driver Code
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
        << longestPalSubstr(str);
    return 0;
}
