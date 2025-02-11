#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream image;
    image.open("image.ppm");
    
    if(image.is_open())
    {
        //placing the header info
        image<<"P3"<<endl;
        image<<"250 250"<<endl;
        image<<"255"<<endl;
        
        for(int i=0; i<250; i++)
        {
            for(int j=0; j<250; j++)
            {
                image<<(i*j)%255<<" "<<(i*j)%255<<" "<<(i*j)%255<<endl;
            }
        }
    }

    image.close();
    return 0;
}