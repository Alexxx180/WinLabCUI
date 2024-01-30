#ifndef SCREEN_ART_BAR
#define SCREEN_ART_BAR

#include <vector>

#include "screen/art/drawing.h"
#include "common/types.h"
#include "input/boundary.h"

#include <conio.h>

class Bar {
private:
    const float max_percents = 100.0f;
    const COORD m_percentage = {
        static_cast<short>(max_percents * 10), 8
    };
    COORD m_cursor, m_slider, m_optimization = { 0, -1 };
    short m_step;
    float m_count;
    bool m_orientation;
    wchar_t carriage, volume;

    Frame m_symbols;
    Stapler m_gun;

    void Drawing(wchar_t symbol) {
        Draw(&m_cursor, symbol);
    }

    void Slide(short position) {
        m_gun.progress(&m_cursor, position);
    }

    void Extend(short position) {
        m_gun.pins(&m_cursor, position);
    }

    void PercentagePosition() {
        Extend(m_slider.Y);
        Slide(m_optimization.Y);
    }

    void ClearPercentage() {
        if (m_optimization.Y < 0)
            return;

        PercentagePosition();
        //wprintf(L"Width: 100.0 . %i |", m_percentage.Y);
        Clean(&m_cursor, m_percentage.Y);
    }

    void SetPercentage(float basis) {
        PercentagePosition();

        float result = max_percents * basis;
        MoveCursor(&m_cursor);
        wprintf(L"%.1f %%", result);
    }


    // Don't depend on size
    void FillBar(char symbol) {
        short i = placement.P1.Y;
        short size = placement.SumY();

        while (++i < size) {
            VLine(&m_cursor, i);
            Drawing(symbol);
        }
    }

    // Don't depend on size
    void ClearBar(short width) {
        short i = placement.P1.Y;
        short size = placement.SumY();

        while (++i < size) {
            VLine(&m_cursor, i);
            Clean(&m_cursor, width);
        }
    }

    // Depends on sliding methods
    void DrawEdges(Edges* edges, Range* target) {
        short i = target->P1.X;
        short size = target->SumX();

        short start = target->P1.Y;
        short end = target->SumY();

        while (++i < size) {
            Slide(i);

            Extend(start);
            Drawing(edges->left);

            Extend(end);
            Drawing(edges->right);
        }
    }

    void DrawAngles() {
        m_cursor = placement.P1;
        Drawing(m_symbols.top.left);

        HLine(&m_cursor, placement.SumX());
        Drawing(m_symbols.top.right);

        VLine(&m_cursor, placement.SumY());
        Drawing(m_symbols.bottom.right);

        HLine(&m_cursor, placement.P1.X);
        Drawing(m_symbols.bottom.left);
    }

    void SetOrientation() {
        if (m_orientation) {
            m_gun.Set(VLine, HLine);

            volume = m_symbols.horizontal.center;
            carriage = m_symbols.horizontal.left;

            m_slider.Y = placement.SumX() + 2;
        } else {
            m_gun.Set(HLine, VLine);

            volume = m_symbols.vertical.center;
            carriage = m_symbols.vertical.right;

            m_slider.Y = placement.SumY() + 1;
        }
    }

    void MoveCarriage() {
        if (m_slider.X == m_optimization.Y)
            return;

        short position, target, size;

        position = placement.P1.X;

        HLine(&m_cursor, position + 1);
        ClearBar(placement.SumX() - position);

        Slide(m_slider.X);
        FillBar(carriage);

        size = m_cursor.X - position;

        position += m_percentage.Y;
        while (position < size) {
            Slide(position);
            FillBar(volume);
            position += m_percentage.Y;
        }
    }

public:
    Range placement;

    Bar* SetSize(Range* sizes) {
        placement = *sizes;
        return this;
    }

    Bar* SetSymbols(Frame* symbols) {
        m_symbols = *symbols;
        return this;
    }

    // Sets the dependencies
    Bar* Orientation(bool vertical) {
        m_orientation = vertical;
        return this;
    }

    Bar* SetDivisions(unsigned int count) {
        m_optimization.X = static_cast<short>(count / m_percentage.X);
        m_step = m_optimization.X - 1;
        m_count = count;
        return this;
    }

    Bar* Show() {
        m_gun.Set(HLine, VLine);
        DrawEdges(&m_symbols.horizontal, &placement);

        Range reverse = placement.SwapSizes();

        m_gun.Set(VLine, HLine);
        DrawEdges(&m_symbols.vertical, &reverse);

        DrawAngles();
        SetOrientation();
        return this;
    }

    Bar* Progress(float basis) {
        short start = placement.P1.X;
        short end = placement.P2.X;

        m_slider.X = static_cast<short>(start + basis * end);
        
        MoveCarriage();

        ClearPercentage();

        m_optimization.Y = m_slider.X;

        SetPercentage(basis);
        return this;
    }

    Bar* ProgressData(float value) {
        if (++m_step < m_optimization.X)
            return this;

        if (m_step > 0)
            m_step = 0;

        float basis = value / m_count;
        return Progress(basis);
    }
};

#endif
