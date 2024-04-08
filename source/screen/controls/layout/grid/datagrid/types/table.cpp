#include "screen/controls/layout/grid/datagrid/types/table.h"
#include "task/forms/defaults/debug.h"

void Table :: Update(uint next) {
    m_record = next;
    m_end = m_record >= m_pages.Enumeration.Absolute || 
        m_record - m_pages.Records >= m_pages.Enumeration.Relative;
}

void Table :: Scroll() { Update(m_record + 1); }

void Table :: Anchor() { Update(m_pages.Records); }

void Table :: Set(const Page& records) { m_pages.Set(records); }

void Table :: Progress() {
    if (page_character_results)
        m_pages.Length();
    else
        m_pages.Count();
}

void Table :: Home() { m_pages.Home(); }

void Table :: End() { m_pages.End(); }

void Table :: Down() { m_pages.Down(); }

void Table :: Up() { m_pages.Up(); }
