#ifndef SCREEN_MATRIX_TOOLS_LAYER_LAYER
#define SCREEN_MATRIX_TOOLS_LAYER_LAYER

#include "screen/matrix/tools/layer/fragment.h"
#include "screen/controls/matrix/screen.h"
#include "screen/controls/bar/bar.h"
#include "screen/controls/matrix/pen.h"
#include "screen/interaction/interaction.h"

struct Layer {
    Fragment<Grid> back;
    Fragment<Stencil> out;
    Fragment<Bar> status;
    byte TargetLayer;

    void Add(Screen* screen) {
        back.Add(screen->back);
        out.Add(screen->out);
    }

    Layer* Target(byte current) {
        TargetLayer = current;
        back.Target(current);
        out.Target(current);
        status.Target(current);
        return this;
    }

    // Writing output
    Layer* Clip(std::string name) {
        Pen::ink().Clip(name);
        return this;
    }
    
    template<typename TYPE>
    Layer* Bounds(Boundary<TYPE>& limits) {
        Pen::ink().Bounds(limits);
        return this;
    }

    template<typename TYPE>
    Layer* FBounds(const wchar_t* format, Boundary<TYPE>& limits) {
        Pen::ink().FBounds(format, limits);
        return this;
    }

    template <typename...args>
    Layer* Text(args... rest) {
        Pen::ink().Text(rest...);
        return this;
    }

    Layer* Typo(int position) {
        Jump()->Move();
        Pen::ink().Typo(position);
        Next();
        return Move()->Clear()->Line()->Move();
    }
    
    template<typename TYPE>
    Layer* FText(const wchar_t* format, TYPE argument) {
        Pen::ink().FText(format, argument);
        return this;
    }

    // Stencil forms
    /* Use
    
    Markdown: ..., ...
    
    Form(0)->Move()
    
      Sample    Text
      ▔
         Different   Text
    
    Form(1)->Move()
    
      Sample    Text
    
         Different   Text
         ▔
    */
    
    Layer* Form(byte form) {
        out.current->Form(form);
        return this;
    }

    Layer* Move() {
        out.current->Move();
        return this;
    }
    
    Layer* Clear() {
        out.current->Clear();
        return this;
    }
    
    Layer* Field() {
        out.current->Field();
        return this;
    }

    /*
    Stencil Pages Use
    
    Markdown: 2, 12
    
      Sample    Text
    ▔
    Page(0)->Move()
    
      Sample    Text
      ▔
    Flip(1)->Move()
    
      Sample    Text
                ▔
    */
    
    Layer* Span(byte columns) {
        out.current->Span(columns);
        return this;
    }
    
    Layer* Page(byte column) {
        out.current->Page(column);
        return this;
    }
    
    Layer* Flip(char direction) {
        out.current->Flip(direction);
        return this;
    }

    /* Stencil Lines Use
    
    Markdown: 0, 2
    
    Line(0)->Move()     ; Line(1)->Move()
    
      Sample  Text      ;  Sample  Text      
      ▔
      Different   Text  ;  Different   Text  
                           ▔
    Size(2)->Jump(1)->Move()
    
      Sample  Text
    
      Different   Text
      ▔
    Line()->Move()      ; Jump()->Move()
                           ▁
      Sample  Text      ;  Sample  Text      
      ▁
      Different   Text  ;  Different   Text  
    */
    
    Layer* Size(byte padding) {
        out.current->Size(padding);
        return this;
    }
    
    Layer* Line(char direction) {
        out.current->Line(direction);
        return this;
    }
    
    Layer* Line() {
        out.current->Line();
        return this;
    }
    
    Layer* Jump(char direction) {
        out.current->Jump(direction);
        return this;
    }
    
    Layer* Jump() {
        out.current->Jump();
        return this;
    }

    // Grid background
    Layer* ShowBack() {
        back.current->Show();
        return this;
    }

    Layer* Redraw() {
        char size = back.size();
        while (--size >= 0) back.at(size).Show();
        return this;
    }

    // Progress background
    Layer* ShowBar() {
        status.current->Show();
        return this;
    }
    
    Layer* Progress(float basis) {
        status.current->Progress(basis);
        return this;
    }
    
    Layer* ProgressData(float value) {
        status.current->ProgressData(value);
        return this;
    }
};

#endif
