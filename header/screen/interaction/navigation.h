#ifndef SCREEN_INTERACTION_NAVIGATION
#define SCREEN_INTERACTION_NAVIGATION

class Navigation {
    protected:
        virtual char Input() = 0;

        virtual char Action() = 0;
        virtual void Previous() = 0;
        virtual void Next() = 0;
        virtual void Climb() = 0;
        virtual void Slide() = 0;
        virtual void First() = 0;
        virtual void Last() = 0;

    public:
        virtual void Draw() = 0;
        virtual short Choice() = 0;
        char Query();
};

#endif
