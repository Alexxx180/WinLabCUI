
const std::wstring text = L"Example of (original) string";

std::wstring Strings :: Replace() {
    size_t start = text.find(L"(");
    size_t end = text.find(L")");
    return text.replace(start, end - start, L"");
}

void Strings :: Show() {
    std::wstring next = Replace();
    
}
