#ifndef SNAKE_HPP
#define SNAKE_HPP

class Snake{
    public:

        Snake();
        ~Snake();
        int move(int direction);
        void print();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();

    private:

        int posX = 400;
        int posY = 320;
        int direction = 0;

};
 
#endif
