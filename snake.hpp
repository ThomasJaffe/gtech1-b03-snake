#ifndef SNAKE_HPP
#define SNAKE_HPP

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

    private:

        int posX = 300;
        int posY = 300;
        int direction = 0;

};
 
#endif
