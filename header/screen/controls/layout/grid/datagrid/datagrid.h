#ifndef SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_DATAGRID
#define SCREEN_CONTROLS_LAYOUT_GRID_DATAGRID_DATAGRID

#include "screen/controls/layout/grid/datagrid/types/table.h"
#include "screen/interaction/navigation.h"

class DataGrid : public Navigation {
    private:
        void (*m_update)(Table *grid);

    protected:
        char Input();
        char Action();

        void Next();
        void Previous();
        void First();
        void Last();
        void Climb();
        void Slide();

    public:
        Table table;

        void SetView(void (*update)(Table *grid));
        void OutputControls();
        void Draw();
        short Choice();
};

#endif
