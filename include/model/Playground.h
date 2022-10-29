#ifndef PLAYGROUND_H
#define PLAYGROUND_H


class Playground
{
    private:

    public:
        Playground();
        virtual ~Playground();
        Playground(const Playground& other);
        Playground& operator=(const Playground& other);
};

#endif // PLAYGROUND_H
