void ManualArrayInput() {
    InputParameterValue(numeric);
}

void RandomArrayInput() {
    Boundary<short>* limits = numberic->Edges();

    short size = limits->start + limits.end + 1;

    numeric->result = rand() % size + limits->start;
}

short (*array_input)(void)[2] = {
    RandomArrayInput, ManualArrayInput
};

std::vector<short> ArrayInputLoop(short size) {
    Boundary<short> limits(-99, 99);
    std::vector<short> result(size);

    numeric->SetBounds(&limits);

    InputParameterName(texts["input_array_elements"]);

    numeric->Edges->View();

    short i = 0;

    while (i < size) {
        array_input[current_array_input]();
        result.push_back(numeric->result);

        Pen::ink().screen.Span(1)->Page(field + 1);
        Pen::ink().screen->Move()->Clear();
        Pen::ink().Text(size, L" / ", ++i);
    }

    return result;
}

void QueryArray() {
    Boundary<short> limits(1, 20);
    numeric->Bounds(&limits);

    short size = numeric->result;

    original = ArrayInputLoop(size);
    sorted = original;

    Pen::ink().array.Show();
    Pen::ink().screen.Span(1)->Form(4)->Size(2);
    Pen::ink().Quote("output_source_array");
    Pen::ink().screen.Line();
    Pen::ink().Quote("output_sorted_array");

}
