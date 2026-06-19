#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    int i, j;
    i = 0;
    j = s.size() - 1;

    while (i < j)
    {
        // 1. Handle non-alphanumeric character on the left
        if (!isalnum(static_cast<unsigned char>(s[i])))
        {
            cout << "Skipping left: " << s[i] << endl;
            i++;
            continue; // Immediately start the next loop iteration
        }

        // 2. Handle non-alphanumeric character on the right
        if (!isalnum(static_cast<unsigned char>(s[j])))
        {
            cout << "Skipping right: " << s[j] << endl; // Fixed s[i] to s[j]
            j--;
            continue; // Immediately start the next loop iteration
        }

        // 3. Both are now verified alphanumeric. Compare them case-insensitively.
        if (tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j])))
        {
            return false;
        }

        // 4. Move both pointers inward only after a successful comparison
        i++;
        j--;
    }

    return true;
}

int main()
{

    string s = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);

    cout << "Result : " << result << endl;

    return 0;
}