//return true if ransomNote can be constructed from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


bool ransom_note(string ransom, string magazine) {
        string ans="";
        for(int i=0;i<ransom.length();i++){
            for(int j=0;j<magazine.length();j++){
                if(ransom[i]==magazine[j]){
                    magazine.erase(magazine.begin()+j);
                    ans+=ransom[i];
                    break;
                }
            }
        }
        if(ans==ransom)
            return true;
        return false;
    }
int main(){
    string ransomNote,magazine;
    cout<<"Enter two string for ransom note: ";

    cin>>ransomNote;
    cin>>magazine;
    if(ransom_note(ransomNote,magazine))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
