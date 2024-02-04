class Table {
    private:
        Page m_lines;

    public:
        Page records;
        bool End, Over;

        void Update() {
            End = m_lines.Relative < records.Relative;
            Over = m_lines.Absolute < records.Absolute;
        }

        void Iterate() {
            m_lines.Iterate();
            Update();
        }

        Page* GetLines() { return *m_lines; }

        void SetLines(Page lines) {
            m_lines = lines;
            Update();
        }



};
