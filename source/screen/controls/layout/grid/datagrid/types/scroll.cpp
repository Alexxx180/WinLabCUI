#include "screen/controls/layout/grid/datagrid/types/scroll.h"

#include "screen/controls/matrix/pen.h"
#include "task/forms/defaults/debug.h"

void Set(const Page& page) {
    m_page.Set(page);
    m_bottom = page.Split();
}

void Update(long next) {
    m_current = next;
    m_records = m_current * m_page.Relative;
}

void Scroll :: Home() { Update(Top); }

void Scroll :: End() { Update(m_bottom - First); }

void Scroll :: Count() {
    Pen::ink().Clip("status_pages");
    Pen::ink().Text(First + m_current, L" / ", m_bottom);
}

void Scroll :: Length() {
    Pen::ink().Text(m_records, L" / ", m_page.Absolute);
}

void Scroll :: Down() {
    long last = m_bottom - First;
    long next = m_current + page_listing;
    m_isBottom = next > last;
    Update(m_isBottom ? last : next);
}

void Scroll :: Up() {
    long next = m_current - page_listing;
    m_isTop = next < Top;
    Update(m_isTop ? Top : next);
}
