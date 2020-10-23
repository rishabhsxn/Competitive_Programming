#include<iostream>

using namespace std; 

bool isAutoBiographyNum(string number) 
{ 
	int count = 0, position, size, digit; 

	size = number.length(); 

	for (int i = 0; i < size; i++) { 
		position = number[i] - '0'; 
		count = 0; 
 
		for (int j = 0; j < size; j++) { 
			digit = number[j] - '0'; 
			if (digit == i) 
				count++; 
		} 

		if (position != count) 
			return false; 
	} 

	return true; 
}

int CountUniqueCharacters(string str){
    int count = 0;

    for (int i = 0; i <str.length(); i++){
         bool appears = false;
         for (int j = 0; j < i; j++){
              if (str[j] == str[i]){
                  appears = true;
                  break;
              }
         }

         if (!appears){
             count++;
         }
    }

    return count;
}

int findAutoCount(string s){
    if(!isAutoBiographyNum(s))
        return 0;
    
    return CountUniqueCharacters(s);

}


int main() 
{ 
    string s;
    getline(cin, s);

    cout << findAutoCount(s) << endl;

	return 0; 
} 
