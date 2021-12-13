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

    static void resize(window current, int width, int length)
    {
        if((current.windowPos.x+width)<80&&(current.windowPos.y+length)<50)
        {
            current.width=width;
            current.length=length;
        }
    }

    static void move(window current, int x, int y)
    {
        if((x+current.width<80)&&(y+current.length<50))
        {
            current.windowPos.setX(x);
            current.windowPos.setY(y);
        }
    }

    static void display()
    {
        
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
