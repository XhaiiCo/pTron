#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "vector"
#include "Case.h"

class Playground
{
    private:
        const inline static int NB_COLUMN = 10 ;
        const inline static int NB_LINE = 10 ;

        std::vector<std::vector<Case*>> cases ;

    public:
        Playground();
        virtual ~Playground();
        Playground(const Playground& other);
        Playground& operator=(const Playground& other);

        void init() ;
        void createCase() ;

        std::string str() const ;
};

#endif // PLAYGROUND_H
