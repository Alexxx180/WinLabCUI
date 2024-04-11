#include "screen/controls/layout/grid/datagrid/types/scroll.h"

#include "screen/controls/matrix/pen.h"
#include "task/forms/defaults/debug.h"

void Scroll :: Set(const Page& page) {
    m_page.Set(page);
    m_last = m_page.Split() - First;
}

void Scroll :: Reload(long value) {
    m_isBottom = value >= Last;
    m_isTop = value <= Top;
}

void Scroll :: Update(long next) {
    m_current = next;
    m_records = m_current * m_page.Relative;
}

void Scroll :: Home() {
    Reload(Top);
    Update(Top);
}

void Scroll :: End() {
    Reload(Last);
    Update(Last);
}

void Scroll :: Down() {
    long next = m_current + page_listing;
    Reload(next);
    Update(m_isBottom ? Last : next);
}

void Scroll :: Up() {
    long prev = m_current - page_listing;
    Reload(prev);
    Update(m_isTop ? Top : prev);
}

void Scroll :: Count() {
    Pen::ink().Clip("status_pages");
    Pen::ink().Text(First + m_current, L" / ", First + m_last);
}

void Scroll :: Length() {
    Pen::ink().Text(m_records, L" / ", m_page.Absolute);
}
