#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream encImage;
    ofstream encPlainText;
    encPlainText.open("encPlainText.txt");
    encImage.open("encryptionImage.ppm");
    
    char ch;
    string pixelValue = "";
    int newLine = 1;



    if(encImage.is_open())
    {
        //copy the header info
        string type="", height="", width="", RGB="";
        
        encImage>>type;
        encImage>>width;
        encImage>>height;
        encImage>>RGB;

        int count = 1;
        
        while(1)
        {
            bitset<8> charBinary(0);
            if(count == 9)
            {
                encImage>>pixelValue;
                if(stoi(pixelValue) % 2 == 1)
                {
                    break;
                }
                count = 1;
                continue;
            }
            for(int i=7; i>=0; i--)
            {
                encImage>>pixelValue;
                if(stoi(pixelValue) % 2 == 1)
                {
                    charBinary.set(i);
                }
            }

            char ch = (char)(charBinary.to_ulong());
            cout<<ch;
            count++;
            // {
            //     encImage<<to_string(stoi(pixelValue)&254)<<" ";
            // }
            //     else
            //     {
                    // encImage<<to_string(stoi(pixelValue)-1)<<" ";
            //         encImage<<to_string(stoi(pixelValue)|1)<<" ";
            //     }
            //     newLine++;
            //     if(newLine>3)
            //     {
            //         newLine = 1;
            //         encImage<<endl;
            //     }
            // }
        //     if(!plainText.eof())
        //     {
        //         encImage>>pixelValue;
        //         encImage << to_string(stoi(pixelValue) & 254) <<" ";
        //         newLine++;
        //     }
        //     else
        //     {
        //         encImage>>pixelValue;
        //         encImage << to_string(stoi(pixelValue) | 1) <<" ";
        //         newLine++;
        //     }
        //     if(newLine>3)
        //     {
        //         newLine = 1;
        //         encImage<<endl;
        //     }
        // }

        // while(!encImage.eof())
        // {
        //     encImage>>pixelValue;
        //     encImage<<pixelValue<<" ";
        //     newLine++;
        //     if(newLine>3)
        //     {
        //         newLine = 1;
        //         encImage<<endl;
        //     }
        // }
        // while(getline(encImage, pixelValue))
        // {
        //     encImage<<pixelValue<<endl;
        // }
        }
    }

    // plainText.close();
    encImage.close();
    encPlainText.open("encPlainText.txt");
    // encImage.close();

    return 0;
}