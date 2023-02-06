// C++ implementation to find the
// length of longest palindromic
// sub-string using Recursion

#include <iostream>
using namespace std;

// Function to find maximum
// of the two variables
int max(int x, int y)
{
	return (x > y) ? x : y;
}

// Function to find the longest
// palindromic substring : Recursion
int longestPalindromic(string str,
			int i, int j, int count)
{
	
	// Base condition when the start
	// index is greater than end index
	if (i > j)
		return count;
	
	// Base condition when both the
	// start and end index are equal
	if (i == j)
		return (count + 1);
		
	// Condition when corner characters
	// are equal in the string
	if (str[i] == str[j]) {
		
		// Recursive call to find the
		// longest Palindromic string
		// by excluding the corner characters
		count = longestPalindromic(str, i + 1,
				j - 1, count + 2);
		return max(count,
		max(longestPalindromic(str, i + 1, j, 0),
		longestPalindromic(str, i, j - 1, 0)));
	}
	
	// Recursive call to find the
	// longest Palindromic string
	// by including one corner
	// character at a time
	return max(
	longestPalindromic(str, i + 1, j, 0),
	longestPalindromic(str, i, j - 1, 0));
}

// Function to find the longest
// palindromic sub-string
int longest_palindromic_substr(string str)
{
	// Utility function call
	return longestPalindromic(str, 0,
				str.length() - 1, 0);
}

// Driver Code
int main()
{
	string str = "aaaabbaa";
	
	// Function Call
	cout << longest_palindromic_substr(str);
	return 0;
}
