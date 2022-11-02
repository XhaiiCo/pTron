#ifndef COLOR_H
#define COLOR_H

//This class represents a color
class Color
{
    private:
        //RGB value
        int red ;
        int green ;
        int blue ;

    public:
        Color(int red = 0, int green = 0, int blue = 0);
        virtual ~Color();
        Color(const Color& other);
        Color& operator=(const Color& other);

        //This method valid that the color value is between 0 and 255
        bool validColor(int value) ;

        //Setters
        bool setRed(int value) ;
        bool setGreen(int value) ;
        bool setBlue(int value) ;

        //Getters
        int getRed(){ return this->red ;}
        int getGreen(){ return this->green ;}
        int getBlue(){ return this->blue ;}



};

#endif // COLOR_H
