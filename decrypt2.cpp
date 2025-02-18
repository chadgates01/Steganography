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

    // encPlainText.open("encPlainText.txt");
    encImage.open("encryptedImage.ppm");
    

    char ch;
    string pixelValue = "";


    if(!encImage.is_open())
    {
        cout<<"Error while opening file";
        return 1;
        
    }
    //copy the header info
    string type="", dimensions="", RGB="";
        
    getline(encImage, type);
    getline(encImage, dimensions);
    // getline(encImage, height);
    getline(encImage, RGB);

    // int count = 1;
    string line;
    string text="";
    
    while(1)
    {
        string pixelValue;
        string binary = "";
        for(int i=0;i<8;i++){
            encImage>>pixelValue;
            int pixel = stoi(pixelValue);
            binary += to_string(pixel & 1);
        }
        encImage>>pixelValue;
        int pixel = stoi(pixelValue);
        if(pixel & 1){
            break;
        }
        text+= binaryToASCII(binary);
    }

    cout<<text<<endl;

    // plainText.close();
    encImage.close();
    encPlainText.open("encPlainText.txt");
    // encImage.close();

    return 0;
}
