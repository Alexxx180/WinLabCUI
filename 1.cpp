#ifndef SCREEN_INTERACTION_NAVIGATION
#define SCREEN_INTERACTION_NAVIGATION

class Navigation {
    protected:
        virtual char Input() = 0;

        char Action();
        void Previous();
        void Next();
        void Climb();
        void Slide();
        void First();
        void Last();

    public:
        virtual void Draw() = 0;
        char Query();
        short Choice();
};

#endif
