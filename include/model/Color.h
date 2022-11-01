#ifndef COLOR_H
#define COLOR_H


class Color
{
    private:
        int red ;
        int green ;
        int blue ;

    public:
        Color(int red = 0, int green = 0, int blue = 0);
        virtual ~Color();
        Color(const Color& other);
        Color& operator=(const Color& other);

        bool validColor(int value) ;

        bool setRed(int value) ;
        bool setGreen(int value) ;
        bool setBlue(int value) ;

        int getRed(){ return this->red ;}
        int getGreen(){ return this->green ;}
        int getBlue(){ return this->blue ;}



};

#endif // COLOR_H
