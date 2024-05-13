std::vector<Record> Records :: DemandOverProposal(char i) {
    std::vector<Record> target;
    while (i < 28) {
        if (model[i].IsDemandBigger())
            target.push_back(model[i]);
        i += week;
    }
    return target;
}

Records :: Records() {
    // Type, demand, proposal, cost (today, yesterday)
    model[0] = { 0, 500, 400, 200,  120 };
    model[1] = { 1, 200,  20, 640, 5300 };
    model[2] = { 2, 135, 420, 440,   23 };
    model[3] = { 0, 410, 123, 250,  350 };
    model[4] = { 0, 556, 724, 856,  430 };
    model[5] = { 2, 760, 443, 240,  470 };
    model[6] = { 3, 589, 670, 380, 2710 };
    model[7] = { 0, 513, 232, 901, 1923 };
    model[8] = { 0,  23, 560, 889,   12 };
    model[9] = { 3, 612, 420, 440,  459 };
    model[10] = { 2, 123, 784, 124, 9320 };
    model[11] = { 0, 548, 718, 293, 3280 };
    model[12] = { 0, 663,  21,  41, 3481 };
    model[13] = { 2, 680, 281, 483,  565 };
    model[14] = { 0, 391, 101, 231, 1923 };
    model[15] = { 1,  23, 122, 222,  384 };
    model[16] = { 0, 291, 420, 999,  111 };
    model[17] = { 0, 132, 784, 894, 9320 };
    model[18] = { 2, 289, 398, 679,  132 };
    model[19] = { 0, 593, 311, 442, 3231 };
    model[20] = { 3, 132, 281,  83,  565 };
    model[21] = { 0, 100, 393, 231, 1342 };
    model[22] = { 0, 124, 823, 222,  444 };
    model[23] = { 0,   5, 998, 233,  472 };
    model[24] = { 1, 839, 784, 894,  239 };
    model[25] = { 0, 128, 398, 679,  132 };
    model[26] = { 2, 302, 101, 442, 4891 };
    model[27] = { 0, 132, 281,  83,  543 };
}
