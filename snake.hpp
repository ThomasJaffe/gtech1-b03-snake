#ifndef SNAKE_HPP
#define SNAKE_HPP

#define HEAD_SIZE 40

class Snake{
    public:

        Snake();
        ~Snake();
        void move(int direction);
        void print();

    private:

        int posX = 300;
        int posY = 300;
        int direction = 0;

};

#endif
