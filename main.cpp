#include <iostream>

class window;

class coord
{
private:
    int x;
    int y;
public:
    coord()
    {
        x=0;
        y=0;
    }

    coord(int x, int y)
    {
        if(x>=0&&x<80&&y>=0&&y<50)
        {
            this->x = x;
            this->y=y;
        }
        else
        {
            this->x=0;
            this->y=0;
        }
    }

    void setX(int x)
    {
        if(x>=0&&x<80)
            this->x=x;
    }

    void setY(int y)
    {
        if(y>=0&&y<50)
            this->y=y;
    }

    friend class window;
};

class window
{
private:
    coord windowPos;
    int width, length;

public:
    window()
    {
        windowPos=coord(2,2);
        width=5;
        length=5;
    }

    window(coord Pos, int width, int length)
    {
        if((Pos.x+width)<80&&(Pos.y+length)<50)
        {
            this->length=length;
            this->width=width;
            this->windowPos=Pos;
        }
        else
            window();

    }

    bool isInsideWindow(int x, int y)
    {
        return x>=windowPos.x && x<(windowPos.x+width) && y>=windowPos.y && y<(windowPos.y+length);
    }

    void resize(int width, int length)
    {
        if((windowPos.x+width)<80&&(windowPos.y+length)<50)
        {
            this->width=width;
            this->length=length;
        }
    }

    void move(int x, int y)
    {
        if((x+width<80)&&(y+length<50))
        {
            windowPos.setX(x);
            windowPos.setY(y);
        }
    }

    void display()
    {
        for(int y=0;y<50;y++)
        {
            for (int x = 0; x < 80; x++) {
                if (this->isInsideWindow(x, y))
                    std::cout << "1";
                else
                    std::cout << "0";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    //std::cout << "Hello, World!" << std::endl;

    window test;
    std::string input;
    int x,y;

    do
    {
        std::cout << "Input command: ";
        std::cin >> input;
        if(input=="move")
        {
            std::cout << "Input new coords for the window: ";
            std::cin >> x >> y;
            test.move(x, y);
        }
        else if(input=="resize")
        {
            std::cout << "Input new size of the window: ";
            std::cin >> x >> y;
            test.resize(x, y);
        }
        else if(input=="display")
        {
            test.display();
        }

    }
    while(input!="close");

    return 0;
}
