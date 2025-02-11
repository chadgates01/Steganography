#include<bits/stdc++.h>
using namespace std;

char binaryToASCII(string bits)
{
    int val = 0;
    for(int i=bits.length()-1;i>=0;i--)
    {
        val = (val << 1) + (bits[i] - '0');
    }
    return (char)val;
}

int main()
{
    ifstream encImage;
    ofstream encPlainText;
    cout<<"1";
    // encPlainText.open("encPlainText.txt");
    encImage.open("encryptedImage.ppm");
    
    cout<<"1";

    char ch;
    string pixelValue = "";

    cout<<"1";

    if(!encImage.is_open())
    {
        cout<<"Error while opening file";
        return 1;
        
    }
    //copy the header info
    string type="", height="", width="", RGB="";
        
    getline(encImage, type);
    getline(encImage, width);
    // getline(encImage, height);
    getline(encImage, RGB);

    // int count = 1;
    string line;
    string text="";
    
    while(1)
    {
        string pixelValue;
        string binary = "";
        for(int i =0;i<8;i++){
            encImage>>pixelValue;
            int pixel = stoi(pixelValue);
            binary += to_string(pixel & 1);
        }
        encImage>>pixelValue;
        int pixel = stoi(pixelValue);
        text+= binaryToASCII(binary);
        if(pixel & 1){
            break;
        }
    }

    cout<<text<<endl;

    // plainText.close();
    encImage.close();
    encPlainText.open("encPlainText.txt");
    // encImage.close();

    return 0;
}
