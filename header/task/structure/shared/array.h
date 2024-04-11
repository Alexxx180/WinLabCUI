#ifndef TASK_STRUCTURE_SHARED_ARRAY
#define TASK_STRUCTURE_SHARED_ARRAY

#include <vector>
#include <string>

#include "common/texts/format.h"
#include "screen/controls/layout/grid/datagrid/datagrid.h"
#include "screen/matrix/tools.h"
#include "screen/interaction/interaction.h"
#include "screen/interaction/lifetime/internal.h"
#include "screen/interaction/controller/keyboard.h"
#include "task/structure/output/sort/pages.h"

template<typename TYPE>
class SharedArray : public SharedPainter {
    private:
        void DrawCell(char parameter) {
            out->FText(NO4, parameter);
        }

        void DrawCell(std::wstring parameter) {
            out->Text(parameter, L" ");
        }

        void DrawRow(char line, std::vector<TYPE>& array, Table& table) {
            out->Line(line)->Move()->Clear()->Move();

            for (table.Anchor(); !table.IsEnd; table.Scroll()) {
                TYPE item = array.at(table.Record);
                DrawCell(item);
            }
        }

    public:
        std::vector<TYPE> original, sorted;

        void Duplicate() {
            sorted = original;
        }

        void Draw(Table& table) {
            DrawRow(0, original, table);
            DrawRow(1, sorted, table);
        }

        void Output() {
            Page records = { 10, original.size() };

            DataGrid model;
            model.table.Set(records);
            model.SetView(&DrawArray);

            out->ShowBack();
            out->Target(FOOT);
            out->Page(0)->Line(1)->Size(1)->Span(1);

            model.OutputControls();
            out->Page(0)->Line(1)->Move();

            out->Target(MAIN)->Page(1)->Line(0)->Move();
            model.Draw();

            char (DataGrid::*query)() = &DataGrid::Query;
            Await(&model, query, ESC);

            out->Page(0)->Line(3)->Span(3);
            out->Move()->Clear()->Line(0)->Move();

            out->Target(FOOT);
            model.ClearControls();
        }
};

#endif
