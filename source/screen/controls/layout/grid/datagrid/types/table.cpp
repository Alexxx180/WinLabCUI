#include "screen/controls/layout/grid/datagrid/types/table.h"
#include "screen/matrix/pen.h"

void Table :: Update() {
    End = m_lines.Relative < m_records.Relative;
    Over = m_lines.Absolute < m_records.Absolute;
}

void Table :: Scroll() {
    m_lines.Iterate();
    Update();
}

void Table :: SetRecords(Page* records) {
    m_records.Set(records);
    Pages.Bottom = m_records.Split();
}

Page* Table :: GetLines() {
    return &m_lines;
}

void Table :: SetLines(Page* lines) {
    m_lines.Set(lines);
    Update();
}

void Table :: Length() {
    Pen::ink().Text(m_lines.Absolute);
    Pen::ink().Text(L" / ");
    Pen::ink().Text(m_records.Absolute);
}

void Table :: HomePage() {
    Pages.Home();
    m_lines.Home();
}

void Table :: EndPage() {
    Pages.End();
    m_lines.End(m_records.Absolute);
}

void Table :: Down() {
    if (Pages.Down())
        HomePage();
    else
        m_lines.Down(m_records.Absolute, m_records.Relative);
}

void Table :: Up() {
    if (Pages.Up())
        EndPage();
    else
        m_lines.Up(m_records.Relative);
}
