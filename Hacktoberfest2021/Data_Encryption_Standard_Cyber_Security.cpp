#include <bits/stdc++.h>
using namespace std;
string hex2bin(string s)
{
    // hexadecimal to binary conversion
    unordered_map<char, string> mp;
    mp['0'] = "0000";
    mp['1'] = "0001";
    mp['2'] = "0010";
    mp['3'] = "0011";
    mp['4'] = "0100";
    mp['5'] = "0101";
    mp['6'] = "0110";
    mp['7'] = "0111";
    mp['8'] = "1000";
    mp['9'] = "1001";
    mp['A'] = "1010";
    mp['B'] = "1011";
    mp['C'] = "1100";
    mp['D'] = "1101";
    mp['E'] = "1110";
    mp['F'] = "1111";
    string bin = "";
    for (int i = 0; i < s.size(); i++) {
        bin += mp[s[i]];
    }
    return bin;
}
string bin2hex(string s)
{
    // binary to hexadecimal conversion
    unordered_map<string, string> mp;
    mp["0000"] = "0";
    mp["0001"] = "1";
    mp["0010"] = "2";
    mp["0011"] = "3";
    mp["0100"] = "4";
    mp["0101"] = "5";
    mp["0110"] = "6";
    mp["0111"] = "7";
    mp["1000"] = "8";
    mp["1001"] = "9";
    mp["1010"] = "A";
    mp["1011"] = "B";
    mp["1100"] = "C";
    mp["1101"] = "D";
    mp["1110"] = "E";
    mp["1111"] = "F";
    string hex = "";
    for (int i = 0; i < s.length(); i += 4) {
        string ch = "";
        ch += s[i];
        ch += s[i + 1];
        ch += s[i + 2];
        ch += s[i + 3];
        hex += mp[ch];
    }
    return hex;
}
string pc1_keyplus(string s)
{
    int pc_1[56] = { 57, 49, 41, 33, 25, 17, 9,
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36,
                     63, 55, 47, 39, 31, 23, 15,
                     7, 62, 54, 46, 38, 30, 22,
                     14, 6, 61, 53, 45, 37, 29,
                     21, 13, 5, 28, 20, 12, 4 };

    string key_bin_plus="";
    for(int i=0;i<56;i++)
    {
        key_bin_plus+=s[pc_1[i]-1];
    }
    return key_bin_plus;
}
string shift_left(string k, int shifts)
{
    string s = "";
    for (int i = 0; i < shifts; i++) {
        for (int j = 1; j < 28; j++) {
            s += k[j];
        }
        s += k[0];
        k = s;
        s = "";
    }
    return k;
}
void display(string s)
{
    for(int i=0;i<s.size();i++)
    {
        if(i%7==0)
            cout<<" ";
        cout<<s[i];
    }
    cout<<endl<<endl;
}
string pc2_Key(string s)
{
    int pc_2[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };
    string key_bin_48="";
    for(int i=0;i<48;i++)
    {
        key_bin_48+=s[pc_2[i]-1];
    }
    return key_bin_48;
}
int main()
{

    string key,key_bin,key_bin_plus,Final_key;
    cout<<"Insert key: ";
    cin>>key;

    cout<<"\nKey converted into binary: ";
    key_bin=hex2bin(key);
    for(int i=0;i<key_bin.size();i++)
    {
        if(i%8==0)
            cout<<" ";
        cout<<key_bin[i];
    }
    cout<<endl<<endl;


    cout<<"Key converted into 56-bit key K+ using PC-1: ";
    key_bin_plus=pc1_keyplus(key_bin);
    display(key_bin_plus);

    string C[4],D[4];

    C[4]="",D[4]="";

    for(int i=0;i<key_bin_plus.size();i++)
    {
        if(i<key_bin_plus.size()/2)
            C[0]+=key_bin_plus[i];
        else
            D[0]+=key_bin_plus[i];
    }

    cout<<"C0: ";
    display(C[0]);
    cout<<"D0: ";
    display(D[0]);

    int no_of_shifts[16]={1,1,2,2,
                        2,2,2,2,
                        1,2,2,2,
                        2,2,2,1};

    C[1]=shift_left(C[0],no_of_shifts[1]);
    D[1]=shift_left(D[0],no_of_shifts[1]);

    cout<<"C1: ";
    display(C[1]);
    cout<<"D1: ";
    display(D[1]);

    C[2]=shift_left(C[1],no_of_shifts[1]);
    D[2]=shift_left(D[1],no_of_shifts[1]);

    cout<<"C2: ";
    display(C[2]);
    cout<<"D2: ";
    display(D[2]);

    C[3]=shift_left(C[2],no_of_shifts[2]);
    D[3]=shift_left(D[2],no_of_shifts[2]);

    cout<<"C3: ";
    display(C[3]);
    cout<<"D3: ";
    display(D[3]);

    string k1;
    k1=pc2_Key(C[1]+D[1]);
    cout<<"48-bit key K1 using permutation PC-2: "<<k1<<endl;
    return 0;
}
