#ifndef INPUT_TYPER
#define INPUT_TYPER

class Typer {
public:
    virtual bool IsVerified() = 0;
    virtual void TypeInput() = 0;
    virtual ~Typer() { }
};

#endif
