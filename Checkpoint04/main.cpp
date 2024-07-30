// -------------------------------------------
// CIS2542 - Checkpoint 4 - Vectors and Deques
// -------------------------------------------
#include <iomanip>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
// NOTE - You can add any extra STL library file you need here

// -----------------------------------------------------------------
// NAME     - HiMyNameIs
// INPUT    - None!
// OUTPUT   - Your real name somewhere contained in a string
// -----------------------------------------------------------------
std::string HiMyNameIs()
{
    // BEHAVIOR - Return your name as a string
    // NOTE     - All the cool kids are centering their strings these days
    return "         Aniket         ";
}

// -----------------------------------------------------------------
// NAME     - EraseLargestElementFrom
// INPUT    - The VECTOR to remove the largest element from
// OUTPUT   - None!
// -----------------------------------------------------------------
void EraseLargestElementFrom(std::vector<int>& v)
{
    // BEHAVIOR - Find the largest element and remove it from the vector
    //            If the vector is empty, just don't do anything at all
    // NOTE     - ALWAYS think STL!
    
    if (!v.empty())
    {
        std::vector<int>::const_iterator iter = std::max_element(v.begin(), v.end());
        v.erase(iter);
    }
}

// -----------------------------------------------------------------
// NAME     - EraseLargestElementFrom
// INPUT    - The DEQUE to remove the largest element from
// OUTPUT   - None!
// -----------------------------------------------------------------
void EraseLargestElementFrom(std::deque<int>& d)
{
    // BEHAVIOR - Find the largest element and remove it from the deque
    //            If the deque is empty, just don't do anything at all
    // NOTE     - ALWAYS think STL!
    if (!d.empty())
    {
        std::deque<int>::const_iterator iter = std::max_element(d.begin(), d.end());
        d.erase(iter);
    }
}

// -----------------------------------------------------------------
// NAME     - PushBackInto
// INPUTS   - The VECTOR to add VALUE to the back of
// OUTPUT   - None!
// -----------------------------------------------------------------
void PushBackInto(std::vector<int>& v, int value)
{
    // BEHAVIOR - Insert the value into the vector at the back
    v.push_back(value);
}

// -----------------------------------------------------------------
// NAME     - PushBackInto
// INPUTS   - The DEQUE to add VALUE to the back of
// OUTPUT   - None!
// -----------------------------------------------------------------
void PushBackInto(std::deque<int>& d, int value)
{
    // BEHAVIOR - Insert the value into the deque at the back
    d.push_back(value);
}

// -----------------------------------------------------------------
// NAME     - PushFrontInto
// INPUTS   - The VECTOR to add VALUE to the front of
// OUTPUT   - None!
// -----------------------------------------------------------------
void PushFrontInto(std::vector<int>& v, int value)
{
    // BEHAVIOR - Insert the value into the vector at the front
    v.insert(v.begin(), value);
}

// -----------------------------------------------------------------
// NAME     - PushFrontInto
// INPUTS   - The DEQUE to add VALUE to the front of
// OUTPUT   - None!
// -----------------------------------------------------------------
void PushFrontInto(std::deque<int>& d, int value)
{
    // BEHAVIOR - Insert the value into the deque at the front
    d.push_front(value);
}


// -----------------------------------------------
// PLEASE DON'T MODIFY ANYTHING UNDER THIS MESSAGE
// -----------------------------------------------

void IsThereAnErrorInYourCode(bool correct, int testNo, const std::string& s)
{
    std::cout << "TEST CASE" << std::setw(3) << testNo << " - ";
    if (correct == true)
        std::cout << "PASS" << std::endl;
    else
        std::cout << "ERROR - " << s << std::endl;
}

int main()
{
    std::cout << "------------------------" << std::endl;
    std::cout << ((HiMyNameIs() == "") ? "      Slim Shady?" : HiMyNameIs());
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "    PART ONE TESTING    " << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "     60 TOTAL POINTS    " << std::endl;
    std::cout << "   6 POINTS DEDUCTION   " << std::endl;
    std::cout << "        PER ERROR       " << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "     VECTOR TESTING     " << std::endl;
    std::cout << "------------------------" << std::endl;

    std::vector<int> v;
    IsThereAnErrorInYourCode(v.empty() == true, 1, "VECTOR SHOULD BE EMPTY");
    EraseLargestElementFrom(v);
    IsThereAnErrorInYourCode(v.empty() == true, 2, "VECTOR SHOULD BE EMPTY");
    v = { 1 };
    EraseLargestElementFrom(v);
    IsThereAnErrorInYourCode(v.empty() == true, 3, "VECTOR SHOULD BE EMPTY");
    v = { 1, 4 };
    EraseLargestElementFrom(v);
    IsThereAnErrorInYourCode(v == std::vector<int>{1}, 4, "VECTOR SHOULD BE {1}");
    v = { 5, 1, 4 };
    EraseLargestElementFrom(v);
    IsThereAnErrorInYourCode(v == std::vector<int>{1, 4}, 5, "VECTOR SHOULD BE {1, 4}");
    v = { 1, 4 };
    PushBackInto(v, 9);
    IsThereAnErrorInYourCode(v == std::vector<int>{1, 4, 9}, 6, "VECTOR SHOULD BE {1, 4, 9}");
    v = { 1, 4, 9 };
    PushFrontInto(v, 7);
    IsThereAnErrorInYourCode(v == std::vector<int>{7, 1, 4, 9}, 7, "VECTOR SHOULD BE {7, 1, 4, 9}");

    std::cout << "------------------------" << std::endl;
    std::cout << "      DEQUE TESTING     " << std::endl;
    std::cout << "------------------------" << std::endl;

    std::deque<int> d;
    IsThereAnErrorInYourCode(d.empty() == true, 8, "DEQUE SHOULD BE EMPTY");
    EraseLargestElementFrom(d);
    IsThereAnErrorInYourCode(d.empty() == true, 9, "DEQUE SHOULD BE EMPTY");
    d = { 1 };
    EraseLargestElementFrom(d);
    IsThereAnErrorInYourCode(d.empty() == true, 10, "DEQUE SHOULD BE EMPTY");
    d = { 1, 4 };
    EraseLargestElementFrom(d);
    IsThereAnErrorInYourCode(d == std::deque<int>{1}, 11, "DEQUE SHOULD BE {1}");
    d = { 5, 1, 4 };
    EraseLargestElementFrom(d);
    IsThereAnErrorInYourCode(d == std::deque<int>{1, 4}, 12, "DEQUE SHOULD BE {1, 4}");
    d = { 1, 4 };
    PushBackInto(d, 9);
    IsThereAnErrorInYourCode(d == std::deque<int>{1, 4, 9}, 13, "DEQUE SHOULD BE {1, 4, 9}");
    d = { 1, 4, 9 };
    PushFrontInto(d, 7);
    IsThereAnErrorInYourCode(d == std::deque<int>{7, 1, 4, 9}, 14, "DEQUE SHOULD BE {7, 1, 4, 9}");

    std::cout << "------------------------" << std::endl;
    std::cout << "IF THERE ARE NO ERROR MESSAGES ABOVE, ";
    std::cout << "THEN YOUR CODE APPEARS TO WORK AS EXPECTED!" << std::endl;
    std::cout << "------------------------" << std::endl;

    return 0;
}
