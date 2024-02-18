#ifndef SCREEN_ART_CONTROLS_DATA_TYPES_TABLE
#define SCREEN_ART_CONTROLS_DATA_TYPES_TABLE

#include "screen/matrix/pen.h"
#include "screen/art/controls/data/types/page.h"
#include "screen/art/controls/data/types/scroll.h"

class Table {
    private:
        Page m_lines, m_records;

    public:
        Scroll Pages;
        bool End, Over;

        void Update() {
            End = m_lines.Relative < m_records.Relative;
            Over = m_lines.Absolute < m_records.Absolute;
        }

        void Scroll() {
            m_lines.Iterate();
            Update();
        }

        void SetRecords(Page* records) {
            m_records.Set(records);
            Pages.Bottom = m_records.Split();
        }

        Page* GetLines() { return &m_lines; }

        void SetLines(Page* lines) {
            m_lines.Set(lines);
            Update();
        }

        void Length() {
            Pen::ink().Text(m_lines.Absolute);
            Pen::ink().Text(L" / ");
            Pen::ink().Text(m_records.Absolute);
        }

        void HomePage() {
            Pages.Home();
            m_lines.Home();
        }

        void EndPage() {
            Pages.End();
            m_lines.End(m_records.Absolute);
        }

        void Down() {
            if (Pages.Down())
                HomePage();
            else
                m_lines.Down(m_records.Absolute, m_records.Relative);
        }

        void Up() {
            if (Pages.Up())
                EndPage();
            else
                m_lines.Up(m_records.Relative);
        }
};

#endif
