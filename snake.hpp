#ifndef SNAKE_HPP
#define SNAKE_HPP

#define HEAD_SIZE 40

class Snake{
    public:

        Snake();
        ~Snake();
        void move(int direction);
        void print();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        int setcolor();
        int getcolorR();
        int getcolorG();
        int getcolorB();

    private:

        int posX = 300;
        int posY = 300;
        int direction = 0;
        int colorR = 0;
        int colorG = 0;
        int colorB = 0;
};
 
#endif
