#include "screen/controls/layout/grid/datagrid/types/table.h"

void Table :: Scroll() {
    m_end = ++m_record < Pages.Enumeration.Relative;
}

void Table :: Set(const Page& records) { Pages.Set(records); }

void Table :: Progress() {
    if (page_character_results) Pages.Length(); else Pages.Count();
}

void Table :: Anchor() { m_record = Pages.Records; }

void Table :: Home() { Pages.Home(); }

void Table :: End() { Pages.End(); }

void Table :: Down() { Pages.Down(); }

void Table :: Up() { Pages.Up(); }
