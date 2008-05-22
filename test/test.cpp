// A test application for...
// Brizo Disassembler by DEATH, 2003-2004
//
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cassert>

#include <brizo/dasm.h>
#include <brizo/brizo.h>

using namespace std;

int main(int argc, char *argv[])
{
    try {
        if (argc < 2) {
            cout << "Usage: test <filename>" << endl;
            return 0;
        }

        ifstream input(argv[1], ios::binary);
        if (!input.good()) {
            cout << "Bad file: " << argv[1] << endl;
            return 0;
        }

        // Load entire file into memory - not very smart, but serves this test well
        input.seekg(0, ios::end);
		std::size_t size = input.tellg();
        input.seekg(0, ios::beg);

        // This is just a test!
        if (size == 0 || size > (1024 * 1024)) {
            cout << "Gee.. gimme file with decent size." << endl;
            return 0;
        }

        vector<unsigned char> buffer(size);
        input.read(reinterpret_cast<char *>(&buffer[0]), static_cast<streamsize>(size));
        size = input.gcount();

        if (size == 0) {
            cout << "Couldn't read much from file.. in fact, couldn't read nothing at all!" << endl;
            return 0;
        }

        // The core of this test
        Brizo::Disassembler disasm;
        unsigned int total = 0;
        cout << hex;
        while (size) {
            int processed = disasm.Decode(&buffer[total], size);
            if (processed <= 0) {
                cout << "Data at 0x" << total << " is bad? skipping.." << "\n";
                total++;
                size--;
            } else {
                // Format an instruction
                assert(static_cast<std::size_t>(processed) <= size);
                disasm.Format(total);
                // 1 - Address
                cout << setw(8) << setfill('0') << total << " ";
                // 2 - Prefix (optional)
                const char *text = disasm.GetFormattedPrefix();
                if (*text)
                    cout << text << " ";
                // 3 - Opcode mnemonic
                cout << disasm.GetFormattedOpcode();
                // 4 - Operands (optional)
                std::size_t operandCount = disasm.GetOperandCount();
                for (std::size_t i = 0; i < operandCount; i++) {
                    cout << " " << disasm.GetFormattedOperand(i);
                    if (i != (operandCount - 1))
                        cout << ",";
                }

                cout << "\n";
                total += processed;
                size -= processed;
            }
        }
        cout << flush;
    }
    catch(const exception & ex) {
        cout << endl << "Exception caught: " << ex.what() << endl;
    }

	return 0;
}
