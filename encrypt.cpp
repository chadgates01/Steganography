#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream image;
    ifstream plainText;
    ofstream newImage;
    plainText.open("plainText.txt");
    image.open("image.ppm");
    newImage.open("encryptedImage.ppm");
    
    char ch;
    string pixelValue = "";
    int newLine = 1;



    if(image.is_open())
    {
        //copy the header info
        string type="", height="", width="", RGB="";
        
        image>>type;
        image>>width;
        image>>height;
        image>>RGB;

        // newImage<<type<<width<<height<<RGB;

        newImage<<type<<endl;
        newImage<<width<<" "<<height<<endl;
        newImage<<RGB<<endl;
        
        while(plainText.get(ch))
        {
            bitset<8> charBinary(ch);

            for(int i=7; i>=0; i--)
            {
                image>>pixelValue;
                if(charBinary.test(i) == 0)
                {
                    newImage<<to_string(stoi(pixelValue)&254)<<" ";
                }
                else
                {
                    // newImage<<to_string(stoi(pixelValue)-1)<<" ";
                    newImage<<to_string(stoi(pixelValue)|1)<<" ";
                }
                newLine++;
                if(newLine>3)
                {
                    newLine = 1;
                    newImage<<endl;
                }
            }
            if(!plainText.eof())
            {
                image>>pixelValue;
                newImage << to_string(stoi(pixelValue) & 254) <<" ";
                newLine++;
            }
            else
            {
                image>>pixelValue;
                newImage << to_string(stoi(pixelValue) | 1) <<" ";
                newLine++;
            }
            if(newLine>3)
            {
                newLine = 1;
                newImage<<endl;
            }
        }

        // while(!image.eof())
        // {
        //     image>>pixelValue;
        //     newImage<<pixelValue<<" ";
        //     newLine++;
        //     if(newLine>3)
        //     {
        //         newLine = 1;
        //         newImage<<endl;
        //     }
        // }
        while(getline(image, pixelValue))
        {
            newImage<<pixelValue<<endl;
        }
    }

    plainText.close();
    image.close();
    newImage.close();

    return 0;
}