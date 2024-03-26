std::vector<Book> m_basis;

void Book :: Form(byte buffer) {
    if (buffer >= m_basis.size()) 
        throw std::overflow_error("Selected form not found");
    form = buffer;
}
